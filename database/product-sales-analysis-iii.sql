/* Write your T-SQL query statement below */
select 
    s.product_id,
    s.year as first_year,
    s.quantity,
    s.price
from Sales s
JOIN (
    SELECT
        product_id,
        MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
) x
    ON s.product_id = x.product_id
    AND s.year = x.first_year;