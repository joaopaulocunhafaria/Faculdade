#include "geometria.h"
#define PI 3.1417

float quadrado_area(float lado){
  float area;
  area= lado*lado;
  return area;
}

float quadrado_perimetro(float lado){
  
  float perimetro;
  perimetro= 4*lado;
  return perimetro;
}

float retangulo_area(float base, float altura){
  float area; 
  area = base * altura;
  return area;
}

float retangulo_perimetro(float base, float altura){
  float perimetro;
  perimetro= 2*(base*altura);
  return perimetro;
}

float circulo_area(float raio){
  float area;
  area= PI*(raio*raio);
  return area; 
}

float circulo_perimetro(float raio){
  float area; 
  area= 2*PI*raio;
  return area;
}

float triangulo_area(float base, float altura){
  float area; 
  area= (base *altura)/2;
  return area;
}
float triangulo_perimetro(float base, float lado1, float lado2){
  float perimetro;
  perimetro= base+lado1+lado2;
  return perimetro;
}
float trapezio_area(float base, float basemaior, float altura){
  float area; 
  area=((base+basemaior)*altura/2);
  return area;
}
float trapezio_perimetro(float A, float B, float C, float D){//LADO 1, LADO 2, LADO 3, LADO 4
  float perimetro;
  perimetro=A+B+C+D;
  return perimetro;
}