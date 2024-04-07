#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printA (int a)
{
    printf("a=%d", a);
    printf("\n");
}

void printB (int b)
{
    printf("b=%d", b);
    printf("\n");
}

int *returnParam (int *a)
{
    return a;
    printf("\n");
}

int *func (int *a)
{
    int *b;
    b = a;
    return (int *)b;
    printf("\n");
}

int compare(int a, int b)
{
    return a - b;
    printf("\n");
}

int compareInvers(int a, int b)
{
    return b-a;
    printf("\n");
}

void printArray(int *array, unsigned int size)
{
    for(unsigned int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

typedef int(*CompareCondition)(int, int);

void BubbleSort(int *array, unsigned int size, CompareCondition compareFunction)
{
    bool hasSwapped = false;
    do
    {
        hasSwapped = false;
        for(unsigned int i =0; i < size -1; ++i)
        {
            if(compareFunction(array[i], array[i+1]) > 0)
            {
                int tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
                hasSwapped = true;
            }
        }
    } while(hasSwapped);
}

int qsortCompare(const void *a, const void *b)
{
    return(*(int *)a) - (*(int *)b);
}

struct Product;
typedef struct Product Product;

typedef struct ProductOperations
{
    void(*printProduct)(Product *product);
}ProductOperations;

struct Product
{
    ProductOperations *productOperations;
};

typedef struct Computer
{
    Product product;
    char *cpuName;
    int memory;
} Computer;

typedef struct Monitor
{
    Product product;
    double diagonal;
    int horizontalResoution;
    int verticalResolution;
} Monitor;

void printComputer(Product *p)
{
    Computer *c = (Computer *)p;
    printf("Computer: %s, %d\n", c->cpuName, c->memory);
}

void printMonitor(Product *p)
{
    Monitor *m = (Monitor *)p;
    printf("Monitor: %lf %d\n", m->diagonal, m->horizontalResoution);
}

ProductOperations computerOperations = {printComputer};
ProductOperations monitorOperations = {printMonitor};

//check alloc errors
Computer *newComputer()
{
    Computer *computer = (Computer *)malloc(sizeof(Computer));
    computer->product.productOperations = &computerOperations;
    computer->memory = 16;
    computer->cpuName = "intel";

    return computer;
}

Monitor *newMonitor()
{
    Monitor *monitor = (Monitor *)malloc(sizeof(Monitor));
    monitor->product.productOperations = &monitorOperations;
    monitor->diagonal = 24;
    monitor->horizontalResoution = 1920;
    monitor->verticalResolution = 1000;
    return monitor;
}

void printProduct(Product *product)
{
    product->productOperations->printProduct(product);
}

void TestProductImplementation()
{   
    Product *computer = (Product *)(newComputer());
    Product *monitor = (Product *)(newMonitor());

    printProduct(computer);
    printProduct(monitor);

    free(computer);
    free(monitor);
}
int main()
{
    void(*fprintA)(int) = &printA;
    (*fprintA)(2);

    void(*fprintA2)(int) = printA;
    fprintA2(3);

    void(*fprint[])(int) = {printA, printB};
    (fprint[1])(3);
    (*fprint[0])(5);

    int *(*rez)(int *) = &returnParam;

    int *a, b = 2;
    a = &b;
    printf("returnParam = %d\n", *rez(a));

    {
        int *a, b =2;
        a = &b;

        int*(*tab[10])(int *);
        tab[0] = func;
        tab[1] = func;

        printf("func=%d\n", *tab[0](a));
    }

    int array[] = {5, 3, 1, 10};

    BubbleSort(array, 4, compare);
    printArray(array, 4);

    BubbleSort(array, 4, compareInvers);
    printArray(array, 4);

    qsort(array, 4, sizeof(int), qsortCompare);
    printArray(array, 4);

    TestProductImplementation();

    return 0;
}