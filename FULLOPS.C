#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int n;
 struct node *next;
}*start;
void insert_begin(int m)
{
 struct node *temp;
 temp=(struct node *)malloc(sizeof(struct node));
 temp->n=m;
 if (start==NULL)
 {
  start=temp;
  start->next=NULL;
 }
 else
 {
  temp->next=start;
  start=temp;
 }
}
void insert_end(int p)
{
 struct node *temp,*right;
 temp=(struct node *)malloc(sizeof(struct node));
 temp->n=p;
 right=(struct node *)start;
 while (right->next!=NULL)
 right=right->next;
 right->next=temp;
 right=temp;
 right->next=NULL;
}
void insert_specific(int q, int loc)
{
 int i;
 struct node *temp,*left,*right;
 right=start;
 if (loc<=1)
 {
  insert_begin(q);
  return;
 }
 for (i=1;i<loc;i++)
 {
  left=right;
  right=right->next;
  if (right==NULL)
  {
   insert_end(q);
   return;
  }
 }
 temp=(struct node *)malloc(sizeof(struct node));
 temp->n=q;
 temp->next=left->next;
 left->next=temp;
}
int delete_begin()
{
 struct node *temp;
 if (start==NULL)
 {
  return 0;
 }
 else
 {
  temp=start;
  start=start->next;
  printf("Deleted Number Is %d",temp->n);
  return 1;
 }
}
int delete_end()
{
 struct node *temp,*previous;
 if (start==NULL)
 {
  return 0;
 }
 else if ((start)->next==NULL)
 {
  temp=start;
  start=NULL;
  printf("Deleted Number Is %d",temp->n);
  return 1;
 }
 else
 {
  previous=start;
  temp=start->next;
  while (temp->next!=NULL)
  {
   previous=temp;
   temp=temp->next;
  }
  previous->next=NULL;
  printf("Deleted Number Is %d",temp->n);
  return 1;
 }
}
int delete_specific(int m)
{
 struct node *temp,*previous;
 temp=start;
 while (temp!=NULL)
 {
  if (temp->n==m)
  {
   if (temp==start)
   {
    start=temp->next;
	free(temp);
	return 1;
   }
   else
   {
    previous->next=temp->next;
	free(temp);
	return 1;
   } 
  }
  else
  {
   previous=temp;
   temp=temp->next;
  }
 }
 return 0;
}
void traversal(struct node *r)
{
 r=start;
 if (r==NULL)
 {
  return;
 }
 while (r!=NULL)
 {
  printf("%d   ",r->n);
  r=r->next;
 }
 printf("\n");
}
int main()
{
 int choice,num,position;
 struct node *n;
 start=NULL;
 printf("Operations On Linked List\n");
 do
 {
  printf("Select Operation From 1 To 8\n");
  printf("1. Insertion At The Beginning\n");
  printf("2. Insertion At The End\n");
  printf("3. Insertion At The Specific Position\n");
  printf("4. Deletion At The Beginning\n");
  printf("5. Deletion At The End\n");
  printf("6. Deletion The Specific Element\n");
  printf("7. Traversal\n");
  printf("8. Exit\n");
  printf("Enter Your Choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1: printf("Enter The Number To Insert : ");
           scanf("%d",&num);
		   insert_begin(num);
		   break;
   case 2: printf("Enter The Number To Insert : ");
           scanf("%d",&num);
		   insert_end(num);
		   break;
   case 3: printf("Enter The Number To Insert : ");
           scanf("%d",&num);
		   printf("Enter The Position To Insert : ");
		   scanf("%d",&position);
		   insert_specific(num,position);
		   break;
   case 4: delete_begin();
           printf("\n");
		   break;
   case 5: delete_end();
           printf("\n");
		   break;
   case 6: if (start==NULL)
           {
		    printf("List Is Empty!\n");
		   }
		   else
		   {
		    printf("Enter The Element To Delete : ");
            scanf("%d",&num);
			if (delete_specific(num))
			{
			 printf("%d Element Deleted Sucessfully!\n",num);
			}
			else
			{
			 printf("%d Is Not Found In The List!\n",num);
			}
		   }
		   break;
   case 7: if (start==NULL)
           {
		    printf("List Is Empty\n");
		   }
		   else
		   {
		    printf("Elements In The List : ");
		   }
		   traversal(n);
		   break;
   case 8: printf("Program Ended\n"); 
  }
 }while (choice!=8);
 getch();
}
