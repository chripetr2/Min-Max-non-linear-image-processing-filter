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
int i,j,k[3][3],row,line,x,y,min;   //sto pinaka k tha apothikevetai se kathe epanalalipsi i perioxi 3x3 stin opoia tha psaxnoume to min stoixeio
int temp_min_image[N+2][M+2];		//aftos o pinakas tha gemisei gurw gurw me 255 (wste na uparxei geitonia gia ta arxika akriana stoixeia) kai eswterika me tis times tis arxikis eikonas
int temp_min_image_last[N][M];		//aftos tha einai o telikos pinakas min ston opoio i euresi tou elaxistou se omades twn 10 stoixeiwn tha xekinaei apo to (1,1) kai tha teleiwnei sto (N,M)

/*printf("o arxikos pinakas einai:\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",image[i][j]);
	}
}*/

//gemisma tou "megalou" pinaka min me 225
for(i=0;i<(N+2);++i)
{
   for(j=0;j<(M+2);++j)
   {
   temp_min_image[i][j]=255;
   }
}

//gemisma twn eswterikwn shmeiwn tou "megalou" pinaka min me tis arxikes times
for (i=1; i<N+1; i++){
	for(j=1;j<M+1;j++){
	temp_min_image[i][j]=image[i-1][j-1];
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
	k[0][0]=temp_min_image[i-1][j-1];  //sto pinaka k apothikevoume tin perioxi 3x3 gurw apo to stoixeio (i,j)...stin epomeni version den uparxei aftos o pinakas opote meiwnontai oi kukloi
	k[0][1]=temp_min_image[i-1][j];
	k[0][2]=temp_min_image[i-1][j+1];
	k[1][0]=temp_min_image[i][j-1];
	k[1][1]=temp_min_image[i][j];
	k[1][2]=temp_min_image[i][j+1];
	k[2][0]=temp_min_image[i+1][j-1];
	k[2][1]=temp_min_image[i+1][j];
	k[2][2]=temp_min_image[i+1][j+1];

		min=255; //krataei to elaxisto se kathe pinaka k
		row=0;
		line=0;		
		for (x=0;x<3;x++){	//euresi row kai line me tin min timi sto pinaka k 
			for (y=0;y<3;y++){
			if (k[x][y]<min){
					min=k[x][y];
					row=x;
					line=y;	}
			}
		}
			
temp_min_image_last[i-1][j-1]=k[row][line]; //gemizoume kathe fora kai apo 1 stoixeio tou telikou pinaka min	
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
int i,j,k[3][3],row,line,x,y,max;	//sto pinaka k tha apothikevetai se kathe epanalalipsi i perioxi 3x3 stin opoia tha psaxnoume to max stoixeio
int temp_max_image[N+2][M+2];		//aftos o pinakas tha gemisei gurw gurw me 0 (wste na uparxei geitonia gia ta arxika akriana stoixeia) kai eswterika me tis times tis arxikis eikonas
int temp_max_image_last[N][M];		//aftos tha einai o telikos pinakas max ston opoio i euresi tou megistou se omades twn 10 stoixeiwn tha xekinaei apo to (1,1) kai tha teleiwnei sto (N,M)

/*printf("o arxikos pinakas einai:\n");
for (i=0; i<N; i++){
printf("\n%d:",i);
	for(j=0;j<M;j++){
	printf("%d \t",image[i][j]);
	}
}*/

//gemisma tou "megalou" pinaka max me 0
for(i=0;i<(N+2);++i)
{
   for(j=0;j<(M+2);++j)
   {
     temp_max_image[i][j]=0;
   }
}

//gemisma twn eswterikwn shmeiwn tou "megalou" pinaka max me tis arxikes times
for (i=1; i<N+1; i++){
	for(j=1;j<M+1;j++){
	temp_max_image[i][j]=image[i-1][j-1];
	}
}
	
	
//kuriws meros algorithmou	
for (i=1;i<N+1;i++){
	for(j=1;j<M+1;j++){
		k[0][0]=temp_max_image[i-1][j-1]; //sto pinaka k apothikevoume tin perioxi 3x3 gurw apo to stoixeio (i,j)...stin epomeni version den uparxei aftos o pinakas opote meiwnontai oi kukloi
		k[0][1]=temp_max_image[i-1][j];
		k[0][2]=temp_max_image[i-1][j+1];
		k[1][0]=temp_max_image[i][j-1];
		k[1][1]=temp_max_image[i][j];
		k[1][2]=temp_max_image[i][j+1];
		k[2][0]=temp_max_image[i+1][j-1];
		k[2][1]=temp_max_image[i+1][j];
		k[2][2]=temp_max_image[i+1][j+1];

		max=0;	//krataei to megisto se kathe pinaka k
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
		
temp_max_image_last[i-1][j-1]=k[row][line]; //gemizoume kathe fora kai apo 1 stoixeio tou telikou pinaka max
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



