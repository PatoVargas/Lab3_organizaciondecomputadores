#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

float calcular(int n,float *a, float *b);

int main(int argc, char *argv[]){
    	int i,N;
	extern char *optarg;			//arreglo definido por getopt
  	int opcion, error = 0;			// variables para el switch (opcion que se elige) y para un posible error respectivamente
  	int esta_f = 0;		// iniciamos variables para detectar si estan o no f
  	char texto[100];
	char numero[100];
	while((opcion = getopt(argc, argv, "f:"))!=-1)	// while para recibir los argumento del argv
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
	float a[N];
    	float b[N];	
	printf("N = %i\n",N);

    	for(i = 0; i < N; i++){ //se inicializa el arreglo a
        	a[i] = i + 1;
    	}

    	for(i = 0; i < N; i++){	//se inicializa el arreglo b
        	b[i] = i + 1;
    	}

    	printf("%f\n", calcular(N, a, b)); //imprime el resultado final
    	return 0;
}

float calcular(int n,float *a, float *b){  //funcion calcular que recibe el tamaño del arreglo, y los arreglos a y b
	int i;
    	float acc = 0;
    	float acc2 = 0;

    	for(i = 0; i < n; i++){				
        	acc = acc + a[i] / 2 + sqrt(b[i]);//calcula el valor de acc, sumando los elementos del arreglo a divido en 2,
        					  //más la raiz cuadrada de los elementos del arreglo b
    	}

    	for(i = 0; i < n; i++){
        	acc2 = acc2 + pow(a[i], 2) - acc;//calcula el valor de acc2, sumando los elementos del arreglo a elevado a 2,
        					 //menos el resultado de acc obtenido en la primera sumatoria
    	}

    	return acc2;		//retorna el resultado de acc2
}
