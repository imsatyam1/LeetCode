/* Write your T-SQL query statement below */
select top 1 person_name
from (
    select person_name, turn, 
    sum(weight) over (order by turn) as totalweight
    from queue
) as q
where q.totalweight <= 1000
order by turn desc;