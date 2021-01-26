#include<stdio.h>
#include<string.h>
#include<regex.h>
int int_dec(char *ptr1[], char *ptr2[]);
int float_dec(char *ptr1[],char *ptr2[]);
int char_dec(char *ptr1[],char *ptr2[]);
int main()
{
int i=0,j,k;
 char b[100],c[50];
 const char a[] =" ";
 char *token[10];
 fgets(b,99,stdin);
 token[i]=strtok(b,a);
 while(token[i]!= NULL)
{
 i+=1;
 token[i] = strtok(NULL,a);
}
 if(i==4 && strcmp(token[2],"=")== 0)
 { 
    if (!strcmp(token[0],"int")){
      if((int_dec(&token[1],&token[3]))){printf("valid");}
      else{printf("invalid");}
    }
    if (!strcmp(token[0],"float")){
      if((float_dec(&token[1],&token[3]))){printf("valid");}
      else{printf("invalid");}
    }
    if (!strcmp(token[0],"char")){
      if((char_dec(&token[1],&token[3]))){printf("valid");}
      else{printf("invalid");}
    }}
}

int int_dec(char *ptr1[],char *ptr2[])
{
 regex_t regVar;
regex_t regVal;
 regcomp(&regVar,"[a-zA-Z_]+[0-9_]*[a-zA-Z_]*{1,10}" ,REG_ICASE | REG_EXTENDED);
 regcomp(&regVal ,"[-]{0,1}[0-9]+;",REG_ICASE | REG_EXTENDED);
 printf("%s\n",*ptr2);
 if(regexec(&regVar,*ptr1,0,NULL,0) == 0 && regexec(&regVal,*ptr2,0,NULL,0) == 0)
   { 
     return 1;
   }
 else
   {
     return 0;
   }
}
int float_dec(char *ptr1[],char *ptr2[])
{
 regex_t regVar;
regex_t regVal;
 regcomp(&regVar,"[a-zA-Z_]+[0-9_]*[a-zA-Z_]*{1,32}" ,REG_ICASE | REG_EXTENDED);
 regcomp(&regVal ,"[-]{0,1}[0-9]+([.]{0,1}[0-9]*){0,1};",REG_ICASE | REG_EXTENDED);
 printf("%s\n",*ptr2);
 if(regexec(&regVar,*ptr1,0,NULL,0) == 0 && regexec(&regVal,*ptr2,0,NULL,0) == 0)
   { 
     return 1;
   }
 else
   {
     return 0;
   }
}
int char_dec(char *ptr1[],char *ptr2[])
{
 regex_t regVar;
regex_t regVal;
 regcomp(&regVar,"[a-zA-Z_]+[0-9_]*[a-zA-Z_]*{1,32}" ,REG_ICASE | REG_EXTENDED);
 regcomp(&regVal ,"[\"][a-zA-Z0-9_//s]*{1}[\"];",REG_ICASE | REG_EXTENDED);
 printf("%s\n",*ptr2);
 if(regexec(&regVar,*ptr1,0,NULL,0) == 0 && regexec(&regVal,*ptr2,0,NULL,0) == 0)
   { 
     return 1;
   }
 else
   {
     return 0;
   }
}

