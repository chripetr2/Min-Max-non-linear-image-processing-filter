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
void min_max(int image[N][M])
{
int i,j,row_min,row_max,line_min,line_max,x,y,min,max;
int temp_min_image[N+2][M+2];  //aftos o pinakas tha gemisei gurw gurw me 255 (wste na uparxei geitonia gia ta arxika akriana stoixeia) kai eswterika me tis times tis arxikis eikonas 
int temp_min_image_last[N][M]; //aftos tha einai o telikos pinakas min ston opoio i euresi tou elaxistou se omades twn 10 stoixeiwn tha xekinaei apo to (1,1) kai tha teleiwnei sto (N,M)
int temp_max_image[N+2][M+2];  //aftos o pinakas tha gemisei gurw gurw me 0   (wste na uparxei geitonia gia ta arxika akriana stoixeia) kai eswterika me tis times tis arxikis eikonas
int temp_max_image_last[N][M];;//aftos tha einai o telikos pinakas max ston opoio i euresi tou megistou  se omades twn 10 stoixeiwn tha xekinaei tou apo to (1,1) kai tha teleiwnei sto (N,M)

/*printf("o arxikos pinakas einai:\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",image[i][j]);
	}
}*/

//gemisma twn "megalwn" pinakwn min kai max me 225 kai 0 ,antistoixa
//beltistopoihsh me urolling(anti na gemiazei 1-1 ta stoixeia tou pinaka,ta gemizei 16-16)
for(i=0;i<(N+2);i+=2)
{
   for(j=0;j<(M+2);j+=8)
   {
   	  
     //gemisma  tou pinaka gia ta elaxista
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
     
	 //gemisma tou pinaka gia ta megista
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


//gemisma twn eswterikwn shmeiwn twn "megalwn" pinakwn me tis arxikes times 
//beltistopoihsh me unrolling(anti na pigainei sti mnimi kai na fernei 1-1 ta stoixeia,ta fernei 16-16)
for (i=1; i<(N+1); i+=4){
	for(j=1;j<(M+1);j+=4){
	
	//gemisma tou pinaka gia ta elaxista
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
	
	//gemisma tou pinaka gia ta megista	
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
	}
}

/*printf("\n o megalos pinakas min prin ton algorithmo einai\n");	
for (i=0; i<N+2; i++){
printf("\n");
	for(j=0;j<M+2;j++){
	printf("%d \t",temp_min_image[i][j]);
	}
}*/	

/*printf("\n o megalos pinakas max prin ton algorithmo einai\n");	
for (i=0; i<N+2; i++){
printf("\n");
	for(j=0;j<M+2;j++){
	printf("%d \t",temp_max_image[i][j]);
	}
}*/		



//veltistopoihsh me merging se sxesi me ta proigoumena versions
for (i=1;i<N+1;i++){
	for(j=1;j<M+1;j++){
	min=255;								//krataei to elaxisto se kathe omada 10 stoixeiwn
	max=0;									//krataei to megisto  se kathe omada 10 stoixeiwn
		for(x=i-1; x<i+2; x++){				//euresi row_min kai line_min se perioxes 3x3 gurw apo kathe stoixeio (i,j)
			for(y=j-1; y<j+2; y++){			
			if (temp_min_image[x][y]<min){
				min=temp_min_image[x][y];
				row_min=x;					
				line_min=y;}
				
			if (temp_max_image[x][y]>max){  //euresi row_max kai line_max se perioxes 3x3 gurw apo kathe stoixeio (i,j)
				max=temp_max_image[x][y];
				row_max=x;
				line_max=y;}			
			}
		}
				
temp_min_image_last[i-1][j-1]=temp_min_image[row_min][line_min]; //gemizoume kathe fora kai apo 1 stoixeio tou telikou pinaka min 
temp_max_image_last[i-1][j-1]=temp_max_image[row_max][line_max]; //gemizoume kathe fora kai apo 1 stoixeio tou telikou pinaka max 		
	}	
} 

/*printf("\n o pinakas min meta ton algorithmo min einai\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",temp_min_image_last[i][j]);
	}
}	*/
/*printf("\n o pinakas max meta ton algorithmo max einai\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",temp_max_image_last[i][j]);
	}
}	*/

//i eggrafi menei mono gia ton pinaka temp_max_image_last sto arxeio akiyo0_r.y
write_image(temp_min_image_last);
write_image(temp_max_image_last);
}


int main()
{
int image[N][M];
read_sequence(image);
min_max(image);
}



