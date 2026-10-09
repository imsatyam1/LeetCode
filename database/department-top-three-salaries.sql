# Write your MySQL query statement below
WITH RankedEmployees AS (
    select 
        e.*,
        DENSE_RANK() OVER (
            Partition by e.departmentId
            Order by salary desc
        ) as rnk
    From Employee e
) 
select 
    d.name as Department,
    r.name as Employee,
    r.salary as Salary
FROM RankedEmployees r
JOIN Department d
    ON r.departmentId = d.id
Where r.rnk <= 3;