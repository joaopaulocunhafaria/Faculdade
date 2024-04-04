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
    int n = 0;
    double time;
    int *array;
    for (int i = 1; i < 5; i++)
    {

        switch (i)
        {
        case 1:
            n = 1000;

            array = creat_random_array(n);

            time = minMax1(array, n);
              r.write_results(1, n, "random", time, "results.txt");
            time = minMax2(array, n);
            //r.write_results(2, n, "random", time, "results.txt");
            time = minMax3(array, n);
            //r.write_results(3, n, "random", time, "results.txt");

            delete[] array;

            array = create_crescent_sort_array(n);

            time = minMax1(array, n);
              r.write_results(1, n, "crescent", time, "results.txt");
            time = minMax2(array, n);
             //r.write_results(2, n, "crescent", time, "results.txt");
            time = minMax3(array, n);
            //r.write_results(3, n, "crescent", time, "results.txt");

            delete[] array;

            array = create_decrescent_sort_array(n);

            time = minMax1(array, n);
              r.write_results(1, n, "decrescent", time, "results.txt");

            time = minMax2(array, n);
             // r.write_results(2, n, "decrescent", time, "results.txt");

            time = minMax3(array, n);
            //r.write_results(3, n, "decrescent", time, "results.txt");

            delete[] array;

            break;
        case 2:
            n = 10000;

            array = creat_random_array(n);

            time = minMax1(array, n);
              r.write_results(1, n, "random", time, "results.txt");
            time = minMax2(array, n);
             // r.write_results(2, n, "random", time, "results.txt");
            time = minMax3(array, n);
            //r.write_results(3, n, "random", time, "results.txt");

            delete[] array;

            array = create_crescent_sort_array(n);

            time = minMax1(array, n);
             r.write_results(1, n, "crescent", time, "results.txt");

            time = minMax2(array, n);
              // r.write_results(2, n, "crescent", time, "results.txt");

            time = minMax3(array, n);
            //r.write_results(3, n, "crescent", time, "results.txt");

            delete[] array;

            array = create_decrescent_sort_array(n);

            time = minMax1(array, n);
               r.write_results(1, n, "decrescent", time, "results.txt");
            time = minMax2(array, n);
             // r.write_results(2, n, "decrescent", time, "results.txt");
            time = minMax3(array, n);
            //r.write_results(3, n, "decrescent", time, "results.txt");

            delete[] array;
            break;
        case 3:
            n = 100000;

            array = creat_random_array(n);

            time = minMax1(array, n);
              r.write_results(1, n, "random", time, "results.txt");
            time = minMax2(array, n);
            //  r.write_results(2, n, "random", time, "results.txt");
            time = minMax3(array, n);
            //r.write_results(3, n, "random", time, "results.txt");

            delete[] array;

            array = create_crescent_sort_array(n);

            time = minMax1(array, n);
              r.write_results(1, n, "crescent", time, "results.txt");

            time = minMax2(array, n);
             // r.write_results(2, n, "crescent", time, "results.txt");

            time = minMax3(array, n);
            //r.write_results(3, n, "crescent", time, "results.txt");

            delete[] array;

            array = create_decrescent_sort_array(n);

            time = minMax1(array, n);
               r.write_results(1, n, "decrescent", time, "results.txt");
            time = minMax2(array, n);
             // r.write_results(2, n, "decrescent", time, "results.txt");
            time = minMax3(array, n);
            //r.write_results(3, n, "decrescent", time, "results.txt");

            delete[] array;
            break;
        case 4:
            n = 500000;

            array = creat_random_array(n);

            time = minMax1(array, n);
              r.write_results(1, n, "random", time, "results.txt");
            time = minMax2(array, n);
             //  r.write_results(2, n, "random", time, "results.txt");
            time = minMax3(array, n);
            //r.write_results(3, n, "random", time, "results.txt");

            delete[] array;

            array = create_crescent_sort_array(n);

            time = minMax1(array, n);
             r.write_results(1, n, "crescent", time, "results.txt");
            time = minMax2(array, n);
            //  r.write_results(2, n, "crescent", time, "results.txt");
            time = minMax3(array, n);
            //r.write_results(3, n, "crescent", time, "results.txt");

            delete[] array;

            array = create_decrescent_sort_array(n);

            time = minMax1(array, n);
               r.write_results(1, n, "decrescent", time, "results.txt");
            time = minMax2(array, n);
             // r.write_results(2, n, "decrescent", time, "results.txt");
            time = minMax3(array, n);
            //r.write_results(3, n, "decrescent", time, "results.txt");

            delete[] array;
            break;

        default:
            break;
        }
    }
}