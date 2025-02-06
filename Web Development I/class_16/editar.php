<?php
// Conexão com o banco de dados
$conn = new mysqli("localhost", "root", "12345", "empresa");
if ($conn->connect_error) {
    die("Falha na conexão: " . $conn->connect_error);
}

// Verifica se o ID foi passado pela URL
if (isset($_GET['id'])) {
    $id = $_GET['id'];

    // Consulta para buscar os dados do colaborador
    $sql = "SELECT * FROM colaboradores WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("i", $id);
    $stmt->execute();
    $result = $stmt->get_result();

    // Verifica se o colaborador foi encontrado
    if ($result->num_rows > 0) {
        $colaborador = $result->fetch_assoc();
    } else {
        echo "Colaborador não encontrado.";
        exit();
    }
} else {
    echo "ID do colaborador não especificado.";
    exit();
}

// Atualiza os dados do colaborador após o envio do formulário
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $nome = $_POST['nome'];
    $telefone = $_POST['telefone'];
    $endereco = $_POST['endereco'];
    $experiencia = $_POST['experiencia'];
    $salario = $_POST['salario'];

    $sql = "UPDATE colaboradores SET nome = ?, telefone = ?, endereco = ?, experiencia = ?, salario = ? WHERE id = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("sssidi", $nome, $telefone, $endereco, $experiencia, $salario, $id);

    if ($stmt->execute()) {
        header("Location: index.php");
    } else {
        echo "Erro ao atualizar colaborador: " . $stmt->error;
    }
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Editar Colaborador</title>
</head>
<body>
    <h1>Editar Colaborador</h1>

    <!-- Formulário para editar um colaborador -->
    <form action="" method="POST">
        <label>Nome Completo:</label>
        <input type="text" name="nome" value="<?php echo $colaborador['nome']; ?>" required><br>

        <label>Telefone:</label>
        <input type="text" name="telefone" value="<?php echo $colaborador['telefone']; ?>" required pattern="\d{10,15}"><br>

        <label>Endereço:</label>
        <input type="text" name="endereco" value="<?php echo $colaborador['endereco']; ?>" required><br>

        <label>Anos de Experiência:</label>
        <input type="number" name="experiencia" value="<?php echo $colaborador['experiencia']; ?>" required min="0"><br>

        <label>Salário Mensal:</label>
        <input type="number" step="0.01" name="salario" value="<?php echo $colaborador['salario']; ?>" required min="0"><br>

        <button type="submit">Salvar Alterações</button>
    </form>

    <a href="index.php">Voltar</a>
</body>
</html>
