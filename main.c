#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

int main(int argc, char *argv[]){
    if(argc < 4){
        printf("Недостаточно аргументов командной строки даже для 1 выражения\n");
        return 1;
    }
    int *results = (int*)malloc((argc / 3) * sizeof(int));
    if(!results){
        printf("Массив не инициализировался\n");
        return 1;
    }


    int k = 0;
    int res_cnt = 0;
    int i = 1;

    while (i < argc) {
        if (strcmp(argv[i], "-k") == 0 && i + 1 < argc) {
            k = atoi(argv[i + 1]);
            break;
        }

        if(i + 2 < argc){
            int l_op = atoi(argv[i]);
            char znak = argv[i + 1][0];
            int r_op = atoi(argv[i + 2]);
        

        results[res_cnt] = calc(l_op, znak, r_op);
    
        printf("Результат %d: %d\n", res_cnt + 1, results[res_cnt]);

        res_cnt++;
                i += 3; //Рассматриваем следующую тройку элементов
        }
    }

    printf("\nРезультирующая строка:\n");

    char *res_stroka = (char *)malloc((res_cnt + 1) * sizeof(char));
    if (!res_stroka) {
        printf("Массив не инициализировался\n");
        free(results);
        return 1;
    }

    for (int j = 0; j < res_cnt; j++) {
        res_stroka[j] = decrypt(results[j], k);
        printf("%c", res_stroka[j]);
    }
    res_stroka[res_cnt] = '\0';
    free(results);
    free(res_stroka);

    return 0;
}