Select u.product_id, Round(Sum(u.units*p.price)/Sum(u.units), 2) as average_price
From Prices as P join UnitsSold as u
On u.product_id = p.product_id AND u.purchase_date between p.start_date and p.end_date
Group by product_id