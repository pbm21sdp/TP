#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Aplicatia 3.1 Implementati pe calculator structura de date stiva, asa cum este descrisa in laborator. 

#define MAX_SIZE 100
int top = -1;
int stack[MAX_SIZE];

void push(int item) 
{
     if(top == MAX_SIZE-1)
      {
        printf("Stiva este plina\n");
        return;
      }
 stack[++top] = item;
}

int pop() 
{
     if(top == -1)
      {
        printf("Stiva este goala\n");
        return -1;
      }
 return stack[top--];
}

void display() 
{
     if(top == -1) 
     {
        printf("Stiva este goala\n");
        return;
     }
 printf("Elementele din stiva sunt: ");
 for(int i=top; i>=0; i--)
 printf("%d ",stack[i]);
 printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    display();
    printf("Elementul extras din stiva: %d\n", pop());
    display();
    printf("Elementul extras din stiva: %d\n", pop());
    display();
    printf("Elementul extras din stiva: %d\n", pop());
    display();
    return 0;
}
*/

/*Aplicatia 3.2 Implementati pe calculator structura de date coada, asa cum este descrisa in
laborator.

#define MAX_SIZE 100
int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue(int item) 
{
    if(rear == MAX_SIZE-1) 
    { 
        printf("Coada este plina\n");
        return;
    }
    if(front == -1) front = 0;
 queue[++rear] = item;
}

int dequeue() 
{
    if(front == -1 || front > rear) 
    {
        printf("Coada este goala\n");
        return -1;
    }
 return queue[front++];
}

void display()
 {
    if(front == -1 || front > rear)
     {
        printf("Coada este goala\n");
        return;
     }
 printf("Elementele din coada sunt: ");
    for(int i=front; i<=rear; i++)
        printf("%d ",queue[i]);
 printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    printf("Elementul extras din coada: %d\n",dequeue());
    display();
    printf("Elementul extras din coada: %d\n",dequeue());
    display();
    printf("Elementul extras din coada: %d\n",dequeue());
    display();
    return 0;
}
*/

/*Aplicatia 3.4 Sa se implementeze cu ajutorul unei cozi un buffer care retine temporar informatiile
primite de la diversi transmitatori (informatia este adaugata in coada) si le transmite mai apoi catre
un receptor (informatia este eliminata din coada). Informatia primita in buffer are urmatoare
structura: numar identificare transmitator (int), mesaj (sir de caractere de maxim 256 caractere).*/

#define MAX_LUNGIME 256 //lungimea maxima a mesajului
#define MAX_COADA 60 //lungimea maxima a cozii
int front = -1, rear = -1;
int queue[MAX_COADA];

struct infromatie 
{
    int numar_identificare;
    char mesaj[MAX_LUNGIME];
};



