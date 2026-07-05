import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score

def load_processed_data(file_path):
    """Carrega a base já pré-processada na Fase 2."""
    df = pd.read_csv(file_path)
    X = df.drop(columns=['income'])
    y = df['income']
    return X, y

def split_data(X, y):
    """
    Define a estratégia de divisão dos dados.
    Utiliza Hold-out (80% treino / 20% teste) com estratificação.
    """
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, test_size=0.20, random_state=42, stratify=y
    )
    return X_train, X_test, y_train, y_test

def execute_experiments(X_train, X_test, y_train, y_test):
    """
    Seleciona e executa três algoritmos.
    """
    models = {
        "Random Forest": RandomForestClassifier(n_estimators=100, random_state=42),
        "Logistic Regression": LogisticRegression(max_iter=1000, penalty='l2'),
        "KNN (k=5)": KNeighborsClassifier(n_neighbors=5)
    }
    
    results = []
    
    for name, model in models.items():
        print(f"Treinando {name}...")
        model.fit(X_train, y_train)
        y_pred = model.predict(X_test)
        
        results.append({
            "Algoritmo": name,
            "Acurácia": accuracy_score(y_test, y_pred),
            "Precisão": precision_score(y_test, y_pred),
            "Recall": recall_score(y_test, y_pred),
            "F1-Score": f1_score(y_test, y_pred)
        })
        
    return pd.DataFrame(results)

def plot_comparison(results_df):
    """Reporta os resultados em gráficos (Requisito 3.3.5)."""
    df_melted = results_df.melt(id_vars="Algoritmo", var_name="Métrica", value_name="Valor")
    
    plt.figure(figsize=(12, 6))
    sns.barplot(data=df_melted, x="Métrica", y="Valor", hue="Algoritmo", palette="viridis")
    plt.title("Comparação de Desempenho entre Algoritmos")
    plt.ylim(0, 1.0)
    plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
    plt.tight_layout()
    plt.show()

def main():
    
    try:
        X, y = load_processed_data("adult_processed.csv")
    except FileNotFoundError:
        print("Erro: O arquivo 'adult_processed.csv' não foi encontrado. Execute a Fase 2 primeiro.")
        return

    X_train, X_test, y_train, y_test = split_data(X, y)
    print(f"Divisão concluída: {X_train.shape[0]} amostras de treino e {X_test.shape[0]} de teste.")

    results_df = execute_experiments(X_train, X_test, y_train, y_test)
    
    print(results_df.to_string(index=False))
    
    plot_comparison(results_df)

if __name__ == "__main__":
    main()