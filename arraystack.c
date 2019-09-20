/*
1) creation
2) push(int element)
3) pop()
4)traverse()
5) isEmpty()
6) isFull()
7) size()
LIFO = last in first out
C Program to Implement all the stack operation using Static Array
@author - APdebian
@email - apdeban@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5 // pre-processor macro
int stack[CAPACITY],top = -1;
// function declaration
void push(int);
int pop(void);
void peek(void);
void traverse(void);
int isFull(void);
int isEmpty(void);

// driver function

void main()
{
  int ch,item;
  while(1)
  {
    printf("1.Push \n");
    printf("2.Pop \n");
    printf("3.Peek \n");
    printf("4.Traverse \n");
    printf("5.Quit \n");
    printf("enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : printf("Enter element: ");
               scanf("%d",&item);
               push(item);
               break;
      case 2 : item = pop();
               if(item==0)
               {
                 printf("Stack is Underflow \n");
               }
               else
               {
                 printf("element %d is popped.......\n",item);
               }
               break;
      case 3 : peek();
               break;
      case 4 : traverse();
               break;
      case 5 : exit(1);
      default : printf("invalid options \n");
    }
  }
}

// push the element in the stack
void push(int ele)
{
  if(isFull())
  {
    printf("Stack is overflow \n");
  }
  else
  {
    top++;
    stack[top] = ele;
    printf("%d element pushed.....\n",ele);
  }
}

// check the stack is full or not
int isFull(void)
{
  if(top == CAPACITY -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// pop the element from stack
int pop(void)
{
  if(isEmpty())
  {

    return 0;
  }
  else
  {
    return stack[top--];
  }
}
// check stack is empty or not
int isEmpty(void)
{
  if(top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// peek the element from stack
void peek(void)
{
  if(isEmpty())
  {
    printf("stack is empty \n");
  }
  else
  {
    printf("peek element : %d \n",stack[top]);
  }
}

// display the element of the stack
void traverse(void)
{

    if(isEmpty())
    {
      printf("stack is empty \n");
    }
    else
    {
      int i;
      printf("Stack element : \n");
      for(i=0;i<=top;i++)
      {
        printf("%d \n",stack[i]);
      }
    }
}
