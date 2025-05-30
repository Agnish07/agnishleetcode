# Write your MySQL query statement below
select query_name, round(avg(rating/position),2) quality,
round(avg(case when rating >= 3 then 0 else 1 end) * 100,2) poor_query_percentage
from queries
where is not null
group by query_name;