# Write your MySQL query statement below
select m.employee_id, m.name, count(e.employee_id) as reports_count,
round(avg(e.age)) average_age
from employees m
join employees e
on m.employee_id = e.reports_to
group by 1
order by 1;