Select query_name, Round(Avg(rating/position), 2) as quality,
Round(Avg(rating < 3)*100, 2) as poor_query_percentage
From Queries
Group by query_name