#include <stdio.h>

int main()
{
    char words[255];
    scanf("%[^\n]",&words);
    printf("#include <stdio.h>\n");
    printf("int main()\n");
    printf("{\n");
    printf("    printf(\"%%s\\n\",\"%s\");\n",words);
    printf("    return 0;\n");
    printf("}\n");

    return 0;
}