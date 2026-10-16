// Atividade de extração de código dos cursos
// Robô que coleta todos os cursos da Escola Virtual da Fundação Bradesco
// (https://www.ev.org.br/cursos) e salva em cursos.json.
//
// Como o site funciona:
//   - A listagem é paginada: /cursos?pagina=1, /cursos?pagina=2, ...
//   - Cada curso tem sua página: /cursos/<nome-do-curso>
//     com título, área, duração, nível, descrição, conteúdo e detalhes.
//
// Uso: node 4-cursos-fundacao-bradesco.js

const fs = require('fs');
const cheerio = require('cheerio');

const SITE = 'https://www.ev.org.br';

// Baixa uma página e devolve o HTML já "parseado" pelo cheerio
async function baixar(url) {
  const html = await (await fetch(url)).text();
  return cheerio.load(html);
}

// 1) Percorre a listagem e junta os links de todos os cursos
async function pegarLinks() {
  const links = [];
  for (let pagina = 1; ; pagina++) {
    const $ = await baixar(`${SITE}/cursos?pagina=${pagina}`);
    const cards = $('a.m-card_link');
    if (cards.length === 0) break; // página vazia = acabou
    cards.each((i, el) => links.push(SITE + $(el).attr('href')));
    console.log(`Página ${pagina}: ${cards.length} cursos`);
  }
  return links;
}

// 2) Abre a página do curso e extrai as informações
async function extrairCurso(link) {
  const $ = await baixar(link);

  // "Duração 15h" e "Nível Avançado" ficam em <p class="m-info_desc">
  const info = {};
  $('.o-internal-desc_info .m-info_desc').each((i, el) => {
    const nome = $(el).contents().first().text().trim(); // "Duração" ou "Nível"
    info[nome] = $(el).find('strong').text().trim();
  });

  // Aba "Detalhes": pares título/descrição (Pré-requisitos, Idade mínima, Prazo)
  const detalhes = {};
  $('#meenie .o-tabs_txt').each((i, el) => {
    detalhes[$(el).find('.o-tabs_title').text().trim()] =
      $(el).find('.o-tabs_desc').text().trim();
  });

  return {
    titulo: $('h1.o-internal-desc_title').text().trim(),
    area: $('.m-head-title_title').first().text().trim(),
    descricao: $('.o-internal-desc_txt').text().trim(),
    cargaHoraria: info['Duração'] || '',
    nivel: info['Nível'] || '',
    link: link,
    // Aba "Conteúdo": cada <li> é um módulo
    conteudo: $('#eenie li').map((i, el) => $(el).text().trim()).get(),
    detalhes: detalhes,
  };
}

async function main() {
  const links = await pegarLinks();

  const cursos = [];
  for (const link of links) {
    const curso = await extrairCurso(link);
    cursos.push(curso);
    console.log(`${cursos.length}/${links.length} - ${curso.titulo}`);
  }

  // 3) Salva tudo em JSON (o null, 2 deixa o arquivo indentado)
  fs.writeFileSync('cursos.json', JSON.stringify(cursos, null, 2));
  console.log('cursos.json gerado com', cursos.length, 'cursos.');
}

main();
