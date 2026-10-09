/* Write your T-SQL query statement below */
SELECT 
    ROUND(
        CAST(COUNT(DISTINCT a.player_id) AS DECIMAL(10, 2))
        / (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM Activity a
JOIN (
    SELECT 
        player_id,
        MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) first_login
    ON a.player_id = first_login.player_id
    AND a.event_date = DATEADD(day, 1, first_login.first_login);