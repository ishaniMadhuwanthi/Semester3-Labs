#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char **argv){

if(argc !=3)
 {
   printf("Command must be in the type of: ./prog <width> <input_file>\n");
 }
else{
  FILE *ifp;
  ifp = fopen(argv[2],"r");
  int width;
  char word[80];
  int wordMax;
  
  width = atoi(argv[1]);


     //to print words in text
int count = 0;
while(fscanf(ifp,"%s",word) != EOF){
 if(count + strlen(word) <= width)
  {
    printf("%s",word);
    count = count + strlen(word);
  }else{
     printf("\n");
     count = strlen(word);
     printf("%s",word); 
       }
   char letter;
   fscanf(ifp,"%c",&letter);
   if(letter=='\n')
      {
       printf("%c",letter);
       count=0;   
      }else{
             printf("%c",' ');
             count++;
           }   
   }

    //check for error masseges
while(fscanf(ifp,"%s",word) != EOF){
 if(wordMax>width)
    {
      printf("length of words must be less than width\n");
    }
 } 
fclose(ifp);
}
return 0;
}
