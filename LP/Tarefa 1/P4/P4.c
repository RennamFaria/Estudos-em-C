#include <stdio.h>

int main()
{
    int dia1, mes1, ano1, dia2, mes2, ano2;

    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    if (ano1>ano2)
    {
        printf("A segunda data ocorreu antes da primeira.");
        return 0;
    }
    if (ano1<ano2)
    {
        printf("A primeira data ocorreu antes da segunda.");
        return 0;
    }
    else
    {
        if (mes1>mes2)
        {
            printf("A segunda data ocorreu antes da primeira.");
            return 0;
        }
        if (mes1<mes2)
        {
            printf("A primeira data ocorreu antes da segunda.");
            return 0;
        }
        else
        {
            if (dia1>dia2)
            {
                printf("A segunda data ocorreu antes da primeira.");
                return 0;
            }
            if (dia1<dia2)
            {
                printf("A primeira data ocorreu antes da segunda.");
                return 0;
            }
            else
            {
                printf("As duas data ocorreu no mesmo ano.");
                return 0;
            }
        }
    }
}