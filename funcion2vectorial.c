#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>

#include <stdio.h>


#define N 8


int main(int argc, char *argv[])
{
    float a[N] __attribute__((aligned(16)));

    // inicializar el arreglo
    for(size_t i = 0; i < N; i++){
        a[i] = i + 1;
    }

    __m128 acc;

    for(size_t i = 0; i < N; i = i + 8){
        __m128 v = _mm_load_ps(&a[i]);
        __m128 v2 = _mm_load_ps(&a[i + 4]);

        v = _mm_mul_ps(v,v+1);
	v2 = _mm_mul_ps(v2,v2+1);
        acc = _mm_add_ps(acc,_mm_add_ps(v,v2));
    }

    _mm_store_ps(a, acc);

    printf("%f\n", a[0] + a[1] + a[2] + a[3]);

    return 0;
}
