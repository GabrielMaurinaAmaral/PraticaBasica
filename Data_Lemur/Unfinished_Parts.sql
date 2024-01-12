/*
 A Tesla está investigando gargalos de produção e precisa da 
 sua ajuda para extrair os dados relevantes. Escreva uma consulta
 para determinar quais peças iniciaram o processo de montagem, 
 mas ainda não terminaram.

Premissas:

A tabela parts_assembly contém todas as peças atualmente em 
produção, cada uma em diferentes estágios do processo de montagem.
Uma parte inacabada é aquela que não possui data de término.
*/

SELECT part, assembly_step
FROM parts_assembly
WHERE finish_date IS NULL;