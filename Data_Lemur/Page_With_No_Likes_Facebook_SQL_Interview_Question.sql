/*
Suponha que você receba duas tabelas contendo dados sobre páginas do 
Facebook e suas respectivas curtidas (como em “Curtir uma página do Facebook”).
Escreva uma consulta para retornar os IDs das páginas do Facebook que não possuem curtidas. 
A saída deve ser classificada em ordem crescente com base nos IDs das páginas.
*/
SELECt P.page_id
FROM pages P LEFT JOIN page_likes L
ON P.page_id = L.page_id
WHERE L.liked_date IS NULL
ORDER BY 1;