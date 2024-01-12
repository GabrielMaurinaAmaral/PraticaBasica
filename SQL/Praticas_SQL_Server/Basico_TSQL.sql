CREATE DATABASE BASICO_TSQL
GO
USE BASICO_TSQL
GO

CREATE TABLE Carros(
   modelo_Carro VARCHAR(30) NOT NULL,
   fabricante_Carro VARCHAR(30) NOT NULL
)
GO

INSERT INTO Carros VALUES('OMEGA', 'Fiat')
INSERT INTO Carros VALUES('Civic', 'Honda')
INSERT INTO Carros VALUES('Corolla', 'Toyota')
INSERT INTO Carros VALUES('Fusion', 'Ford')
INSERT INTO Carros VALUES('Cruze', 'Chevrolet')
INSERT INTO Carros VALUES('Golf', 'Volkswagen')
INSERT INTO Carros VALUES('Camry', 'Toyota')
INSERT INTO Carros VALUES('Accord', 'Honda')
INSERT INTO Carros VALUES('Focus', 'Ford')
INSERT INTO Carros VALUES('Sentra', 'Nissan')
INSERT INTO Carros VALUES('Mazda3', 'Ford')
GO

DECLARE
       @v_contador_ford INT,
	   @v_contador_fiat INT
BEGIN
       SET @v_contador_ford = (SELECT COUNT(*) FROM CARROS 
	                           WHERE fabricante_Carro='Ford')
       SET @v_contador_fiat = (SELECT COUNT(*) FROM CARROS 
	                           WHERE fabricante_Carro='Fiat')
	   PRINT 'Qunatidade Ford: ' + CAST(@v_contador_ford AS VARCHAR)
       PRINT 'Qunatidade Fiat: ' + CONVERT(VARCHAR, @contador_fiat)
END
GO

-- IF E ELSE
DECLARE
       @num_1 INT = 5
BEGIN
       IF @num_1 = 5
	       PRINT 'VERDADE'
	   ELSE 
	       PRINT 'FALSO'
END
GO

-- case
DECLARE
       @CONTADOR INT
BEGIN
       SELECT *,
	         CASE 
	             WHEN fabricante_Carro = 'Ford' THEN 'FAIXA 1'
		         WHEN fabricante_Carro = 'Fiat' THEN 'FAIXA 2'
		         ELSE 'OUTRAS FAIXAS'
	         END AS 'INFORMAÇAO'
	   FROM CARROS
END
GO

-- TRANSFORMANDO O CODIGO LOGO EM CIMA EM UM BLOCO NOMEADO = PROCEDURE
CREATE PROC divisor @num_1 INT, @num_2 INT
AS
  DECLARE 
         @mensagem CHAR(13) = 'NÃO É DIVISOR'
  BEGIN
        IF @num_1%@num_2=0
		    PRINT CAST(@num_2 AS VARCHAR) +  'É DIVISOR DE ' + CAST(@num_1 AS VARCHAR)
		ELSE
		    PRINT @mensagem
  END
GO

EXEC divisor 2, 10
GO

-- loops while
DECLARE
       @i INT = 1
BEGIN
     WHILE (@i>10)
	      BEGIN
		       PRINT 'VALOR DE @I = ' + CAST(@i AS VARCHAR)
			   SET @i = @i + 1
		  END
END
GO