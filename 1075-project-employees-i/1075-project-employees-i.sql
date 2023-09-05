
Select p.project_id, Round(Avg(e.experience_years), 2) as average_years
From Project as p join Employee as e
On p.employee_id = e.employee_id 
Group by p.project_id