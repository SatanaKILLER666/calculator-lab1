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
    if(argc % 3 != 0){
        printf("Ошибка в количестве введенных аргументов\n");
        return 1;

    }

    int k = -1;
    int res_cnt = 0;
    int i = 1;


    while (i < argc){
        if (strcmp(argv[i], "-k") == 0 && i + 1 < argc) {
            k = atoi(argv[i + 1]);
            char *last_symb_key;
            strtoll(argv[i + 1], &last_symb_key, 10);

            if(*last_symb_key == '\0'){
                break;
            }
            else{
                printf("Неверное значение ключа дешифрования\n");
                return 1;
            }
        }
    i++;
    }


    if(k == -1){
        printf("Неверный флаг или значение.\n");
        return 1;
    }
    i = 1;

    while (i + 2 < argc){
        if(i + 2 < argc){
            int l_op = atoi(argv[i]);
            char znak = argv[i + 1][0];
            int r_op = atoi(argv[i + 2]);
            
            char *last_symb_l;
            char *last_symb_r;
            
            strtoll(argv[i], &last_symb_l, 10);
            strtoll(argv[i + 2], &last_symb_r, 10);
            
            if(*last_symb_l =='\0' && *last_symb_r == '\0'){

                results[res_cnt] = calc(l_op, znak, r_op);
    
                printf("Результат %d: %d\n", res_cnt + 1, results[res_cnt]);

                res_cnt++;

                i += 3; //Рассматриваем следующую тройку элементов
            }
            else{
                printf("Ошибка в операндах\n");
                return(1);
            }

        }
    }

    printf("\nРезультирующая строка: ");

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
    printf("\n");
    res_stroka[res_cnt] = '\0';
    free(results);
    free(res_stroka);

    return 0;
}