Select DATE_FORMAT(trans_date ,'%Y-%m') as month, country, 
count(month(trans_date)) as trans_count,
count(if(state = 'approved', 1, null)) as approved_count, 
Sum(amount) as trans_total_amount, Sum(if(state = 'approved', amount, 0)) as approved_total_amount
from Transactions
Group by DATE_FORMAT(trans_date ,'%Y-%m'), country