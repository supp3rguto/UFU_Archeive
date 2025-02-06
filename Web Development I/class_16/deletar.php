<?php
$id = $_GET['id'];
$conn = new mysqli("localhost", "root", "12345", "empresa");

if ($conn->connect_error) {
    die("Falha na conexão: " . $conn->connect_error);
}

$sql = "DELETE FROM colaboradores WHERE id=?";
$stmt = $conn->prepare($sql);
$stmt->bind_param("i", $id);

if ($stmt->execute()) {
    header("Location: index.php");
} else {
    echo "Erro ao excluir colaborador: " . $stmt->error;
}

$stmt->close();
$conn->close();
?>
