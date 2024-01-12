/*
 Escreva uma consulta que calcule a visualização total de laptops
 e dispositivos móveis, em que dispositivos móveis são definidos 
 como a soma das visualizações de tablets e telefones. Produza a 
 visualização total para laptops como laptop_reviews e a 
 visualização total para dispositivos móveis como mobile_views.
*/

SELECT
    SUM(CASE WHEN device_type = 'tablet' 
        THEN 1 
        ELSE 0 
        END) AS tablet_views,
    SUM(CASE WHEN device_type IN ('laptop', 'phone') 
        THEN 1 
        ELSE 0 
        END) AS mobile_views
FROM viewership;
