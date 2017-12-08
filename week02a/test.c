#include <stdio.h>
#include <ctype.h>

int main () {
   char var1 = 'h';
   char var2 = '2';

   scanf("%c", &var1);
   scanf("%c", &var2);
    
   if( isdigit(var1) ) {
      printf("var1 = |%c| is a digit\n", var1 );
   } else {
      printf("var1 = |%c| is not a digit\n", var1 );
   }
   
   if( isdigit(var2) ) {
      printf("var2 = |%c| is a digit\n", var2 );
   } else {
      printf("var2 = |%c| is not a digit\n", var2 );
   }
   
   return(0);
}