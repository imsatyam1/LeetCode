/* Write your T-SQL query statement below */
select distinct(customer_id)
from customer
where customer_id in (
    select c.customer_id
    from customer c
    GROUP BY customer_id
    HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(*)
    FROM Product)
);