#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

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

    	// inicializar el arreglo
    	for(size_t i = 0; i < N; i++){
    	    a[i] = i + 1;
    	}

    	__m128 acc;
    	
    	for(size_t i = 0; i < N; i = i + 8){
    	    __m128 v = _mm_load_ps(&a[i]);	//se cargan los 4 primeros datos del arreglo en el vector v
    	    __m128 v2 = _mm_load_ps(&a[i + 4]); //se cargan los siguientes 4 datos del arreglo en el vector v2
    	    __m128 v3;
	
    	    v = _mm_mul_ps(v,v+1); //se realiza la multiplcación entre el vector v y v+1
    	    v3 = v2+1;		//se le asigna a v3 el valor de v2+1
    	    v3[3] = 0;		//se le asigna a la ultima posición del vector v3 el valor de 0	
	    v2 = _mm_mul_ps(v2,v3);		//se realiza la multiplicacion entre el vector v2 y v3
            acc = _mm_add_ps(acc,_mm_add_ps(v,v2));	//se realiza la suma del vector v y v2
    	}

    	_mm_store_ps(a, acc);	//se pasan los resultados del vector acc al arreglo a
	
    	printf("%f\n", a[0] + a[1] + a[2] + a[3]);	//se imprime la suma de los valores de las 4 posiciones del arreglo a

    	return 0;
}
