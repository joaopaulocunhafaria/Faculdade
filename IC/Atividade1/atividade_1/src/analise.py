import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
from ucimlrepo import fetch_ucirepo

def fetch_and_prepare_data():
    
    adult = fetch_ucirepo(id=2)
    
    X = adult.data.features
    y = adult.data.targets
    
    df = pd.concat([X, y], axis=1)
     
    df = df.replace('?', np.nan)
     
    df['income'] = df['income'].astype(str).str.strip().str.replace('.', '', regex=False)
    
    return df, adult.metadata, adult.variables

def characterize_problem(metadata, variables):
    print("\n--- 3.1.1 & 3.1.3 CARACTERIZAÇÃO DO PROBLEMA E DA BASE ---")
    print(f"Nome do Dataset: {metadata.name}")
    print(f"Descrição: {metadata.abstract}")
    print(f"Número de Instâncias: {metadata.num_instances}")
    print(f"Número de Atributos: {metadata.num_features}")
    print("\nInformações sobre as Variáveis:")
    print(variables[['name', 'type', 'description']].to_string())
    print("-" * 60)

def inform_task_type(df):
    target_col = 'income' 
    unique_values = df[target_col].unique()
    print(f"\n--- 3.1.2 TIPO DE TAREFA ---")
    print(f"Variável Alvo: {target_col}")
    print(f"Valores únicos unificados no alvo: {unique_values}")
    print("Tarefa: Classificação Binária (Prever se a renda >50K ou <=50K).")
    print("-" * 60)

def generate_descriptive_tables(df):
    print("\n--- 3.1.4 ANÁLISE EXPLORATÓRIA: TABELAS ---")
    print("Estatísticas Descritivas (Atributos Numéricos):")
    print(df.describe())
    print("-" * 60)

def plot_visualizations(df):
    sns.set_theme(style="whitegrid")
    sns.set_context("talk")
    
    order_income = ['<=50K', '>50K']

    plt.figure(figsize=(8, 5))
    sns.histplot(df['age'], bins=20, kde=True, color='teal')
    plt.title('Distribuição de Idade dos Indivíduos', fontsize=18)
    plt.xlabel('Idade', fontsize=15)
    plt.ylabel('Frequência', fontsize=15)
    plt.xticks(fontsize=13)
    plt.yticks(fontsize=13)
    plt.show()

    plt.figure(figsize=(6, 4))
    sns.countplot(data=df, x='income', palette='Set2', order=order_income)
    plt.title('Distribuição Unificada da Variável Alvo (Income)', fontsize=18)
    plt.xlabel('Categoria de Renda', fontsize=15)
    plt.ylabel('Contagem', fontsize=15)
    plt.xticks(fontsize=13)
    plt.yticks(fontsize=13)
    plt.show()

    plt.figure(figsize=(8, 5))
    sns.boxplot(data=df, x='income', y='hours-per-week', palette='Pastel1', order=order_income)
    plt.title('Horas Trabalhadas por Semana vs Renda (Sem Duplicidade)', fontsize=18)
    plt.xlabel('Categoria de Renda', fontsize=15)
    plt.ylabel('Horas por Semana', fontsize=15)
    plt.xticks(fontsize=13)
    plt.yticks(fontsize=13)
    plt.show()

def identify_data_quality(df):
    print("\n--- 3.1.5 PROBLEMAS DE QUALIDADE DE DADOS ---")
    missing = df.isnull().sum()
    print("Contagem de Valores Ausentes (NaN):")
    print(missing[missing > 0])
    


def main():
    df, metadata, variables = fetch_and_prepare_data()

    characterize_problem(metadata, variables)
    inform_task_type(df)

    generate_descriptive_tables(df)
    plot_visualizations(df)

    identify_data_quality(df)

if __name__ == "__main__":
    main()