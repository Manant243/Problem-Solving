

Select distinct product_id, new_price as price 
From Products
Where (product_id, change_date) in (
    Select product_id, max(change_date)
    From Products
    Where change_date <= '2019-08-16'
    Group by product_id
)
Union
Select distinct product_id, 10 as price
From Products
Group by product_id
Having (min(change_date) > '2019-08-16')