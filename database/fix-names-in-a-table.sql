/* Write your T-SQL query statement below */
select u.user_id, concat(upper(left(u.name, 1)), lower(substring(u.name, 2, len(u.name)))) as name
from Users u
order by user_id;