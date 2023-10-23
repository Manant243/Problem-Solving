# Write your MySQL query statement below

Select employee_id, department_id
From Employee
Where employee_id in (
    Select employee_id
    From Employee
    Group by employee_id
    Having Count(employee_id) = 1
)
Or primary_flag = 'Y'