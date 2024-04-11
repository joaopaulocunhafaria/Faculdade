#include "minMax.hpp"
minMax::minMax()
{
    this->r = results();
}

double minMax::minMax1(int *vet, int n)
{

    auto start = std::chrono::high_resolution_clock::now();

    int min = vet[0];
    int max = vet[0];

    for (int i = 1; i < n; i++)
    {
        if (vet[i] > max)
        {
            max = vet[i];
        }
        if (vet[i] < min)
        {
            min = vet[i];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

double minMax::minMax2(int *vet, int n)
{

    auto start = std::chrono::high_resolution_clock::now();
    int min = vet[0];
    int max = vet[0];

    for (int i = 1; i < n; i++)
    {
        if (vet[i] > max)
        {
            max = vet[i];
        }
        else if (vet[i] < min)
        {
            min = vet[i];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    return duration.count();

    // calcular tempo de execucao
}

double minMax::minMax3(int *vet, int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    int Max = vet[0], Min = vet[1];
    int FimDoAnel;

    // Verifica se o tamanho do vetor é ímpar
    if (n % 2 != 0)
    {
        vet[n] = vet[n - 1]; // Copia o último elemento para a próxima posição
        FimDoAnel = n;
    }
    else
    {
        FimDoAnel = n - 1;
    }

    // Começa a verificar a partir do terceiro elemento
    for (int i = 2; i < FimDoAnel; i += 2)
    {
        if (vet[i] > vet[i + 1])
        {
            Max = std::max(Max, vet[i]);
            Min = std::min(Min, vet[i + 1]);
        }
        else
        {
            Max = std::max(Max, vet[i + 1]);
            Min = std::min(Min, vet[i]);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

int *minMax::creat_random_array(int n)
{

    int *array;
    array = new int[n];
    std::random_device rd;
    std::mt19937 gen(rd());

    int min = 0;
    int max = 1000;

    std::uniform_int_distribution<int> dist(min, max);

    for (int i = 0; i < n; i++)
    {
        array[i] = dist(gen);
    }

    return array;
}

void mergeCrescent(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortCrescent(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSortCrescent(arr, l, m);
    mergeSortCrescent(arr, m + 1, r);
    mergeCrescent(arr, l, m, r);
}

void mergeDecrescent(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        { // Alterado para ordem decrescente
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortDecrescent(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSortDecrescent(arr, l, m);
    mergeSortDecrescent(arr, m + 1, r);
    mergeDecrescent(arr, l, m, r);
}

int *minMax::create_crescent_sort_array(int n)
{
    int *array = creat_random_array(n);

    mergeSortCrescent(array, 0, n - 1);

    return array;
}

int *minMax::create_decrescent_sort_array(int n)
{
    int *array = creat_random_array(n);

    mergeSortDecrescent(array, 0, n - 1);

    return array;
}

void minMax::manage_executions()
{

    // Esta função é responsável por ordenar a execução de cada algoritmo,
    // com suas respectivas organizações e tamanhos de entrada. A lógica 
    // dela é um switch case que está dentro de um for, para que seja
    // executada cada quantidade de entrada de dados. Dentro de cada "case",
    // atribui-se um valor diferente para a variável 'n', que será o 
    // tamanho do vetor de testes. Em seguida, a variável "array" recebe
    // um valor retornado por funções que podem gerar arrays aleatórios,
    // crescentes ou decrescentes. Então, inicia-se o cálculo de tempo
    // dentro de um laço for que roda 10 vezes; a variável 'time' tem
    // seu valor somado ao tempo retornado pela função de teste em cada 
    // iteração. Ao final, a variável 'media' recebe o valor da soma dos
    // tempos dividido por 10 para calcular a média de cada algoritmo.
    // Finalmente, a média gerada é escrita em um arquivo utilizando
    // uma instância da classe results.hpp. Após isso, os valores de
    // tempo e média são zerados e o "array" tem seu valor deletado
    // para que se possa começar novamente no próximo caso.

    // Para realizar testes de forma personalizada, basta remover os
    // comentários do caso desejado, como foi feito na última execução.
    // A maneira como o código está disposto foi quando se realizou o
    // cálculo de tempo dos algoritmos com massas de dados crescentes.
    



    int n = 0;
    double time;
    int *array;
    float media = 0;
    for (int i = 1; i < 5; i++)
    {

        switch (i)
        {
        case 1:
        n = 1000;

        array = creat_random_array(n);

        // for (int i = 0; i < 10; i++)
        // {
        //     time += minMax1(array, n);
        // }
        // media = time / 10;

        // r.write_results(1, n, "random", media, "results.txt");

        // media = 0;
        // time = 0;

        delete[] array;

        array = create_crescent_sort_array(n);

        for (int i = 0; i < 10; i++)
        {
            time += minMax1(array, n);
        }
        media = time / 10;

        r.write_results(1, n, "crescent", media, "results.txt");

        media = 0;
        time = 0;

        delete[] array;

        array = create_decrescent_sort_array(n);

        // for (int i = 0; i < 10; i++)
        // {
        //     time += minMax1(array, n);
        // }
        // media = time / 10;

        // r.write_results(1, n, "decrescent", media, "results.txt");

        // media = 0;
        // time = 0;

        delete[] array;

        break;
    case 2:
        n = 10000;

        array = creat_random_array(n);

        // for (int i = 0; i < 10; i++)
        // {
        //     time += minMax1(array, n);
        // }
        // media = time / 10;

        // r.write_results(1, n, "random", media, "results.txt");

        // media = 0;
        // time = 0;

        delete[] array;

        array = create_crescent_sort_array(n);

        for (int i = 0; i < 10; i++)
        {
            time += minMax1(array, n);
        }
        media = time / 10;

        r.write_results(1, n, "crescent", media, "results.txt");

        media = 0;
        time = 0;

        delete[] array;

        array = create_decrescent_sort_array(n);

        // for (int i = 0; i < 10; i++)
        // {
        //     time += minMax1(array, n);
        // }
        // media = time / 10;

        // r.write_results(1, n, "decrescent", media, "results.txt");

        // media = 0;
        // time = 0;

        delete[] array;
        break;
    case 3:
        n = 100000;

        array = creat_random_array(n);

        // for (int i = 0; i < 10; i++)
        // {
        //     time += minMax1(array, n);
        // }
        // media = time / 10;

        // r.write_results(1, n, "random", media, "results.txt");

        // media = 0;
        // time = 0;

        delete[] array;

        array = create_crescent_sort_array(n);

        for (int i = 0; i < 10; i++)
        {
            time += minMax1(array, n);
        }
        media = time / 10;

        r.write_results(1, n, "crescent", media, "results.txt");

        media = 0;
        time = 0;

        delete[] array;

        array = create_decrescent_sort_array(n);

        // for (int i = 0; i < 10; i++)
        // {
        //     time += minMax1(array, n);
        // }
        // media = time / 10;

        // r.write_results(1, n, "decrescent", media, "results.txt");

        // media = 0;

        // time = 0;

        delete[] array;
        break;
    case 4:
        n = 500000;

        array = creat_random_array(n);

        // for (int i = 0; i < 10; i++)
        // {
        //     time += minMax1(array, n);
        // }
        // media = time / 10;

        // r.write_results(1, n, "random", media, "results.txt");

        // media = 0;
        // time = 0;

        delete[] array;

        array = create_crescent_sort_array(n);

        for (int i = 0; i < 10; i++)
        {
            time += minMax1(array, n);
        }
        media = time / 10;

        r.write_results(1, n, "crescent", media, "results.txt");

        media = 0;
        time = 0;

        delete[] array;

        array = create_decrescent_sort_array(n);

        // for (int i = 0; i < 10; i++)
        // {
        //     time += minMax1(array, n);
        // }
        // media = time / 10;

        // r.write_results(1, n, "decrescent", media, "results.txt");

        // media = 0;
        // time = 0;

        delete[] array;
        break;

    default:
        break;
    }
    }
    }