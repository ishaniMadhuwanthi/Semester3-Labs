#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 80 

typedef struct node{
   char word[1000];
   int length;
   struct node * next;
}node_t;

int print_list(node_t * head,int maxlength){
 while(maxlength>0){//word length must have positive value
   node_t * current = head;
     while (current != NULL){//to check whole words in the paragraph and find maximum word length
        if(current->length == maxlength){
      printf("%s\n", current->word);
         }
      current = current->next;
  }maxlength--;
 }
}

int maxlength(node_t * head){//to find the maximum word length
  int i=0;
  node_t * current = head;
     while (current != NULL){
        if(current->length > i){
      i = current->length;
         }
      current = current->next;
}return i;
} 


int main(int argc,char **argv) {

if(argc !=2)
 {
   printf("Command must be in the type of: ./prog <input_file>\n");//check errors in giving commands
 }
else{

   FILE * ifp;
   char buffer[SIZE];

   ifp = fopen(argv[1], "r");//open the file that we want to copy
   node_t head;
   node_t * iterator = &head;

if (ifp == NULL) {
      perror("Error opening file");//check if there is an error in opening file
   } else {
  
     while (!feof(ifp)) {
         fscanf(ifp,"%s",buffer);
         node_t * newNode = NULL;
         newNode = (node_t*)malloc(sizeof(node_t));//allocate space for variable newNode
         iterator->next = newNode;
         strcpy(newNode->word,buffer);
          
         newNode->length= strlen(buffer);
         iterator = newNode;
      }
      fclose(ifp);//close the opened file
    print_list(&head,maxlength(&head));
   }
}
   return 0;
}
