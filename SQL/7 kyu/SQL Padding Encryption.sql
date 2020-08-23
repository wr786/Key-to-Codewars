SELECT
  RPAD(md5, LENGTH(sha256), '1') as md5,
  LPAD(sha1, LENGTH(sha256), '0') as sha1,
  sha256
FROM
  encryption