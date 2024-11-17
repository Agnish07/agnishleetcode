# Write your MySQL query statement below
with unum as(
select num from mynumbers
group by 1
having count(num) = 1)
select max(num) as num
from unum;