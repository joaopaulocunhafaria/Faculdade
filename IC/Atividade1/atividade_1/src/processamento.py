import pandas as pd
import numpy as np
from ucimlrepo import fetch_ucirepo
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler, OneHotEncoder, LabelEncoder

def fetch_and_clean_base():
    """Reutiliza a lógica da Fase 1 para obter o DataFrame limpo."""
    adult = fetch_ucirepo(id=2)
    df = pd.concat([adult.data.features, adult.data.targets], axis=1)
    df = df.replace('?', np.nan)
    df['income'] = df['income'].astype(str).str.strip().str.replace('.', '', regex=False)
    return df

def handle_missing_values(df):
    """Trata valores ausentes usando a moda para colunas categóricas."""
    imputer = SimpleImputer(strategy='most_frequent')

    cols_with_nan = df.columns[df.isnull().any()].tolist()
    df[cols_with_nan] = imputer.fit_transform(df[cols_with_nan])
    return df

def apply_feature_selection(df):
    """
    Seleção de Atributos: Remove variáveis irrelevantes ou redundantes.
    Justificativa: 'fnlwgt' é um peso demográfico e não uma característica individual.
    'education' é redundante pois já existe 'education-num'.
    """
    df_selected = df.drop(columns=['fnlwgt', 'education'])
    return df_selected

def encode_categorical(df):
    """Aplica codificação para variáveis categóricas e alvo."""
    le = LabelEncoder()
    df['income'] = le.fit_transform(df['income'])
    
    nominal_cols = ['workclass', 'marital-status', 'occupation', 
                    'relationship', 'race', 'sex', 'native-country']
    
    df = pd.get_dummies(df, columns=nominal_cols, drop_first=True)
    return df

def scale_numeric_features(df):
    """Normaliza atributos numéricos usando StandardScaler."""
    scaler = StandardScaler()

    num_cols = ['age', 'education-num', 'capital-gain', 'capital-loss', 'hours-per-week']
    
    df[num_cols] = scaler.fit_transform(df[num_cols])
    return df

def main():
    print(" PRÉ-PROCESSAMENTO ")
    
    df = fetch_and_clean_base()
    
    df = handle_missing_values(df)
    print("Valores ausentes tratados .")
    
    df = apply_feature_selection(df)
    print(" Seleção de atributos concluída .")
    
    df = encode_categorical(df)
    print(" Codificação concluída .")
    
    df = scale_numeric_features(df)
    print(" Escalonamento concluído .")
    
    file_name = "adult_processed.csv"
    df.to_csv(file_name, index=False)
    
    print("\nDimensões da base final tratada:", df.shape)
    print("Primeiras linhas da base processada:")
    print(df.head())

if __name__ == "__main__":
    main()
    
    
    
# Explicação das Decisões Tomadas

#     Tratamento de Missing Values (Imputação): Optou-se pela imputação pela moda (valor mais frequente) para as colunas workclass, occupation e native-country. Como são variáveis categóricas, a moda preserva a natureza qualitativa do dado sem a necessidade de descartar instâncias preciosas.

# Seleção de Atributos: Foram removidas as colunas fnlwgt (peso final) e education. A fnlwgt é um controle estatístico do censo e não possui correlação direta com a renda do indivíduo; já a education é uma redundância direta da coluna education-num, que já provê a mesma informação de forma hierárquica.

# Codificação (Encoding): Utilizou-se One-Hot Encoding para as variáveis nominais. Para a variável alvo (income), aplicou-se um Label Encoder para transformá-la em 0 (<=50K) e 1 (>50K), tornando-a compatível com funções de custo de algoritmos de classificação.

# Escalonamento (Scaling): Utilizou-se o StandardScaler (Padronização) nos atributos numéricos. Essa técnica transforma os dados para terem média 0 e desvio padrão 1, o que é essencial para o bom desempenho de algoritmos sensíveis à escala, como SVM e KNN, que serão avaliados na próxima fase.