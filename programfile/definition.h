#include<stdio.h>
#include<limits.h>
#define true 1
#define false 0
typedef int boolean;
typedef struct{
    unsigned int Productnumbers;
    char SerialNumber[8];
    char name[40];
    char type[20];
    char manufacturers[100];
    double price;
    unsigned int numbers;
}products;
typedef struct{
    products productions[100000];
    int len;
}ProLists;