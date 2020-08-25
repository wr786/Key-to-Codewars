SELECT
  name,
  SUM(won) as won,
  SUM(lost) as lost
FROM fighters
WHERE
  move_id not in (
    SELECT id
    FROM winning_moves
    WHERE move in ('Hadoken', 'Shouoken', 'Kikoken')
  )
GROUP BY name
ORDER BY won DESC
LIMIT 6;