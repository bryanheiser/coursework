/*Stefano Costa
Tyler Moore
Bryan Heiser
*/

/*1*/
SELECT *
FROM `store`
ORDER BY `name`;

/*2*/
SELECT *			
FROM `store`
ORDER BY `name`
LIMIT 3;

/*3*/
SELECT * 		
FROM `store`
ORDER BY `name`
LIMIT 3 OFFSET 2;

/*4*/
SELECT *
FROM `store` WHERE `price` > 1
ORDER BY `price`;

/*5*/
SELECT *, (`quantity` * `price`)		
FROM `store`
ORDER BY `name`;

/*6*/
SELECT SUM(`price`)
FROM `store`;

/*7*/
SELECT COUNT(`id`)
FROM `store`;

/*8*/
SELECT *
FROM `course` WHERE `department_id` = 1
ORDER BY `name`;

/*9*/
SELECT SUM(`count`)
FROM `enrollment`;

/*10*/
SELECT COUNT(`id`)
FROM `enrollment`;

/*11*/
SELECT COUNT(`id`)
FROM `department`;

/*12*/

SELECT GROUP_CONCAT(department.name, course.name) as course_name FROM course JOIN department;


/*13*/

SELECT GROUP_CONCAT(department.name, course.name) as course_name FROM course JOIN department ON department.id  = 1;

/*14*/

SELECT *, course.name as course_name FROM course JOIN (department, enrollment) ON (course.department_id = department.id AND course.id = enrollment.id);

/*15*/

UPDATE





