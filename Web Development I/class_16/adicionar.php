<?php
$nome = $_POST['nome'];
$telefone = $_POST['telefone'];
$endereco = $_POST['endereco'];
$experiencia = $_POST['experiencia'];
$salario = $_POST['salario'];

$conn = new mysqli("localhost", "root", "12345", "empresa");

if ($conn->connect_error) {
    die("Falha na conexão: " . $conn->connect_error);
}

$sql = "INSERT INTO colaboradores (nome, telefone, endereco, experiencia, salario) VALUES (?, ?, ?, ?, ?)";
$stmt = $conn->prepare($sql);
$stmt->bind_param("sssii", $nome, $telefone, $endereco, $experiencia, $salario);

if ($stmt->execute()) {
    header("Location: index.php");
} else {
    echo "Erro ao adicionar colaborador: " . $stmt->error;
}

$stmt->close();
$conn->close();
?>
