/*
 Em outras palavras, agrupe os usuários pelo número de tweets
 que postaram em 2022 e conte o número de usuários em cada grupo.
*/

SELECT tweet_bucket, COUNT(*) AS users_num
FROM (SELECT user_id, COUNT(*) AS tweet_bucket
      FROM tweets
      WHERE EXTRACT(YEAR FROM tweet_date) = 2022
      GROUP BY user_id) AS tweet
GROUP BY tweet_bucket
ORDER BY tweet_bucket;
