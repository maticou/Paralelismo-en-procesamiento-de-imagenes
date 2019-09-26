#include <stdio.h>
#include <string.h>
#include <time.h>

int proceso;
int algoritmo;
int estructura;
double time_spent2;
clock_t begin2;
char nombreImagen[50];
FILE *arch,*sali;
unsigned char c,c1,c2;
int fila, colu, i, j, gris;
unsigned char dibu[2046][2046],otra[2046][2046];


void menu(){
	int opcion = 0;
	proceso = 0;
	printf("\nBienvenido al procesador de imagenes\n");
	printf("Selecciones una de las siguientes opciones:\n");
	printf("\n1.- Aplicar dilatacion\n");
	printf("2.- Aplicar erosion\n");
	printf("3.- Salir\n");
	scanf("%d", &opcion);
	
	switch(opcion){
		case 1: proceso = 1;
				menu2("dilatacion");				
				break;
		case 2: proceso = 2;
				menu2("erosion");								
				break;
		case 3: printf("Bye\n");				
				exit(0);
				break;

	}
}

void menu2(char nombre[15]){
	int opcion = 0;	
	algoritmo = 0;
	printf("\nElija tipo de algoritmo para la %s", nombre);
	printf(":\n");
	printf("\n1.- Secuencial\n");
	printf("2.- Paralela\n");
	printf("3.- Volver atras\n");
	scanf("%d", &opcion);
	
	switch(opcion){
		case 1: algoritmo = 1;
				menu3(nombre, "secuencial", proceso, algoritmo);				
				break;
		case 2: algoritmo = 2;
				menu3(nombre, "paralela", proceso, algoritmo);								
				break;
		case 3: menu();
				break;

	}
}

void menu3(char nombre[15], char tipo[15], int proceso, int algoritmo){
	int opcion = 0;	
	estructura = 0;
	printf("\nElija elemento estructurante para la %s %s", nombre, tipo);
	printf(":\n");
	printf("\n1.- Tipo T\n");
	printf("2.- Tipo L\n");
	printf("3.- Tipo |\n");
	printf("4.- Tipo -\n");
	printf("5.- Tipo X\n");
	printf("6.- Tipo +\n");
	printf("7.- Volver atras\n");
	scanf("%d", &opcion);
	
	switch(opcion){
		case 1: estructura = 1;		
				printf("Resumen es proceso %d algoritmo %d estructura %d\n", proceso, algoritmo, estructura);
				if(proceso == 1 && algoritmo == 1){
					dilatacionSecuencialT();
				}	
				else if(proceso == 1 && algoritmo == 2){
					dilatacionParalelaT();
				}
				else if(proceso == 2 && algoritmo == 1){
					erosionSecuencialT();
				}
				else if(proceso == 2 && algoritmo == 2){
					erosionParalelaT();
				}
				break;
		case 2: estructura = 2;
				printf("Resumen es proceso %d algoritmo %d estructura %d\n", proceso, algoritmo, estructura);		
				if(proceso == 1 && algoritmo == 1){
					dilatacionSecuencialL();
				}	
				else if(proceso == 1 && algoritmo == 2){
					dilatacionParalelaL();
				}
				else if(proceso == 2 && algoritmo == 1){
					erosionSecuencialL();
				}
				else if(proceso == 2 && algoritmo == 2){
					erosionParalelaL();
				}
				break;
		case 3: estructura = 3;
				printf("Resumen es proceso %d algoritmo %d estructura %d\n", proceso, algoritmo, estructura);		
				if(proceso == 1 && algoritmo == 1){
					dilatacionSecuencialVertical();
				}	
				else if(proceso == 1 && algoritmo == 2){
					dilatacionParalelaVertical();
				}
				else if(proceso == 2 && algoritmo == 1){
					erosionSecuencialVertical();
				}
				else if(proceso == 2 && algoritmo == 2){
					erosionParalelaVertical();
				}
				break;
		case 4: estructura = 4;
				printf("Resumen es proceso %d algoritmo %d estructura %d\n", proceso, algoritmo, estructura);		
				if(proceso == 1 && algoritmo == 1){
					dilatacionSecuencialHorizontal();
				}	
				else if(proceso == 1 && algoritmo == 2){
					dilatacionParalelaHorizontal();
				}
				else if(proceso == 2 && algoritmo == 1){
					erosionSecuencialHorizontal();
				}
				else if(proceso == 2 && algoritmo == 2){
					erosionParalelaHorizontal();
				}
				break;
		case 5: estructura = 5;
				printf("Resumen es proceso %d algoritmo %d estructura %d\n", proceso, algoritmo, estructura);		
				if(proceso == 1 && algoritmo == 1){
					dilatacionSecuencialX();
				}	
				else if(proceso == 1 && algoritmo == 2){
					dilatacionParalelaX();
				}
				else if(proceso == 2 && algoritmo == 1){
					erosionSecuencialX();
				}
				else if(proceso == 2 && algoritmo == 2){
					erosionParalelaX();
				}
				break;	
		case 6: estructura = 6;
				printf("Resumen es proceso %d algoritmo %d estructura %d\n", proceso, algoritmo, estructura);		
				if(proceso == 1 && algoritmo == 1){
					dilatacionSecuencialSuma();
				}	
				else if(proceso == 1 && algoritmo == 2){
					dilatacionParalelaSuma();
				}
				else if(proceso == 2 && algoritmo == 1){
					erosionSecuencialSuma();
				}
				else if(proceso == 2 && algoritmo == 2){
					erosionParalelaSuma();
				}
				break;			
		case 7: menu2(nombre);
				break;

	}
}


void abrirArchivo(){
	printf("Escriba el nombre de la imagen sin la extencion .pgm:\n");	
	scanf("%s", &nombreImagen);
	char imageName[50];
	strcpy(imageName, nombreImagen);

	arch=fopen(strcat(imageName, ".pgm"),"rb");
	c1=fgetc(arch);
	c2=fgetc(arch);
    if (c1!='P' || c2!='5')
    {
		printf("\nFormato no corresponde a una Imagen\n");
		exit (0);
    }
	c=fgetc(arch);
    c=fgetc(arch);
	while (c!='\n')
		c=fgetc(arch);
	fscanf(arch,"%d",&colu);
	fscanf(arch,"%d",&fila);
	fscanf(arch,"%d",&gris);
	
	printf("\n%c%c",c1,c2);
	printf("\nfila : %d",fila);
	printf("\ncolu : %d",colu);
	printf("\ngris : %d",gris);

	for(i=0; i<fila; i++){
		for(j=0; j<colu; j++)
		{
			c=fgetc(arch);
			dibu[i][j] = c;
			otra[i][j] = c;
		}
	}
}

void cerrarArchivo(char nombreArchivo[50]){
	sali=fopen(nombreArchivo,"wb");
	fprintf(sali,"P5\n");
	fprintf(sali,"# Creado por Matias Parra y Manuel Gonzalez. (2019)\n");
	fprintf(sali,"%d %d\n",colu,fila);
    fprintf(sali,"%d\n",gris);
	for(i=0; i<fila; i++){
		for(j=0; j<colu; j++)
		{
			fprintf(sali,"%c",otra[i][j]);
		}
	}
	clock_t end2 = clock();
	time_spent2 += (double)(end2 - begin2)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo completo (abrir, procesar y cerrar imagen) fue %f segundos\n", time_spent2);
	sleep(1);
}

//Tipo T
void dilatacionSecuencialT(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();

	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int max =0;
			int k[3];
			k[0] = dibu[i][j+1];
			k[1] = dibu[i][j];
			k[2] = dibu[i+1][j];
			int l;
			for(l=0;l<3;l++){
				if(k[l]>max){
					max = k[l];
				}
			}
			otra[i][j]=max;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la dilatacion secuencual tipo T fue %f segundos\n", time_spent);

	cerrarArchivo(strcat(nombreImagen, "_dilatacionSecuencialT.pgm"));
}

void dilatacionParalelaT(){
	printf("Tecnica no implementada\n");
}

void erosionSecuencialT(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();

	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int min =255;
			int k[3];
			k[0] = dibu[i][j+1];
			k[1] = dibu[i][j];
			k[2] = dibu[i+1][j];
			int l;
			for(l=0;l<3;l++){
				if(k[l]<min){
					min = k[l];
				}
			}
			otra[i][j]=min;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la erosion secuencual tipo T fue %f segundos\n", time_spent);
	cerrarArchivo(strcat(nombreImagen, "_erosionSecuencialT.pgm"));
}

void erosionParalelaT(){
	printf("Tecnica no implementada\n");
}



//Tipo L
void dilatacionSecuencialL(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();

	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int max =0;
			int k[3];
			k[0] = dibu[i-1][j];
			k[1] = dibu[i][j];
			k[2] = dibu[i][j+1];
			int l;
			for(l=0;l<3;l++){
				if(k[l]>max){
					max = k[l];
				}
			}
			otra[i][j]=max;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la dilatacion secuencual tipo L fue %f segundos\n", time_spent);
	cerrarArchivo(strcat(nombreImagen, "_dilatacionSecuencialL.pgm"));
}

void dilatacionParalelaL(){
	printf("Tecnica no implementada\n");
}

void erosionSecuencialL(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();
	
	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int min =255;
			int k[3];
			k[0] = dibu[i-1][j];
			k[1] = dibu[i][j];
			k[2] = dibu[i][j+1];
			int l;
			for(l=0;l<3;l++){
				if(k[l]<min){
					min = k[l];
				}
			}
			otra[i][j]=min;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la erosion secuencual tipo L fue %f segundos\n", time_spent);	
	cerrarArchivo(strcat(nombreImagen, "_erosionSecuencialL.pgm"));
}

void erosionParalelaL(){
	printf("Tecnica no implementada\n");
}



//Tipo Vertical (|)
void dilatacionSecuencialVertical(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();
	
	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int max =0;
			int k[3];
			k[0] = dibu[i-1][j];
			k[1] = dibu[i][j];
			k[2] = dibu[i+1][j];
			int l;
			for(l=0;l<3;l++){
				if(k[l]>max){
					max = k[l];
				}
			}
			otra[i][j]=max;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la dilatacion secuencual tipo vertical fue %f segundos\n", time_spent);
	cerrarArchivo(strcat(nombreImagen, "_dilatacionSecuencialVertical.pgm"));
}

void dilatacionParalelaVertical(){
	printf("Tecnica no implementada\n");
}

void erosionSecuencialVertical(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();

	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int min =255;
			int k[3];
			k[0] = dibu[i-1][j];
			k[1] = dibu[i][j];
			k[2] = dibu[i+1][j];
			int l;
			for(l=0;l<3;l++){
				if(k[l]<min){
					min = k[l];
				}
			}
			otra[i][j]=min;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la erosion secuencual tipo vertical fue %f segundos\n", time_spent);	
	cerrarArchivo(strcat(nombreImagen, "_erosionSecuencialVertical.pgm"));
}

void erosionParalelaVertical(){
	printf("Tecnica no implementada\n");
}



//Tipo Horizontal (-)
void dilatacionSecuencialHorizontal(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();

	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int max =0;
			int k[2];
			k[0] = dibu[i][j+1];
			k[1] = dibu[i][j];
			int l;
			for(l=0;l<2;l++){
				if(k[l]>max){
					max = k[l];
				}
			}
			otra[i][j]=max;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la dilatacion secuencual tipo horizontal fue %f segundos\n", time_spent);	
	cerrarArchivo(strcat(nombreImagen, "_dilatacionSecuencialHorizontal.pgm"));
}

void dilatacionParalelaHorizontal(){
	printf("Tecnica no implementada\n");
}

void erosionSecuencialHorizontal(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();

	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int min =255;
			int k[2];
			k[0] = dibu[i][j+1];
			k[1] = dibu[i][j];
			int l;
			for(l=0;l<2;l++){
				if(k[l]<min){
					min = k[l];
				}
			}
			otra[i][j]=min;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la erosion secuencual tipo horizontal fue %f segundos\n", time_spent);
	cerrarArchivo(strcat(nombreImagen, "_erosionSecuencialHorizontal.pgm"));
}

void erosionParalelaHorizontal(){
	printf("Tecnica no implementada\n");	
}



//Tipo X
void dilatacionSecuencialX(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();

	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int max =0;
			int k[5];
			k[0] = dibu[i-1][j-1];
			k[1] = dibu[i+1][j-1];
			k[2] = dibu[i][j];
			k[3] = dibu[i-1][j+1];
			k[4] = dibu[i+1][j+1];
			int l;
			for(l=0;l<5;l++){
				if(k[l]>max){
					max = k[l];
				}
			}
			otra[i][j]=max;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la dilatacion secuencual tipo X fue %f segundos\n", time_spent);	
	cerrarArchivo(strcat(nombreImagen, "_dilatacionSecuencialX.pgm"));
}

void dilatacionParalelaX(){
	printf("Tecnica no implementada\n");
}

void erosionSecuencialX(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();

	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int min =255;
			int k[5];
			k[0] = dibu[i-1][j-1];
			k[1] = dibu[i+1][j-1];
			k[2] = dibu[i][j];
			k[3] = dibu[i-1][j+1];
			k[4] = dibu[i+1][j+1];
			int l;
			for(l=0;l<5;l++){
				if(k[l]<min){
					min = k[l];
				}
			}
			otra[i][j]=min;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la erosion secuencual tipo X fue %f segundos\n", time_spent);	
	cerrarArchivo(strcat(nombreImagen, "_erosionSecuencialX.pgm"));
}

void erosionParalelaX(){
	printf("Tecnica no implementada\n");
}



//Tipo Suma (+)
void dilatacionSecuencialSuma(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();

	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int max =0;
			int k[5];
			k[0] = dibu[i][j-1];
			k[1] = dibu[i-1][j];
			k[2] = dibu[i][j];
			k[3] = dibu[i][j+1];
			k[4] = dibu[i+1][j];
			int l;
			for(l=0;l<5;l++){
				if(k[l]>max){
					max = k[l];
				}
			}
			otra[i][j]=max;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la dilatacion secuencual tipo + fue %f segundos\n", time_spent);
	cerrarArchivo(strcat(nombreImagen, "_dilatacionSecuencialSuma.pgm"));
}

void dilatacionParalelaSuma(){
	printf("Tecnica no implementada\n");
}

void erosionSecuencialSuma(){
	time_spent2 = 0.0;		
	begin2 = clock();

	abrirArchivo();

	double time_spent = 0.0;
	clock_t begin = clock();

	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int min =255;
			int k[5];
			k[0] = dibu[i][j-1];
			k[1] = dibu[i-1][j];
			k[2] = dibu[i][j];
			k[3] = dibu[i][j+1];
			k[4] = dibu[i+1][j];
			int l;
			for(l=0;l<5;l++){
				if(k[l]<min){
					min = k[l];
				}
			}
			otra[i][j]=min;
		}
	}

	clock_t end = clock();
	time_spent += (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("\nEl tiempo de la erosion secuencual tipo + fue %f segundos\n", time_spent);	
	cerrarArchivo(strcat(nombreImagen, "_erosionSecuencialSuma.pgm"));
}

void erosionParalelaSuma(){
	printf("Tecnica no implementada\n");
}



main(){
	while(1){
		menu();
	}
}
