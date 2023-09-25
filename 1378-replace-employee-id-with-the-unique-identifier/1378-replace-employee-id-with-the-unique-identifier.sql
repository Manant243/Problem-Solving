Select e.name, eu.unique_id
From Employees as e left join EmployeeUNI as eu
On e.id = eu.id