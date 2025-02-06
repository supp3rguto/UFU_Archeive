<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Notas dos Alunos</title>
</head>
<body>
    <h1>Notas dos Alunos</h1>
    <?php
        $notas = [35, 77, 65, 49, 28, 95];
        echo "<ul>";
        foreach ($notas as $nota) {
            $status = $nota >= 60 ? "Aprovado" : "Reprovado";
            echo "<li>Nota: $nota - Status: $status</li>";
        }
        echo "</ul>";
    ?>
</body>
</html>
