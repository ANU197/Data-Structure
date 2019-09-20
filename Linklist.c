/*
1) append
2) addatafter
3) addatbegin
4) length of linklist
5) display linklist
6) delete
7) swap the element
8) reverse the linklist
C Program to Implement all the Linklist operations
@author - apdeban@gmail.com
*/
#include<stdio.h>
#include<stdlib.h>
//create a linklist node
struct node
{
  int data;
  struct node* link;
};
// root or head node
struct node* root = NULL;
//function declaration
void append(void);
void addatafter();
void addatbegin(void);
int length(void);
void display(void);
void delete(void);
void swap(void);
void reverse(void);

//declare the global variable
int len,loc;
// driver function
void main()
{
  int ch;
  while(1)
  {
    printf("Single Linklist operation : \n");
    printf("1.Append \n");
    printf("2.add at begining \n");
    printf("3.add at after \n");
    printf("4.length \n");
    printf("5.display \n");
    printf("6.delete \n");
    printf("7.Swap the node \n");
    printf("8.Reverse the linklist \n");
    printf("9.quit \n");
    printf("enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1 : append();
               break;
      case 2 : addatbegin();
               break;
      case 3 : addatafter();
               break;
      case 4 : len = length();
               printf("\nLength : %d \n",len);
               break;
      case 5 : display();
               break;
      case 6 : delete();
               break;
      case 7 : swap();
               break;
      case 8 : reverse();
               break;
      case 9 : exit(1);
      default : printf("invalid options");
    }
  }
}


// Append the node
void append(void)
{
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  printf("enter node data: ");
  scanf("%d",&temp->data);
  if(root==NULL)
  {
    root = temp;
  }
  else
  {
    struct node* p;
    p = root;
    while(p->link != NULL)
    {
      p = p->link;
    }
    p->link = temp;
  }
}

// add at begin
void addatbegin(void)
{
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  printf("enter node data: ");
  scanf("%d",&temp->data);
  temp->link = root;
  root = temp;

}

// add at after
void addatafter()
{
  struct node* temp, *p;
  int loc;
  int len,i=1;
  len = length();
  printf("enter the location to insert data: ");
  scanf("%d",&loc);
  if(loc>len)
  {
    printf("invalid loc \n");
    printf("list is having %d node \n",len);
  }
  else
  {
    p = root;
    while(i<loc)
    {
      p = p->link;
      i++;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    printf("enter node data: ");
    scanf("%d",&temp->data);
    temp->link = p->link;
    p->link = temp;
  }

}

// find the length of total node
int length(void)
{
  struct node* temp;
  int count = 0;
  temp = root;
  if(temp == NULL)
  {
    printf("List is empty ");
  }
  else
  {
    while(temp != NULL)
    {
      temp = temp->link;
      count++;
    }
  }
  return count;
}

// display the node element
void display(void)
{
  struct node* temp;
  temp = root;
  if(temp == NULL)
  {
    printf("List is empty \n");
  }
  else
  {
    while(temp != NULL)
    {
      printf("%d -> ",temp->data);
      temp = temp->link;

    }
    printf("\n\n");
  }
}

// delete the element at nth location
void delete(void)
{
  struct node* temp;
  struct node* p,*q;
  int loc,i=1;
  len = length();
  printf("enter the location to delete: ");
  scanf("%d",&loc);
  if(loc>len)
  {
    printf("Invalid Location\n");
    printf("Linklist contain %d node",len);
  }
  else if(loc == 1)
  {
    temp = root;
    root = temp->link;
    temp->link = NULL;
    free(temp);
  }
  else
  {
    p = root;
    while(i < loc-1)
    {
      p = p->link;
      i++;
    }
    q = p->link;
    p->link = q->link;
    q->link = NULL;
    free(q);
  }
}

// swap the node
void swap(void)
{
  struct node* r;
  struct node* p,*q;
  int loc,i=1;
  len = length();
  printf("enter the location to swap: ");
  scanf("%d",&loc);
  p = root;
  while(i<loc-1)
  {
    p = p->link;
    i++;
  }
  q = p->link;
  r = q->link;
  q->link = r->link;
  r->link = q;
  p->link = r;
}

// reverse the linklist
void reverse(void)
{
  int i=0,k,temp,len;
  len = length();
  int j = len - 1;
  struct node* p,*q;
  p = q = root;
  while(i<j)
  {
    k =0;
    while(k<j)
    {
      q = q->link;
      k++;
    }
    temp = p->data;
    p->data = q->data;
    q->data = temp;
    i++;
    j--;
    p = p->link;
    q = root;
  }

}
