/* 
ORGANIZAR FISICAMENTE E LOGICAMENTE UM BANCO DE DADOS 
1- CRIAR O BANCO COM ARQUIVOS PARA OS SETORES DE MKT E RH
2- CRIAR UM ARQUIVO GERAL
3- DEIXAR O MDF APENAS COM O DICIONARIO DE DADOS
4- CRIAR 2 GRUPOS DE ARQUIVOS (PRIMARY - MDF)
*/
USE EMPRESA 
GO

CREATE TABLE ALUNO(
    IDALUNO INT PRIMARY KEY IDENTITY,
	NOME VARCHAR(30) NOT NULL,
	SEXO CHAR(1) NOT NULL,
	NASCIMENTO DATE NOT NULL,
	EMAIL VARCHAR(30) UNIQUE
)
GO
/*CONSTRAINTS*/
ALTER TABLE ALUNO
ADD CONSTRAINT CK_SEXO CHECK(SEXO IN('M', 'F'))
GO
/*1X1*/
CREATE TABLE ENDERECO(
   ID_ENDERECO INT PRIMARY KEY IDENTITY(100,10),
   BAIRRO VARCHAR(30),
   UF CHAR(2)NOT NULL,
   CHECK(UF IN('RJ', 'SP','MG')),
   ID__ALUNO INT UNIQUE
)
GO

/* CRIANDO FK -> LIGAÇÃO DAS TABELAS*/
ALTER TABLE ENDERECO ADD CONSTRAINT FK_ENDERECO_ALUNO 
FOREIGN KEY(ID__ALUNO) REFERENCES ALUNO(IDALUNO)
GO

-- PROCIDURES - CRIADAS E ARMAZENADAS NO SISTEMA

SP_COLUMNS ALUNO
GO

SP_HELP ALUNO
GO

-- INSERINDO DADOS
INSERT INTO ALUNO VALUES
('ANDRE', 'M', '1981/12/09', 'ANDRE@GMAIL.COM')
INSERT INTO ALUNO VALUES
('MARIA', 'F', '1990/05/15', 'maria@gmail.com')
INSERT INTO ALUNO VALUES
('CARLOS', 'M', '1985/08/25', 'carlos@hotmail.com')
INSERT INTO ALUNO VALUES
('ANA', 'F', '1988/02/18', 'ana@yahoo.com')
INSERT INTO ALUNO VALUES
('FABIO', 'M', '1995/10/30', 'fabio@gmail.com')
INSERT INTO ALUNO VALUES
('LUCIA', 'F', '1982/06/14', 'lucia@hotmail.com')
INSERT INTO ALUNO VALUES
('RICARDO', 'M', '1998/03/22', 'ricardo@yahoo.com')
INSERT INTO ALUNO VALUES
('CLAUDIA', 'F', '1989/07/07', 'claudia@gmail.com')
INSERT INTO ALUNO VALUES
('GUSTAVO', 'M', '1993/11/18', 'gustavo@hotmail.com')
GO

SELECT * FROM ALUNO
GO

INSERT INTO ENDERECO VALUES('FLRAMENGO', 'RJ', 1)
INSERT INTO ENDERECO VALUES('MORUMBI', 'SP', 2)
INSERT INTO ENDERECO VALUES('TIJUCA', 'RJ', 8)
INSERT INTO ENDERECO VALUES('IPANEMA', 'RJ', 9)
INSERT INTO ENDERECO VALUES('PINHEIROS', 'SP', 5)
INSERT INTO ENDERECO VALUES('VILA OLIMPIA', 'SP', 6)
INSERT INTO ENDERECO VALUES('SAVASSI', 'MG', 7)
GO

SELECT * FROM ENDERECO
GO

--CRIENDO A TABELA TELEFONES 1xN
CREATE TABLE TELEFONE(
      IDTELEFONE INT PRIMARY KEY IDENTITY,
	  TIPO CHAR(3) NOT NULL,
	  NUMERO VARCHAR(10) NOT NULL,
	  ID_ALUNO INT,
	  CHECK (TIPO IN ('RES', 'COM', 'CEL'))
)
GO

INSERT INTO TELEFONE VALUES('CEL', '99873291', 1)
INSERT INTO TELEFONE VALUES('RES', '22334455', 1)
INSERT INTO TELEFONE VALUES('COM', '31234567', 1)
INSERT INTO TELEFONE VALUES('CEL', '987654321', 5)
INSERT INTO TELEFONE VALUES('RES', '11112222', 3)
INSERT INTO TELEFONE VALUES('CEL', '999888777', 4)
INSERT INTO TELEFONE VALUES('COM', '33334444', 5)
GO

SELECT * FROM TELEFONE
GO

-- pegar data atual
SELECT GETDATE()
GO

--CLAUSULA AMBIGUA
SELECT A.NOME, 
       ISNULL(T.TIPO, 'SEM') AS 'TIPO', 
	   ISNULL(T.NUMERO, 'NUMERO') AS 'TELEFONE',
	   E.BAIRRO, 
	   E.UF
FROM ALUNO A 
     INNER JOIN TELEFONE T
     ON A.IDALUNO=T.ID_ALUNO 
     INNER JOIN ENDERECO E
     ON A.IDALUNO=E.ID__ALUNO
GO

--coversão de dados
SELECT 1 + '1'
GO
SELECT '1' + '1'
GO
SELECT 'CURSO' + '1'
GO
--função conversão de dados
SELECT CAST('1' AS INT) + CAST('1' AS INT)
GO
--CONVERSAO E CONCATENACAO
SELECT NOME, NASCIMENTO
FROM ALUNO
GO

SELECT NOME, 
       CAST(DAY(NASCIMENTO) AS varchar)+'/'+
	   CAST(MONTH(NASCIMENTO)AS varchar)+'/'+
	   CAST(YEAR(NASCIMENTO)AS varchar) AS 'NASCIMENTO'
FROM ALUNO
GO

-- CHARINDEX - RETORNA UM INTEIRO
-- CONTAGEM DEFAULT - INICIA EM 01
SELECT NOME, CHARINDEX('A', NOME) AS INDICE
FROM ALUNO
GO

SELECT NOME, CHARINDEX('A', NOME, 2) AS INDICE
FROM ALUNO
GO

--BULK INSERT - IMPORTACAO DE ARQUIVOS
CREATE TABLE LANCAMENTO_CONTABIL(
       CONTA INT,
	   VALOR INT,
	   DEB_CRED CHAR(1)
)
GO

SELECT * FROM LANCAMENTO_CONTABIL
GO

--IMPORTANDO BANCO DE DAOS DE UM ARQUIVO
BULK INSERT LANCAMENTO_CONTABIL 
FROM 'C:\CODE\PraticaBasica\SQL\Praticas_SQL_Server\CONTAS.txt'
WITH(
    FIRSTROW=2,
	DATAFILETYPE='char',
	FIELDTERMINATOR='\t',
	ROWTERMINATOR ='\n'
)
GO
-- '\t' = TAB, '\n' = ENTER

DELETE FROM LANCAMENTO_CONTABIL
GO
/* DESAFIO DO SALDO
QUERY QUE TRAGA O NUMERO DA CONTA SALDO - DEVEDOR OU CREDOR*/
SELECT CONTA, VALOR,
CHARINDEX('D', DEB_CRED) AS DEBITO,
CHARINDEX('C', DEB_CRED) AS CREDITO,
CHARINDEX('C', DEB_CRED) * 2 - 1 AS MULTIPLICADOR
FROM LANCAMENTO_CONTABIL
GO

SELECT CONTA, 
       SUM(VALOR * (CHARINDEX('C', DEB_CRED) * 2 - 1)) AS SALDO
FROM LANCAMENTO_CONTABIL
GROUP BY CONTA
GO

-- TRIGGERS
CREATE TABLE Produtos(
      id_Produto INT PRIMARY KEY IDENTITY,
	  nome_Produto VARCHAR(50) NOT NULL UNIQUE,
	  categoria_Produto VARCHAR(30) NOT NULL,
	  preco_Produto NUMERIC(10, 2) NOT NULL
)
GO

CREATE TABLE Historicos(
      id_opercao_Historico INT PRIMARY KEY IDENTITY,
	  produto_Historico VARCHAR(50) NOT NULL UNIQUE,
	  categoria_Historico VARCHAR(30) NOT NULL,
	  preco_antigo_Historico NUMERIC(10, 2) NOT NULL,
	  preco_novo_Historico NUMERIC(10, 2) NOT NULL,
	  data_Historico DATETIME,
	  usuario_Historico VARCHAR(30),
	  mensagem_Historico VARCHAR(100)
)
GO

-- Adicionando mais produtos
INSERT INTO Produtos VALUES('Mouse sem Fio', 'ELETRÔNICOS', 39.99);
INSERT INTO Produtos VALUES('Fone de Ouvido Bluetooth', 'ELETRÔNICOS', 89.90);
INSERT INTO Produtos VALUES('Mochila para Notebook', 'ACESSÓRIOS', 120.00);
INSERT INTO Produtos VALUES('Smartphone Android', 'ELETRÔNICOS', 899.99);
INSERT INTO Produtos VALUES('Teclado Mecânico Gamer', 'ELETRÔNICOS', 199.00);
INSERT INTO Produtos VALUES('Cadeira Ergonômica', 'MÓVEIS', 349.90);
INSERT INTO Produtos VALUES('Livros Python', 'LIVROS', 120.00);
INSERT INTO Produtos VALUES('Monitor Ultrawide', 'ELETRÔNICOS', 799.00);
INSERT INTO Produtos VALUES('Impressora Multifuncional', 'ELETRÔNICOS', 299.99);
INSERT INTO Produtos VALUES('Notebook Core i7', 'INFORMÁTICA', 2399.00);
INSERT INTO Produtos VALUES('Ventilador de Teto', 'ELETRODOMÉSTICOS', 149.90);
INSERT INTO Produtos VALUES('Máquina de Café Expresso', 'ELETRODOMÉSTICOS', 399.00);
INSERT INTO Produtos VALUES('Fogão 4 Bocas', 'ELETRODOMÉSTICOS', 499.99);
INSERT INTO Produtos VALUES('Smart TV 55 Polegadas', 'ELETRÔNICOS', 1799.00);
INSERT INTO Produtos VALUES('Cama Box Casal', 'MÓVEIS', 899.90);
INSERT INTO Produtos VALUES('Bicicleta Ergométrica', 'FITNESS', 499.00);
INSERT INTO Produtos VALUES('Máquina de Lavar Roupa', 'ELETRODOMÉSTICOS', 899.99);
INSERT INTO Produtos VALUES('Cadeira de Escritório', 'MÓVEIS', 249.90);
INSERT INTO Produtos VALUES('Console de Videogame', 'ELETRÔNICOS', 399.00);
INSERT INTO Produtos VALUES('Panela de Pressão Elétrica', 'ELETRODOMÉSTICOS', 129.00);
GO

SELECT * FROM Produtos
GO

SELECT * FROM Historicos
GO

-- VERIFICAR USURARIO
SELECT SUSER_NAME()
GO

-- TRIGGER DADOS - DATA MANIPULATION LANGUAGE
CREATE TRIGGER TRG_ATUALIZA_PRECO
ON dbo.Produtos
FOR UPDATE
AS --DECLARAÇÃO DE VARIAVEIS PARA USAR NA TRIGGER
    DECLARE @id_produto INT
	DECLARE @produto VARCHAR(30)
	DECLARE @categoria VARCHAR(10)
	DECLARE @preco NUMERIC(10,2)
	DECLARE @preco_novo NUMERIC(10,2)
	DECLARE @data DATETIME
	DECLARE @usuario VARCHAR(30)
	DECLARE @mensagem VARCHAR(100)
	-- PRIMERIO BLOCO
	SELECT @id_produto = id_Produto FROM inserted
	SELECT @produto = nome_Produto FROM inserted
	SELECT @categoria = categoria_Produto FROM inserted
	SELECT @preco = preco_Produto FROM inserted
	SELECT @preco_novo = preco_Produto FROM inserted
	-- SEGUNDO BLOCO 
	SET @data = GETDATE()
	SET @usuario = SUSER_NAME()
	SET @mensagem = 'VALOR INSERIDO PELA TRIGGER TRG_ATUALIZA_PRECO'
	-- INSERINDO NO HISTORICO
	INSERT INTO Historicos 
	(produto_Historico, categoria_Historico, preco_antigo_Historico, preco_novo_Historico, data_Historico, usuario_Historico, mensagem_Historico)
	VALUES
	(@produto, @categoria, @preco, @preco_novo, @data, @usuario, @mensagem)

	PRINT('TRIGGER EXECUTADA')
GO

-- fazendo update para dar trigger no historico
UPDATE Produtos SET preco_Produto=100.00
WHERE id_Produto=2
UPDATE Produtos SET preco_Produto = 95.00 WHERE id_Produto = 5;
UPDATE Produtos SET preco_Produto = 1500.00 WHERE id_Produto = 10;
UPDATE Produtos SET preco_Produto = 299.99 WHERE id_Produto = 15;
UPDATE Produtos SET preco_Produto = 799.00 WHERE id_Produto = 20;
GO

-- OUTRA MANEIRA DE MANIPULAR O TRIGGER
CREATE TRIGGER TRG_ATUALIZA_PRECO
ON dbo.Produtos
FOR UPDATE AS
IF UPDATE(preco)
BEGIN
--DECLARAÇÃO DE VARIAVEIS PARA USAR NA TRIGGER
    DECLARE @id_produto INT
	DECLARE @produto VARCHAR(30)
	DECLARE @categoria VARCHAR(10)
	DECLARE @preco NUMERIC(10,2)
	DECLARE @preco_novo NUMERIC(10,2)
	DECLARE @data DATETIME
	DECLARE @usuario VARCHAR(30)
	DECLARE @mensagem VARCHAR(100)
	-- PRIMERIO BLOCO
	SELECT @id_produto = id_Produto FROM inserted
	SELECT @produto = nome_Produto FROM inserted
	SELECT @categoria = categoria_Produto FROM inserted
	SELECT @preco = preco_Produto FROM deleted
	SELECT @preco_novo = preco_Produto FROM inserted
	-- SEGUNDO BLOCO 
	SET @data = GETDATE()
	SET @usuario = SUSER_NAME()
	SET @mensagem = 'VALOR INSERIDO PELA TRIGGER TRG_ATUALIZA_PRECO'
	-- INSERINDO NO HISTORICO
	INSERT INTO Historicos 
	(produto_Historico, categoria_Historico, preco_antigo_Historico, preco_novo_Historico, data_Historico, usuario_Historico, mensagem_Historico)
	VALUES
	(@produto, @categoria, @preco, @preco_novo, @data, @usuario, @mensagem)

	PRINT('TRIGGER EXECUTADA')
END
GO

UPDATE Produtos SET preco_Produto = 5.00 WHERE id_Produto = 1;

--VARIAVEIS COM SELECT
SELECT 10+10
GO

--ATRIBUINDO SELECTS A VARIAVEIS - ANONIMO
DECLARE
       @resultado INT

-- TRIGGER UPDADE -> MELHOR MANEIRA REDUZIDA
CREATE TABLE Empregado(
       id_Empregado INT PRIMARY KEY,
	   nome_Empregado VARCHAR(30),
	   salario_Empregado MONEY,
	   id_gerente INT
)
GO

ALTER TABLE Empregado ADD CONSTRAINT fk_gerente
FOREIGN KEY(id_gerente) REFERENCES Empregado(id_Empregado)
GO

CREATE TABLE Salario(
       id_empregado INT,
	   antigo_Salario MONEY,
	   novo_Salario MONEY,
	   data_Salario DATETIME
)
GO
-- TRIGGER UPDADE -> MELHOR MANEIRA REDUZIDA
CREATE TRIGGER tigger_Salario
on dbo.Empregado
FOR UPDATE AS
IF UPDATE(salario_Empregado)
BEGIN
     INSERT INTO Salario 
	 (id_empregado, antigo_Salario, novo_Salario, data_Salario)
	 SELECT e.id_Empregado, D.salario_Empregado, E.salario_Empregado, GETDATE() 
	 FROM Empregado E, deleted D
	 WHERE E.id_Empregado=D.id_Empregado
END
GO

DROP TRIGGER tigger_Salario
GO

-- Inserindo dados na tabela Empregado
INSERT INTO Empregado VALUES (1, 'João', 5000.00, NULL) 
INSERT INTO Empregado VALUES (2, 'Maria', 6000.00, 1)   
INSERT INTO Empregado VALUES (3, 'Pedro', 5500.00, 2)  
INSERT INTO Empregado VALUES (4, 'Ana', 5200.00, 1)   
INSERT INTO Empregado VALUES (5, 'Carlos', 7000.00, 3)
INSERT INTO Empregado VALUES (6, 'Laura', 4800.00, 2)  
INSERT INTO Empregado VALUES (7, 'Miguel', 7500.00, 3)
INSERT INTO Empregado VALUES (8, 'Clara', 5800.00, 1)   
INSERT INTO Empregado VALUES (9, 'Felipe', 6700.00, 2)   
INSERT INTO Empregado VALUES (10, 'Gabriel', 5200.00, NULL)
GO

UPDATE Empregado SET salario_Empregado=salario_Empregado*1.1
GO
SELECT * FROM Empregado
GO
SELECT * FROM Salario
GO
SELECT * FROM Salario
WHERE id_empregado=2
GO

-- CRIANDO ''LIMITES'' ESSAS COISA
CREATE TABLE Range_Salario(
     minimo_Range MONEY,
	 maximo_Range MONEY,
)
GO

INSERT INTO Range_Salario VALUES(2000, 9000) 
GO

CREATE TRIGGER trigger_range
on dbo.Empregado
FOR INSERT, UPDATE
AS
     DECLARE
	        @minimo_salario MONEY,
			@maximo_salario MONEY,
			@atual_salario MONEY

	 SELECT @minimo_salario = minimo_Range, 
	        @maximo_salario = maximo_Range
	 FROM Range_Salario

	 SELECT @atual_salario = I.salario_Empregado
	 FROM INSERTED I

	 IF(@atual_salario < @minimo_salario)
	 BEGIN
	      RAISERROR('SALARIO MANOR QUE PISO', 16,1)
		  ROLLBACK TRANSACTION
	 END

	 IF(@atual_salario>@maximo_salario)
	 BEGIN
	      RAISERROR('SALARIO MANOR QUE PISO', 16,1)
		  ROLLBACK TRANSACTION
	 END
GO
--VERIFICANDO TRIGGER
SP_HELPTEXT trigger_range
GO

SELECT * FROM Range_Salario
GO

UPDATE Empregado SET salario_Empregado= 10000.00
WHERE id_Empregado=1
GO

-- CRIANDO PROCIDURES NO SQL SERVER, so dale


