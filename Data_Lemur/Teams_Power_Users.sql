/*
Escreva uma consulta para identificar os dois principais 
usuários avançados que enviaram o maior número de mensagens 
no Microsoft Teams em agosto de 2022. Exiba os IDs desses 
dois usuários junto com o número total de mensagens que 
eles enviaram. Produza os resultados em ordem decrescente 
com base na contagem de mensagens.
*/

SELECT sender_id, COUNT(*)
FROM messages
WHERE EXTRACT(YEAR FROM sent_date) = 2022
  AND EXTRACT(MONTH FROM sent_date) = 08
GROUP BY sender_id
ORDER BY 2 DESC
LIMIT 2;