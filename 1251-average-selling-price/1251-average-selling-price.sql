# Write your MySQL query statement below
-- select p.product_id, round(COALESCE(sum(p.price*u.units),0) / sum(u.units), 2) as average_price
-- from prices as p left join unitssold as u
-- on (p.product_id = u.product_id) and (u.purchase_date >= p.start_date and u.purchase_date <= p.end_date)
-- group by p.product_id;

SELECT p.product_id, IFNULL(ROUND(SUM(units*price)/SUM(units),2),0) AS average_price
FROM Prices p LEFT JOIN UnitsSold u
ON p.product_id = u.product_id AND
u.purchase_date BETWEEN start_date AND end_date
group by product_id

