#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RESET		0
#define BRIGHT 		1

#define BLACK 		0
#define RED		1
#define GREEN		2
#define YELLOW		3
#define BLUE		4
#define MAGENTA		5
#define CYAN		6
#define	WHITE		7

void textcolor(int attr, int fg, int bg);

void textcolor(int attr, int fg, int bg)
{	char command[13];

	/* Command is the control command to the terminal */

	/* textcolor(BRIGHT,BLACK,WHITE) will have characters printed in
	black in white background */
	sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
	printf("%s", command);
}

int getD(int R);


int main(int argc, char **argv){

int fg,bg;//bg-background colour,fg-foreground colour

if(argc < 4){
   printf("Not enough arguments\n");
}else if(argc > 4){
   printf("Too many arguments\n");
}else{
//to get foregroud color


if(strcmp("black",argv[2]) == 0){
   fg = 0;
}else if(strcmp("red",argv[2]) == 0){
   fg = 1;
}else if(strcmp("green",argv[2]) == 0){
   fg = 2;
}else if(strcmp("yellow",argv[2]) == 0){
  fg = 3;
}else if(strcmp("blue",argv[2]) == 0){
  fg = 4;
}else if(strcmp("magenta",argv[2]) == 0){
   fg = 5;
}else if(strcmp("cyan",argv[2]) == 0){
   fg = 6;
}else if(strcmp("white",argv[2]) == 0){
   fg = 7;
}else{
   printf("Foreground color is not available\n");
 return -1;
}


//to get backgroud color
 

if(strcmp("black", argv[3]) == 0){
   bg = 0;
}else if(strcmp("red",argv[3]) == 0){
   bg = 1;
}else if(strcmp("green", argv[3]) == 0){
  bg = 2;
}else if(strcmp("yellow", argv[3]) == 0){
   bg = 3;
}else if(strcmp("blue", argv[3]) == 0){
  bg = 4;
}else if(strcmp("magenta", argv[3]) == 0){
   bg = 5;
}else if(strcmp("cyan", argv[3]) == 0){
   bg = 6;
}else if(strcmp("white", argv[3]) == 0){
  bg = 7;
}else{
   printf("Background color is not available\n");
 return -1;
}

/*if((strcmp("checker",argv[1]) != 0) || (strcmp("donut",argv[1]) != 0)){
   printf("Requested figure is not found\n");
   }
else{*/

 //to get checker or donut...

 if(strcmp("checker",argv[1]) == 0){
      
      int r,c,i,j;

    for(c = 1 ; c <= 4 ; c++){
      for(i = 1 ; i <= 8 ; i++){
        for(r = 1 ; r <= 4 ; r++){
               textcolor(BRIGHT,fg,bg);
               printf("        ");	
               textcolor(BRIGHT,bg,fg);
               printf("        ");
         }
          printf(" ");
          printf("\n");
       }

      for(i = 1 ; i <= 8 ; i++){
          for(r = 1 ; r <= 4 ; r++){
               textcolor(BRIGHT,bg,fg);
               printf("        ");	
               textcolor(BRIGHT,fg,bg);
               printf("        ");
           }
            printf(" ");
            printf("\n");
       }
     }
   
 } 
//for donut
 
else if(strcmp("donut",argv[1]) == 0){
  
   int i,j;
   int R; 
   int s;
   int cir;
  scanf("%d",&R);//R=radius

 s = getD(R);
 
 for(i = (-s/2) ; i <= (s/2) ; i++){
      for(j = (-s/2) ; j <= (s/2) ; j++){
         if(((i*i + j*j) < (s*R)) && ((i*i + j*j) >= ((s*R)/4))){
             textcolor(BRIGHT,fg,bg);
          }else{
             textcolor(BRIGHT,bg,fg);
          }
           printf(" ");
      }
      textcolor(BRIGHT,bg,fg);
      printf("\n");
     }    
   }
  }

  textcolor(RESET,WHITE,BLACK);	
return 0;	
 }

int getD(int R)
{
  return (4*R);
}




