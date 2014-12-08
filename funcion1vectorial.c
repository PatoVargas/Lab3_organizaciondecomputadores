#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>


#include <stdio.h>


#define N 8

__m128 funcionPow(__m128 base,__m128 exponente);

int main(int argc, char *argv[])
{
    float vector[N] __attribute__((aligned(16)));

    // inicializar el arreglo
    for(size_t i = 0; i < N; i++){
        vector[i] = i + 1;
    }

    __m128 acc;

    for(size_t i = 0; i < N; i = i + 8){
        __m128 v = _mm_load_ps(&vector[i]);
        __m128 v2 = _mm_load_ps(&vector[i + 4]);
        __m128 v3;
        __m128 v4;
        __m128 v5;
        __m128 v6;

        v5 = _mm_sqrt_ps(v);
        v6 = _mm_sqrt_ps(v2);
        v3 = funcionPow(v5,v);
        v4 = funcionPow(v6,v2);

        acc = _mm_add_ps(acc,_mm_add_ps(v3,v4));
  }

  _mm_store_ps(vector,acc);

  printf("%f\n", vector[0] + vector[1] + vector[2] + vector[3]);

  return 0;
}

__m128 funcionPow(__m128 base,__m128 exponente){
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

    fin = _mm_load_ps(&resultado[0]);
    return fin;
}




