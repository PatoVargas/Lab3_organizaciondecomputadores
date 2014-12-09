#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


//float calculo(float *a);

int main(int argc, char *argv[])
{
	int i,N;
	extern char *optarg;			//arreglo definido por getopt
  	int opcion, error = 0;			// variables para el switch (opcion que se elige) y para un posible error respectivamente
  	int esta_f = 0;		// iniciamos variables para detectar si estan o no f
  	char texto[100];
	char numero[10];
	while((opcion = getopt(argc, argv, "f:"))!=-1)	
  		switch (opcion){
  			case 'f':
  				esta_f = 1;	//registramos que había una f
				strcpy (texto,optarg);  				
				break;
  			case '?':
  				error = 1;	//marcamos que hubo un error en la sintaxis de entrada
  				break;
  		}
  	if (esta_f == 0){			
  		printf("falta ingresar f \n");
  	}
  	if (error == 1){			// si encontramos algun error en la sintaxis
  		printf("error de sintaxis");
  	}
	
	FILE *archivo;
	archivo = fopen(texto,"r");
	
	if (archivo == NULL){
 
		printf("\nError de apertura del archivo. \n\n");
        }else{
	    while (feof(archivo) == 0)
	    {	
		fscanf(archivo,"%s",numero);
		
	    }
        }

	N = atoi(numero);

	float a[N] __attribute__((aligned(16)));
	float b[N] __attribute__((aligned(16)));
	float c[N] __attribute__((aligned(16)));

	    // inicializar el arreglo
	    for(size_t i = 0; i < N; i++){
		a[i] = i + 1;
	    }

	    for(size_t i = 0; i < N; i++){
		b[i] = i + 1;
	    }
	
		for(size_t i = 0; i < N; i++){
		c[i] = 2;
	    }

    	__m128 acc;
    	__m128 acc2;
	__m128 acc3;
	__m128 acc4;
	__m128 acc5;
    	__m128 v3;
    	__m128 v4;
    	__m128 v5;
	__m128 v6;
	__m128 v7;
	__m128 v8;
	__m128 v9;
	__m128 v10;
	__m128 v11;
	__m128 v12;
	__m128 otro;
	


    for(size_t i = 0; i < N; i = i + 8){
        __m128 v = _mm_load_ps(&a[i]);
	__m128 v2 = _mm_load_ps(&a[i+4]);
        __m128 v3 = _mm_load_ps(&b[i]);
        __m128 v4 = _mm_load_ps(&b[i+4]);
	otro = _mm_load_ps(&c[i]);

        v3 = _mm_sqrt_ps(v3);
	v4 = _mm_sqrt_ps(v4);

        v5 = _mm_div_ps(v,otro);
	v6 = _mm_div_ps(v2,otro);
	
	v7 = _mm_add_ps(v5,v3);
	v8 = _mm_add_ps(v6,v4);

        acc = _mm_add_ps(acc,v7);
	acc3 = _mm_add_ps(acc3,v8);

    }


    for(size_t i = 0; i < N; i = i + 8){
        __m128 v9 = _mm_load_ps(&a[i]);
	__m128 v10 = _mm_load_ps(&a[i+4]);
        v11 = _mm_mul_ps(v9,v9);
	v12 = _mm_mul_ps(v10,v10);
        
	acc2 = _mm_sub_ps(_mm_add_ps(acc2,v11),acc);
	acc4 = _mm_sub_ps(_mm_add_ps(acc4,v11),acc3);
	acc5 = _mm_add_ps(acc5,_mm_add_ps(acc2,acc4));
    }

    _mm_store_ps(a,acc5);

    printf("%f\n", a[0] + a[1] + a[2] + a[3]);

  }

