# Write your MySQL query statement below

Select Signups.user_id, ROUND(AVG(if(Confirmations.action = "confirmed", 1, 0)), 2) as confirmation_rate
from Signups left join Confirmations
On Signups.user_id = Confirmations.user_id
Group by Signups.user_id
