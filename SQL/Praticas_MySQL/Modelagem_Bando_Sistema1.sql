/*PRIMEIRA FORMA NORMAL

  1- TODO CAMPO VETORITAL SE TORNA OUTRA TABELA

  2- TODO CAMPO MULTIVALORADO SE TORNA OUTRA TABELA  QUANDO O CAMPO FOR DIVISIVEL

  3- TODO TABELA NECESSITA DE PELO MENOS UM CAMPO QUE IDENTIFIQUE TODO O REGISTRO COMO SENDO UNICO.
  
*/

CREATE DATABASE Comercio;
USE Comercio;
SHOW DATABASE;

CREATE TABLE Clientes(
  id_cliente INT PRIMARY KEY AUTO_INCREMENT,
  nome_cliente VARCHAR(30) NOT NULL,
  sexo_cliente ENUM('F','M') NOT NULL,
  email_cliente VARCHAR(30) UNIQUE,
  cpf_cliente VARCHAR(11) UNIQUE
  );
SHOW TABLES;
DESC Clientes;

/*EM REALCIONAMENTO 1 X 1 A CHAVES ESTRANGEIRA FICA NA TABELA MAIS FRACA' */
/*EM REALCIONAMENTO 1 X N A CHAVES ESTRANGEIRA FICA CADINALIDADE N' */

CREATE TABLE Endereco(
  id_endereco INT PRIMARY KEY AUTO_INCREMENT,
  rua_endereco VARCHAR(30) NOT NULL,
  bairro_endereco VARCHAR(30) NOT NULL,
  cidade_endereco VARCHAR(30) NOT NULL,
  estado_endereco CHAR(2) NOT NULL,
  id__cliente INT UNIQUE,
  FOREIGN KEY (id__cliente) 
  REFERENCES Clientes (id_cliente)
);
SHOW TABLES;
DESC Endereco;

CREATE TABLE Telefone(
  id_telefone INT PRIMARY KEY AUTO_INCREMENT,
  tipo_telefone ENUM('RES','COM','CEL') NOT NULL,
  numero_telefone VARCHAR(10) NOT NULL,
  id__cliente INT,
  FOREIGN KEY (id__cliente) 
  REFERENCES Clientes (id_cliente)  
);
SHOW TABLES;
DESC Telefone;

DESC Clientes;
INSERT INTO Clientes VALUES(NULL, 'JOAO','M','joao@gmail.com','11111111111');
INSERT INTO Clientes VALUES(NULL, 'Ana','F','ana@gmail.com','22222222222');
INSERT INTO Clientes VALUES(NULL, 'Julia','F', NULL,'33333333333');
INSERT INTO Clientes VALUES(NULL, 'Gabriel','M','gabriel@gmail.com','44444444444');
INSERT INTO Clientes VALUES(NULL, 'Nicolie','F','nino@hotmail.com','55555555555');
INSERT INTO Clientes VALUES(NULL, 'Marrio','M', NULL,'66666666666');
SELECT * FROM Clientes;

DESC Endereco;
INSERT INTO Endereco VALUES(NULL, 'Rua Mimhapika', 'Centro', 'Pato Branco','PR', 3);
INSERT INTO Endereco VALUES(NULL, 'Rua Caue Moura', 'Centro', 'Jundiai','SP', 2);
INSERT INTO Endereco VALUES(NULL, 'Rua Lanadel Rei', 'Fundos', 'Itapema','SC', 1);
INSERT INTO Endereco VALUES(NULL, 'Rua PC Siqueira', 'Interior', 'Jundiai','SP', 4);
INSERT INTO Endereco VALUES(NULL, 'Rua Padre Quevedo', 'Centro', 'Itapema','SC', 5);
SELECT * FROM Endereco;

DESC Telefone;         
INSERT INTO Telefone VALUES(NULL, 'CEL', '4611112222', 5);
INSERT INTO Telefone VALUES(NULL, 'RES', '4622223333', 5);
INSERT INTO Telefone VALUES(NULL, 'CEL', '4233334444', 1);
INSERT INTO Telefone VALUES(NULL, 'COM', '4411115555', 3);
INSERT INTO Telefone VALUES(NULL, 'CEL', '4511119999', 4);
INSERT INTO Telefone VALUES(NULL, 'COM', '4388884444', 6);
SELECT * FROM Telefone;

/* PROJEÇÃO -> é tudo que voce quer ver na tela */
SELECT NOW() AS Data_Atual;
SELECT 2+2 AS Soma;
SELECT 2+2 AS Soma, nome_funcionario, NOW() FROM funcionarios;

/* SELEÇÃO ->  Ssunconjunto de um conjunto total da tabela*/
SELECT id_funcionario, nome_funcionario, sexo_funcionario /*projeção*/ 
FROM funcionarios /*origem*/
WHERE sexo_funcionario='Feminino'; /*seleção*/

/*JUNÇÃO -> JOIN*/
SELECT * FROM Cliente;
SELECT * FROM Endereco;

SELECT nome_cliente, sexo_cliente, bairro_endereco,cidade_endereco
FROM Clientes, Endereco
WHERE Clientes.id_cliente=Endereco.id_cliente;

SELECT nome_cliente, sexo_cliente, bairro_endereco,cidade_endereco
FROM Clientes, Endereco
WHERE Clientes.id_cliente=Endereco.id_cliente
AND sexo_cliente='F';
/*maneira correta*/
SELECT nome_cliente, sexo_cliente, bairro_endereco,cidade_endereco
FROM Clientes 
INNER JOIN Endereco
ON id_cliente=id__cliente;

SELECT nome_cliente, sexo_cliente, bairro_endereco, cidade_endereco /*projeção*/
FROM Clientes /*origem*/
    INNER JOIN Endereco/*junção*/
    ON Clientes.id_cliente=Endereco.id_cliente
WHERE sexo_cliente='F';/*seleção*/

SELECT nome_cliente, sexo_cliente, email_cliente, tipo_telefone, numero_telefone
FROM Clientes 
    INNER JOIN Telefone
    ON Clientes.id_cliente=Telefone.id_cliente;

/*desadio-> nome, sexo, bairro, cidade, tipo numerio*/
SELECT nome_cliente, sexo_cliente, bairro_endereco, cidade_endereco , tipo_telefone, numero_telefone
FROM Clientes  
    INNER JOIN Endereco
    ON Clientes.id_cliente=Endereco.id_cliente
    INNER JOIN Telefone
    ON Clientes.id_cliente=Telefone.id_cliente;

/*Maneira mais adequada*/
SELECT Clientes.nome_cliente, Clientes.sexo_cliente, Endereco.bairro_endereco, Endereco.cidade_endereco , Telefone.tipo_telefone, Telefone.numero_telefone
FROM Clientes  
    INNER JOIN Endereco
    ON Clientes.id_cliente=Endereco.id_cliente
    INNER JOIN Telefone
    ON Clientes.id_cliente=Telefone.id_cliente;

/*COMANDOS DML->*/
USE Comercio;
INSERT INTO Clientes VALUES(NULL, 'Marcos','M', NULL,'999999999999');
INSERT INTO Endereco VALUES(NULL, 'Rua Marquinos Padre', 'Alvorecer', 'Niteroi', 'RJ', 9);

/*maneira adequada de fazer update*/
SELECT * FROM Clientes 
WHERE id_cliente=4;

UPDATE Clientes
SET nome_cliente='Gabriel Maurina', sexo_cliente='F'
WHERE id_cliente=4;

/*maneira adequada de deletar*/
SELECT * FROM Clientes 
WHERE id_cliente=1;

DELETE FROM Telefone
WHERE id_cliente=1;

DELETE FROM Endereco
WHERE id_cliente=1;

DELETE FROM Clientes
WHERE id_cliente=1;

/*COMANDOS DDL -> DATA DIFINITION LINGUAGE*/
USE PROJETO;

/*criar tabelas*/
CREATE TABLE Produto(
  id_produto INTEGER PRIMARY KEY AUTO_INCREMENT,
  nome_produto VARCHAR(30) NOT NULL,
  preco_produto INT 
);

/*alterando nome de uma cluna - CHANGE*/
alter TABLE Produto /**/
CHANGE preco_produto valor_unitario_produto INT NOT NULL;/**/

/*alterando nome de uma cluna - MODIFY*/
alter TABLE Produto
MODIFY valor_unitario_produto INT NOT NULL; /*ALTERA SÓ OS ATRIBUTOS*/

/*ADD -> ACINIONANDO COLUNA*/
alter TABLE Produto
ADD peso_produto FLOAT(10,2) NOT NULL; 

/*DROP -> APAGAR ALGO*/
ALTER TABLE Produto
DROP COLUMN peso_produto;

/*ACIONAR COLUNA EM LUGAR ESPECIFICO*/
ALTER TABLE Produto
ADD COLUMN peso_produto FLOAT(10,2)
AFTER nome_produto;

