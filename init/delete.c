#include <stdio.h>
#include<stdlib.h>



struct node{
int data;
struct node *link;
};



struct node *head;



void create_ll(int data)
{
struct node *tmp = (struct node *) malloc(sizeof(struct node));
struct node *tmp2;
if (tmp == NULL)
return;



tmp->data = data;
if(head == NULL)
head = tmp;
else
{
tmp2 = head;
while(tmp2->link != NULL)
tmp2 = tmp2 ->link;
tmp2->link = tmp;
}
}




void del_pos(struct node **head,int pos){
struct node *current = *head;
struct node *previous = *head;
if(*head==NULL){
printf("List is empty\n");
}
else if(pos == 1){
*head = current->link;
current = NULL;
}
else{
while(pos != 1){
previous = current;
current = current->link;
pos--;
}
previous->link = current->link;
current=NULL;
}



}




int main()
{
create_ll(10);
create_ll(20);
create_ll(30);
create_ll(40);
int pos = 1;
del_pos(&head,pos);
struct node *ptr = head;
while(ptr!=NULL){
printf("%d-->",ptr->data);
ptr=ptr->link;
}
printf("NULL\n");
return 0;
}