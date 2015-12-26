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
/*printf("Image doesn't exist\n");*/

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
int i,j,row,line,x,y,min;
int temp_min_image[N+2][M+2];  //aftos o pinakas tha gemisei gurw gurw me 255 (wste na uparxei geitonia gia ta arxika akriana stoixeia) kai eswterika me tis times tis arxikis eikonas 
int temp_min_image_last[N][M]; //aftos tha einai o telikos pinakas min ston opoio i euresi tou elaxistou se omades twn 10 stoixeiwn tha xekinaei apo to (1,1) kai tha teleiwnei sto (N,M)

/*printf("o arxikos pinakas einai:\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",image[i][j]);
	}
}*/

//gemisma tou "megalou" pinaka min me 225
//beltistopoihsh me urolling(anti na gemizei 1-1 ta stoixeia tou pinaka,ta gemiazei 16-16)
for(i=0;i<(N+2);i+=2)
{
   for(j=0;j<(M+2);j+=8)
   {
   	/*for(k=0; k<2; k++){
   		for(l=0; l<8; l++){                //me afti ti for trwei parapanw kuklous
   		temp_min_image[i+k][j+l]=255;}} */ //gia i>2 peftei se exception
     
     temp_min_image[i][j]=255;
     temp_min_image[i][j+1]=255;
     temp_min_image[i][j+2]=255;
     temp_min_image[i][j+3]=255;
     temp_min_image[i][j+4]=255;
     temp_min_image[i][j+5]=255;
     temp_min_image[i][j+6]=255;
     temp_min_image[i][j+7]=255;
 
     temp_min_image[i+1][j]=255;
     temp_min_image[i+1][j+1]=255;
     temp_min_image[i+1][j+2]=255;
     temp_min_image[i+1][j+3]=255;
     temp_min_image[i+1][j+4]=255;
     temp_min_image[i+1][j+5]=255;
     temp_min_image[i+1][j+6]=255;
     temp_min_image[i+1][j+7]=255;
   }
}


//gemisma twn eswterikwn shmeiwn tou "megalou" pinaka min me tis arxikes times 
//beltistopoihsh me unrolling(anti na pigainei sti mnimi kai na fernei 1-1 ta stoixeia,ta fernei 16-16)
for (i=1; i<(N+1); i+=4){
	for(j=1;j<(M+1);j+=4){
	/*for (k=0; k<4; k++){
		for(l=0; l<4; l++){
		temp_min_image[i+k][j+l]=image[i-1+k][j-1+k];}}*/ //to idio kai edw me panw
	
	temp_min_image[i][j]=image[i-1][j-1];
	temp_min_image[i][j+1]=image[i-1][j];
	temp_min_image[i][j+2]=image[i-1][j+1];
	temp_min_image[i][j+3]=image[i-1][j+2];
	
	temp_min_image[i+1][j]=image[i][j-1];
	temp_min_image[i+1][j+1]=image[i][j];
	temp_min_image[i+1][j+2]=image[i][j+1];
	temp_min_image[i+1][j+3]=image[i][j+2];
	
	temp_min_image[i+2][j]=image[i+1][j-1];
	temp_min_image[i+2][j+1]=image[i+1][j];
	temp_min_image[i+2][j+2]=image[i+1][j+1];
	temp_min_image[i+2][j+3]=image[i+1][j+2];
	
	temp_min_image[i+3][j]=image[i+2][j-1];
	temp_min_image[i+3][j+1]=image[i+2][j];
	temp_min_image[i+3][j+2]=image[i+2][j+1];
	temp_min_image[i+3][j+3]=image[i+2][j+2];
	//genika veltiwne me ti prosthiki kathe entolis(auxisi tou i kai j)...
	}
}

/*printf("\n o megalos pinakas min prin ton algorithmo einai\n");	
for (i=0; i<N+2; i++){
printf("\n");
	for(j=0;j<M+2;j++){
	printf("%d \t",temp_min_image[i][j]);
	}
}*/	
	

//kuriws meros algorithmou
for (i=1;i<N+1;i++){
	for(j=1;j<M+1;j++){
	min=255;             					//krataei to elaxisto se kathe omada 10 stoixeiwn
		for(x=i-1; x<i+2; x++){				//euresi row kai line se perioxes 3x3 gurw apo kathe stoixeio (i,j)
			for(y=j-1; y<j+2; y++){			
			if (temp_min_image[x][y]<min){
				min=temp_min_image[x][y];
				row=x;
				line=y;}
			}
		}
	
temp_min_image_last[i-1][j-1]=temp_min_image[row][line]; //gemizoume kathe fora kai apo 1 stoixeio tou telikou pinaka min	
	}	
} 

/*printf("\n o pinakas min meta ton algorithmo min einai\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",temp_min_image_last[i][j]);
	}
}*/	


write_image(temp_min_image_last); //grafoume sto arxeio akiyo0_r.y
}



void max(int image[N][M])
{
int i,j,row,line,x,y,max;
int temp_max_image[N+2][M+2]; //aftos o pinakas tha gemisei gurw gurw me 0 (wste na uparxei geitonia gia ta arxika akriana stoixeia) kai eswterika me tis times tis arxikis eikonas
int temp_max_image_last[N][M];//aftos tha einai o telikos pinakas max ston opoio i euresi tou megistou se omades twn 10 stoixeiwn tha xekinaei apo to (1,1) kai tha teleiwnei sto (N,M)

/*printf("o arxikos pinakas einai:\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",image[i][j]);
	}
}*/

//gemisma tou "megalou" pinaka max me 0
//beltistopoihsh me urolling(anti na gemizei 1-1 ta stoixeia tou pinaka,ta gemiazei 16-16)
for(i=0;i<(N+2);i+=2)
{
   for(j=0;j<(M+2);j+=8)
   {
     temp_max_image[i][j]=0;
     temp_max_image[i][j+1]=0;
     temp_max_image[i][j+2]=0;
     temp_max_image[i][j+3]=0;
     temp_max_image[i][j+4]=0;
     temp_max_image[i][j+5]=0;
     temp_max_image[i][j+6]=0;
     temp_max_image[i][j+7]=0;
     
     temp_max_image[i+1][j]=0;
     temp_max_image[i+1][j+1]=0;
     temp_max_image[i+1][j+2]=0;
     temp_max_image[i+1][j+3]=0;
     temp_max_image[i+1][j+4]=0;
     temp_max_image[i+1][j+5]=0;
     temp_max_image[i+1][j+6]=0;
     temp_max_image[i+1][j+7]=0;
   }
}

//gemisma twn eswterikwn shmeiwn tou "megalou" pinaka max me tis arxikes times 
//beltistopoihsh me unrolling(anti na pigainei sti mnimi kai na fernei 1-1 ta stoixeia,ta fernei 16-16)
for (i=1; i<N+1; i+=4){
	for(j=1;j<M+1;j+=4){
	/*for (k=0; k<4; k++){
		for(l=0; l<4; l++){
		temp_max_image[i+k][j+l]=image[i-1+k][j-1+k];}}*/ //to idio kai edw me panw
		
	temp_max_image[i][j]=image[i-1][j-1];
	temp_max_image[i][j+1]=image[i-1][j];
	temp_max_image[i][j+2]=image[i-1][j+1];
	temp_max_image[i][j+3]=image[i-1][j+2];
	
	temp_max_image[i+1][j]=image[i][j-1];
	temp_max_image[i+1][j+1]=image[i][j];
	temp_max_image[i+1][j+2]=image[i][j+1];
	temp_max_image[i+1][j+3]=image[i][j+2];
	
	temp_max_image[i+2][j]=image[i+1][j-1];
	temp_max_image[i+2][j+1]=image[i+1][j];
	temp_max_image[i+2][j+2]=image[i+1][j+1];
	temp_max_image[i+2][j+3]=image[i+1][j+2];
	
	temp_max_image[i+3][j]=image[i+2][j-1];
	temp_max_image[i+3][j+1]=image[i+2][j];
	temp_max_image[i+3][j+2]=image[i+2][j+1];
	temp_max_image[i+3][j+3]=image[i+2][j+2];
	//genika veltiwne me ti prosthiki kathe entolis(auxisi tou i kai j)...
	}
}
		
//kuriws meros algorithmou	
for (i=1;i<N+1;i++){
	for(j=1;j<M+1;j++){
	max=0;									//krataei to megisto se kathe omada 10 stoixeiwn
		for(x=i-1; x<i+2; x++){				//euresi row kai line se perioxes 3x3 gurw apo kathe stoixeio (i,j)
			for(y=j-1; y<j+2; y++){
			if (temp_max_image[x][y]>max){
			max=temp_max_image[x][y];
			row=x;
			line=y;}
			}
		}
	
temp_max_image_last[i-1][j-1]=temp_max_image[row][line]; //gemizoume kathe fora kai apo 1 stoixeio tou telikou pinaka max		
	}	
} 

/*printf("\n o pinakas max meta ton algorithmo max einai\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",temp_max_image_last[i][j]);
	}
}*/	

write_image(temp_max_image_last); //grafoume sto arxeio akiyo0_r.y	
}



int main()
{
int image[N][M];
read_sequence(image);
min(image);
max(image);
}



