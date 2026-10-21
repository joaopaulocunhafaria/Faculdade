// Carrinho miniatura - 2 rodas + 2 eixos (peças separadas)
// Encaixe tipo "clic": a ponta do eixo tem garras flexíveis com dente.
// As garras entram no furo da roda e o dente trava num canal interno.
// O eixo tem perfil em "D" (círculo com um corte plano) e é impresso
// deitado sobre essa face plana. O furo da roda tem o mesmo "D", o que
// também impede a roda de girar solta no eixo.
$fn = 100;

// ===================== RODA =====================
espessura_roda  = 10;   // 10 mm
raio_roda       = 20; // Diâmetro 45 mm
raio_cubo_roda  = 8.5;  // Cubo central reforçado (abriga o encaixe)
raio_curva_pneu = 5;    // Curvatura da banda: espessura_roda/2 = totalmente redondo (moto)

// ===================== EIXO =====================
comprimento_eixo = 80;   // Comprimento total (ponta a ponta), mm
raio_haste       = 3;    // Haste de 6.0 mm
// Corte plano: tira 1/3 de um dos raios da haste.
// A face plana fica a 2/3 do raio abaixo do centro e é comum a todo o eixo.
dist_corte = raio_haste - raio_haste / 3;

// ============ ENCAIXE CLIC DAS PONTAS ============
raio_base_enc   = 8;    // Disco base (fica fora da roda, serve de batente)
altura_base_enc = 2;
raio_cubo_enc   = 3;    // Cilindro central (limita a flexão das garras)
raio_int_garra  = 3.6;  // Garras em arco: o vão de 0.6 mm até o cilindro
raio_ext_garra  = 5;    // central é o espaço para a garra dobrar
angulo_garra    = 70;   // Abertura de cada garra (graus)
num_garras      = 2;
dente           = 0.6;  // Quanto o dente sai para fora da garra
altura_dente    = 2.5;  // Altura da ponta com rampa de entrada

// Folgas para impressão FDM; aumente se ficar justo demais.
folga        = 0.2;  // Folga radial entre garra e furo da roda
folga_axial  = 0.2;  // Folga em altura entre o dente e o canal da roda
margem_fundo = 1;    // Material da roda abaixo do canal (o dente fica escondido)

// Profundidade, a partir da face de entrada da roda, onde o dente trava no canal
prof_trava     = espessura_roda - margem_fundo - altura_dente;
altura_trava   = altura_base_enc + prof_trava; // onde o dente trava (coordenada do eixo)
altura_encaixe = altura_trava + altura_dente;
comprimento_haste = comprimento_eixo - 2 * altura_encaixe;

// Semiespaço acima da face plana (y >= -d). Intersectar com ele faz o corte em "D".
module lado_util(d, h = 200) {
    translate([-50, -d, -h/2]) cube([100, 100, h]);
}

// ===================== ENCAIXE (macho, na ponta do eixo) =====================
module garra() {
    rotate([0, 0, -angulo_garra/2])
        rotate_extrude(angle = angulo_garra)
            polygon([
                [raio_int_garra, 0],
                [raio_ext_garra, 0],
                [raio_ext_garra, altura_trava],                  // face de trava
                [raio_ext_garra + dente, altura_trava],
                [raio_ext_garra + dente, altura_trava + 0.5],
                [raio_ext_garra - 0.3, altura_encaixe],         // rampa de entrada
                [raio_int_garra, altura_encaixe]
            ]);
}

module encaixe() {
    cylinder(h = altura_base_enc, r = raio_base_enc);              // base / batente
    cylinder(h = altura_trava, r = raio_cubo_enc);                 // cilindro central
    // Garras nos lados (eixo x): com o eixo deitado elas dobram
    // paralelas à mesa, no sentido mais forte das camadas.
    for (i = [0 : num_garras - 1])
        rotate([0, 0, i * 360 / num_garras]) garra();
}

// ===================== RODA =====================
module roda_perfeita() {
    difference() {
        union() {
            difference() {
                // Pneu com banda de rodagem convexa (perfil de moto)
                rotate_extrude()
                    hull() {
                        translate([0, -espessura_roda/2])
                            square([raio_roda - raio_curva_pneu, espessura_roda]);
                        translate([raio_roda - raio_curva_pneu,  espessura_roda/2 - raio_curva_pneu])
                            circle(r = raio_curva_pneu);
                        translate([raio_roda - raio_curva_pneu, -(espessura_roda/2 - raio_curva_pneu)])
                            circle(r = raio_curva_pneu);
                    }
                // Rebaixos laterais
                translate([0, 0, espessura_roda/2])
                    cylinder(h = 4, r1 = raio_roda - 6, r2 = raio_cubo_roda, center = true);
                translate([0, 0, -espessura_roda/2])
                    cylinder(h = 4, r1 = raio_cubo_roda, r2 = raio_roda - 6, center = true);
            }
            // Cubo central com espessura total (aloja o encaixe)
            cylinder(h = espessura_roda, r = raio_cubo_roda, center = true);
        }
        // Furo e canal em "D": a parte reta do furo encosta na face plana
        // do cilindro central do eixo e trava a rotação.
        intersection() {
            union() {
                // Furo passante para as garras
                cylinder(h = espessura_roda + 2, r = raio_ext_garra + folga, center = true);
                // Canal de trava: anel mais largo dentro do furo onde o dente se aloja.
                // O teto do canal é a face que segura o dente (o "clic").
                translate([0, 0, espessura_roda/2 - prof_trava - altura_dente - folga_axial])
                    cylinder(h = altura_dente + 2*folga_axial, r = raio_ext_garra + dente + folga);
            }
            lado_util(dist_corte + folga, espessura_roda + 4);
        }
    }
}

// ===================== EIXO =====================
module eixo() {
    intersection() {
        union() {
            // ponta inferior (garras para baixo, apoiadas em z=0)
            translate([0, 0, altura_encaixe]) mirror([0, 0, 1]) encaixe();
            // haste
            translate([0, 0, altura_encaixe]) cylinder(h = comprimento_haste, r = raio_haste);
            // ponta superior (garras para cima)
            translate([0, 0, altura_encaixe + comprimento_haste]) encaixe();
        }
        // Corte plano comum à haste, ao batente e às garras
        translate([0, 0, comprimento_eixo/2]) lado_util(dist_corte, comprimento_eixo + 2);
    }
}

// ===================== CHASSI =====================
// Carroceria em cunha: bico baixo na frente, sobe até a traseira,
// com um cockpit retangular aberto em cima (como na imagem).
// Coordenadas locais: x = comprimento (bico em x=0), y = largura
// (centrada), z = altura (fundo em z=0, impresso apoiado no fundo).
comprimento_chassi = 160;
folga_lateral      = 1.5;  // Folga entre a lateral do chassi e o batente do eixo
largura_chassi     = comprimento_haste - 2 * folga_lateral;
largura_bico       = 30;   // Largura na ponta do bico
altura_bico        = 4;    // Altura na ponta do bico
x_fim_bico         = 30;   // Onde o bico em rampa encontra a carroceria
altura_dianteira   = 22;   // Altura no fim do bico
altura_traseira    = 34;   // Altura na traseira

folga_solo   = 8;                        // Altura do fundo do chassi ao chão
altura_eixo  = raio_roda - folga_solo;   // Centro dos eixos medido do fundo do chassi
x_eixo_diant = 40;
x_eixo_tras  = 140;

// Cockpit
x_cockpit       = 65;
comp_cockpit    = 55;
largura_cockpit = 35;
piso_cockpit    = 5;   // Espessura do fundo do cockpit

// Mancais de encaixe: as pontas do eixo já têm batentes, então o eixo não
// passa por um furo fechado. O mancal é um canal aberto por baixo; a entrada
// é mais estreita que o eixo (mesmo pela face plana, que tem
// raio_haste + dist_corte = 5 mm) e o eixo entra com um "clic".
// Rasgos ao lado do canal deixam as abas finas o bastante para flexionar.
folga_mancal     = 0.3;                              // Eixo gira livre no chassi
raio_mancal      = raio_haste + folga_mancal;
abertura_mancal  = raio_haste + dist_corte - 0.4;    // Entrada do canal (4.6 mm)
espessura_aba    = 1.5;                              // Aba flexível de cada lado
largura_rasgo    = 1;
// Só as pontas do mancal encostam no eixo: 5 mm em cada lateral do chassi.
// No miolo o furo é alargado para o eixo não tocar (menos atrito).
contato_mancal   = 5;
raio_alivio      = raio_mancal + 0.7;  // Deixa ~0.8 mm de parede até o rasgo

// Texto gravado na rampa do bico, legível para quem olha o carrinho de frente
texto_bico       = "CEFET-MG";
tamanho_texto    = 6;
fonte_texto      = "Liberation Sans:style=Bold";
prof_texto       = 0.8;              // Profundidade da gravação
x_texto          = 17;               // Centro do texto ao longo do bico
angulo_bico      = atan((altura_dianteira - altura_bico) / x_fim_bico);

module texto_frente() {
    z_rampa = altura_bico + (altura_dianteira - altura_bico) * x_texto / x_fim_bico;
    // Apoia o texto no plano da rampa; o "pé" das letras fica para o bico
    translate([x_texto, 0, z_rampa])
        rotate([0, -angulo_bico, 0])
            translate([0, 0, -prof_texto])
                linear_extrude(prof_texto + 1)
                    rotate([0, 0, -90])
                        text(texto_bico, size = tamanho_texto, font = fonte_texto,
                             halign = "center", valign = "center");
}

module fatia(x, h, w) {
    translate([x, -w/2, 0]) cube([0.01, w, h]);
}

module mancal(x) {
    translate([x, 0, altura_eixo]) {
        // Furo onde o eixo gira
        rotate([90, 0, 0]) cylinder(h = largura_chassi + 2, r = raio_mancal, center = true);
        // Alívio central: sem contato com o eixo fora das duas faixas laterais
        rotate([90, 0, 0])
            cylinder(h = largura_chassi - 2 * contato_mancal, r = raio_alivio, center = true);
        // Entrada estreita pelo fundo
        translate([-abertura_mancal/2, -largura_chassi/2 - 1, -altura_eixo - 1])
            cube([abertura_mancal, largura_chassi + 2, altura_eixo + 1]);
        // Rasgos de alívio que formam as abas
        for (s = [-1, 1])
            translate([s * (raio_mancal + espessura_aba + largura_rasgo/2) - largura_rasgo/2,
                       -largura_chassi/2 - 1, -altura_eixo - 1])
                cube([largura_rasgo, largura_chassi + 2, altura_eixo + 1 + raio_mancal]);
    }
}

module chassi() {
    difference() {
        // Corpo em cunha
        hull() {
            fatia(0,                      altura_bico,      largura_bico);
            fatia(x_fim_bico,             altura_dianteira, largura_chassi);
            fatia(comprimento_chassi - 0.01, altura_traseira, largura_chassi);
        }
        // Cockpit aberto em cima
        translate([x_cockpit, -largura_cockpit/2, piso_cockpit])
            cube([comp_cockpit, largura_cockpit, altura_traseira]);
        // Mancais dos eixos
        mancal(x_eixo_diant);
        mancal(x_eixo_tras);
        // Nome gravado no bico
        texto_frente();
    }
}

// Visualização do carrinho montado (só para conferência, não imprimir)
module montagem() {
    y_roda = comprimento_eixo/2 - altura_encaixe + altura_base_enc + espessura_roda/2;
    translate([0, 0, folga_solo]) chassi();
    for (x = [x_eixo_diant, x_eixo_tras]) {
        translate([x, -comprimento_eixo/2, raio_roda]) rotate([-90, 0, 0]) eixo();
        translate([x,  y_roda, raio_roda]) rotate([ 90, 0, 0]) roda_perfeita();
        translate([x, -y_roda, raio_roda]) rotate([-90, 0, 0]) roda_perfeita();
    }
}

// ===================== MONTAGEM (separados) =====================
espaco = 2 * raio_roda + 10;

// Chassi deitado sobre o fundo, ao lado das rodas
translate([0, -(raio_roda + largura_chassi/2 + 10), 0]) chassi();

// Para ver o carrinho montado, comente as peças acima e descomente:
// montagem();

// 2 rodas deitadas
for (x = [0, 1])
    translate([x, 0, espessura_roda/2]) roda_perfeita();

// 2 eixos deitados sobre a face plana, ao lado das rodas
/*for (j = [0, 0])
    translate([2 * espaco + j * (2 * raio_base_enc + 6), comprimento_eixo/2, dist_corte])
        rotate([90, 0, 0]) eixo();
*/