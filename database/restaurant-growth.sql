/* Write your T-SQL query statement below */
with daily as (
    select 
        visited_on, 
        sum(amount) as amount
    FROM Customer
    GROUP BY visited_on
)

select
    visited_on,
    sum(amount) over(
        order by visited_on
        rows between 6 preceding and current row
    ) as amount,

    round(
        sum(amount) over (
            order by visited_on
            rows between 6 preceding and current row
        ) / 7.0,
        2
    ) as average_amount
from daily
order by visited_on
offset 6 rows;