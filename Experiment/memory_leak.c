#include <stdio.h>
#include <stdlib.h>

void leak() {
    char *prision = (char*)malloc((size_t)(1024 * 1024 * 1024));    // 1 Mbytes
    prision[0] = '0';
}

int main(void) {
    while (1) {
        printf("press any key to leak the memory");
        getchar();
        leak();
    }
    return 1;
}