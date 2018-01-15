#include <stdio.h>
#include <stdlib.h>

void func(int **a) {
   printf("a is %p\n", a);
   printf("*a is %p\n", *a);
   *a = malloc(sizeof(int));
}

int main(void) {
   int *p;
   printf("&p is %p\n", &p);
   func(&p);
   *p = 6;
   free(p);
   return 0;
}
