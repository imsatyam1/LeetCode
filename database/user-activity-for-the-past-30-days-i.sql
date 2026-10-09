/* Write your T-SQL query statement below */
select distinct(activity_date) as day, count(distinct(user_id)) as active_users
from Activity
WHERE DATEDIFF(day, activity_date, '2019-07-27') BETWEEN 0 AND 29
group by activity_date;