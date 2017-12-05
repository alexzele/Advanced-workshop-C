#include<stdio.h>
#include<stdlib.h>
#include "list.h"


void InputAfterShlashotList(ListShlashot* last, int i, int j, int value){
	last->next = (ListShlashot*) malloc(sizeof(ListShlashot));
	last->next->data.value = value;
	last->next->data.i = i;
	last->next->data.j = j;
	last->next->next = NULL;
}
ListShlashot* CreatelistShlashot(){
	ListShlashot* node;
	node = (ListShlashot*)malloc(sizeof(ListShlashot));
	node->data.i = NULL;
	node->data.j = NULL;
	node->data.value = NULL;
	node->next = NULL;
	return node;
}
void FreeListShlashot(ListShlashot *l){
	ListShlashot *temp, *temp_next;
	temp = l;
	while (temp->next){
		temp_next = temp->next;
		free(temp);
		temp = temp_next;
	}
	free(temp);
}



void PrintListTrio(ListShlashot* l){
	ListShlashot *temp;
	temp = l->next;
	printf("the list :\n");
	printf("value | row | coll\n");
	while (temp){
		printf(" _________|_________\n");
		printf("|%3d   |%3d  | %3d  |\n", temp->data.value, temp->data.i, temp->data.j);
		printf("|______|_____|______|\n");
		printf("          |\n");
		printf("          |\n");
		temp = temp->next;
	}
}

void InsertAfter(list **head, list *prev, int key){
	list *newNode = (list *)malloc(sizeof(list));
	newNode->value = key;
	newNode->next = prev->next;
	prev->next = newNode;
}
void InsertFirst(list **head, int key){
	list *newNode = (list *)malloc(sizeof(list));
	newNode->value = key;
	newNode->next = *head;
	*head = newNode;
}
void DeleteFirst(list **head){
	list *temp;
	temp = (*head);
	(*head) = (*head)->next;
	free(temp);
}
void DeleteAfter(list ** head, list * prev){
	list *temp;
	temp = prev->next;
	if (!(temp))
		return;
	prev->next = temp->next;
	free(temp);
}
list* CreateList(){
	list l;
	l.next = NULL;
	return &l;
}
list* InputList(){
	int size, i, num;
	list *temp, *l = NULL;
	printf("Please enter the size of your list:\n");
	scanf("%d",&size);
	if (size < 0){
		printf("Error %d can not be a size of list\n",size);
		return NULL;
	}
	if (size == 0){
		return NULL;
	}
	printf("Enter %d elements of your list:\n", size);
	InsertFirst(&l, 0);
	l->next = NULL;
	temp = l;
	for (i = 0; i < size; i++){
		scanf("%d", &num);
		if (num<0){
			printf("You Enter a negative number please insert agian:\n");
			scanf("%d", &num);
		}

		InsertAfter(&l, temp, num);
		temp = temp->next;
	}
	DeleteFirst(&l);
	return l;
}

	
void PrintList(list *l){
	list* temp = l;
	if (!l){
		printf("The List is empty...\n");
		return;
	}
	while (temp->next){
		printf("|%d|---> ", temp->value);
		temp = temp->next;
	}
	printf("|%d|\n", temp->value);
}
void FreeList(list* l){
	list* temp,*temp_prev;
	temp = l;
	temp_prev = temp;
	while (temp){
		temp = temp->next;
		free(temp_prev);
		temp_prev = temp;
	}
}



