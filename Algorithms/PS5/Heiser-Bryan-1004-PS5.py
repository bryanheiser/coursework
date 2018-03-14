import numpy as np
import pandas as pd
import random
import matplotlib.pylab as plt
from collections import Counter

def f1(c):
	val = ord(c) - 64
	return val

def h1(x):
	charSum = 0
	l = 5701
	for ii in range(len(name)):
		charSum += f1(name[ii])
	bucket1 = charSum % l
	return bucket1
	
def f2(c, a):
	value = ord(c) - 64
	val = value * a
	return val
	
def h2(x):
	charSum2 = 0
	l = 5701
	for jj in range(len(name)):
		a = random.randrange(0,l-1)
		charSum2 += f2(name[jj], a)
	bucket2 = charSum2 % l
	return bucket2


with open('dataFile.txt') as dataFile:
	h1arr = []
	h2arr = []
	for line in dataFile:
		choice = np.random.choice([0,1])
		if choice:
			a = line.split()
			name = a[0]
			h1arr.append(h1(name))
			h2arr.append(h2(name))
	h1arr = np.asarray(h1arr)
	h2arr = np.asarray(h2arr)
			
fig, ax = plt.subplots(figsize=(12,6))
n, bins, patches = plt.hist(h1arr, 5701, color="steelblue", alpha=0.5)
plt.xlim(0, 5701)
plt.title("h1(x)", fontsize=16)
ax.set_xlabel("Buckets", fontsize=16)
ax.set_ylabel("Frequency", fontsize=16)
fig.savefig("h1.jpg")

fig, ax = plt.subplots(figsize=(12,6))
n, bins, patches = plt.hist(h2arr, 5701, color="steelblue", alpha=0.5)
plt.xlim(0, 5701)
plt.title("h2(x)", fontsize=16)
ax.set_xlabel("Buckets", fontsize=16)
ax.set_ylabel("Frequency", fontsize=16)
fig.savefig("h2.jpg")

h1freqArr = []
h2freqArr = []
for j in range(200):
	newh1Arr = []
	newh2Arr = []
	n = 100*(201-j)
	for i in range(len(h1arr)-n):
		newh1Arr.append(h1arr[i])
		newh2Arr.append(h2arr[i])
	newh1Arr = np.asarray(newh1Arr)
	newh2Arr = np.asarray(newh2Arr)
	freqh1 = Counter(newh1Arr)
	freqh2 = Counter(newh2Arr)
	commonh1 = freqh1.most_common()
	commonh2 = freqh2.most_common()
	h1freqArr.append(commonh1[1][1])
	h2freqArr.append(commonh2[1][1])
	
fig, ax = plt.subplots(figsize=(12,6))
plt.plot(h1freqArr)
ax.set_xlabel("Trials (Stepping by 100 in Size Each Trial)", fontsize=16)
ax.set_ylabel("Highest Frequency", fontsize=16)
fig.savefig("h1freq.jpg")

fig, ax = plt.subplots(figsize=(12,6))
plt.plot(h2freqArr)
ax.set_xlabel("Trials (Stepping by 100 in Size Each Trial)", fontsize=16)
ax.set_ylabel("Highest Frequency", fontsize=16)
fig.savefig("h2freq.jpg")







	
		
		
		
		
