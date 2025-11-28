CREATE DATABASE IF NOT EXISTS bookverse;
USE bookverse;

CREATE TABLE usuario (
    usuario_id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    tipo VARCHAR(20) NOT NULL,
    email VARCHAR(150) NOT NULL UNIQUE
) ENGINE=InnoDB;

CREATE TABLE localizacao (
    localizacao_id INT AUTO_INCREMENT PRIMARY KEY,
    setor VARCHAR(50),
    estante VARCHAR(50),
    prateleira VARCHAR(50)
) ENGINE=InnoDB;

CREATE TABLE editora (
    editora_id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL
) ENGINE=InnoDB;

CREATE TABLE genero (
    genero_id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL
) ENGINE=InnoDB;

CREATE TABLE autor (
    autor_id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL
) ENGINE=InnoDB;

CREATE TABLE livro (
    livro_id INT AUTO_INCREMENT PRIMARY KEY,
    titulo VARCHAR(200) NOT NULL,
    isbn VARCHAR(30) UNIQUE,
    editora_id INT,
    genero_id INT,
    localizacao_id INT,
    ano_publicacao INT,

    FOREIGN KEY (editora_id) REFERENCES editora(editora_id),
    FOREIGN KEY (genero_id) REFERENCES genero(genero_id),
    FOREIGN KEY (localizacao_id) REFERENCES localizacao(localizacao_id)
) ENGINE=InnoDB;

CREATE TABLE livro_autor (
    livro_id INT,
    autor_id INT,
    ordem_autor INT,
    PRIMARY KEY (livro_id, autor_id),

    FOREIGN KEY (livro_id) REFERENCES livro(livro_id)
        ON DELETE CASCADE,
    FOREIGN KEY (autor_id) REFERENCES autor(autor_id)
        ON DELETE CASCADE
) ENGINE=InnoDB;

CREATE TABLE reserva (
    reserva_id INT AUTO_INCREMENT PRIMARY KEY,
    usuario_id INT NOT NULL,
    livro_id INT NOT NULL,
    data_reserva DATE NOT NULL,
    
    FOREIGN KEY (usuario_id) REFERENCES usuario(usuario_id),
    FOREIGN KEY (livro_id) REFERENCES livro(livro_id)
) ENGINE=InnoDB;

CREATE TABLE emprestimo (
    emprestimo_id INT AUTO_INCREMENT PRIMARY KEY,
    exemplar_id INT NOT NULL,
    usuario_id INT NOT NULL,
    data_retirada DATE NOT NULL,
    data_prevista_devolucao DATE NOT NULL,
    data_devolucao DATE,

    FOREIGN KEY (usuario_id) REFERENCES usuario(usuario_id)
) ENGINE=InnoDB;

CREATE TABLE renovacao (
    renovacao_id INT AUTO_INCREMENT PRIMARY KEY,
    emprestimo_id INT NOT NULL,
    data_renovacao DATE NOT NULL,

    FOREIGN KEY (emprestimo_id) REFERENCES emprestimo(emprestimo_id)
) ENGINE=InnoDB;

CREATE TABLE auditoria (
    auditoria_id INT AUTO_INCREMENT PRIMARY KEY,
    emprestimo_id INT NOT NULL,
    acao VARCHAR(255),
    data_acao TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    
    FOREIGN KEY (emprestimo_id) REFERENCES emprestimo(emprestimo_id)
) ENGINE=InnoDB;
