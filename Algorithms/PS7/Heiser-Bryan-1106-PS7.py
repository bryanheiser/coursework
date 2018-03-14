#this function finds the cost to sub a with b
def sub(a,b):
	c = 0
	if(a!=b):
		c = 10
		
	return c

#this function finds cost of transpose(i.e. swap and possible subs)
def trans(a,b):
	#adds cost of swap since it happens everytime there is a transpose
	c = 10
	
	#checks length of input substrings and determining sub costs
	if(len(a)==2 and len(b)==2):
		c += sub(a[1],b[0])
		c += sub(a[0],b[1])
	elif(len(a)==2 and len(b)==1):
		c += sub(a[0],b)
	elif(len(a)==1 and len(b)==2):
		c += sub(a,b[0])
	elif(len(a)==1 and len(b)==1):
		c += sub(a,b)
		
	return c

def alignStrings(x,y):
	indel = 1
	x_len = len(x)+1
	y_len = len(y)+1
		
	#initialize S matrix with large values
	S = []
	for k in range(y_len):
		S.append([])
		for l in range(x_len):
			S[k].append(10000)
			
	#fill top row with indels
	for n in range(y_len):
		S[n][0] = n
	
	#fill left column with indels
	for m in range(x_len):
		S[0][m] = m
	
	#find min cost for aligning the two strings at different points of the string
	for i in range(1,y_len):
		for j in range(1,x_len):
			if(i>=2 and j>=2):
				upper_corner = S[i-2][j-2] + trans(x[j-1:j+1],y[i-1:i+1])
			else:
				upper_corner = 10000
			
			#makes sure element of strings accessed for sub are in bounds
			sub_i = i-1
			sub_j = j-1
			if(sub_i >= len(y)):
				sub_i = len(y)-1
			if(sub_j >= len(x)):
				sub_j = len(x)-1
			
			#uses cost of previously computed costs to determine possible costs for S[i][j]	
			corner = S[i-1][j-1] + sub(x[sub_j],y[sub_i])
			up = S[i-1][j] + indel
			left = S[i][j-1] + indel
			
			#finds min of all costs computed and updates cost martix
			S[i][j] = min(upper_corner, corner, up, left)
	
	return S

#find optimal operation cost that led to current cost in matrix S
def determineOptimalOp(S,i,j,x,y):
	if(j>0 and i>0):
		if(S[i][j]==S[i-1][j-1]):
			optimal = 0
			return optimal
		
	optimal = 1
	#computes and returns cost of transposing x to become y
	#makes sure this computation does not extend out of bounds
	if(i>=2 and j>=2):
		transpose = trans(x[j-1:j+1],y[i-1:i+1])
		far_corner = S[i-2][j-2] + transpose
		if(S[i][j] == far_corner):
			optimal = transpose
			
	indel = 1
	#compute all other costs around current element of i,j
	#while current element has three costs to look at
	if(i>0 and j>0):
		subOp = sub(x[j-1],y[i-1])
		corner = S[i-1][j-1] + subOp
		if(S[i][j] == corner):
			optimal = subOp	
		
		up = S[i-1][j] + indel
		left = S[i][j-1] + indel
		if(S[i][j] == left or S[i][j] == up):
			optimal = indel
	#determines possible costs when current element can only look left
	elif(i==0):
		left = S[i][j-1] + indel
		if(S[i][j] == left):
			optimal = indel
	#determines possible costs when current element can only look up
	elif(j==0):
		up = S[i-1][j] + indel
		if(S[i][j] == up):
			optimal = indel
	
	return optimal
	
#finds and returns indices of where previous optimal op came from
def updateIndices(S,i,j,a):
	b = len(a)-1
	if(a[b]==0):
		return [i-1,j-1]
	elif(a[b]==1):
		if(i==0):
			return [i,j-1]
		elif(j==0):
			return [i-1,j]
		elif(S[i][j-1]>S[i-1][j]):
			return [i-1,j]
		else:
			return [i,j-1]
	else:
		return [i-2,j-2]
			
			
		return 
	
#generates array of optimal operation costs that formed the optimal cost of aligning x & y
def extractAlignment(S,x,y):
	a = []
	i = len(y)
	j = len(x)
	while(i>0 or j>0):
		#adds previous optimal op to array a then updates the i & j to where that op came from in S
		a.append(determineOptimalOp(S,i,j,x,y))
		[i,j] = updateIndices(S,i,j,a)
		
	return a
	
#finds the substrings of input string x that are less than or equal to the length L
#that align with string y via a run of no-ops
def commonSubstrings(x,L,a):
	subStrings=[]
	count = 0
	i=0
	while(i < len(a)-1):
		if(a[i]==0):
			#iterates over each no-op forming size of current substring in x
			while(a[i]==0):
				count+=1
				i+=1
			#executes if substring length is greater than or equal to input size L
			if(count>=L):
				subStrings.append(x[len(x)-i:len(x)-i+count])
			count = 0
		i+=1
		
	return subStrings
	
#make string x = first file
with open('csci3104_F2017_PS7_data_string_x.txt') as dataFile:
	for line in dataFile:
		string_x = line
	
#make string y = second file	
with open('csci3104_F2017_PS7_data_string_y.txt') as dataFile1:
	for line in dataFile1:
		string_y = line
	
#call to find common substrings of string x from y	
print(commonSubstrings(string_x, 10, extractAlignment(alignStrings(string_x,string_y), string_x, string_y)))


