#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
        char *ch;
        int i;
        size_t len = 256;

        printf("$ ");

        ch = malloc(len + 1);

        i = _getline(&ch, &len, stdin);

        if (i != -1)
                printf("%s", ch);

        free(ch);

        return 0;
}
