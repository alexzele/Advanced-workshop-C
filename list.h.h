#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int value;
	int i;
	int j;
}Shlashot;

typedef struct ListShlashot {
	Shlashot data;
	struct ListShlashot* next;
}ListShlashot;

typedef struct List {
	int value;
	struct List *next;
}list;
void InputAfterShlashotList(ListShlashot* , int , int , int );
ListShlashot* CreatelistShlashot();
void FreeListShlashot(ListShlashot *);
void PrintListTrio(ListShlashot* );
void InsertAfter(list **, list *, int );
void InsertFirst(list **, int key);
void DeleteFirst(list **);
void DeleteAfter(list ** , list * );
list* CreateList();
list* InputList();
void PrintList(list *);
void FreeList(list* );


