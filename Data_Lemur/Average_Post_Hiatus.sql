/*
Dada uma tabela de postagens do Facebook, para cada usuário 
que postou pelo menos duas vezes em 2021, escreva uma consulta
para encontrar o número de dias entre a primeira postagem do
ano de cada usuário e a última postagem do ano no ano de 2021. 
Produza o usuário e número de dias entre a primeira e a última 
postagem de cada usuário.
*/

WITH User_Posts AS (
    SELECT user_id,
           MIN(post_date) AS first_post,
           MAX(post_date) AS last_post
    FROM posts
    WHERE EXTRACT(YEAR FROM post_date) = 2021
    GROUP BY user_id
    HAVING COUNT(*) >= 2
)

SELECT user_id,
       EXTRACT(DAY FROM (last_post - first_post)) AS days_between
FROM UserPosts;

