# Write your MySQL query statement below
select name from employee 
join (
    select managerid as id, count(1) as cnt
    from employee
    group by 1
    having cnt >= 5
) as t 
using(id);