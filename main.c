#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j;
  int check=0;
  char inpop;
  
  Stack s;
  s.size=0;
  s.top=NULL;

  //cannot use ()
 
  for(i=1;i<argc;i++)
  {
     for(j=0;j<strlen(argv[i]);j++)
     {
       switch (argv[i][j])
       {
        case '{':
          push(&s,'{');
           break;
            
        case '[':
          push(&s,'[');
          break;

        case ']':
          inpop = pop(&s);
          if(inpop != '[')
          {
          check++;
          }
          break;

        case '}':
          inpop = pop(&s);
          if(inpop !='{')
          {
          check++;
          }
          break;
       }
       if(check!=0) break;
     }
    printf("\nThe size is : %d and check : %d\n",s.size,check);
     if(s.size>0||check!=0)
     {
       printf("The parentheses do not match for %s\n",argv[i]);
     }
     else 
     {
       printf("The parenthese match successfully for %s\n",argv[i]);
     }
     check=0;
     pop_all(&s);
  }
   return 0;
}

