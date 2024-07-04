#ifndef DEFINITION_H
#define DEFINITION_H
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <limits.h>
#define true 1
#define false 0
#define MAX 100000
typedef int boolean;
typedef struct {
    int SerialNumber;
    char name[40];
    char type[20];
    char manufacturers[100];
    double price;
    unsigned int numbers;
} products;
typedef struct {
    products productions[MAX];
    int len;
} ProLists;
FILE *fp;
#endif // DEFINITION_H