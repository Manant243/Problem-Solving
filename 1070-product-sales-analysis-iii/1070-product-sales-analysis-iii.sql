Select product_id, year as first_year, quantity, price
from Sales
Where (product_id, year) in (

    Select product_id, min(year)
    from sales
    Group by product_id
)