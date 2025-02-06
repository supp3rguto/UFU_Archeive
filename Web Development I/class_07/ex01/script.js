function verificarNota() {
    let nota = document.getElementById("nota").value;
    let mensagem;
    if (nota < 0 || nota > 100) {
        mensagem = "Por favor, insira uma nota entre 0 e 100.";
    } else if (nota >= 90) {
        mensagem = "Excelente";
    } else if (nota >= 60) {
        mensagem = "Bom";
    } else {
        mensagem = "Precisa Melhorar";
    }
    document.getElementById("desempenho").innerText = mensagem;
}
