SELECT age, COUNT(id) as people_count
FROM people
GROUP BY age