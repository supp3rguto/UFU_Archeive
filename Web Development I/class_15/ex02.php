<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Lista de Números</title>
</head>
<body>
    <h1>Números de 1 a 30</h1>
    <ul>
        <?php
            for ($i = 1; $i <= 30; $i++) {
                echo "<li>$i</li>";
            }
        ?>
    </ul>
</body>
</html>
