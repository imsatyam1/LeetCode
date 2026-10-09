select e.employee_id, e.name, 
COUNT(m.employee_id) AS reports_count,
Round(avg(cast(m.age as float)), 0) as average_age
from Employees e
Join Employees m
on e.employee_id = m.reports_to
group by e.employee_id, e.name
order by e.employee_id;