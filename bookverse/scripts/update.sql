USE bookverse;
UPDATE usuario
SET email = 'novoemail@teste.com'
WHERE usuario_id = 1;

UPDATE livro
SET localizacao_id = 2
WHERE livro_id = 3;

UPDATE emprestimo
SET data_devolucao = '2025-01-18'
WHERE emprestimo_id = 1;
