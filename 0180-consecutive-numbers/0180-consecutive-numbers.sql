
with cte as(
    Select num,
    lead(num, 1) over() num1,
    lead(num, 2) over() num2
    from Logs
)

Select distinct num as ConsecutiveNums from cte Where num = num1 and num = num2