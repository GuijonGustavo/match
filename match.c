#include <stdio.h>

/* This opens the functions to be read and written */
void openfiles() ;
/* This closes the function to be written out */
void closefiles();

void loop();

void peaks();

/*Count of lines in file*/
int lines_input = 15;

int matrix[15][3];

/* Datafile to be open */
FILE *datafilewrite;
FILE *datafileread;

int main() {
	openfiles();
	loop();
	peaks();
	closefiles();
}

void peaks(){
  for (int i = 0; i < 15; i++) {
  if(matrix[i][1] > matrix[i-1][1] && matrix[i][1] > matrix[i+1][1] ){
    fprintf(datafilewrite, "%d %d\n", matrix[i][0], matrix[i][1]); 
    }
  }

  printf("%s", "Hola");
}
	
void loop()
{
int  tobs, Lth;

for(int m = 0; m < 15; m++){
    fscanf(datafileread, "%d  %d", &tobs, &Lth);
    matrix[m][0] = tobs ;
    matrix[m][1] = Lth ;
  }
}



void openfiles()
{

  datafilewrite = fopen("match.dat", "w");

  datafileread = fopen("data", "r");

  if (datafilewrite == NULL )
    {
     (void)printf("The data file match.dat was not OPEN \n\r"); 
    }
  if (datafileread == NULL )
    {
     printf("The data file data.dat was not OPEN \n\r");
    }

}

void closefiles()
{

  fclose(datafilewrite);
  fclose(datafileread);

}
