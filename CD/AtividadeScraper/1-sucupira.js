// Mini Atividade 1 - Questão 1
// Extrai 500 programas de pós-graduação da Plataforma Sucupira (CAPES).
//
// O site https://sucupira.capes.gov.br/programas/detalhamento/2099 é feito em Vue,
// então o HTML vem vazio. Analisando o site (aba Rede do navegador) descobrimos
// que ele busca os dados numa API JSON:
//   - lista de programas:  /api/data/observatorio/ppg?page=0&size=100
//   - detalhe do programa: /api/data/observatorio/ppg/{id}
//
// Uso: node 1-sucupira.js   ->  gera sucupira.csv

const fs = require('fs');

const API = 'https://sucupira.capes.gov.br/api/data/observatorio/ppg';
const TOTAL = 500;

// Transforma uma lista de objetos em texto CSV (separado por ;)
function paraCSV(linhas) {
  const colunas = Object.keys(linhas[0]);
  // Coloca cada valor entre aspas e escapa aspas internas
  const celula = (v) => '"' + String(v ?? '').replace(/"/g, '""') + '"';
  const corpo = linhas.map((l) => colunas.map((c) => celula(l[c])).join(';'));
  return [colunas.join(';'), ...corpo].join('\n');
}

async function main() {
  // 1) Pega os IDs dos programas na listagem (5 páginas de 100 = 500)
  const ids = [];
  for (let pagina = 0; ids.length < TOTAL; pagina++) {
    const resp = await fetch(`${API}?page=${pagina}&size=100`);
    const dados = await resp.json();
    if (dados.content.length === 0) break; // acabaram os programas
    dados.content.forEach((p) => ids.push(p.idPrograma));
  }

  // 2) Para cada programa, busca o detalhe e monta a linha com os campos pedidos
  const cursos = [];
  for (const id of ids.slice(0, TOTAL)) {
    const p = await (await fetch(`${API}/${id}`)).json();
    const obs = p.observatorio || {};
    const lista = obs.cursos || [];

    // Um programa pode ter um curso de mestrado e/ou um de doutorado
    const mestrado = lista.find((c) => c.grau.includes('Mestrado')) || {};
    const doutorado = lista.find((c) => c.grau === 'Doutorado') || {};
    const universidade = (obs.instituicoes || []).find((i) => i.principal) || {};

    cursos.push({
      codigo: p.codigo,
      nome: p.nome,
      areaBasica: p.nomeAreaConhecimento,
      areaAvaliacao: p.nomeAreaAvaliacao,
      situacao: p.situacao,
      cidade: obs.endMunicipio,
      mestrado: mestrado.nome ? 'Sim' : 'Não',
      nota: p.conceito,
      situacaoMestrado: mestrado.situacao,
      doutorado: doutorado.nome ? 'Sim' : 'Não',
      codigoMestrado: mestrado.codigo,
      situacaoDoutorado: doutorado.situacao,
      notaMestrado: mestrado.conceito,
      codigoDoutorado: doutorado.codigo,
      notaDoutorado: doutorado.conceito,
      cep: obs.endCep,
      inicio: obs.anoInicio,
      universidade: universidade.nomeIes || p.siglaIes,
    });
    console.log(`${cursos.length}/${TOTAL} - ${p.codigo} ${p.nome}`);
  }

  // 3) Salva o resultado
  fs.writeFileSync('sucupira.csv', paraCSV(cursos));
  console.log('Arquivo sucupira.csv gerado com', cursos.length, 'cursos.');
}

main();
