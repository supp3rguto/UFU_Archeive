CREATE TABLE produtos (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    estoque INT DEFAULT 0,
    preco DECIMAL(10, 2) NOT NULL
);

ALTER TABLE produtos
ADD COLUMN foto VARCHAR(255);

INSERT INTO produtos(nome, estoque, preco, foto)
VALUES 
	('Composteira', 2, 499, 'C:\xampp\htdocs\reforestjr\Imagens\produtos\composteira.jpg'),
	('Horta Vertical', 0, 799, 'C:\xampp\htdocs\reforestjr\Imagens\produtos\hortaVertical.webp');
