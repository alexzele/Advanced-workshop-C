//אלכס זלנצוב 321233256
//מייק רוז 312691207

#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#define N_A 3
#define M_A 2
#define N_B 2
#define M_B 3


void Ex1();
int* PowerArray(int );
void PrintArray(int* , int );
void Ex2();
int * InputMatrix_a(int a[][M_A], int , int );
int * InputMatrix_b(int b[][M_B], int , int );
void PrintMatrixStart_a(int a[][M_A], int , int );
void PrintMatrixStart_b(int b[][M_B], int , int );
int** MultiplicationMatrices(int a[][M_A], int , int , int b[][M_B], int , int , int* , int* );
void PrintMatrixDin(int**, int , int );
void FreeMatrixDin(int **, int , int );
void Ex3();
void PrintArrayTrio(Shlashot* , int );
int ** CreateMatrixDin(int* , int*);
int EqualIndex(int** , int , int , Shlashot** array, ListShlashot** );
void Ex4();
list* OrderOddEven(list** );
void Ex5();
list* OddEvenList (list** );

int main(){
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu one or cyclically?\n (once- enter 0, cyclically-enter any other number )\n");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do {
			for (i = 1; i <= 5; i++)
				printf("Ex %d--->%d\n", i, i);
			printf("Exit--->0\n");
			do {
				select = 0;
				printf("please select 0-5: \n");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 5));
			switch (select) {
			case 1:
				Ex1();
				break;
			case 2: 
				Ex2();
				break;
			case 3:
				Ex3();
				break;
			case 4:
				Ex4 ();
				break;
			case 5:
				Ex5 ();
				break;
			}
		} 
		while (all_Ex_in_loop && select);
			return 0;
}


int* PowerArray(int n)
{
	int i;
	int *a;
	if (n > 0){
		a = (int*)malloc(sizeof(int)*n);
		if (!a){
			printf("Error not enogh space to the Array!\n");
			return NULL;
		}
		a[0] = 1;
		for (i = 1; i < n; i++){
			a[i] = a[i - 1] * 2;
		}
		return a;
	}
	else{
		printf("Error the number %d can not be a size of array\n", n);
		return NULL;
	}
}
void PrintArray(int* a, int size)
{
	int i;
	printf("Your array is:\n");
	for (i = 0; i < size; i++){
		printf("%d\n", a[i]);
	}
	printf("\n");
}
void Ex1()
{
	int  size, flage;
	int *a;
	printf("Please insert the size of you array\n");
	scanf("%d", &size);
	if (size > 31){
		printf("Worning the number that you will be compute is to big...!\n");
		printf("To stop press 0 \n else press any key\n");
		scanf("%d", &flage);
		if (!flage)
			return;
	}
	a = PowerArray(size);
	if (a){
		PrintArray(a, size);
		free(a);
	}
}
int* InputMatrix_a(int a[][M_A], int row, int coll){
	int i, j;
	printf("Please enter %d element of your matrix:\n", row*coll);
	for (i = 0; i < row; i++){
		for (j = 0; j < coll; j++){
			scanf("%d", &a[i][j]);
		}
	}
	return a;
}
int * InputMatrix_b(int b[][M_B], int row, int coll){
	int i, j;
	printf("Please enter %d element of your matrix:\n", row*coll);
	for (i = 0; i < row; i++){
		for (j = 0; j < coll; j++){
			scanf("%d", &b[i][j]);
		}
	}
	return b;
}
void PrintMatrixStart_a(int a[][M_A], int row, int coll){
	int i, j;
	printf("Your matrix:\n");
	for (i = 0; i < row; i++){
		for (j = 0; j < coll; j++){
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}
void PrintMatrixStart_b(int b[][M_B], int row, int coll){
	int i, j;
	printf("Your matrix:\n");
	for (i = 0; i < row; i++){
		for (j = 0; j < coll; j++)
		{
			printf("%3d", b[i][j]);
		}
		printf("\n");
	}
}
void PrintMatrixDin(int **m, int row, int coll){
	int i, j;
	printf("The matrix:\n");
	for (i = 0; i < row; i++){
		for (j = 0; j < coll; j++){
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
}
void FreeMatrixDin(int **m, int row, int coll){
	int i, j;
	for (i = 0; i < row; i++)
	{
		free(m[i]);
	}
	free(m);
}
int** MultiplicationMatrices(int a[][M_A], int row_a, int coll_a, int b[][M_B], int row_b, int coll_b, int *new_row, int* new_coll)
{
	int i, j, k = 0, row_new, coll_new, sum_temp = 0, **new_matrix, *first_matrix, *second_matrix;

	if ((coll_a != row_b) && (coll_b != row_a)){
		printf("Error this tow matricis can't be multiplication...!\n");
		return NULL;
	}

	if ((coll_a == row_b)){
		row_new = row_a;
		coll_new = coll_b;
	}
	else {//(row_a==coll_b)
		row_new = row_b;
		coll_new = coll_a;
	}
	new_matrix = (int**)malloc(sizeof(int*)*row_new);
	for (i = 0; i < row_new; i++){
		new_matrix[i] = (int*)malloc(sizeof(int)*coll_new);
	}
	if ((coll_a == row_b)){
		for (i = 0; i < row_new; i++){
			for (j = 0; j < coll_new; j++){
				sum_temp = 0;
				for (k = 0; k < row_b; k++){
					sum_temp = sum_temp + (a[i][k])*(b[k][j]);
				}
				new_matrix[i][j] = sum_temp;
			}
		}
	}
	else
	{
		for (i = 0; i < row_new; i++){
			for (j = 0; j < coll_new; j++){
				sum_temp = 0;
				for (k = 0; k < row_a; k++){
					sum_temp = sum_temp + (b[i][k])*(a[k][j]);
				}
				new_matrix[i][j] = sum_temp;
			}
		}
	}
	*new_row = row_new;
	*new_coll = coll_new;
	return new_matrix;
}
void Ex2(){
	int A[N_A][M_A], B[N_B][M_B];
	int row_a = N_A, coll_a = M_A, row_b = N_B, coll_b = M_B, new_row, new_coll;
	int* a, *b, **m;
	a = InputMatrix_a(A, row_a, coll_a);
	b = InputMatrix_b(B, row_b, coll_b);
	PrintMatrixStart_a(a, row_a, coll_a);
	PrintMatrixStart_b(b, row_b, coll_b);
	m = MultiplicationMatrices(a, row_a, coll_a, b, row_b, coll_b, &new_row, &new_coll);
	if (m){
		printf("Matrix after the multiplication\n");
		PrintMatrixDin(m, new_row, new_coll);
		FreeMatrixDin(m, new_row, new_coll);
	}
}
int EqualIndex(int **m, int row, int coll, Shlashot** array, ListShlashot **list){
	int i, j, k = 0, size_arr = 0;
	Shlashot* arr;
	ListShlashot *l, *last;
	l = CreateList();
	last = l;

	for (i = 0; i < row; i++){
		for (j = 0; j < coll; j++){
			if (m[i][j] == (i + j))	{
				InputAfterShlashotList(last, i, j, m[i][j]);
				last = last->next;
				size_arr++;
			}
		}
	}
	if (size_arr == 0){
		return 0;
	}
	arr = (Shlashot*)malloc(size_arr * sizeof(Shlashot));
	last = l->next;
	for (i = 0; i < size_arr; i++){
		arr[i] = last->data;
		last = last->next;
	}
	*list = l;
	*array = arr;
	return size_arr;
}
int ** CreateMatrixDin(int* row, int*coll){
	int i, j, r, c;
	int **m;
	printf("Please Enter the size of your matrix: (rows and colls)\n");
	scanf("%d %d", &r, &c);
	if ((r <= 0) || (c <= 0)){
		printf("Error the size %dX%d can not be size of matrix\n", r, c);
		return NULL;
	}
	m = (int**)malloc(r * sizeof(int*));
	for (i = 0; i < r; i++){
		m[i] = (int*)malloc(c * sizeof(int));
	}
	printf("Please enter %d elements of matrix:\n", c*r);
	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++){
			scanf("%d", &m[i][j]);
		}
	}
	*row = r;
	*coll = c;
	return m;
}
void PrintArrayTrio(Shlashot* arr, int size){
	int i;
	printf("The array:\n");
	printf("value | row | coll\n");
	for (i = 0; i < size; i++){
		printf("%3d   |%2d   | %3d\n", arr[i].value, arr[i].i, arr[i].j);
	}
}
void Ex3(){
	int** m, row, coll, count;
	Shlashot *arr;
	ListShlashot *l;
	m = CreateMatrixDin(&row, &coll);
	if (!m){
		return;
	}
	PrintMatrixDin(m, row, coll);
	count = EqualIndex(m, row, coll, &arr, &l);
	printf("The number of elemets that equal to the idexes is %d\n", count);
	if (count){
		PrintArrayTrio(arr, count);
		PrintListTrio(l);
		free(arr);
		FreeListShlashot(l);
		FreeMatrixDin(m, row, coll);
	}

}
list* OrderOddEven(list** l){
	list *list_odd, *temp, *temp_prev, *last_odd;
	if ((*l) == NULL){
		printf("The list is empty...\n");
		return NULL;
	}
	InsertFirst(&list_odd, 0);
	list_odd->next = NULL;
	last_odd = list_odd;
	while (*l){
		if (((*l)->value) % 2 != 0){
			InsertAfter(&list_odd, last_odd, (*l)->value);
			DeleteFirst(l);
			last_odd = last_odd->next;
		}
		else break;
	}
	temp = *l;
	temp_prev = temp;
	while (temp){
		if ((temp->value) % 2 == 0){
			temp_prev = temp;
			temp = temp->next;
		}
		else{
			InsertAfter(&list_odd, last_odd, temp->value);
			last_odd = last_odd->next;
			DeleteAfter(l, temp_prev);
			temp = temp_prev->next;
		}
	}
	DeleteFirst(&list_odd);
	return list_odd;
}
void Ex4(){
	list*l, *odd_list;
	l = InputList();
	printf("The list that you insert: ");
	PrintList(l);
	odd_list = OrderOddEven(&l);
	printf("Even list: ");
	PrintList(l);
	printf("Odd list: ");
	PrintList(odd_list);
	FreeList(odd_list);
	FreeList(l);
}
void Ex5(){
	list*l, *odd_list;
	l = InputList();
	printf("The list that you insert: ");
	PrintList(l);
	odd_list = OddEvenList(&l);
	printf("Even list: ");
	PrintList(l);
	printf("Odd list: ");
	PrintList(odd_list);
	FreeList(odd_list);
	FreeList(l);

}
list* OddEvenList (list ** ls){ // פונקציה לתרגיל 5
	list * pivot = *ls;
	list * prev_node = NULL;
	list * head_odd_list = NULL;
	list * curr_odd_list = NULL;
	while (pivot){
		if (pivot->value%2!=0){
			if (!prev_node && !head_odd_list){			
				head_odd_list = pivot;
				pivot=pivot->next;
				*ls = pivot;
				head_odd_list->next = NULL;
				curr_odd_list=head_odd_list;
			}
			else{										
				if(!head_odd_list){						
					head_odd_list = pivot;
					prev_node->next=pivot->next;
					pivot=pivot->next;
					head_odd_list->next = NULL;
					curr_odd_list=head_odd_list;
				}
				else{				
					if (!prev_node){
							curr_odd_list->next=pivot;
							pivot=pivot->next;
							*ls = pivot;
							curr_odd_list=curr_odd_list->next;
							curr_odd_list->next = NULL;
					}
					else{			
					curr_odd_list->next=pivot;
					prev_node->next=pivot->next;
					pivot=pivot->next;
					curr_odd_list=curr_odd_list->next;
					curr_odd_list->next = NULL;
					}	
				}
			}
		}
		else{
			prev_node=pivot;
			pivot=pivot->next;
		}
	}
	return head_odd_list;
}


