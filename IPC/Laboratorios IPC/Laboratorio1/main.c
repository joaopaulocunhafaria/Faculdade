#include <stdio.h>

int exponencial(int base, int expoente)
{

    if (expoente == 0)
    {
        return 1;
    }
    else if (expoente == 1)
    {
        return base;
    }
    else
    {

        int resultado = base;

        for (int i = 1; i < expoente; i++)
        {
            resultado = resultado * base;
        }
        return resultado;
    }
}

int fatorial(int base)
{

    if (base == 0)
    {
        return 1;
    }
    else if (base == 1)
    {
        return 1;
    }
    else
    {
        int resultado = base;

        for (int i = base-1; i  > 0; i--)
        {
            resultado *= i;
        }
        return resultado;
   }
}

int main()
{
     for (int i = 0; i < 100000000; i++)
     {
        printf("ok\n");
     }
     
    return 0;
}