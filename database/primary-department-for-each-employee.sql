# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
Where primary_flag = 'Y'

UNION

SELECT employee_id, department_id
From Employee
Group BY employee_id
Having Count(*) = 1;