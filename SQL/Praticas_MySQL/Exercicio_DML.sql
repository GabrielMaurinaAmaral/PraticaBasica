/* EXERCICIOS DML */

USE Clientes;
SHOW TABLES;

INSERT INTO Clientes VALUES(NULL,'JOAO','M','JOAOA@IG.COM','76567587887');
INSERT INTO Clientes VALUES(NULL,'CARLOS','M','CARLOSA@IG.COM','5464553466');
INSERT INTO Clientes VALUES(NULL,'ANA','F','ANA@IG.COM','456545678');
INSERT INTO Clientes VALUES(NULL,'CLARA','F',NULL,'5687766856');
INSERT INTO Clientes VALUES(NULL,'JORGE','M','JORGE@IG.COM','8756547688');
INSERT INTO Clientes VALUES(NULL,'CELIA','M','JCELIA@IG.COM','5767876889');
INSERT INTO Clientes VALUES(NULL,'FLAVIO','M','FLAVIO@IG.COM','4657765');
INSERT INTO Clientes VALUES(NULL,'ANDRE','M','ANDRE@GLOBO.COM','7687567');
INSERT INTO Clientes VALUES(NULL,'GIOVANA','F',NULL,'0876655');
INSERT INTO Clientes VALUES(NULL,'KARLA','M','KARLA@GMAIL.COM','545676778');
INSERT INTO Clientes VALUES(NULL,'DANIELE','M','DANIELE@GMAIL.COM','43536789');
INSERT INTO Clientes VALUES(NULL,'LORENA','M',NULL,'774557887');
INSERT INTO Clientes VALUES(NULL,'EDUARDO','M',NULL,'54376457');
INSERT INTO Clientes VALUES(NULL,'ANTONIO','F','ANTONIO@IG.COM','12436767');
INSERT INTO Clientes VALUES(NULL,'ANTONIO','M','ANTONIO@UOL.COM','3423565');
INSERT INTO Clientes VALUES(NULL,'ELAINE','M','ELAINE@GLOBO.COM','32567763');
INSERT INTO Clientes VALUES(NULL,'CARMEM','M','CARMEM@IG.COM','787832213');
INSERT INTO Clientes VALUES(NULL,'ADRIANA','F','ADRIANA@GMAIL.COM','88556942');
INSERT INTO Clientes VALUES(NULL,'JOICE','F','JOICE@GMAIL.COM','55412256');

/* CADASTRE UM Endereco PARA CADA Clientes */

INSERT INTO Endereco VALUES(NULL,'RUA GUEDES','CASCADURA','B. HORIZONTE','MG',9);
INSERT INTO Endereco VALUES(NULL,'RUA MAIA LACERDA','ESTACIO','RIO DE JANEIRO','RJ',10);
INSERT INTO Endereco VALUES(NULL,'RUA VISCONDESSA','CENTRO','RIO DE JANEIRO','RJ',11);
INSERT INTO Endereco VALUES(NULL,'RUA NELSON MANDELA','COPACABANA','RIO DE JANEIRO','RJ',12);
INSERT INTO Endereco VALUES(NULL,'RUA ARAUJO LIMA','CENTRO','VITORIA','ES',13);
INSERT INTO Endereco VALUES(NULL,'RUA CASTRO ALVES','LEBLON','RIO DE JANEIRO','RJ',14);
INSERT INTO Endereco VALUES(NULL,'AV CAPITAO ANTUNES','CENTRO','CURITIBA','PR',15);
INSERT INTO Endereco VALUES(NULL,'AV CARLOS BARROSO','JARDINS','SAO PAULO','SP',16);
INSERT INTO Endereco VALUES(NULL,'ALAMEDA SAMPAIO','BOM RETIRO','CURITIBA','PR',17);
INSERT INTO Endereco VALUES(NULL,'RUA DA LAPA','LAPA','SAO PAULO','SP',18);
INSERT INTO Endereco VALUES(NULL,'RUA GERONIMO','CENTRO','RIO DE JANEIRO','RJ',19);
INSERT INTO Endereco VALUES(NULL,'RUA GOMES FREIRE','CENTRO','RIO DE JANEIRO','RJ',20);
INSERT INTO Endereco VALUES(NULL,'RUA GOMES FREIRE','CENTRO','RIO DE JANEIRO','RJ',21);

/* CADASTRE TELEFONES PARA OS CLIENTES */


INSERT INTO Telefone VALUES(NULL,'RES','68976565',9);
INSERT INTO Telefone VALUES(NULL,'CEL','99656675',9);
INSERT INTO Telefone VALUES(NULL,'CEL','33567765',11);
INSERT INTO Telefone VALUES(NULL,'CEL','88668786',11);
INSERT INTO Telefone VALUES(NULL,'COM','55689654',11);
INSERT INTO Telefone VALUES(NULL,'COM','88687979',12);
INSERT INTO Telefone VALUES(NULL,'COM','88965676',13);
INSERT INTO Telefone VALUES(NULL,'CEL','89966809',15);
INSERT INTO Telefone VALUES(NULL,'COM','88679978',16);
INSERT INTO Telefone VALUES(NULL,'CEL','99655768',17);
INSERT INTO Telefone VALUES(NULL,'RES','89955665',18);
INSERT INTO Telefone VALUES(NULL,'RES','77455786',19);
INSERT INTO Telefone VALUES(NULL,'COM','89766554',19);
INSERT INTO Telefone VALUES(NULL,'RES','77755785',20);
INSERT INTO Telefone VALUES(NULL,'COM','44522578',20);

DES Clientes;
DES Endereco;
DES Telefone;

/* RELATORIO GERAL DE TODOS OS CLIENTES */
SELECT * FROM Clientes;

/* RELATORIO GERAL DE TODOS OS CLIENTES (Telefone E Endereco) */
SELECT C.id_cliente, C.nome_cliente, C.sexo_cliente, C.email_cliente, C.cpf_cliente, 
E.rua_endereco, E.bairro_endereco, E.cidade_endereco, E.estado_endereco,
T.tipo_telefone, T.numero_telefone
FROM Clientes C
    INNER JOIN Endereco E
    ON C.id_cliente=E.id_cliente
    INNER JOIN Telefone T
    ON C.id_cliente=T.id_cliente;

/* RELAÇÃO DE HOMENS */
SELECT C.id_cliente, C.nome_cliente, C.email_cliente, C.cpf_cliente, 
E.rua_endereco, E.bairro_endereco, E.cidade_endereco, E.estado_endereco,
T.tipo_telefone, T.numero_telefone
FROM Clientes C
    INNER JOIN Endereco E
    ON C.id_cliente=E.id_cliente
    INNER JOIN Telefone T
    ON C.id_cliente=T.id_cliente
WHERE sexo_cliente='M';

/*TORNA 12, 13, 18, 19 MULHERES*/
UPDATE Clientes SET sexo_cliente='F'
WHERE id_cliente IN (12, 13, 18, 19);

/* RELAÇÃO DE MULHERES */
SELECT C.id_cliente, C.nome_cliente, C.email_cliente, C.cpf_cliente, 
E.rua_endereco, E.bairro_endereco, E.cidade_endereco, E.estado_endereco,
T.tipo_telefone, T.numero_telefone
FROM Clientes C
    INNER JOIN Endereco E
    ON C.id_cliente=E.id_cliente
    INNER JOIN Telefone T
    ON C.id_cliente=T.id_cliente
WHERE sexo_cliente='F';

/* QUANTIDADE DE HOMENS E MULHERES */
SELECT sexo_cliente, COUNT(*) 'Quantidade'
FROM Clientes 
GROUP BY sexo_cliente;

/* IDS E EMAIL DAS MULHERES QUE MOREN NO CENTRO 
   DO RIO DE JANEIRO E NÃO TENHAM CELULAR */
SELECT C.id_cliente, C.email_cliente, C.sexo_cliente, 
       E.bairro_endereco, E.cidade_endereco,
       T.tipo_telefone, T.numero_telefone
FROM Clientes C
INNER JOIN Endereco E ON C.id_cliente = E.id_cliente
LEFT JOIN Telefone T ON C.id_cliente = T.id_cliente
WHERE C.sexo_cliente = 'F'
  AND E.bairro_endereco = 'CENTRO'
  AND E.cidade_endereco = 'RIO DE JANEIRO'
  AND (T.tipo_telefone IS NULL OR T.tipo_telefone != 'CEL');

/* PARA UMA CAMPANHA DE MARKETING, O SETOR SOLICITOU UM
RELATÓRIO COM O NOME, EMAIL E TELEFONE CELULAR 
DOS CLIENTES QUE MORAM NO ESTADO DO RIO DE JANEIRO 
VOCÊ TERÁ QUE PASSAR A QUERY PARA GERAR O RELATORIO PARA
O PROGRAMADOR */
SELECT C.nome_cliente, C.email_cliente, T.numero_telefone /*PROJEÇÃO*/
FROM Clientes C /*ORIGEM*/
    INNER JOIN Endereco E /*JUNÇÃO*/
    ON C.id_cliente = E.id_cliente /*CONDIÇÃO DA JUNÇÃO*/
    INNER JOIN Telefone T /*JUNÇÃO*/
    ON C.id_cliente = T.id_cliente /*CONDIÇÃO DA JUNÇÃO*/
WHERE E.estado_endereco = 'RJ' AND T.tipo_telefone='CEL'; /*SELEÇÃO*/

/* PARA UMA CAMPANHA DE PRODUTOS DE BELEZA, O COMERCIAL SOLICITOU UM
RELATÓRIO COM O NOME, EMAIL E TELEFONE CELULAR 
DAS MULHERES QUE MORAM NO ESTADO DE SÃO PAULO 
VOCÊ TERÁ QUE PASSAR A QUERY PARA GERAR O RELATORIO PARA
O PROGRAMADOR */

SELECT C.nome_cliente, C.email_cliente, T.numero_telefone /*PROJEÇÃO*/
FROM Clientes C /*ORIGEM*/
    INNER JOIN Endereco E /*JUNÇÃO*/
    ON C.id_cliente = E.id_cliente /*CONDIÇÃO DA JUNÇÃO*/
    INNER JOIN Telefone T /*JUNÇÃO*/
    ON C.id_cliente = T.id_cliente /*CONDIÇÃO DA JUNÇÃO*/
WHERE E.estado_endereco = 'SP' AND C.sexo_cliente='F'; /*SELEÇÃO*/

