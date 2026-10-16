// Mini Atividade 1 - Questão 3
// Baixa as tirinhas do XKCD, da mais recente até a primeira, seguindo o botão "Prev".
//   - fetch     -> faz o download das páginas (equivalente ao requests)
//   - cheerio   -> encontra a imagem e o link "Prev" (equivalente ao BeautifulSoup)
//   - as imagens são salvas na pasta ./xkcd
//
// Uso: node 3-xkcd.js          (baixa todas, demora bastante)
//      node 3-xkcd.js 10       (baixa só as 10 mais recentes, para testar)

const fs = require('fs');
const cheerio = require('cheerio');

const limite = Number(process.argv[2]) || Infinity;

async function main() {
  fs.mkdirSync('xkcd', { recursive: true });

  let url = 'https://xkcd.com/';
  let baixadas = 0;

  // A primeira tirinha tem o "Prev" apontando para "#", aí o laço termina
  while (!url.endsWith('#') && baixadas < limite) {
    // 1) Baixa a página
    console.log('Página:', url);
    const $ = cheerio.load(await (await fetch(url)).text());

    // 2) Acha a URL da imagem dentro de <div id="comic">
    const src = $('#comic img').attr('src');
    if (src) {
      const urlImagem = 'https:' + src; // vem como "//imgs.xkcd.com/..."
      // 3) Baixa a imagem e salva no disco
      const imagem = Buffer.from(await (await fetch(urlImagem)).arrayBuffer());
      fs.writeFileSync('xkcd/' + urlImagem.split('/').pop(), imagem);
      console.log('  salvou', urlImagem);
    } else {
      console.log('  sem imagem nesta página'); // algumas tirinhas são interativas
    }

    // 4) Acha o link "Prev" e repete
    const prev = $('a[rel="prev"]').attr('href');
    url = new URL(prev, url).href;
    baixadas++;
  }

  console.log('Fim! Tirinhas processadas:', baixadas);
}

main();
