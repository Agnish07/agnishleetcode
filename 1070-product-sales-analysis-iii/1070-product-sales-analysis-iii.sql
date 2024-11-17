# Write your MySQL query statement below
with ptoy as
    (
        select product_id, min(year) year
        from sales
        group by 1
    )
select sales.product_id, ptoy.year as first_year,
sales.quantity, sales.price
from sales
inner join ptoy
using(product_id, year);
