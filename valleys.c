#include <stdio.h>

/* This opens the functions to be read and written */
void openfiles() ;
/* This closes the function to be written out */
void closefiles();

void loop();

void valleys();

/*Count of lines in file*/
int lines_input = 15;

#define MAX 39961

float matrix[MAX][2];

/* Datafile to be open */
FILE *datafilewrite;
FILE *datafileread;

int main() {
	openfiles();
	loop();
	valleys();
	closefiles();
}

void valleys(){
  for (int i = 0; i < MAX; i++) {
  if(matrix[i][1] < matrix[i-1][1] && matrix[i][1] < matrix[i+1][1] ){
    fprintf(datafilewrite, "%f %f\n", matrix[i][0], matrix[i][1]); 
    }
  }

  printf("%s", "Hola");
}
	
void loop()
{
float Lth;

for(int m = 1; m < MAX; m++){
    fscanf(datafileread, "%f", &Lth);
    matrix[m][0] = m;
    matrix[m][1] = Lth ;
  }
}



void openfiles()
{

  datafilewrite = fopen("mrk501-gamma-valleys.dat", "w");

  datafileread = fopen("mrk501-gamma-wf.dat", "r");

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
