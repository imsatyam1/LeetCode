/* Write your T-SQL query statement below */
select s.name 
from salesperson s
where sales_id not in (
    select o.sales_id from Orders o
    JOIN Company c ON o.com_id = c.com_id
    WHERE c.name = 'RED'
)