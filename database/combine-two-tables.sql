/* Write your T-SQL query statement below */
SELECT 
p.firstname as firstName, 
p.lastname as lastName, 
a.city as city,
a.state as state

FROM Person p
left Join Address a
on p.personId = a.personId;