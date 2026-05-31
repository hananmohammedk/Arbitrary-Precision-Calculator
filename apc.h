#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define SUCCESS 0
#define FAILURE 1

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}dll;

int insert(int data, dll**head,dll**tail);
void print(dll *head);
int validate(char *num1,char *opr,char*num2);
int addition(dll**,dll**,dll**,dll**,dll**,dll**);
int insert_res(int num,dll**,dll**);
int subtraction(dll**,dll**,dll**,dll**,dll**,dll**);
int compare(dll**,dll**);
int leading_zero(dll **, dll **);
int multiplication(dll**,dll**,dll**,dll**,dll**,dll**);
int division(dll**,dll**,dll**,dll**,dll**,dll**);
int negative_sign(dll**,dll**);

#endif