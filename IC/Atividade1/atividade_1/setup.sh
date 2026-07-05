#!/bin/bash
echo "Configurando o ambiente para Inteligência Computacional..."
python3 -m venv venv
source venv/bin/activate
pip install --upgrade pip
pip install -r requirements.txt
echo "Tudo pronto! Para rodar os scripts, use: source venv/bin/activate"