/*1*/
SELECT DISTINCT name, statecode FROM states;

/*2*/
SELECT * FROM counties WHERE name LIKE 'Prince%';

/*3*/
SELECT DISTINCT population_2010 FROM states WHERE statecode LIKE 'IN%';

/*4*/
SELECT COUNT(counties.name) as num_counties_MD FROM counties INNER JOIN states ON counties.statecode=states.statecode WHERE counties.statecode LIKE 'MD%';

/*5*/
SELECT name FROM states WHERE admitted_to_union = (SELECT MAX(admitted_to_union) FROM states);

/*6*/
SELECT name FROM senators WHERE affiliation LIKE 'D%' AND name NOT IN (SELECT chairman FROM committees) ORDER BY name;
