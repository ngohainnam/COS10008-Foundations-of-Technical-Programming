
/*Hai Nam Ngo
Student No 10348815*/

//Question 4

#include<stdio.h>  
#include<stdbool.h>  //for true/false function. True is creating loop and False is exiting program.

void main()
{
	
int a=30,b=60,c=90;  //seats
int choice;
int tickets,concession,kids;
bool program=true;
float price;


//Creating a loop when program is true (still running)
while(program)
{
	
	//display options for tickets
	printf("1 - Class A\n");
	printf("2 - Class B\n");
	printf("3 - Class C\n");
	printf("4 - Current Availability\n");
	printf("5 - Exit\n");
	printf("Enter your option...\n");

	scanf("%d",&choice);
	switch(choice)
		{

		//if chossing Class A	
		case 1: 
		//Enter number of ticket for each section
		printf("How many full tickets ...\n");
		scanf("%d",&tickets);
		printf("How many concession tickets -Senior and children under 12 and above 3 ...\n");
		scanf("%d",&concession);
		printf("How many kids under 3 years...\n");
		scanf("%d",&kids);

		//if entering the higher number of ticket than actual avalaible ammount
		if((tickets+concession+kids)>a)
			{
				printf("Less tickets available than required ...\n");
				printf("Total available in class A is %d\n",a);
				printf("Class B is %d\n",b);
				printf("Class C is %d\n",c);
				printf("\n");
				printf("\n");
			}
		else
			{
				//if tickets are still available
				a=a-(tickets+concession+kids);
				price=price+(25*tickets+15*concession);
				printf("Your total ticket price = %.2f\n",price);
				printf("\n");
				printf("\n");
			}
		break;

		//if chossing Class B
		case 2:
		printf("How many full tickets ...\n");
		scanf("%d",&tickets);
		printf("How many concession tickets -Senior and children under 12 and above 3 ...\n");
		scanf("%d",&concession);
		printf("How many kids under 3 years...\n");
		scanf("%d",&kids);

		if((tickets+concession+kids)>b)
			{
				printf("Less tickets available than required ...\n");
				printf("Total available in class B is %d\n",b);
				printf("Class A is %d\n",a);
				printf("Class C is %d\n",c);
				printf("\n");
				printf("\n");
			}
		else
			{
				b=b-(tickets+concession+kids);
				price=price+(15*tickets+10*concession);
				printf("Your total ticket price = %.2f\n",price);
				printf("\n");
				printf("\n");
			}
		break;

		//if chossing Class C
		case 3:
		printf("How many full tickets ...\n");
		scanf("%d",&tickets);
		printf("How many concession tickets -Senior and children under 12 and above 3 ...\n");
		scanf("%d",&concession);
		printf("How many kids under 3 years...\n");
		scanf("%d",&kids);
		
		if((tickets+concession+kids)>c)
			{
				printf("Less tickets available than required ...\n");
				printf("Total available in class C is %d\n",c);
				printf("Class A is %d\n",a);
				printf("Class B is %d\n",b);
				printf("\n");
				printf("\n");
			}
		else
			{
				c=c-(tickets+concession+kids);
				price=price+(9*tickets+5*concession);
				printf("Your total ticket price = %.2f\n",price);
				printf("\n");
				printf("\n");
			}
		break;

		case 4:
		//printing total available tickets
		printf("Total available\n");
		printf("Class A is %d\n",a);
		printf("Class B is %d\n",b);
		printf("Class C is %d\n",c);
		printf("\n");
		printf("\n");
		break;

		case 5:
		//printing total available tickets
		printf("Total available\n");
		printf("Class A is %d\n",a);
		printf("Class B is %d\n",b);
		printf("Class C is %d\n",c);

		//if false then end the loop (exit the program)
		program=false;  
		}
	}
}