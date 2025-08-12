# Write your MySQL query statement below
select w1.Id 
from Weather w1
join Weather w2
where datediff(w1.recorddate, w2.recorddate) = 1
and w1.temperature > w2.temperature;