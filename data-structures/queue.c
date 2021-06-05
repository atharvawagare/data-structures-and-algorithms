#include<stdio.h>
#include<stdlib.h>

#define CAPACITY 5

void insert(int);
void delete();
void traverse();

int ch, ele, rear=0, front=0, i;
int queue[CAPACITY];

void main(){

	while(1){

		printf("\nChoices are :: \n");
		printf("1. Insert element\n");
		printf("2. Traverse queue\n");
		printf("3. Delete element\n");
		printf("4. Exit\n");
		printf("Choice > ");
		scanf("%d", &ch);

		switch(ch){

			case 1:
				if(rear==CAPACITY){
					printf("\nQueue is overflow.\n");
				}
				else{
					printf("Element > ");
					scanf("%d", &ele);
					insert(ele);
				}
				break;

			case 2:
				if(front==rear){
					printf("\nQueue is Empty.\n");
				}
				else{
					traverse();	
				}
				break;

			case 3:
				if(front==rear){
					printf("\nQueue is Already Empty.\n");
				}
				else{
					delete();	
				}
				break;

			case 4:
				exit(0);
				break;

			default:
				printf("\n\nInvalid Input. Enter Proper Choice.\n\n");
		}
	}
}

void insert(int ele){
	queue[rear]=ele;
	rear++;
}

void delete(){

	printf("\n%d is Deleted.\n", queue[front]);

	for(i=0; i<rear-1; i++){
		queue[i]=queue[i+1];
	}

	rear--;
}

void traverse(){

	printf("\nThe Queue is as follows ::\n");

	for(i=front; i<rear; i++){
		printf("%d\n", queue[i]);
	}
}





