# Write your MySQL query statement below
select m.name 
from employee e join employee m
on m.id = e.managerId
group by m.id
having count(*) >= 5