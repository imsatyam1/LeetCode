CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        /* Write your T-SQL query statement below. */
        SELECT  max(salary)
        from (select salary, dense_rank() over (order by salary desc) as rnk
        from Employee
    ) as ranked
    where rnk = @N
    );
END 