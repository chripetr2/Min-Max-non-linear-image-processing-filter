#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define N 144
#define M 176

/*sunartiseis anagnwsis kai eggrafis*/
void read_sequence(int image[N][M])
{
FILE *infile;
int i,j;
if((infile=fopen("akiyo0.y","rb"))==NULL)
{
printf("Image doesn't exist\n");

exit(-1);
}
for(i=0;i<N;i++)
for(j=0;j<M;j++)
{
image[i][j]=(int)fgetc(infile);
}
/*printf("diavase tin eikona kai tin kleinei\n");*/
fclose(infile);
}

void write_image(int image[N][M])
{
FILE *infile;
int i,j;
if((infile=fopen("akiyo0_r.y","w+"))==NULL)
{
exit(-1);
}
for(i=0;i<N;i++)
for(j=0;j<M;j++)
{
fputc(image[i][j],infile);
}

fclose(infile);
}



/*kuries sunartiseis min kai max*/
void min(int image[N][M])
{
int i,j,k[3][3],row,line,x,y,min;	//sto pinaka k tha apothikevetai se kathe epanalalipsi i perioxi 3x3 stin opoia tha psaxnoume to min stoixeio
int temp_min_image[N][M];			//aftos tha einai o telikos pinakas min

/*printf("o arxikos pinakas einai:\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",image[i][j]);
	}
}*/ 

//dhmiourgoume to pinaka k gia 9 diaforetikes periptwseis analog me to pou vrisketai to (i,j),diladi stis 4 akres, stis 4 plevres i endiamesa
//stin epomeni version boroume na glitwsoume olous aftous tous elegxous gemizontas ton pinaka exwterika me tis katallikes times
for (i=0; i<N; i++){
	for(j=0;j<M;j++){

if (i==0 && j==0){
k[0][0]=255;
k[0][1]=255;
k[0][2]=255;
k[1][0]=255;
k[2][0]=255;
k[1][1]=image[0][0];
k[1][2]=image[0][1];
k[2][1]=image[1][0];
k[2][2]=image[1][1];}		
		
else if (i==0 && j==M-1){
k[0][0]=255;
k[0][1]=255;
k[0][2]=255;
k[1][0]=image[0][M-2];
k[1][1]=image[0][M-1];
k[1][2]=255;
k[2][0]=image[1][M-2];
k[2][1]=image[1][M-1];
k[2][2]=255;}

else if (i==N-1 && j==0){
k[0][0]=255;
k[0][1]=image[N-2][0];
k[0][2]=image[N-2][1];
k[1][0]=255;
k[1][1]=image[N-1][0];
k[1][2]=image[N-1][1];
k[2][0]=255;
k[2][1]=255;
k[2][2]=255;}

else if (i==N-1 && j==M-1){
k[0][0]=image[N-2][M-2];
k[0][1]=image[N-2][M-1];
k[0][2]=255;
k[1][0]=image[N-1][M-2];
k[1][1]=image[N-1][M-1];
k[1][2]=255;
k[2][0]=255;
k[2][1]=255;
k[2][2]=255;}

else if(i==0){
k[0][0]=255;
k[0][1]=255;
k[0][2]=255;
k[1][0]=image[i][j-1];
k[1][1]=image[i][j];
k[1][2]=image[i][j+1];
k[2][0]=image[i+1][j-1];
k[2][1]=image[i+1][j];
k[2][2]=image[i+1][j+1];}

else if(i==N-1){
k[0][0]=image[i-1][j-1];
k[0][1]=image[i-1][j];
k[0][2]=image[i-1][j+1];
k[1][0]=image[i][j-1];
k[1][1]=image[i][j];
k[1][2]=image[i][j+1];
k[2][0]=255;
k[2][1]=255;
k[2][2]=255;}

else if(j==0){
k[0][0]=255;
k[0][1]=image[i-1][j];
k[0][2]=image[i-1][j+1];
k[1][0]=255;
k[1][1]=image[i][j];
k[1][2]=image[i][j+1];
k[2][0]=255;
k[2][1]=image[i+1][j];
k[2][2]=image[i+1][j+1];}

else if(j==M-1){
k[0][0]=image[i-1][j-1];
k[0][1]=image[i-1][j];
k[0][2]=255;
k[1][0]=image[i][j-1];
k[1][1]=image[i][j];
k[1][2]=255;
k[2][0]=image[i+1][j-1];
k[2][1]=image[i+1][j];
k[2][2]=255;}
	
else{
k[0][0]=image[i-1][j-1];
k[0][1]=image[i-1][j];
k[0][2]=image[i-1][j+1];
k[1][0]=image[i][j-1];
k[1][1]=image[i][j];
k[1][2]=image[i][j+1];
k[2][0]=image[i+1][j-1];
k[2][1]=image[i+1][j];
k[2][2]=image[i+1][j+1];}


/*edw exei gemisei o k kai kanoume sugrisi gia tin allagi tou pixel*/
		min=255; //krataei to elaxisto se kathe pinaka k
		row=0;
		line=0;
		
		for (x=0;x<3;x++){
			for (y=0;y<3;y++){ 		//euresi row kai line me tin min timi sto pinaka k
				if (k[x][y]<min){
					min=k[x][y];
					row=x;
					line=y;
				}
			}
		}

temp_min_image[i][j]=k[row][line]; //gemizoume kathe fora kai apo 1 stoixeio tou telikou pinaka min
	}	
} 

/*printf("\n o pinakas min meta ton algorithmo min einai\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",temp_min_image[i][j]);
	}
}*/	
write_image(temp_min_image); //grafoume sto arxeio akiyo0_r.y
}


void max(int image[N][M])
{
int i,j,k[3][3],row,line,x,y,max;
int temp_max_image[N][M];

/*printf("o arxikos pinakas einai:\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",image[i][j]);
	}
}*/

//dhmiourgoume to pinaka k gia 9 diaforetikes periptwseis analog me to pou vrisketai to (i,j),diladi stis 4 akres, stis 4 plevres i endiamesa
//stin epomeni version boroume na glitwsoume olous aftous tous elegxous gemizontas ton pinaka exwterika me tis katallikes times
for (i=0; i<N; i++){
	for(j=0;j<M;j++){
	
if (i==0 && j==0){
k[0][0]=0;
k[0][1]=0;
k[0][2]=0;
k[1][0]=0;
k[2][0]=0;
k[1][1]=image[0][0];
k[1][2]=image[0][1];
k[2][1]=image[1][0];
k[2][2]=image[1][1];}		
		
else if (i==0 && j==M-1){
k[0][0]=0;
k[0][1]=0;
k[0][2]=0;
k[1][0]=image[0][M-2];
k[1][1]=image[0][M-1];
k[1][2]=0;
k[2][0]=image[1][M-2];
k[2][1]=image[1][M-1];
k[2][2]=0;}

else if (i==N-1 && j==0){
k[0][0]=0;
k[0][1]=image[N-2][0];
k[0][2]=image[N-2][1];
k[1][0]=0;
k[1][1]=image[N-1][0];
k[1][2]=image[N-1][1];
k[2][0]=0;
k[2][1]=0;
k[2][2]=0;}

else if (i==N-1 && j==M-1){
k[0][0]=image[N-2][M-2];
k[0][1]=image[N-2][M-1];
k[0][2]=0;
k[1][0]=image[N-1][M-2];
k[1][1]=image[N-1][M-1];
k[1][2]=0;
k[2][0]=0;
k[2][1]=0;
k[2][2]=0;}

else if(i==0){
k[0][0]=0;
k[0][1]=0;
k[0][2]=0;
k[1][0]=image[i][j-1];
k[1][1]=image[i][j];
k[1][2]=image[i][j+1];
k[2][0]=image[i+1][j-1];
k[2][1]=image[i+1][j];
k[2][2]=image[i+1][j+1];}

else if(i==N-1){
k[0][0]=image[i-1][j-1];
k[0][1]=image[i-1][j];
k[0][2]=image[i-1][j+1];
k[1][0]=image[i][j-1];
k[1][1]=image[i][j];
k[1][2]=image[i][j+1];
k[2][0]=0;
k[2][1]=0;
k[2][2]=0;}

else if(j==0){
k[0][0]=0;
k[0][1]=image[i-1][j];
k[0][2]=image[i-1][j+1];
k[1][0]=0;
k[1][1]=image[i][j];
k[1][2]=image[i][j+1];
k[2][0]=0;
k[2][1]=image[i+1][j];
k[2][2]=image[i+1][j+1];}

else if(j==M-1){
k[0][0]=image[i-1][j-1];
k[0][1]=image[i-1][j];
k[0][2]=0;
k[1][0]=image[i][j-1];
k[1][1]=image[i][j];
k[1][2]=0;
k[2][0]=image[i+1][j-1];
k[2][1]=image[i+1][j];
k[2][2]=0;}
	
else{
k[0][0]=image[i-1][j-1];
k[0][1]=image[i-1][j];
k[0][2]=image[i-1][j+1];
k[1][0]=image[i][j-1];
k[1][1]=image[i][j];
k[1][2]=image[i][j+1];
k[2][0]=image[i+1][j-1];
k[2][1]=image[i+1][j];
k[2][2]=image[i+1][j+1];}


/*edw exei gemisei o k kai kanoume sugrisi gia tin allagi tou pixel*/
		max=0; //krataei to megisto se kathe pinaka k
		row=0;
		line=0;
		
		for (x=0;x<3;x++){			//euresi row kai line me tin max timi sto pinaka k
			for (y=0;y<3;y++){
				if (k[x][y]>max){
					max=k[x][y];
					row=x;
					line=y;
				}
			}
		}
		

	temp_max_image[i][j]=k[row][line]; //gemizoume kathe fora kai apo 1 stoixeio tou telikou pinaka max
	}	
} 

/*printf("\n o pinakas max meta ton algorithmo max einai\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",temp_max_image[i][j]);
	}
}*/	

write_image(temp_max_image);  //grafoume sto arxeio akiyo0_r.y
}




int main()
{
int image[N][M];
read_sequence(image);
min(image);
max(image);
}



