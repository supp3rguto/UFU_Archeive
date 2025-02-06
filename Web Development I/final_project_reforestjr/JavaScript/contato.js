function validarFormulario(event) {
    event.preventDefault(); // Evita o envio automático do formulário

    // Obtém os campos
    const nome = document.getElementById('nome');
    const email = document.getElementById('email');
    const assunto = document.getElementById('assunto');
    const mensagem = document.getElementById('mensagem');

    let formValido = true;

    // Validação do campo Nome
    if (nome.value.trim() === "" || nome.value.trim().split(' ').length < 2) {
        nome.classList.add('is-invalid');
        formValido = false;
    } else {
        nome.classList.remove('is-invalid');
    }

    // Validação do campo E-mail
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    if (!emailRegex.test(email.value.trim())) {
        email.classList.add('is-invalid');
        formValido = false;
    } else {
        email.classList.remove('is-invalid');
    }

    if (assunto.value.trim() === "") {
        assunto.classList.add('is-invalid');
        formValido = false;
    } else {
        assunto.classList.remove('is-invalid');
    }

    if (mensagem.value.trim() === "") {
        mensagem.classList.add('is-invalid');
        formValido = false;
    } else {
        mensagem.classList.remove('is-invalid');
    }

    if (formValido) {
        const nomeCompleto = nome.value.trim();
        const assuntoTexto = assunto.value.trim();
        const mensagemTexto = mensagem.value.trim();
        
        const mensagemWhatsApp = `Olá, meu nome é ${nomeCompleto}. \nAssunto: ${assuntoTexto}\nMensagem: ${mensagemTexto}`;

    
        const whatsappNumber = '+5517982296740';
        const whatsappURL = `https://api.whatsapp.com/send?phone=${whatsappNumber}&text=${encodeURIComponent(mensagemWhatsApp)}`;

        window.open(whatsappURL, '_blank');
    }
}
