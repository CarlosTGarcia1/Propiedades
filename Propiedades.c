#include <stdio.h>

//FUNCIÓN PARA IMPRIMIR LOS ARREGLOS...
void imprimir(int array[],int tam){
	printf(" {");
	for(int i=0;i<tam;i++){
		printf(" %d ", array[i]);	
	}
	printf("} ");
}

//FUNCIÓN PARA UNIÓN DE CADENAS...
void unir(int arrayA[],int tamA,int arrayB[],int tamB,int arrayC[]){
	for(int i=0;i<tamA;i++){
		arrayC[i]=arrayA[i]; 
		}
	for(int i=0;i<tamB;i++){
		arrayC[tamA+i]=arrayB[i];
		}	
	printf("A U B: {");
	for(int i=0; i<tamA+tamB;i++){
		printf(" %d ", arrayC[i]); 
		}
	printf("}");
}

//FUNCIÓN PARA INTERSECCIÓN DE CADENAS...
void interseccion(int arrayA[],int tamA,int arrayB[],int tamB){
	printf("A I B: {");
	for(int i=0;i<tamA;i++){
		for(int j=0;j<tamB;j++){
			if(arrayA[i]==arrayB[j]){
				printf(" %d ",arrayA[i]);
			}
		}
	}
	printf("}");
}

//FUNCIÓN PARA COMPLEMENTO...
void complemento(int arrayA[],int arrayB[],int tamA,int tamB){
    printf("Complemento: ");
    for(int i=0;i<tamB;i++){
        int com=0;
        for(int j=0;j<tamA;j++) {
            if(arrayB[i]==arrayA[j]){
                com=1;
            }
        }
        if (!com) {
            printf("%d ",arrayB[i]);
        }
    }
    printf("\n");
}

//FUNCIÓN DE DIFERENCIA...
void diferencia(int arrayA[], int arrayB[], int tamA, int tamB){
    printf("A - B: ");
    for(int i=0;i<tamA;i++){
        int dif=0;
        for(int j=0; j<tamB;j++) {
            if(arrayA[i]==arrayB[j]){
                dif=1;
            }
        }
        if(!dif){
            printf("%d ", arrayA[i]);
        }
    }
}

//FUNCION DE PRODUCTO CARTESIANO....
void productocartesiano(int arrayA[], int arrayB[], int tamA, int tamB) {
    int i, j;
    for (i = 0; i < tamA; i++) {
        for (j = 0; j < tamB; j++) {
            printf(" %d%d \n", arrayA[i], arrayB[j]);
        }
    }
    printf("\n");
}
	
//FUNCION DE CONCATENACION....
 void concatenacion(int arrayA[], int arrayB[], int tamA,int tamB) {
    int cont=0;
    for (int i=0; i<tamA && cont<3; i++) {
        for (int j=0; j<tamB && cont<3; j++) {
            printf(" %d%d \n", arrayA[i], arrayB[j]);
            cont++;
        } 
    }
    cont = 0;
    for (int i=0; i<tamA && cont<3; i++) {
        for (int j=0; j<tamB && cont<3; j++) {
            for (int k=j+1; k<tamB && cont<3; k++) {
                printf(" %d%d%d \n", arrayA[i], arrayB[j], arrayB[k]);
                cont++;
            }
        }
    }
}
 
int main(){ 
	int opcion;
	int arrayA[]={1,2,3,6};	
	int arrayB[]={3,4,5,7};	
	int tamA=sizeof(arrayA)/sizeof(arrayA[0]); 
	int tamB=sizeof(arrayB)/sizeof(arrayB[0]); 
	int arrayC[tamA+tamB]; 
	
	printf(" A-");
	imprimir(arrayA,tamA);
	printf("B-");
	imprimir(arrayB,tamB);
	do{
	printf("\n\n MENU \n 1.UNION\n 2.INTERSECCION\n 3.COMPLEMENTO\n 4.DIFERENCIA\n 5.PRODUCTO CARTESIANO\n 6.CONCATENACION\n 7.SALIR \n Opcion: ");
	scanf("%d", &opcion); 
	switch(opcion){  
		case 1: 
	    	imprimir(arrayA,tamA);
	        imprimir(arrayB,tamB);
	        printf("\n\n");
			unir(arrayA,tamA,arrayB,tamB,arrayC);
			break;
		case 2:
		    imprimir(arrayA,tamA);
        	imprimir(arrayB,tamB);
            printf("\n\n");
			interseccion(arrayA,tamA,arrayB,tamB);
			break;
		case 3: 
	    	imprimir(arrayA,tamA);
        	imprimir(arrayB,tamB);
        	printf("\n\n");
			complemento(arrayA, arrayB, tamA, tamB);
			break;  
		case 4: 
	     	imprimir(arrayA,tamA);
	        imprimir(arrayB,tamB);
	        printf("\n\n");
		    diferencia(arrayA, arrayB, tamA, tamB);
		    break;
	    case 5:
	        imprimir(arrayA,tamA);
        	imprimir(arrayB,tamB);
            printf("\n\n");
			productocartesiano(arrayA,arrayB,tamA,tamB);
			break;
		case 6:
		    imprimir(arrayA,tamA);
         	imprimir(arrayB,tamB);
         	printf("\n\n");
			concatenacion(arrayA,arrayB,tamA,tamB);
			break;
		case 7:
			printf("\nAdios");
			break;
		default:
			printf("opcion no valida.\n");
			break;
		   }
		}while(opcion!=8);
		
	return 0;
}
