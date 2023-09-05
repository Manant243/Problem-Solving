Select r.contest_id, Round((count(u.user_id)/ (Select count(*) from Users))*100, 2) as percentage
From Register as r join Users as u
On r.user_id = u.user_id
Group by r.contest_id
Order by percentage desc, r.contest_id asc