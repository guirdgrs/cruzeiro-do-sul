USE bookverse;
INSERT INTO usuario (nome, tipo, email) VALUES
('Guilherme Silva', 'aluno', 'gui@email.com'),
('Maria Souza', 'professor', 'maria@uni.com'),
('João Pedro', 'aluno', 'joao@teste.com');

INSERT INTO localizacao (setor, estante, prateleira) VALUES
('A', 'Estante 1', 'Prateleira 1'),
('A', 'Estante 1', 'Prateleira 2'),
('B', 'Estante 2', 'Prateleira 1');

INSERT INTO editora (nome) VALUES
('Editora Atlas'),
('Companhia das Letras'),
('HarperCollins');

INSERT INTO genero (nome) VALUES
('Fantasia'),
('Ficção Científica'),
('Terror');

INSERT INTO autor (nome) VALUES
('J. R. R. Tolkien'),
('H. P. Lovecraft'),
('Isaac Asimov');

INSERT INTO livro (titulo, isbn, editora_id, genero_id, localizacao_id, ano_publicacao) VALUES
('O Senhor dos Anéis', 'ISBN001', 1, 1, 1, 1954),
('Fundação', 'ISBN002', 3, 2, 2, 1951),
('O Chamado de Cthulhu', 'ISBN003', 2, 3, 3, 1928);

INSERT INTO livro_autor (livro_id, autor_id, ordem_autor) VALUES
(1, 1, 1),
(2, 3, 1),
(3, 2, 1);

INSERT INTO reserva (usuario_id, livro_id, data_reserva) VALUES
(1, 1, '2025-01-10'),
(2, 2, '2025-01-12'),
(1, 3, '2025-01-20');

INSERT INTO emprestimo (exemplar_id, usuario_id, data_retirada, data_prevista_devolucao, data_devolucao) VALUES
(101, 1, '2025-01-05', '2025-01-20', NULL),
(102, 2, '2025-01-07', '2025-01-22', '2025-01-15'),
(103, 3, '2025-01-10', '2025-01-25', NULL);

INSERT INTO renovacao (emprestimo_id, data_renovacao) VALUES
(1, '2025-01-18'),
(3, '2025-01-22');

INSERT INTO auditoria (emprestimo_id, acao) VALUES
(1, 'Criação de empréstimo'),
(2, 'Devolução registrada'),
(1, 'Renovação realizada');
