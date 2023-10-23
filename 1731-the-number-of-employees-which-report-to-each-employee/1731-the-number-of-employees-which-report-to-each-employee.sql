Select second.employee_id, second.name, Count(firs.employee_id) as reports_count,
Round(Avg(firs.age)) as average_age
From Employees as firs join Employees as second
On firs.reports_to = second.employee_id
Group by second.employee_id
Order by second.employee_id
