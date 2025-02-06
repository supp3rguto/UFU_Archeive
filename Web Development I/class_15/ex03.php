<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Produtos</title>
</head>
<body>
    <h1>Lista de Produtos</h1>
    <?php
        $produtos = [
            ["nome" => "Produto A", "preco" => 10.50, "quantidade" => 5],
            ["nome" => "Produto B", "preco" => 20.00, "quantidade" => 3],
            ["nome" => "Produto C", "preco" => 15.75, "quantidade" => 10]
        ];
    ?>
    <table border="1">
        <tr>
            <th>Nome</th>
            <th>Preço</th>
            <th>Quantidade</th>
        </tr>
        <?php
            foreach ($produtos as $produto) {
                echo "<tr>";
                echo "<td>" . $produto["nome"] . "</td>";
                echo "<td>R$ " . number_format($produto["preco"], 2, ',', '.') . "</td>";
                echo "<td>" . $produto["quantidade"] . "</td>";
                echo "</tr>";
            }
        ?>
    </table>
</body>
</html>
