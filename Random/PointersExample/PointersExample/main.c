#include "stdio.h"
#include "stdint.h"
#include "myMath.h"


/***************************************************************************************/
void swap(uint8_t* a, uint8_t* b) {
	uint8_t tmp = *a;
	*a = *b;
	*b = tmp;
}

void printSwap() {
    uint8_t x = 5;
    uint8_t y = 10;
    printf("x = %d, y = %d => swap()\n", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
}

/***************************************************************************************/
/* void pointer / wildcard */
void printData(void* ptr, char type) {
    switch (type) {
    case 'i':
        printf("Integer value: %d\n", *(int*)ptr);
        break;
    case 'd':
        printf("Double value: %f\n", *(double*)ptr);
        break;
    case 'f':
        printf("Float value: %f\n", *(float*)ptr);
        break;
    case 'c':
        printf("Character value: %c\n", *(char*)ptr);
        break;
    default:
        printf("Unknown type!\n");
    }
}

void dataPrinter() {
    int num = 42;
    double dec = 1.823;
    float pi = 3.14f;
    char letter = 'A';

    printData(&num, 'i');
    printData(&dec, 'd');
    printData(&pi, 'f');
    printData(&letter, 'c');
}

/***************************************************************************************/
void calc() {
    int numA = 151;
    int numB = 14;

    int result = add(numA, numB);
    printData(&result, 'i');
    result = sub(numA, numB);
    printData(&result, 'i');
    result = mul(numA, numB);
    printData(&result, 'i');
    double resultX = division(numA, numB);
    printData(&resultX, 'd');
    result = pow(numA, numB);
    printData(&result, 'i');
}

/***************************************************************************************/
void altCalc(int (*operation)(int, int)) {
    int numA = 151;
    int numB = 14;

    int result = operation(numA, numB);

    printData(&result, 'i');
}

/***************************************************************************************/
int main() 
{
    printSwap();
    dataPrinter();
    calc();
    altCalc(&add);

    return 0;
}
