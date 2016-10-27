#include <stdio.h>

int main(void)
{
    FILE *fp;
    int c;
	int count[26] = {0};
    fp = fopen("alice.txt", "r"); // error check this!
       FILE *fptr;

   fptr = fopen("binary.txt", "w+");
    if(fptr == NULL)
   {
      printf("Error!");
      exit(0);
   }
	char store[4];
	int count1 = 0;
		int j = 0;
    while((c = fgetc(fp)) != EOF) {
    	store[count1] = c;
      if (count1 == 3) 
      {
      	count1  = 0;
      	j = store[0] + (store[1]<<8) + (store[1]<<16) + (store[1]<<24);
      	printf("%d \t",j);
      	////char output[9];
      	//itoa(j, output, 2);
      	//sprintf(output, "%d", j);
      	//fprintf(fptr,"%s", char(j));
      	fputc(j, fptr);
      	j = 0;
      }
        count1++;

    }

    fclose(fp);
 
    return 0;
}
