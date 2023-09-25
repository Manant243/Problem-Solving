Select customer_id, count(customer_id) as count_no_trans
From Visits
Where visit_id not in 
(Select v.visit_id
From Visits as v inner join Transactions as t
On v.visit_id = t.visit_id)
Group by customer_id
