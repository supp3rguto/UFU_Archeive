document.addEventListener("DOMContentLoaded", function () {
    // Função para transição suave entre páginas
    const links = document.querySelectorAll("a");
     links.forEach((link) => {
        link.addEventListener("click", function (e) {
            e.preventDefault();
            const href = this.getAttribute("href");
            
            if (href !== "#" && href !== "") {
                document.body.classList.add("fade-out");
                setTimeout(() => {
                    window.location.href = href;
                }, 500); // Tempo da animação de saída
            }
        });
    });

    // Rolagem suave para âncoras
    const anchorLinks = document.querySelectorAll('a[href^="#"]');
    anchorLinks.forEach((link) => {
        link.addEventListener("click", function (e) {
            e.preventDefault();
            const target = document.querySelector(this.getAttribute("href"));
            if (target) {
                window.scrollTo({
                    top: target.offsetTop,
                    behavior: "smooth",
                });
            }
        });
    });

    // Efeito de fade-in ao carregar a página
    document.body.classList.add("fade-in");
});


// Carrega o header
fetch('header.html')
.then(response => response.text())
.then(data => {
    document.getElementById('header').innerHTML = data;
});

// Carrega o footer
fetch('footer.html')
.then(response => response.text())
.then(data => {
    document.getElementById('footer').innerHTML = data;
});