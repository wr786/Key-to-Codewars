SELECT
  name,
  weight,
  price,
  CAST(ROUND(CAST(1000 * price / weight as NUMERIC), 2) as FLOAT) as price_per_kg
FROM
  products
ORDER BY 
  price_per_kg ASC, name ASC;