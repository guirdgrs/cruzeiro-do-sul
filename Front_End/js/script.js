const routes = {
  '/': 'pages/home.html',
  '/projetos': 'pages/projetos.html',
  '/equipe': 'pages/equipe.html',
  '/doacao': 'pages/doacao.html',
  '/cadastro': 'pages/cadastro.html'
};


async function loadRoute() {
  const path = window.location.hash.replace('#', '') || '/';
  const route = routes[path] || routes['/'];

  try {
    const response = await fetch(route);
    const html = await response.text();

    document.getElementById('app').innerHTML = html;
    // Scrollando para o topo
    window.scrollTo({ top: 0, behavior: "smooth" });

    // Focando o primeiro elemento
    const main = document.getElementById('main-content') || document.getElementById('app');
    main.setAttribute('tabindex', '-1');
    main.focus();
    
  } catch (error) {
    document.getElementById('app').innerHTML = `<h2>Página não encontrada</h2>`;
  }
}

window.addEventListener('hashchange', loadRoute);

window.addEventListener('load', loadRoute);
