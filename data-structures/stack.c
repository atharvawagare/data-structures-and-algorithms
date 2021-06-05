#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

void push(int);
int pop();
void peak();

int ele, ch, top=-1, item;
int stack[CAPACITY];

void main(){

	while(1){

		printf("\nChoices are :: \n");
		printf("1. Push The Element\n");
		printf("2. Pop The Element\n");
		printf("3. Find Peak Element\n");
		printf("4. Traverse The Stack\n");
		printf("5. Quit\n");
		printf("Choice > ");
		
		scanf("%d", &ch);

		switch(ch){

			case 1:
				printf("\nElement > ");
				scanf("%d", &ele);
				push(ele);
				break;
			case 2:
				item=pop();
				if(item!=0){
					printf("\n\n%d has Popped\n\n", item);	
				}
				break;

			case 3:
				peak();
				break;

			case 4:
				printf("\nStack is \n");
				for(int i=CAPACITY-1; i>=0; i--){
					printf("%d\n", stack[i]);
				}
				break;

			case 5:
				exit(0);
				break;

			default:
				printf("\n\nInvalid Input. Enter Proper Choice.\n\n");

		}
	}
}

void push(int ele){

	if(top==CAPACITY-1){
		printf("Stack is Full. Element Cannot Be Pushed.\n");
	}
	else{
		top+=1;
		stack[top]=ele;
		printf("%d is Successfully Pushed in Stack.\n", ele);
	}

}

int pop(){
	if(top==-1){	
		printf("\n\nStack Is Empty (Stack is Underflow)\n\n");
	}
	else{
		item=stack[top];
		stack[top]=0;
		top=top-1;
		return item;
	}
}

void peak(){
	if(top==-1){
		printf("\n\nStack Is Empty (Stack is Underflow)\n\n");
	}
	else{
		printf("\n\nPeak Element is %d\n\n", stack[top]);
	}
}