/* Write your T-SQL query statement below */
select contest_id as contest_id,
ROUND(COUNT(user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
from Register r
group by contest_id
ORDER BY percentage DESC, contest_id ASC;