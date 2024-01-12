DROP DATABASE IF EXISTS Livraria;

CREATE DATABASE Livraria;
USE Livraria;

DROP TABLE IF EXISTS Livro;

CREATE TABLE Livro (
    nome_livro VARCHAR(30) NOT NULL,
    nome_autor VARCHAR(30) NOT NULL,
    sexo_autor CHAR(1) NOT NULL,
    numero_paginas INT NOT NULL,
    nome_editora VARCHAR(30) NOT NULL,
    valor_livro FLOAT(3,2) NOT NULL,
    estado_editora CHAR(2) NOT NULL,
    ano_publicacao YEAR
);

INSERT INTO Livro VALUES('Cavaleiro Real', 'Ana Claudia', 'F', 465, 'Atlas', 49.9, 'RJ', 2009);
INSERT INTO Livro VALUES('SQL para leigos', 'João Nunes', 'M', 450, 'Addison', 98, 'SP', 2018);
INSERT INTO Livro VALUES('Receitas Caseiras', 'Celia Tavares', 'F', 210, 'Atlas', 45, 'RJ', 2008);
INSERT INTO Livro VALUES('Pessoas Efetivas', 'Eduardo Santos', 'M', 390, 'Beta', 78.99, 'RJ', 2018);
INSERT INTO Livro VALUES('Habitos Saudaveis', 'Eduardo Santos', 'M', 630, 'Beta', 150.99, 'RJ', 2019);
INSERT INTO Livro VALUES('A Casa Marron', 'Hermes Macedo', 'M', 250, 'Bubba', 60, 'MG', 2016);
INSERT INTO Livro VALUES('Estacio Querido', 'Geraldo Francisco', 'M', 310, 'Insignia', 100, 'ES', 2015);
INSERT INTO Livro VALUES('Pra sempre amigos', 'Leda Silva', 'F', 510, 'Insignia', 78.98, 'ES', 2011);
INSERT INTO Livro VALUES('Copas Inesqueciveis', 'Marco Alcantara', 'M', 200, 'Larson', 130.98, 'RS', 2018);
INSERT INTO Livro VALUES('O poder da mente', 'Clara Mafra', 'F', 120, 'Continental', 56.58, 'RS', 2017);

SELECT * FROM Livro;
SELECT nome_livro, nome_editora from Livro;
SELECT nome_livro, estado_editora FROM Livro WHERE sexo_autor='M';
SELECT nome_autor, nome_livro, numero_paginas FROM Livro WHERE sexo_autor='F';
SELECT nome_livro, valor_livro FROM Livro WHERE estado_editora='SP';
SELECT nome_livro, sexo_autor, estado_editora FROM Livro WHERE sexo_autor='M' AND (estado_editora='SP' OR estado_editora='RJ');

/*COUNT SERVE PARA CONTAR ALGO*/
SELECT COUNT(*) AS 'quantidade de registros' FROM Livro;
SELECT sexo_autor, COUNT(*) FROM Livro GROUP BY sexo_autor;
SELECT estado_editora, COUNT(*) FROM Livro GROUP BY estado_editora;

