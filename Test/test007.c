#include <stdio.h>
#include <string.h>

int main(){
    char cc[][10] = {"\x1b[31m", "hello world"};
    printf("\x1b[31m");
    printf("%d%", strlen("\x1b[31m"));
    printf("hello world\n");
    printf("\x1b[33m");
    printf("hello world\n");

    printf("%s%s", cc[0], cc[1]);
}
