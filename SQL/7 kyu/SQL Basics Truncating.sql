SELECT
  (CASE WHEN number1 + number2 < 0
    THEN CEIL(number1 + number2)
    ELSE FLOOR(number1 + number2)
  END) as towardzero
FROM
  decimals;