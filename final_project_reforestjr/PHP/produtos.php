<?php
// Configuração de conexão com o banco de dados
$host = 'localhost';
$db = 'reforestjr';
$user = 'postgres';
$pass = 'senha';

try {
    $conn = new PDO("mysql:host=$host;dbname=$db;charset=utf8", $user, $pass);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Consulta SQL para obter todos os produtos
    $stmt = $conn->query("SELECT nome, quantidade_estoque, preco FROM produtos");

    echo "<table border='1'>
            <tr>
                <th>Nome do Produto</th>
                <th>Quantidade em Estoque</th>
                <th>Preço</th>
                <th>Status</th>
            </tr>";

    // Itera sobre cada produto e exibe as informações
    while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
        echo "<tr>";
        echo "<td>" . htmlspecialchars($row['nome']) . "</td>";
        echo "<td>" . $row['quantidade_estoque'] . "</td>";
        echo "<td>R$ " . number_format($row['preco'], 2, ',', '.') . "</td>";
        
        // Verificação de disponibilidade no estoque
        if ($row['quantidade_estoque'] > 0) {
            echo "<td>Em estoque</td>";
        } else {
            echo "<td>Produto indisponível - <a href='encomenda.php?produto=" . urlencode($row['nome']) . "'>Solicitar encomenda</a></td>";
        }
        
        echo "</tr>";
    }

    echo "</table>";
} catch (PDOException $e) {
    echo "Erro ao conectar com o banco de dados: " . $e->getMessage();
}
?>
