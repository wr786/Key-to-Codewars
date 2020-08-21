SELECT capital
FROM countries
WHERE country LIKE 'E%' AND continent in ('Africa', 'Afrika')
ORDER BY capital
LIMIT 3;