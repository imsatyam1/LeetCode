/* Write your T-SQL query statement below */
select p1.product_id,
    coalesce(
        (
            select top 1 p2.new_price
            from products p2
            where p1.product_id = p2.product_id
            and p2.change_date <= '2019-08-16'
            ORDER BY p2.change_date DESC
        ), 10
    ) as price

from (
    select distinct(product_id) 
    from products 
) as p1;