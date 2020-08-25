SELECT *
FROM students
WHERE (quality1 = 'evil' and quality2 = 'cunning')
  OR  (quality1 = 'brave' and quality2 <> 'evil')
  OR  (quality1 = 'studious' or quality2 = 'intelligent')
  OR  (quality1 = 'hufflepuff' or quality2 = 'hufflepuff')
;