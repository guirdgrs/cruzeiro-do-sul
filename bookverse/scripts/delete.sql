USE bookverse;
SET @USER_ID = 3;

DELETE FROM reserva
WHERE usuario_id = @USER_ID;

DELETE FROM renovacao
WHERE emprestimo_id IN (
    SELECT emprestimo_id
    FROM emprestimo
    WHERE usuario_id = @USER_ID
);

DELETE FROM emprestimo
WHERE usuario_id = @USER_ID;

DELETE FROM usuario
WHERE usuario_id = @USER_ID;