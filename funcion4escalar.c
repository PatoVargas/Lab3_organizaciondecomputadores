#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

//7266599

int calcular(int n,char *a);

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
	
	char a[N];

    	for(i = 0; i < N; i++){
        	a[i] = i % 120 + 1;
    	}

    	printf("%d\n", calcular(N,a));
    
    	return 0;
}

int calcular(int n, char *a){
	int i;    	
	int acc = 0;

    	for(i = 0; i < n - 1; i++){
       		char tmp = a[i] ^ a[i + 1];
       		acc = acc + tmp;
    	}

    	return acc;
}

