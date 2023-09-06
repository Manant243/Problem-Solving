Select activity_date as day, count(distinct user_id) as active_users
from Activity
Where DATEDIFF('2019-7-27', activity_date) between 0 AND 29
Group by activity_date