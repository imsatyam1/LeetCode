/* Write your T-SQL query statement below */
select e.name as name 
from Employee e
where e.id in (
    select managerId
    from Employee
    WHERE managerId IS NOT NULL
    group by managerId
    having count(*) >= 5
);