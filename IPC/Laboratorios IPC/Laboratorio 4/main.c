#include "geometria.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#define lado 4
#define base 4
#define altura 5
#define raio 4
#define lado1 10
#define lado2 10
#define basemaior 10
#define A 5
#define B 5
#define C 8
#define D 6

int main(void) {

  printf("A AREA DO QUADRADO DE LADO %d É %f",lado, quadrado_area(lado));
  printf("\n\nO PERIMETRO DO QUADRADO DE LADO %d É: %f",lado, quadrado_perimetro(lado));
  printf("\n\nA AREA DE UM  CIRCULO  DE RAIO %d É: %f",raio,  circulo_area(raio));
  printf("\n\nO PERIMETRO DE UM CIRCULO DE RAIO %d, É: %f", raio,
         circulo_perimetro(raio));
  printf("\n\nUM RETANGULO DE LADO %d E BASE %d TEM AREA DE %f", altura, base,
         retangulo_area(base, altura));
  printf("\n\nUM RETANGULO DE LADO %d E BASE %d TEM PERIMETRO DE %f", altura,
         base, retangulo_perimetro(base, altura));
  printf("\n\nUM TRIANGULO COM A BASE %d E ALTURA  %d TEM AREA   %f",
         altura, base, triangulo_area(base, altura));
  printf("\n\nUM TRIANGULO COM LADO %d, LADO  %d E BASE %d, TEM "
         "PERIMETRO DE  %f",
         base, lado1, lado2, triangulo_perimetro(base, lado1, lado2));
printf("\n\nUM TRAPEZIO DE BASE %d, %d E ALTURA %d TEM AREA DE: %f",base, basemaior,altura, trapezio_area(base, basemaior, altura)); 
  printf("\n\nUM TRAPEZIO COM CADA UM DE SEUS LADOS DE VALOR %d, %d, %d, %d TEM PERIMETRO DE %f ",A, B,C, D, trapezio_perimetro(A, B,C, D)); 
  
  
  return 0;
}
