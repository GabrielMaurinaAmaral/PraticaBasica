CREATE DATABASE IF NOT EXISTS AGENDA
USE AGENDA

CREATE TABLE Pacientes(
    id_Paciente INT PRIMARY KEY AUTO_INCREMENT,
    nome_Paciente VARCHAR(30) UNIQUE NOT NULL, 
    sexo_Paciente ENUM('F', 'M') NOT NULL,
    email_Paciente VARCHAR(30) UNIQUE NOT NULL,
    nascimento_Paciente DATE NOT NULL
);

CREATE TABLE Medicos(
    id_Medico INT PRIMARY KEY AUTO_INCREMENT,
    nome_Medico VARCHAR(30) UNIQUE NOT NULL,
    sexo_Medico ENUM('F', 'M') NOT NULL,
    especialidade_Medico VARCHAR(30) NOT NULL,
    funcionario_Medico ENUM('S', 'N') NOT NULL
); 

CREATE TABLE Hospitais(
    id_Hospital INT PRIMARY KEY AUTO_INCREMENT,
    nome_Hospital VARCHAR(30) UNIQUE NOT NULL,
    bairro_Hospital VARCHAR(30) NOT NULL,
    cidade_Hospital VARCHAR(30) NOT NULL,
    estado_Hospital CHAR(2) NOT NULL
);

CREATE TABLE Consultas(
    id_Consulta INT PRIMARY KEY AUTO_INCREMENT,
    id__Paciente INT,
    id__Medico INT,
    id__Hospital INT,
    data_Consulta DATETIME UNIQUE NOT NULL ,
    diagnostico_Consulta VARCHAR(30) NOT NULL
);

CREATE TABLE Internacoes(
    id_Internacao INT PRIMARY KEY AUTO_INCREMENT,
    quanto_Internacao INT UNIQUE,
    entrada_Internacao DATE NOT NULL,
    saida_Internacao DATE NOT NULL,
    observacao_Internacao VARCHAR(255),
    id__Consulta INT UNIQUE
);
/* criando as constraints 
ligando as tabelas */
ALTER TABLE Consultas ADD CONSTRAINT fk_Consultas_Pacientes
FOREIGN KEY (id__Paciente) REFERENCES Pacientes(id_Paciente);

ALTER TABLE Consultas ADD CONSTRAINT fk_Consultas_Medicos
FOREIGN KEY (id__Medico) REFERENCES Medicos(id_Medico);

ALTER TABLE Consultas ADD CONSTRAINT fk_Consultas_Hospitais
FOREIGN KEY (id__Hospital) REFERENCES Hospitais(id_Hospital);

ALTER TABLE Internacoes ADD CONSTRAINT fk_Internacoes_Consultas
FOREIGN KEY (id__Consulta) REFERENCES Consultas(id_Consulta);

-- PROCURANDP AS CPNSTRAINTS PELA DATABASE
SHOW DATABASES;
USE INFORMATION_SCHEMA;
SHOW TABLES;
SELECT * FROM TABLE_CONSTRAINTS;
SELECT * FROM TABLE_CONSTRAINTS 
WHERE CONSTRAINT_SCHEMA='cursores';

INSERT INTO Pacientes (nome_Paciente, sexo_Paciente, email_Paciente, nascimento_Paciente) VALUES
('Maria Silva', 'F', 'maria@gmail.com', '1990-05-15'),
('João Oliveira', 'M', 'joao@gmail.com', '1985-08-20'),
('Ana Souza', 'F', 'ana@gmail.com', '2000-02-10');
('Rafael Oliveira', 'M', 'rafael@gmail.com', '1992-03-18'),
('Camila Santos', 'F', 'camila@gmail.com', '1988-09-25'),
('Lucas Souza', 'M', 'lucas@gmail.com', '1995-06-12'),
('Aline Lima', 'F', 'aline@gmail.com', '2002-11-30'),
('Bruno Costa', 'M', 'bruno@gmail.com', '1990-07-05');

INSERT INTO Medicos (nome_Medico, sexo_Medico, especialidade_Medico, funcionario_Medico) VALUES
('Dr. Carlos Santos', 'M', 'Cardiologia', 'S'),
('Dra. Laura Almeida', 'F', 'Pediatria', 'S'),
('Dr. Marcos Lima', 'M', 'Ortopedia', 'S');
('Dra. Juliana Pereira', 'F', 'Ginecologia', 'S'),
('Dr. Eduardo Rocha', 'M', 'Neurologia', 'S'),
('Dra. Fernanda Martins', 'F', 'Oftalmologia', 'S'),
('Dr. Rodrigo Oliveira', 'M', 'Dermatologia', 'S'),
('Dra. Carolina Santos', 'F', 'Psiquiatria', 'S');

INSERT INTO Hospitais (nome_Hospital, bairro_Hospital, cidade_Hospital, estado_Hospital) VALUES
('Hospital Central', 'Centro', 'São Paulo', 'SP'),
('Hospital Municipal', 'Vila Nova', 'Rio de Janeiro', 'RJ'),
('Hospital São Lucas', 'Jardins', 'Belo Horizonte', 'MG');
('Hospital São José', 'Centro', 'Porto Alegre', 'RS'),
('Hospital São Francisco', 'Centro', 'Curitiba', 'PR'),
('Hospital Santa Clara', 'Jardim', 'Florianópolis', 'SC'),
('Hospital Nossa Senhora', 'Centro', 'Recife', 'PE'),
('Hospital Santa Rita', 'Bairro Novo', 'Salvador', 'BA');

INSERT INTO Consultas (id__Paciente, id__Medico, id__Hospital, data_Consulta, diagnostico_Consulta) VALUES
(1, 1, 1, '2023-11-01 10:00:00', 'Check-up'),
(2, 2, 2, '2023-11-02 14:30:00', 'Febre'),
(3, 3, 3, '2023-11-03 08:45:00', 'Fratura');
(4, 3, 2, '2023-11-10 09:30:00', 'Consulta de rotina'),
(2, 1, 1, '2023-11-12 15:45:00', 'Acompanhamento de gravidez'),
(5, 5, 4, '2023-11-15 11:00:00', 'Avaliação psiquiátrica'),
(1, 2, 3, '2023-11-20 14:15:00', 'Dor de cabeça persistente'),
(3, 4, 5, '2023-11-25 08:00:00', 'Problemas dermatológicos');

INSERT INTO Internacoes (quanto_Internacao, entrada_Internacao, saida_Internacao, observacao_Internacao, id__Consulta) VALUES
(101, '2023-11-01', '2023-11-03', 'Paciente em recuperação', 1),
(102, '2023-11-02', '2023-11-05', 'Observação de quadro clínico', 2),
(103, '2023-11-03', '2023-11-07', 'Cirurgia realizada', 3);
(104, '2023-11-11', '2023-11-14', 'Cirurgia programada', 1),
(105, '2023-11-13', '2023-11-18', 'Monitoramento pós-operatório', 2),
(106, '2023-11-16', '2023-11-21', 'Avaliação psiquiátrica intensiva', 3),
(107, '2023-11-22', '2023-11-25', 'Observação clínica', 4),
(108, '2023-11-27', '2023-12-02', 'Cirurgia dermatológica', 5);

SELECT * FROM Pacientes;
SELECT * FROM Medicos;
SELECT * FROM Hospitais;
SELECT * FROM Consultas;
SELECT * FROM Internacoes;
