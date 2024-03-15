#include "minMax.hpp"
minMax::minMax() {}

void minMax::minMax1(int *vet, int n)
{

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

    cout << "Min: " << min << endl
         << "Max: " << max << endl;
    // calcular tempo de execucao
}

void minMax::minMax2(int *vet, int n)
{

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
    cout << "Min: " << min << endl
         << "Max: " << max << endl;

    // calcular tempo de execucao
}

void minMax::minMax3(int *vet, int n)
{

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
    cout << "Min: " << min << endl
         << "Max: " << max << endl;

    // calcular tempo de execucao
}

int *minMax::creat_random_array(int n)
{

    int *array;
    array = new int[n];

    // implementar metodo de randomizacao

    return array;
}

int *minMax::create_crescent_sort_array(int n)
{
    int *array;
    array = new int[n];

    // implementar metodo de ordenacao crescente

    return array;
}

int *minMax::create_decrescent_sort_array(int n)
{
    int *array;
    array = new int[n];

    // implementar metodo de ordenacao decrescente

    return array;
}

void minMax::manage_executions()
{
    int n = 0;
    int *array;
    for (int i = 1; i < 5; i++)
    {

        switch (i)
        {
        case 1:
            n = 1000;

            array = creat_random_array(n);

            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;

            array = create_crescent_sort_array(n);

            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;

            array = create_decrescent_sort_array(n);
            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;

            break;
        case 2:
            n = 10000;

            array = creat_random_array(n);

            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;

            array = create_crescent_sort_array(n);

            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;

            array = create_decrescent_sort_array(n);
            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;
            break;
        case 3:
            n = 100000;

            array = creat_random_array(n);

            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;

            array = create_crescent_sort_array(n);

            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;

            array = create_decrescent_sort_array(n);
            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;
            break;
        case 4:
            n = 500000;

            array = creat_random_array(n);

            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;

            array = create_crescent_sort_array(n);

            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;

            array = create_decrescent_sort_array(n);
            for (int i = 0; i < 3; i++)
            {
                minMax1(array, n);
                minMax2(array, n);
                minMax3(array, n);
            }
            delete[] array;
            break;

        default:
            break;
        }
    }
}