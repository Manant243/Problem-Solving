Select p.product_name, s.year, s.price
from Sales as s join Product as p 
On s.product_id = p.product_id