# Guia de Configuração do Ambiente Virtual

Este projeto utiliza um ambiente virtual (virtual environment) do Python para gerenciar as dependências localmente, mantendo-as isoladas da instalação global do Python do sistema.

## 1. Criando o Ambiente Virtual
Para criar um ambiente virtual, abra o terminal no diretório raiz do projeto e execute:
```bash
python3 -m venv venv
```

## 2. Ativando o Ambiente Virtual
Antes de instalar as dependências ou executar scripts, você precisa ativar o ambiente virtual:
- **Linux/macOS:**
  ```bash
  source venv/bin/activate
  ```
- **Windows (Prompt de Comando):**
  ```cmd
  venv\Scripts\activate.bat
  ```
- **Windows (PowerShell):**
  ```powershell
  venv\Scripts\Activate.ps1
  ```

*(Você saberá que ele está ativado quando o prompt do seu terminal estiver prefixado com `(venv)`).*

## 3. Instalando as Dependências
Uma vez ativado, instale os pacotes necessários utilizando o arquivo `requirements.txt`:
```bash
pip install -r requirements.txt
```

## 4. Desativando
Quando terminar de trabalhar no projeto, você pode sair do ambiente virtual simplesmente digitando:
```bash
deactivate
```

## Adicionando Novas Dependências
Sempre que adicionar uma nova biblioteca externa ao projeto, lembre-se de incluí-la no arquivo `requirements.txt` com sua versão específica (por exemplo, `pacote==1.2.3`). Você pode usar `pip freeze > requirements.txt` para capturar o estado atual, mas certifique-se de incluir apenas os pacotes principais (top-level) necessários.
