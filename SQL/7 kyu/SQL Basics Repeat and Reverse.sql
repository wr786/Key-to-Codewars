SELECT
  LPAD(name, LENGTH(name)*3, name) as name, 
  REVERSE(characteristics) as characteristics 
FROM monsters