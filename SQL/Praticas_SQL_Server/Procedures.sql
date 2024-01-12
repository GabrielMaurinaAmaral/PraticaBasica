CREATE DATABASE PROCEDURE_DATABASE
GO
USE PROCEDURE_DATABASE
GO

CREATE TABLE Clientes(
  id_Cliente INT PRIMARY KEY IDENTITY,
  nome_Cliente VARCHAR(30) NOT NULL,
  sexo_Cliente  CHAR(1) NOT NULL,
  email_Cliente VARCHAR(30) UNIQUE,
  cpf_Cliente VARCHAR(11) UNIQUE,
  CHECK (sexo_Cliente IN ('F', 'M'))
)
GO

CREATE TABLE Endereco(
  id_Endereco INT PRIMARY KEY IDENTITY,
  rua_Endereco VARCHAR(30) NOT NULL,
  bairro_Endereco VARCHAR(30) NOT NULL,
  cidade_Endereco VARCHAR(30) NOT NULL,
  estado_Endereco CHAR(2) NOT NULL,
  id__cliente INT UNIQUE
)
GO

CREATE TABLE Telefone(
  id_telefone INT PRIMARY KEY IDENTITY,
  tipo_telefone CHAR(3) NOT NULL,
  numero_telefone VARCHAR(10) NOT NULL,
  id__cliente INT,
  CHECK(tipo_telefone IN ('RES','COM','CEL')) 
)
GO

ALTER TABLE Endereco ADD CONSTRAINT fk_endereco_cliente
FOREIGN KEY (id__cliente) REFERENCES Clientes(id_Cliente)
GO

ALTER TABLE Telefone ADD CONSTRAINT fk_telefones_cliente
FOREIGN KEY (id__cliente) REFERENCES Clientes(id_Cliente)
GO

INSERT INTO Clientes VALUES('JOAO','M','joao@gmail.com','11111111111')
INSERT INTO Clientes VALUES('Ana','F','ana@gmail.com','22222222222')
INSERT INTO Clientes VALUES('Julia','F', NULL,'33333333333')
INSERT INTO Clientes VALUES('Gabriel','M','gabriel@gmail.com','44444444444')
INSERT INTO Clientes VALUES('Nicolie','F','nino@hotmail.com','55555555555')
INSERT INTO Clientes VALUES('Marrio','M', NULL,'66666666666')
SELECT * FROM Clientes;
GO

INSERT INTO Endereco VALUES('Rua Mimhapika', 'Centro', 'Pato Branco','PR', 3);
INSERT INTO Endereco VALUES('Rua Caue Moura', 'Centro', 'Jundiai','SP', 2);
INSERT INTO Endereco VALUES('Rua Lanadel Rei', 'Fundos', 'Itapema','SC', 1);
INSERT INTO Endereco VALUES('Rua PC Siqueira', 'Interior', 'Jundiai','SP', 4);
INSERT INTO Endereco VALUES('Rua Padre Quevedo', 'Centro', 'Itapema','SC', 5);
SELECT * FROM Endereco;
GO

INSERT INTO Telefone VALUES('CEL', '4611112222', 5)
INSERT INTO Telefone VALUES('RES', '4622223333', 5)
INSERT INTO Telefone VALUES('CEL', '4233334444', 1)
INSERT INTO Telefone VALUES('COM', '4411115555', 3)
INSERT INTO Telefone VALUES('CEL', '4511119999', 4)
INSERT INTO Telefone VALUES('COM', '4388884444', 6)
SELECT * FROM Telefone;
GO

--CRIADNO PROCEDURES
CREATE PROC SOMA
AS
    SELECT 10 + 10 AS SOMA
GO

EXEC SOMA
GO

--CRIADNO PROCIDURES COM PARAMETROS
CREATE PROC Soma @num_1 INT, @num_2 INT
AS
    SELECT @num_1 + @num_2 AS Soma
GO

EXEC Soma 1, 2
GO

-- POCEDURES EM TABLEAS
SELECT nome, numero
FROM Clientes
INNER JOIN Telefone
ON id_cliente = id__cliente
WHERE tipo_telefone = 'CEL'
GO
-- PROCEDURE EQUIVALENTE AO CODIGOS
CREATE PROC mostrar_Telefone_tipo @tipo CHAR(3)
AS
       SELECT nome_Cliente, numero_telefone
       FROM Clientes
       INNER JOIN Telefone
       ON id_cliente = id__cliente
       WHERE tipo_telefone = @tipo
GO

EXEC mostrar_Telefone_tipo 'CEL'
GO

-- Parametros de OUTPUT
SELECT tipo_Telefone, COUNT(*) AS QUANTIDADE
FROM Telefone
GROUP BY tipo_telefone
GO

CREATE PROCEDURE quantida_Telefone_tipo @tipo CHAR(3), @contador INT OUTPUT
AS
  SELECT @contador = COUNT(*)
  FROM Telefone
  WHERE tipo_telefone = @tipo
GO
-- COMO EXECUTAR O PROCEDURE COM SIADA/OUTPUT
DECLARE @saida INT
EXEC quantida_Telefone_tipo 'CEL', @contador = @saida OUTPUT
SELECT @saida AS 'quantidade desse tipo'
GO
-- tambem pode ser assim
-- COMO EXECUTAR O PROCEDURE COM SIADA/OUTPUT
DECLARE @saida INT
EXEC quantida_Telefone_tipo 'CEL', @saida OUTPUT
SELECT @saida AS 'quantidade desse tipo'
GO

-- GuaRda o ultimo identity inserido, LOGO O ID DA ULTIMA COISA A SER INSERIDA EM ALGUMA TABELA
SELECT @@IDENTITY
GO

-- PROCEDURE DE CADASTRO
CREATE PROC cadastro @nome VARCHAR(30), @sexo CHAR(1), @tipo CHAR(3), @numero VARCHAR(10)
AS 
   DECLARE @fk_id_cliente INT

   INSERT INTO Clientes VALUES (@nome, @sexo, NULL, NULL)
   
   SET @fk_id_cliente = (SELECT @@IDENTITY FROM Clientes
                         WHERE id_Cliente=@@IDENTITY)
   
   INSERT INTO Telefone VALUES (@tipo, @numero, @fk_id_cliente)
GO
--TESTAR A PROCEDUTE
cadastro 'Gabriel', 'M', 'CEL', '998877655'
GO

--LINGUAGEM DE PROGRAMAÇÃO SO SQL SERVER -> TSQL

DECLARE
       @v_numero NUMERIC(10,2) = 102.52,
       @v_data DATETIME = '20230601'
BEGIN
       PRINT 'VALOR NUMERICO: ' + CAST(@v_numero AS VARCHAR)
	   PRINT 'VALOR NUMERICO: ' + CONVERT(VARCHAR, @v_numero)
       PRINT 'VALOR NUMERICO: ' + CAST(@v_data AS VARCHAR)
	   PRINT 'VALOR NUMERICO: ' + CONVERT(VARCHAR, @v_data)
END
