/* Write your T-SQL query statement below */
select max(salary) as  SecondHighestSalary
from (select salary, dense_rank() over (order by salary desc) as rnk from Employee) as t
where rnk = 2;