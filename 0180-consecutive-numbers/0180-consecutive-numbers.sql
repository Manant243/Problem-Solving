Select distinct num as ConsecutiveNums
From Logs
Where (id+1, num) in (Select * from Logs) and (id+2, num) in (Select * from Logs)