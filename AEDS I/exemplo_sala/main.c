#include <stdio.h>

void impri_serie(int n)
{

    int aux = -3;
    for (int i = 0; i < n; i++)
    {

        if (i == 0)
        {
            printf("1, ");
        }
        else
        {

            printf("1/");
            printf("%d, ", aux);
             aux*=-1;
             aux+=2;
        }
    }
}

int main()
{ 

    printf("\n\n\n");
     impri_serie(6);
    printf("\n\n\n");

    return 0;
}