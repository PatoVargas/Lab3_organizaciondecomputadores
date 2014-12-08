#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>


#include <stdio.h>


#define N 8

__m128 funcionPow(__m128 base,__m128 exponente);

int main(int argc, char *argv[])
{
    float vector[N] __attribute__((aligned(16)));

    // para inicializar el arreglo
    for(size_t i = 0; i < N; i++){
        vector[i] = i + 1;
    }

    for(size_t i = 0; i < N; i = i + 8){
        __m128 v = _mm_load_ps(&vector[i]);		//se cargan los 4 primeros datos del arreglo al vector v
        __m128 v2 = _mm_load_ps(&vector[i + 4]);	//se cargan los 4 siguientes datos del arreglo al vector v2
        __m128 v3;
        __m128 v4;
        __m128 v5;
        __m128 v6;
        __m128 acc;

        v5 = _mm_sqrt_ps(v);  //se saca la raiz de los elementos del vector v
        v6 = _mm_sqrt_ps(v2); //se saca la raiz de los elementos del vector v2
        v3 = funcionPow(v5,v);	//se llama a la funcionPow la cual se encarga de sacar la potencia entre v5 y v
        v4 = funcionPow(v6,v2);	//se llama a la funcionPow la cual se encarga de sacar la potencia entre v6 y v2

        acc = _mm_add_ps(acc,_mm_add_ps(v3,v4)); //se calcula la suma de los vectores v3 y v4 y ese resultado se suma con acc
  }

  _mm_store_ps(vector,acc); //se pasa el vector acc al array vector

  printf("%f\n", vector[0] + vector[1] + vector[2] + vector[3]); //se calcula el resultado

  return 0;
}

__m128 funcionPow(__m128 base,__m128 exponente){ //funcion que recibe el vector base y el vector exponente
    float base1[4]; //para guardar los datos del vector base
    float exponente1[4]; //para guardar los datos del vector exponente
    float resultado[4]; //para guardar los datos de los resultados de las potencias
    float acc = 1.0;
    __m128 fin;
    _mm_store_ps(exponente1,exponente); //se pasa el vector al array exponente1
    _mm_store_ps(base1,base); //se pasa el vector al array base1

    for(size_t i = 0;i<4;i ++){
        for(size_t j = 0;j<exponente1[i];j++){
            acc *= base1[i];
        }
        resultado[i] = acc; //se guarda en el array el resultado de la potencia
	acc = 1;
    }

    fin = _mm_load_ps(&resultado[0]); //para cargar los datos del array al vector
    return fin; //retorna el vector resultante
}




