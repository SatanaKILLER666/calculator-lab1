#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"calc.h"

//Функция для вычисления результата

int calc(int l_op, char znak, int r_op){
    switch(znak){
        case '+':
            return l_op + r_op;
        case '-':
            return l_op - r_op;
        case '*':
            return l_op * r_op;
        case '%':
            if(r_op == 0){
                printf("Деление на ноль\n");
                exit(1);
            }
            return l_op % r_op;
        default:
            printf("Введён некорректный оператор\n");
            exit(2);
    }
}


//Функция преобразования результирующей текстовой строки

char decrypt(int res, int k) { 
    return (char)(res - k);
}
