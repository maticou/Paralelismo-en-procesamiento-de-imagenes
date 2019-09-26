#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define num_hilos 20

int fila, colu, i, j, gris;
int num_filas;
int fila_actual = 1;

FILE *arch, *sali;

unsigned char dibu[1000][1000],otra[1000][1000];
pthread_mutex_t mutex;

void *erosion(void *arg){
	int fila_final = fila_actual+num_filas+1;

	pthread_mutex_lock(&mutex);

	for(i=fila_actual; i<fila_final; i++){
		for(j=1; j<colu; j++){
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
	fila_actual = fila_actual+num_filas;

	sali=fopen("erosionN.pgm","wb");
	fprintf(sali,"P5\n");
	fprintf(sali,"%d %d\n",colu,fila);
    fprintf(sali,"%d\n",gris);
	for(i=0; i<fila; i++){
		for(j=0; j<colu; j++)
		{
			fprintf(sali,"%c",otra[i][j]);
		}
	}

	fclose(sali);

	pthread_mutex_unlock(&mutex);
}


void *dilatacion(void *arg){
	int fila_final = fila_actual+num_filas+1;

	pthread_mutex_lock(&mutex);

	for(i=fila_actual; i<fila_final; i++){
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

	fila_actual = fila_actual+num_filas;

	sali=fopen("dilatacionN.pgm","wb");
	fprintf(sali,"P5\n");
	fprintf(sali,"%d %d\n",colu,fila);
    fprintf(sali,"%d\n",gris);
	for(i=0; i<fila; i++){
		for(j=0; j<colu; j++)
		{
			fprintf(sali,"%c",otra[i][j]);
		}
	}

	fclose(sali);

	pthread_mutex_unlock(&mutex);
}


main(){
	unsigned char c, c1, c2;

	arch=fopen("4.pgm","rb");
	c1=fgetc(arch);
	c2=fgetc(arch);

	if (c1!='P' || c2!='5')
    {
		printf("\nFormato no corresponde a una Imagen\n");
		exit (0);
    }

	c=fgetc(arch);
    c=fgetc(arch);

    while(c!='\n'){
    	c=fgetc(arch);
    }    

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

	num_filas = fila / num_hilos;

	pthread_t threads1[num_hilos];
	pthread_t threads2[num_hilos];

	for(int num = 0; num < num_hilos; num++){
		int aux = (num*num_filas)+1;
		int *p;
    	pthread_create(&threads1[num], NULL, erosion, (void*)(p));
    	pthread_create(&threads2[num], NULL, dilatacion, (void*)(p));
    }

    for(int num = 0; num < num_hilos; num++){
    	pthread_join(threads1[num], NULL);
    	pthread_join(threads2[num], NULL);
    }

    fclose(arch);

}