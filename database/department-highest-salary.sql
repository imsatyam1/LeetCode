# Write your MySQL query statement below
with RankedEmployees AS (
    SELECT 
        e.*,
        DENSE_RANK() OVER (
            PARTITION BY departmentId
            ORDER BY salary DESC
        ) AS rnk
    FROM Employee e
)
SELECT 
    d.name as Department,
    r.name as Employee,
    r.salary as Salary
FROM RankedEmployees r
JOIN Department d
    ON r.departmentId = d.id
WHERE rnk = 1;