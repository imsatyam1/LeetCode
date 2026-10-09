SELECT
    query_name,
    CAST(SUM(CAST(rating AS FLOAT) / position) / COUNT(*) AS DECIMAL(10, 2)) AS quality,
    CAST(
        SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(*)
        AS DECIMAL(10, 2)
    ) AS poor_query_percentage
FROM Queries
GROUP BY query_name;