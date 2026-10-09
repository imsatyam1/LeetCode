/* Write your T-SQL query statement below */
with cte as (
    select *, 
    ROW_NUMBER() over (partition by email order by id) as rnk
    from person
)

delete from cte
where rnk > 1;