#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>

#include <stdio.h>


#define N 8*100

int main(int argc, char *argv[])
{
    float a[N] __attribute__((aligned(16)));
    float b[N] __attribute__((aligned(16)));
    
    // inicializar el arreglo
    for(size_t i = 0; i < N; i++){
        a[i] = i + 1;
    }
    
    for(size_t i = 0; i < N; i++){
        b[i] = i + 1;
    }
    
    __m128 acc;
    __m128 v3;
    
    for(size_t i = 0; i < N; i = i + 4){
        __m128 v = _mm_load_ps(&a[i]);
        __m128 v2 = _mm_load_ps(&b[i]);
        v5[0] = 2;
        v5[1] = 2;
        v5[2] = 2;
        v5[3] = 2;
        
        v2 = _mm_sqrt_ps(v2);
        v3 = _mm_add_ps(v2,v5);
        
        acc = _mm_add_ps(acc,v);
        acc = _mm_div_ps(acc,v3);
        
        }
        
        for(size_t i = 0; i < N; i = i + 4){
        __m128 v = _mm_load_ps(&a[i]);
        v4 = _mm_mul_ps(v,v);
        acc2 = _mm_add_ps(acc2,_mm_sub_ps(v4,acc));
    }

    _mm_store_ps(a,acc2);

    printf("%f\n", a[0] + a[1] + a[2] + a[3]);




}
        
