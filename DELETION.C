#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int n;
 struct node *next;
}*start;
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
 int choice,num;
 struct node *n;
 start=NULL;
 printf("Deletion Operations On Linked List\n");
 do
 {
  printf("Select Operation From 1 To 5\n");
  printf("1. Deletion At The Beginning\n");
  printf("2. Deletion At The End\n");
  printf("3. Deletion At The Specific Position\n");
  printf("4. Traversal\n");
  printf("5. Exit\n");
  printf("Enter Your Choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1: delete_begin();
		   break;
   case 2: delete_end();
		   break;
   case 3: if (start==NULL)
           {
		    printf("List Is Empty\n");
		   }
		   else
		   {
		    printf("Enter The Number To Delete : ");
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
   case 4: if (start==NULL)
           {
		    printf("List Is Empty\n");
		   }
		   else
		   {
		    printf("Elements In The List : ");
		   }
		   traversal(n);
		   break;
   case 5: printf("Program Ended\n"); 
  }
 }while (choice!=5);
 getch();
}
