/* Write your T-SQL query statement below */
select id as Id from
(
    select id, recordDate, temperature,
    lag(temperature) over (order by recordDate) as prev_temp,
    lag(recordDate) over (order by recordDate) as prev_date
    from weather
) t
where temperature > prev_temp and datediff(day, prev_date, recordDate) = 1;