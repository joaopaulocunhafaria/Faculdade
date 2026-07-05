# Instrucoes de Execucao

Este guia descreve os passos para configurar o ambiente e garantir a reprodutibilidade dos experimentos do projeto de Inteligencia Computacional.

## Pre-requisitos

- Python 3 instalado no sistema.

## Configuracao do Ambiente

Siga os comandos abaixo para preparar o ambiente virtual e instalar as dependencias necessarias.

1. Criar o ambiente virtual:

```bash
python3 -m venv venv
```

2. Ativar o ambiente virtual:

- Linux ou macOS:

```bash
source venv/bin/activate
```

- Windows:

```bash
venv\Scripts\activate
```

3. Atualizar o gerenciador de pacotes:

```bash
pip install --upgrade pip
```

4. Instalar as dependencias do projeto:

```bash
pip install -r requirements.txt
```

## Execucao dos Scripts

Para garantir a execucao correta da metodologia experimental proposta, os arquivos devem ser executados na seguinte ordem:

1. Executar a analise exploratoria:

```bash
python3 src/analise.py
```

2. Executar o pre-processamento e geracao da base tratada:

```bash
python3 src/processamento.py
```

3. Executar o treinamento e avaliacao dos modelos:

```bash
python3 src/experimento.py
```

O codigo esta organizado de modo a permitir a reproducao integral dos resultados apresentados.
