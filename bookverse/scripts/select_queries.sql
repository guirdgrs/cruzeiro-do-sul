USE bookverse;

-- 1) Listar todos os livros com nome da editora e gênero
SELECT l.titulo, e.nome AS editora, g.nome AS genero
FROM livro l
JOIN editora e ON l.editora_id = e.editora_id
JOIN genero g ON l.genero_id = g.genero_id;

-- 2) Mostrar empréstimos em aberto (sem data_devolucao)
SELECT e.emprestimo_id, u.nome AS usuario, e.data_retirada
FROM emprestimo e
JOIN usuario u ON e.usuario_id = u.usuario_id
WHERE e.data_devolucao IS NULL;

-- 3) Listar reservas feitas por um usuário específico
SELECT r.reserva_id, l.titulo, r.data_reserva
FROM reserva r
JOIN livro l ON r.livro_id = l.livro_id
WHERE r.usuario_id = 1;

-- 4) Livros ordenados do mais antigo para o mais recente
SELECT titulo, ano_publicacao
FROM livro
ORDER BY ano_publicacao ASC;

-- 5) Buscar autores de um livro específico
SELECT a.nome AS autor
FROM livro_autor la
JOIN autor a ON la.autor_id = a.autor_id
WHERE la.livro_id = 1;
