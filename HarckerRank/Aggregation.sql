/**/
SELECT SUM(POPULATION) 
FROM CITY
WHERE DISTRICT = 'California';

/* Consulte a população média de todas as cidades em CITY
onde o distrito é a Califórnia. */
SELECT AVG(POPULATION)
FROM CITY
WHERE DISTRICT='California';

/* Consulte a população média de todas as cidades de CITY, 
arredondada para o número inteiro mais próximo. */
SELECT FLOOR(AVG(POPULATION))
FROM CITY
WHERE DISTRICT='California';

/* Consulte a soma das populações de todas as cidades 
japonesas em CITY. O COUNTRYCODE do Japão é JPN. */
SELECT SUM(POPULATION) 
FROM CITY
WHERE COUNTRYCODE = 'JPN';

/* Consulte a diferença entre as populações máxima
e mínima em CITY. */
SELECT MAX(POPULATION) - MIN(POPULATION)
FROM CITY;

/* Consulte uma contagem do número de 
cidades em CITY com uma população maior que */
SELECT COUNT(*)
FROM CITY
WHERE POPULATION>100000;

/* Consulte os dois valores a seguir na tabela STATION:
A soma de todos os valores em LAT_N arredondados para 
uma escala de casas decimais. A soma de todos os valores
em LONG_W arredondados para uma escala de casas decimais. */
SELECT ROUND(SUM(LAT_N), 2), ROUND(SUM(LONG_W), 2)
FROM STATION;

/* Consulte a soma das Latitudes Norte (LAT_N) de STATION
 com valores maiores e menores que . Trunque sua resposta 
 para casas decimais. */
SELECT ROUND(SUM(LAT_N), 4) 
FROM STATION 
WHERE LAT_N > 38.7880 AND LAT_N < 137.2345;

/*Consulte o maior valor das Latitudes Norte (LAT_N) de 
STATION que seja menor que . Trunque sua resposta para 
casas decimais. */
SELECT ROUND(MAX(LAT_N), 4)
FROM STATION
WHERE LAT_N < 137.2345;


/*Definimos os rendimentos totais de um funcionário como o
  salário mensal*mês trabalhado e os rendimentos totais máximos
  como os rendimentos totais máximos de qualquer funcionário 
  na tabela Funcionário. Escreva uma consulta para encontrar 
  os rendimentos totais máximos de todos os funcionários, bem 
  como o número total de funcionários que têm rendimentos 
  totais máximos.*/
SELECT MAX(SALARY * MONTHS), COUNT(*)
FROM EMPLOYEE
WHERE SALARY * MONTHS = (SELECT MAX(SALARY * MONTHS) FROM EMPLOYEE);

/*Consulte os dois valores a seguir na tabela STATION: A soma 
  de todos os valores em LAT_N arredondados para uma escala de 
  casas decimais. A soma de todos os valores em LONG_W 
  arredondados para uma escala de casas decimais.
*/

SELECT ROUND(SUM(LAT_N), 2), ROUND(SUM(LONG_W), 2)
FROM STATION;