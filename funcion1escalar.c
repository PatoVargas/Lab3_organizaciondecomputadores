#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

float calculo(int n,float *a);

int main(int argc, char *argv[])
{
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
    	float vector[N];		//vector de tamaño N
   	for(i = 0; i < N; i++){		//para inicializar el vector
        	vector[i] = i + 1;
    	}

    	printf("%f\n", calculo(N,vector)); //llamada a la funcion calculo
    	return 0;
}

float calculo(int n,float *a){ //funcion para calcular la sumatoria la cual recibe el tamaño del arreglo y el arreglo
	float aux = 0; 
	int i;	
	for(i =0 ; i< n; i++){
        	aux = aux + pow(sqrt(a[i]),a[i]);	//calcula el valor de aux, sumando aux con la potencia de la raiz de cada elemento elevado al mismo elemento

  	}
	return aux; //retorna el valor de aux
}

