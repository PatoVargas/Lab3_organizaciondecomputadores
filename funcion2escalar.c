#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
    	int i,N;
    	extern char *optarg;			//arreglo definido por getopt
  	int opcion, error = 0;			// variables para el switch (opcion que se elige) y para un posible error respectivamente
  	int esta_f = 0;		// iniciamos variables para detectar si estan o no f
  	char texto[100];
	char numero[10];
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
	float vector[N];

	for(i = 0; i < N;i++){     //para inicializar el arreglo
        	vector[i] = i + 1;
    	}

    	float suma = 0;
    	
	for(i = 0 ; i < N; i++){  //para realizar la operacion termino a termino
        	suma = suma+vector[i]*vector[i+1];  //se suma cada elemento del arreglo multiplicando por su siguiente elemento

    	}
    
	printf("%f\n",suma); //se imprime el resultado de suma
	return 0;
}
