/*
Ketty dá a Eve a tarefa de gerar um relatório contendo três colunas: 
Nome, Nota e Nota. Ketty não quer os NOMES dos alunos que receberam 
nota inferior a 8. O relatório deve estar em ordem decrescente por 
nota - ou seja, as notas mais altas são inseridas primeiro. Se houver 
mais de um aluno com a mesma nota (8-10) atribuída a eles, ordene 
esses alunos em particular pelo nome em ordem alfabética. Por fim,
se a nota for inferior a 8, use “NULL” como nome e liste-os por notas
em ordem decrescente. Se houver mais de um aluno com a mesma nota 
(1-7) atribuída a eles, ordene esses alunos em particular pelas 
notas em ordem crescente
*/
SELECT 
    CASE
        WHEN G.Grade >= 8 THEN S.Name
        ELSE NULL
    END AS StudentName,
    G.Grade, 
    S.Marks
FROM Students S INNER JOIN Grades G 
ON G.Min_Mark <= S.Marks AND S.Marks <= G.Max_Mark
ORDER BY 
    G.Grade DESC,
    CASE
        WHEN G.Grade >= 8 THEN S.Name
    END ASC,
    S.Marks ASC;

/**/
