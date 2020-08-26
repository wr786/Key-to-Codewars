SELECT
  race,
  COUNT(id) as count
FROM demographics
GROUP BY race
ORDER BY count DESC;