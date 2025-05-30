#include<stdio.h>
#define n 5
int top=-1; int stack[n];
int main()
	{
		int choice; 
		void push(); 
		void display(); 
		void pop(); 
		void peep(); 
		void change();
		printf("Choose The Operation you want to perform:\n0 for Display Stack\n1 for PUSH\n2 for POP\n3 for PEEP\n4 to Change\n5 to Exit\n\n");
		do
		{
			printf("\n ");
			printf("\nEnter choosed Operation:");
			scanf("%d",&choice);
			switch(choice)
			{
				case 0: display();
				break;
				
				case 1: push();
				break; 
				
				case 2: pop();
 				break; 
				 
				case 3:	peep();
				break; 
				
				case 4:	change();
				break; 
				
				case 5:
					printf("Exited!"); 
					break;
				
				default:
					printf("Invalid Number!");
			}
		}while(choice<5 || choice>6); 
		
		getc;
		return 0;
	}
void display()
	{
		if(top==-1)
		{
			printf("\nStack Underflow!\n");
		}
		else
		{
			for(int i=0;i<=n;i++)
			{
				printf("\nThe value of Index %d is %d",i,stack[i]);
			}
		}
	}

void push()
	{
		int value; 
		if(top==10)
		{
			printf("\nStack Overflowed!\n");
		}
		else
		{
			for(top=0;top<=n;top++)
			{
				printf("Enter value of Index %d:",top); 
				scanf("%d",&value);
				stack[top]=value;
			}
		}
	}

void pop()
	{ 
		int i; 
		if(top==-1)
		{
			printf("/nStack Underflow!");
		}
		else
		{
			printf("POP Operation performed on Stack"); 
			for(top=n;top>-1;top--)
			{
				stack[top]=0;
			}
		}
	}

void peep()
	{
		int i; 
		if(top==-1)
		{
			printf("\nStack Underflow!");
		}
		else
		{
			printf("Enter value of Index:"); 
			scanf("%d",&i);
			
			if(top-i<0)
			{
				printf("No Value Stored at the Index!!\n");
			}
			printf("Value at TOP is %d",stack[i]);
		}
	}

void change()
	{
		int i;
		int value;
		if(top==-1)
		{
			printf("\nStack Underflow!");
		}
		else
		{
			printf("Choose the Index you want to PEEP:"); 
			scanf("%d",&i);
			printf("Enter the new Value:"); 
			scanf("%d",&value); 
			stack[i]=value;
		}
	}
