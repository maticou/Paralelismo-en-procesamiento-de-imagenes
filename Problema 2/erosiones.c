// lectura.c   (Creado por Rodrigo Pavez M)
#include <stdio.h>

/* Programa que permite la lectura y generacion de archivos en formato PGM
Este formato tiene la siguiente estructura:
P5									// Es la cadena magica que identifica al PGM
# Comentarios pueden ser varios		
ancho alto							// Pixel de ancho y pixel de alto en formato decimal
grises								// Escala de grises entre 0 y 255 en formato decimal
los ascii correspondientes a la cantidad ancho x alto pixeles.
*/

main()
{
	FILE *arch,*sali;
	unsigned char c,c1,c2;
	int fila, colu, i, j, gris;
	unsigned char dibu[2046][2046],otra[2046][2046];

	//arch=fopen("imgNueva.pgm","rb");
	arch=fopen("12.pgm","rb");
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

// Proceso	- Erosion normal
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
	// Fin del Proceso	
    sali=fopen("erosionN.pgm","wb");
	fprintf(sali,"P5\n");
	fprintf(sali,"# Creado por Rodrigo Pavez. (2019)\n");
	fprintf(sali,"%d %d\n",colu,fila);
    fprintf(sali,"%d\n",gris);
	for(i=0; i<fila; i++){
		for(j=0; j<colu; j++)
		{
			fprintf(sali,"%c",otra[i][j]);
		}
	}
	sleep(1);
// Proceso	- Erosion 1
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
	// Fin del Proceso	
    sali=fopen("erosion1.pgm","wb");
	fprintf(sali,"P5\n");
	fprintf(sali,"# Creado por Rodrigo Pavez. (2019)\n");
	fprintf(sali,"%d %d\n",colu,fila);
    fprintf(sali,"%d\n",gris);
	for(i=0; i<fila; i++){
		for(j=0; j<colu; j++)
		{
			fprintf(sali,"%c",otra[i][j]);
		}
	}
sleep(1);
// Proceso	- Erosion 2
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
	// Fin del Proceso	
    sali=fopen("erosion2.pgm","wb");
	fprintf(sali,"P5\n");
	fprintf(sali,"# Creado por Rodrigo Pavez. (2019)\n");
	fprintf(sali,"%d %d\n",colu,fila);
    fprintf(sali,"%d\n",gris);
	for(i=0; i<fila; i++){
		for(j=0; j<colu; j++)
		{
			fprintf(sali,"%c",otra[i][j]);
		}
	}
sleep(1);
// Proceso	- Erosion 3
	for(i=1; i<fila-1; i++){
		for(j=1; j<colu-1; j++){
			int min =255;
			int k[3];
			k[0] = dibu[i-1][j];
			k[1] = dibu[i][j];
			k[2] = dibu[i+1][j];
			int l;
			for(l=0;l<5;l++){
				if(k[l]<min){
					min = k[l];
				}
			}
			otra[i][j]=min;
		}
	}
	// Fin del Proceso	
    sali=fopen("erosion3.pgm","wb");
	fprintf(sali,"P5\n");
	fprintf(sali,"# Creado por Rodrigo Pavez. (2019)\n");
	fprintf(sali,"%d %d\n",colu,fila);
    fprintf(sali,"%d\n",gris);
	for(i=0; i<fila; i++){
		for(j=0; j<colu; j++)
		{
			fprintf(sali,"%c",otra[i][j]);
		}
	}
sleep(1);
// Proceso	- Erosion 4
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
	// Fin del Proceso	
    sali=fopen("erosion4.pgm","wb");
	fprintf(sali,"P5\n");
	fprintf(sali,"# Creado por Rodrigo Pavez. (2019)\n");
	fprintf(sali,"%d %d\n",colu,fila);
    fprintf(sali,"%d\n",gris);
	for(i=0; i<fila; i++){
		for(j=0; j<colu; j++)
		{
			fprintf(sali,"%c",otra[i][j]);
		}
	}
sleep(1);
// Proceso	- Erosion 5
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
	// Fin del Proceso	
    sali=fopen("erosion5.pgm","wb");
	fprintf(sali,"P5\n");
	fprintf(sali,"# Creado por Rodrigo Pavez. (2019)\n");
	fprintf(sali,"%d %d\n",colu,fila);
    fprintf(sali,"%d\n",gris);
	for(i=0; i<fila; i++){
		for(j=0; j<colu; j++)
		{
			fprintf(sali,"%c",otra[i][j]);
		}
	}	
	sleep(1);
	fclose(arch);
	fclose(sali);
}
