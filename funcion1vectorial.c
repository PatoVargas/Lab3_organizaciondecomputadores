#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

__m128 funcionPow(__m128 base,__m128 exponente);

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


