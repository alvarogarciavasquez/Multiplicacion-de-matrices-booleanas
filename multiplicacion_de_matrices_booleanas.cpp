/*
multiplicacion_de_matrices_booleanas.cpp
11/11/2021
Álvaro García Vásquez
Multiplicación de matrices booleanas
*/


#include <stdio.h>

#define bool_positive 1 //Defino el valor en caso de que en una suma booleana al menos exista un 1
#define bool_negative 0 //Defino el valor en caso de que en una suma booleana no existe ningun 1

//Define fuction print matrix


int main(void){
	int dimension=0, sum, value; //Declaro las variables |dimension: dimension de la matriz |sum: suma total al sumar las multiplicaciones de las matrices |value: valor boobleano que ira llenando la matriz.
	
	
	//Mensaje de inicio
	printf("Este programa calcula la multiplicacion de una matriz booleana por si misma.\n");
	printf("\nDimension de la matriz: ");
	scanf("%d",&dimension); //Se obtiene el valor de las dimensiones que tendrá la matriz (la matriz será cuadrada).
	printf("__________________________________________________________\n");
	printf("Ingresa cada valor booleano de la matriz: \n\n");
	
	//Definir matrices con las dimensiones dadas.
	int matriz[dimension][dimension]; //Matriz booleana dada por el usuario.
	int matriz_result[dimension][dimension]; //Matriz resultante.
	
	//Recibir valores de la matriz
	for(int i=0; i<dimension; i++){
		for(int j=0; j<dimension; j++){
			do{ //Este ciclo do-while no permite que el usuario ingrese otros valores que no sea 1 o 0.
				printf("Valor(%d,%d): ",i+1,j+1); //Pide el valor booleano en (n,m) posición.
				scanf("%d", &value); //Recibe el valor.
				matriz[i][j]=value; //Se añade el valor a la posición (n,m) de la matriz
				if(value>1){ 
					printf("Error, no escribiste un numero booleano, intenta de nuevo.\n"); //En caso de que el usuario ingrese un valor no booleano aparece este mensaje.
				}
			}while(value>1); //Si el valor dado es diferente a un numero booleano se repite el ciclo hasta que sea un numero booleano.
		}
	}
	printf("\n");
	
	//Operación
	for(int n=0; n<dimension; n++){
		for(int m=0; m<dimension; m++){
			sum=0;//Se reinicia el valor de la suma a 0 para cada iteración.
			for(int k=0; k<dimension; k++){
				sum += matriz[n][k]*matriz[k][m]; //Se hace la suma de todas las multiplicaciones en cada fila por columna.
			}
			if(sum > 0){ //En caso de que la suma sea 1 o mayor el valor resgistrado en la matriz resultante es 1
				matriz_result[n][m]= bool_positive;
			}
			else{ //En caso de que la suma sea 0 el valor resgistrado en la matriz resultante es 0
				matriz_result[n][m]= bool_negative;
			}
		}
	}
	
	//Imprimir matriz x matriz = matriz resultante.
	printf("\n__________________________________________________________\n");
	printf("Matriz(%dx%d) x Matriz(%dx%d) = Matriz Resultante(%dx%d)\n\n",dimension,dimension,dimension,dimension,dimension,dimension); //Se imprime el formato en el que apareceran las matrices y el resultado final.
	for(int n=0; n<dimension; n++){
		
		//Se imprime la matriz dada por el usuario
		for(int m=0; m<dimension; m++){
			//La forma en que imprime la matriz es solo para darle el estilo de que se vean encerradas con llaves.
			if(m==0){
				printf("| %d ",matriz[n][m]);
			}
			else if(m==dimension-1){
				printf("%d |",matriz[n][m]);
			}
			else{
				printf("%d ",matriz[n][m]);
			}
		}
		
		//Se imprime un espacio para la siguiente matriz, en caso de que sea la mitad de la matriz se imprime el signo de multiplicación
		if(n == dimension/2){
			printf("  x  ");
		}
		else{
			printf("     ");
		}
		
		//Se imprime la matriz dada por el usuario otra vez
		for(int m=0; m<dimension; m++){
			//La forma en que imprime la matriz es solo para darle el estilo de que se vean encerradas con llaves.
			if(m==0){
				printf("| %d ",matriz[n][m]);
			}
			else if(m==dimension-1){
				printf("%d |",matriz[n][m]);
			}
			else{
				printf("%d ",matriz[n][m]);
			}
		}
		
		//Se imprime un espacio para la siguiente matriz, en caso de que sea la mitad de la matriz se imprime el signo de igualdad.
		if(n == dimension/2){
			printf("  =  ");
		}
		else{
			printf("     ");
		}
		
		//Se imprime la matriz resultante.
		for(int m=0; m<dimension; m++){
			//La forma en que imprime la matriz es solo para darle el estilo de que se vean encerradas con llaves.
			if(m==0){
				printf("| %d ",matriz_result[n][m]);
			}
			else if(m==dimension-1){
				printf("%d |",matriz_result[n][m]);
			}
			else{
				printf("%d ",matriz_result[n][m]);
			}
		}
		printf("\n");
	}
	
	//Imprimir la matriz resultante | Se imprime de nuevo como resultado apartado y resultado final.
	printf("\n__________________________________________________________\n");
	printf("Matriz resultante:\n\n");
	for(int n=0; n<dimension; n++){
		for(int m=0; m<dimension; m++){
			//La forma en que imprime la matriz es solo para darle el estilo de que se vean encerradas con llaves.
			if(m==0){
				printf("| %d ",matriz_result[n][m]);
			}
			else if(m==dimension-1){
				printf("%d |",matriz_result[n][m]);
			}
			else{
				printf("%d ",matriz_result[n][m]);
			}
		}
		printf("\n");
	}
	printf("\n__________________________________________________________\n");
	
	return 0;
}
