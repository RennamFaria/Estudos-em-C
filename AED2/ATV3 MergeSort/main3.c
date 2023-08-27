#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    int data;
    struct node* next;
};
 
struct node* sortedmerge(struct node* esq, struct node* dir);
void frontbacksplit(struct node* head, struct node** esq, struct node** dir);
 
 
void mergesort(struct node** headRef)
{
    struct node* head = *headRef;
    struct node* esq;
    struct node* dir;
    if ((head == NULL) || (head -> next == NULL))
    {
        return;
    }
    frontbacksplit(head, &esq, &dir);
    mergesort(&esq);
    mergesort(&dir);
    *headRef = sortedmerge(esq, dir);
}
 
struct node* sortedmerge(struct node* esq, struct node* dir)
{
    struct node* result = NULL;
 
    if (esq == NULL)
        return(dir);
    else if (dir == NULL)
        return(esq);
 
    if ( esq-> data <= dir -> data)
    {
        result = esq;
        result -> next = sortedmerge(esq -> next, dir);
    }
    else
    {
        result = dir;
        result -> next = sortedmerge(esq, dir->next);
    }
    return(result);
}
 
void frontbacksplit(struct node* head, struct node** esq, struct node** dir)
{
    struct node* fast;
    struct node* slow;
    if (head==NULL || head->next==NULL){
        *esq = head;
        *dir = NULL;
    }
    else{
        slow = head;
        fast = head -> next;
        while (fast != NULL){
            fast = fast -> next;
            if (fast != NULL){
                slow = slow -> next;
                fast = fast -> next;
            }
    }
 
    *esq = head;
    *dir = slow -> next;
    slow -> next = NULL;
    }
}
 
void printlist(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node -> data);
        node = node -> next;
    }
}
 
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main()
{
    struct node* esq = NULL;
    push(&esq, 15);
    push(&esq, 10);
    push(&esq, 5);
    push(&esq, 20);
    push(&esq, 3);
    push(&esq, 26775);
    mergesort(&esq);
    printf("\n Sorted Linked List is: \n");
    printlist(esq);
    return 0;
}