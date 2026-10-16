// Mini Atividade 1 - Questão 2
// Extrai dados de duas URLs diferentes e gera dois arquivos CSV.
// (O enunciado pede Python; aqui foi feito em JavaScript, com a mesma ideia:
//  fetch = requests, cheerio = BeautifulSoup)
//
//   URL 1: https://books.toscrape.com   -> livros.csv  (título, preço, estoque, nota)
//   URL 2: https://quotes.toscrape.com  -> frases.csv  (frase, autor, tags)
//
// Uso: node 2-dois-sites-csv.js

const fs = require('fs');
const cheerio = require('cheerio');

// Baixa uma página e devolve o HTML já "parseado" pelo cheerio
async function baixar(url) {
  const html = await (await fetch(url)).text();
  return cheerio.load(html);
}

// Transforma uma lista de objetos em texto CSV (separado por ;)
function paraCSV(linhas) {
  const colunas = Object.keys(linhas[0]);
  const celula = (v) => '"' + String(v ?? '').replace(/"/g, '""') + '"';
  const corpo = linhas.map((l) => colunas.map((c) => celula(l[c])).join(';'));
  return [colunas.join(';'), ...corpo].join('\n');
}

// URL 1: livros (o site tem 50 páginas de 20 livros)
async function extrairLivros() {
  const livros = [];
  for (let pagina = 1; pagina <= 50; pagina++) {
    const $ = await baixar(`https://books.toscrape.com/catalogue/page-${pagina}.html`);
    // Cada livro fica dentro de <article class="product_pod">
    $('article.product_pod').each((i, el) => {
      livros.push({
        titulo: $(el).find('h3 a').attr('title'),
        preco: $(el).find('.price_color').text(),
        estoque: $(el).find('.availability').text().trim(),
        // a nota vem na classe, ex: "star-rating Three"
        nota: $(el).find('.star-rating').attr('class').replace('star-rating ', ''),
      });
    });
    console.log('livros: página', pagina);
  }
  return livros;
}

// URL 2: frases (segue o botão "Next" até a última página)
async function extrairFrases() {
  const frases = [];
  let url = 'https://quotes.toscrape.com/';
  while (url) {
    const $ = await baixar(url);
    $('.quote').each((i, el) => {
      frases.push({
        frase: $(el).find('.text').text(),
        autor: $(el).find('.author').text(),
        tags: $(el).find('.tag').map((j, t) => $(t).text()).get().join(', '),
      });
    });
    console.log('frases:', url);
    // Se existir o link "Next", vai para a próxima página; senão para
    const proxima = $('li.next a').attr('href');
    url = proxima ? new URL(proxima, url).href : null;
  }
  return frases;
}

async function main() {
  const livros = await extrairLivros();
  fs.writeFileSync('livros.csv', paraCSV(livros));
  console.log('livros.csv gerado com', livros.length, 'linhas');

  const frases = await extrairFrases();
  fs.writeFileSync('frases.csv', paraCSV(frases));
  console.log('frases.csv gerado com', frases.length, 'linhas');
}

main();
