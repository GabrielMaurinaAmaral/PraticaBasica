/*MODELAGEM BASICA*/

/*CLIENTE

NOME - CARATER(30)
CPF - NUMERICO(11)
EMAIL - CARATER(30)
TELEFONE - CARATER(30)
ENDERECO - CARATER(100)
SEXO - CARATER(1)*/

/* MODELAGEM CONCEITUAL -> RASCUNHO 
   MODELAGEM LÓGICA -> QUALQUER 
   MODELAGEM FÍSICA -> SCRIPT DE BANCO */

/* CRIANDO BANCOS DE DADOS */
CREATE DATABASE PROJETO;

USE PROJETO;
SHOW TABLES;

/* CLIENTE */
CREATE TABLE CLIENTE (
  NOME VARCHAR(30),
  SEXO CHAR(1),
  EMAIL VARCHAR(30),
  CPF BIGINT(11),
  TELEFONE VARCHAR(30),
  ENDERECO VARCHAR(100)
);

/* VERIFICANDO AS TABELAS DO BANCO */
/* mostrar */
SHOW TABLES;

/* exibindo a estrutura de uma tabela */
DESC CLIENTE;

/* Inserindo mais registros na tabela CLIENTE */
INSERT INTO CLIENTE VALUES('Maria', 'F', 'maria@email.com', 987654321, '987654321', 'Avenida Principal - São Paulo, SP');
INSERT INTO CLIENTE VALUES('Carlos', 'M', 'carlos@email.com', 876543210, '876543210', 'Rua Secundária - Belo Horizonte, MG');
INSERT INTO CLIENTE VALUES('Ana', 'F', 'ana@email.com', 765432109, '765432109', 'Travessa da Esquina - Curitiba, PR');
INSERT INTO CLIENTE VALUES('Ricardo', 'M', 'ricardo@email.com', 654321098, '654321098', 'Rua da Colina - Porto Alegre, RS');
INSERT INTO CLIENTE VALUES('Fernanda', 'F', 'fernanda@email.com', 543210987, '543210987', 'Avenida das Flores - Florianópolis, SC');
INSERT INTO CLIENTE VALUES('Lucas', 'M', 'lucas@email.com', 432109876, '432109876', 'Praça Central - Salvador, BA');

/*SELECT*/

SELECT NOW();
SELECT 'Maria';
SELECT 'BANCO DE DADOS';
SELECT NOME, SEXO, EMAIL FROM CLIENTE;
SELECT NOME, SEXO, EMAIL, ENDERECO FROM CLIENTE;

/*FILTROS*/
SELECT NOME, SEXO FROM CLIENTE WHERE SEX0 ='M';
SELECT NOME, SEXO FROM CLIENTE WHERE SEX0 ='F';
SELECT NOME, SEXO FROM CLIENTE WHERE ENDERECO LIKE '%PR';
SELECT NOME, SEXO, ENDERECO FROM CLIENTE WHERE ENDERECO LIKE 'Rua%';

USE PROJETO;

CREATE TABLE funcionarios
  (
      id_funcionario integer,
      nome_funcionario varchar(100),
      email_funcionario varchar(200),
      sexo_funcionario varchar(10),
      departamento_funcionario varchar(100),
      admissao_fuuncionario varchar(10),
      salario_funcionario integer,
      cargo_funcionario varchar(100),
      id_regiao_funcionario int,
      primary key (id_funcionario)
  );

/*COUT*/
SELECT COUNT(*) AS 'quantidade de registros' FROM funcionarios;

/*OR AND*/
select departamento_funcionario, COUNT(*)  from funcionarios group by departamento_funcionario order by 1;
/*roupas=53 filmes=36*/
select nome_funcionario_ from funcionarios where departamento_funcionario='Roupas' or departamento_funcionario='Filmes';
select departamento_funcionario, COUNT(*)  from funcionarios group by departamento_funcionario order by 1;
/*lar=52 filmes=36*/
select nome_funcionario_, email_funcionario from funcionarios where departamento_funcionario='Filmes' or departamento_funcionario='Lar';
select departamento_funcionario, COUNT(*)  from funcionarios group by departamento_funcionario order by 1;
select sexo_funcionario, COUNT(*)  from funcionarios group by sexo_funcionario order by 1;
/*jardim=47 masculino=504*/
select nome_funcionario_, email_funcionario, sexo_funcionario, departamento_funcionario from funcionarios where sexo_funcionario='Masculino' or departamento_funcionario='Jardim';

/*UPDATE*/
select * from funcionarios where nome_funcionario_ like 'Ryan';
UPDATE funcionarios SET email_funcionario='ryan@gmail.com' WHERE nome_funcionario_ LIKE 'Ryan';
select nome_funcionario_, email_funcionario from funcionarios;

/*DELETE*/
DELETE FROM funcionarios WHERE nome_funcionario_ LIKE 'Ryan'; 

/*ALIAS*/

/*DISTINCT - remova as duplicidades*/
SELECT * FROM funcionarios;
SELECT DISTINCT id_funcionario, nome_funcionario FROM funcionarios; 

/*SUBSELECT - remova as duplicidades*/

/*função*/
IFNULL()

SELECT C.nome_cliente, IFNULL(C.email_cliente, 'não tem email') AS email, E.estado_endereco, T.numero_telefone 
FROM Clientes C
    INNER JOIN Endereco E
    ON C.id_cliente=E.id_cliente
    INNER JOIN Telefone T
    ON C.id_cliente=T.id_cliente;

/*VIEW*/
CREATE VIEW nome_e_sexo AS SELECT nome_funcionario, sexo_funcionario FROM funcionarios;
SELECT * FROM nome_e_sexo;
SELECT nome_funcionario FROM nome_e_sexo;

CREATE VIEW v_relatorio AS SELECT C.nome_cliente, C.sexo_cliente, C.email_cliente, 
E.bairro_endereco, E.cidade_endereco, E.estado_endereco,
T.tipo_telefone, T.numero_telefone
FROM Clientes C
    INNER JOIN Endereco E
    ON C.id_cliente=E.id_cliente
    INNER JOIN Telefone T
    ON C.id_cliente=T.id_cliente;

/* Operações de DML em Views */
UPDATE 

CREATE TABLE Jogadores(
	id_jogador INT,
	nome_jogador VARCHAR(30),
	estado_jogador CHAR(2)
);

INSERT INTO Jogadores VALUES(1,'GUERRERO','RS');
INSERT INTO Jogadores VALUES(2,'GABIGOL','RJ');
INSERT INTO Jogadores VALUES(3,'GANSO','RJ');
INSERT INTO Jogadores VALUES(4,'NENÊ', 'RJ');
INSERT INTO Jogadores VALUES(5,'LOVE','SP');

CREATE VIEW v_jogadores AS
SELECT nome_jogador, estado_jogador
FROM Jogadores;

SELECT * FROM v_jogadores;

DELETE FROM v_jogadores
WHERE nome_jogador = 'GUERRERO';

INSERT INTO v_jogadores VALUES('GUERRERO','RS');

SELECT * FROM Jogadores;

SELECT * FROM v_jogadores
WHERE estado_jogador='RJ';

/* ORDEM BY */
CREATE TABLE Alunos(
	nummero_aluno INT,
	nome_aluno VARCHAR(30)
);

INSERT INTO Alunos VALUES(1,'JOAO');
INSERT INTO Alunos VALUES(1,'MARIA');
INSERT INTO Alunos VALUES(2,'ZOE');
INSERT INTO Alunos VALUES(2,'ANDRE');
INSERT INTO Alunos VALUES(3,'CLARA');
INSERT INTO Alunos VALUES(1,'CLARA');
INSERT INTO Alunos VALUES(4,'MAFRA');
INSERT INTO Alunos VALUES(5,'JANAINA');
INSERT INTO Alunos VALUES(1,'JANAINA');
INSERT INTO Alunos VALUES(3,'MARCELO');
INSERT INTO Alunos VALUES(4,'GIOVANI');
INSERT INTO Alunos VALUES(5,'ANTONIO');
INSERT INTO Alunos VALUES(6,'ANA');
INSERT INTO Alunos VALUES(6,'VIVIANE'); 
/*ordena pelo nome da coluna*/
SELECT * FROM Alunos
ORDER BY nummero_aluno;
/*ordena pelo id da coluna*/
SELECT * FROM Alunos
ORDER BY 2;
/*ordena pelo numero e nome*/
SELECT * FROM Alunos
ORDER BY 1, 2;
/*ASC -> ordena crescente*/
SELECT * FROM Alunos
ORDER BY 1 ASC;
/*DESC -> ordena decrecente*/
SELECT * FROM Alunos
ORDER BY 1 DESC;

/**/
SELECT  C.NOME, 
		C.SEXO, 
		IFNULL(C.EMAIL,'CLIENTE SEM EMAIL') AS "E-MAIL", 
		T.TIPO, 
		T.NUMERO, 
		E.BAIRRO, 
		E.CIDADE, 
		E.ESTADO
FROM CLIENTE C 
INNER JOIN TELEFONE T 
ON C.IDCLIENTE = T.ID_CLIENTE 
INNER JOIN ENDERECO E 
ON C.IDCLIENTE = E.ID_CLIENTE
ORDER BY 1;

/**/
SELECT SUM(CITY.POPULATION) AS 'POPULAÇÃO NA ASIA'
FROM CITY JOIN COUNTRY
ON CITY.COUNTRYCODE = COUNTRY.CODE
WHERE COUNTRY.CONTINENT = 'Asia';

/**/
SELECT CITY.NAME AS 'Nome das Cidades na Africa'
FROM CITY JOIN COUNTRY
ON CITY.COUNTRYCODE = COUNTRY.CODE
WHERE COUNTRY.CONTINENT = 'Africa';

/* Dadas as tabelas CITY e COUNTRY, consulte os nomes 
  de todos os continentes (COUNTRY.Continent) e suas 
  respectivas populações médias de cidades (CITY.Population) 
  arredondados para o número inteiro mais próximo */
SELECT COUNTRY.CONTINENT AS 'CONTINENTES',
      FLOOR(AVG(CITY.POPULATION)) AS 'MEDIA' 
FROM COUNTRY JOIN CITY    
    ON CITY.COUNTRYCODE = COUNTRY.CODE
GROUP BY COUNTRY.CONTINENT;

/* Ketty dá a Eve a tarefa de gerar um relatório contendo 
  três colunas: Nome, Nota e Nota. Ketty não quer os NOMES 
  dos alunos que receberam nota inferior a 8. O relatório 
  deve estar em ordem decrescente por nota - ou seja, as 
  notas mais altas são inseridas primeiro. Se houver mais
  de um aluno com a mesma nota (8-10) atribuída a eles, 
  ordene esses alunos em particular pelo nome em ordem 
  alfabética. Por fim, se a nota for inferior a 8, use 
  “NULL” como nome e liste-os por notas em ordem decrescente. 
  Se houver mais de um aluno com a mesma nota (1-7) atribuída 
  a eles, ordene esses alunos pelas notas em ordem crescente. 
  Escreva uma consulta para ajudar Eva.
​*/