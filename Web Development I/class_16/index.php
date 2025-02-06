<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <title>Gerenciamento de Colaboradores</title>
</head>
<body>
    <h1>Gerenciamento de Colaboradores</h1>

    <!-- Formulário para adicionar um novo colaborador -->
    <form action="adicionar.php" method="POST">
        <label>Nome Completo:</label>
        <input type="text" name="nome" required><br>

        <label>Telefone:</label>
        <input type="text" name="telefone" required pattern="\d{10,15}"><br>

        <label>Endereço:</label>
        <input type="text" name="endereco" required><br>

        <label>Anos de Experiência:</label>
        <input type="number" name="experiencia" required min="0"><br>

        <label>Salário Mensal:</label>
        <input type="number" step="0.01" name="salario" required min="0"><br>

        <button type="submit">Adicionar Colaborador</button>
    </form>

    <h2>Lista de Colaboradores</h2>
    <table border="1">
        <tr>
            <th>Nome</th>
            <th>Telefone</th>
            <th>Endereço</th>
            <th>Anos de Experiência</th>
            <th>Salário Mensal</th>
            <th>Ações</th>
        </tr>
        <?php
            // Conexão com o banco de dados e exibição dos colaboradores
            $conn = new mysqli("localhost", "root", "12345", "empresa");
            if ($conn->connect_error) {
                die("Falha na conexão: " . $conn->connect_error);
            }

            $sql = "SELECT * FROM colaboradores";
            $result = $conn->query($sql);

            if ($result->num_rows > 0) {
                while($row = $result->fetch_assoc()) {
                    echo "<tr>
                            <td>{$row['nome']}</td>
                            <td>{$row['telefone']}</td>
                            <td>{$row['endereco']}</td>
                            <td>{$row['experiencia']}</td>
                            <td>{$row['salario']}</td>
                            <td>
                                <a href='editar.php?id={$row['id']}'>Editar</a> | 
                                <a href='deletar.php?id={$row['id']}'>Excluir</a>
                            </td>
                          </tr>";
                }
            } else {
                echo "<tr><td colspan='6'>Nenhum colaborador encontrado</td></tr>";
            }
            $conn->close();
        ?>
    </table>
</body>
</html>
