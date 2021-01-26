#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct a{
 char ch;
 struct a* prev;
 };
struct a* top;
void push(char s)
{
  struct a* latest = (struct a* )malloc(sizeof(struct a));
  if(latest == NULL){
   printf("error...stack overflow");
   exit(0);
    }
   latest->ch = s;
   printf("\n pushing : %c",latest->ch);
   latest->prev = top;	 
   top=latest;
}
void pop()
{
  printf("\npopping : %c",top->ch);
  top=top->prev;
}
int main()
{ int i=0;
 char a[100];
 printf("enter the expression : ");
 fgets(a,99,stdin);
 for(i=0;i<strlen(a)-1;i++){
  if (a[i]=='('||a[i]=='['||a[i]=='{'){
   push(a[i]);}
  else
  { if(top == NULL)
     {  push(a[i]);}
    if ((a[i]==')' && top->ch == '(')||(a[i]=='}' && top->ch == '{')||(a[i]==']' && top->ch == '['))
        {pop();continue;}
    //else {printf("\nINVALID"); exit(0);}
  }  
}
  if (top == NULL){
      printf("\nValid");}
  else{ printf("\nInValid");}
return 0;
  }  
