#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char igualdade(char a, char b)
{
    if (a == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int verificar_palindromo(char string[])
{

    char frase[100] = "";
    char frase2[100] = "";
    char matfrase[10][10];
    char aux;

    int i = 0;
    int j = 0;
    int k = 0;

    int tam1 = 0;
    int tam2 = 0;
    int tam3 = 0;
    int size = 0;
    int cont = 0;

    tam1 = strlen(string);
    // transformando a frase para caixa baixa
    for (i = 0; i < tam1; i++)
    {
        string[i] = tolower(string[i]);
    }

   

    // transformando em uma matriz
    i = 0;
    while (string[i] != '\0')
    {
        if (string[i] != ' ')
        {
            matfrase[j][k] = string[i];
            k++;
        }
        if (string[i] == ' ')
        {
            matfrase[j][k] = '\0';
            j++;
            k = 0;
        }
        i++;
    }
    matfrase[j][k] = '\0';

    size = j + 1;

    // concatenando sem espaços
    // essa string sera invertida
    for (i = 0; i < size; i++)
    {
        strcat(frase2, matfrase[i]);
    }

    tam2 = strlen(frase2);
    frase2[tam2] = '\0';

    // copiando sem espaços
    // essa string permaneçera igual, para ser comparado a string invertida no
    // final do programa

    for (i = 0; i < size; i++)
    {
        strcat(frase, matfrase[i]);
    }

    tam3 = strlen(frase);
    frase[tam3] = '\0';

    // invertendo string

    for (i = 0; i < (tam2 / 2); i++)
    {
        aux = frase2[i];
        frase2[i] = frase2[tam2 - i - 1];
        frase2[tam2 - i - 1] = aux;
    }

    
    for (i = 0; i < tam2; i++)
    {
        if (igualdade(frase[i], frase2[i]) == 1)
        {
            cont++;
        }
    }

    // comparando as frases
    if (cont == tam2)
    {
      return 1;
    }else{
        return 0;
    }
    
}

int main()
{
    char string[100];
    int tam1 = 0;
    int aux=0;

    printf("DIGITE A FRASE: ");
    fgets(string, 100, stdin);

    tam1 = strlen(string) - 1;

    string[tam1] = '\0';

aux=verificar_palindromo(string);
 

 if(aux==1){
    printf("E PALINDROMO");
 }else{printf("NAO E PALINDROMO");
 }
 return 0;
}