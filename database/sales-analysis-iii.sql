# Write your MySQL query statement below
SELECT p.product_id, p.product_name
FROM Product p
JOIN Sales s
ON p.product_id = s.product_id
Group by s.product_id 
Having
    MIN(s.sale_date) >= '2019-01-01' and MAX(s.sale_date) <= '2019-03-31';