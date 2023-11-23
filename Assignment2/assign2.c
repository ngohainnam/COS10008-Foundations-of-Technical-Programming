#include <stdio.h> //include standard input and output library
#include <stdlib.h> //include standard library 
#include <string.h> //include string library

//enumeration to define burger type
enum burger_type{Chicken,Ham,Vegie};

//structure for burger
struct Burger
{
    enum burger_type btype; //field to store type of burger
    int burger_quantity; //field to store quantity of burger
}Burger;

//structure for chips
struct Chips
{
    char chip_desc[20]; //field to store description of chips
    int chips_quantity; //field to store quantity of chips
}Chips;

//structure for drinks
struct Drinks
{
    char drink_desc[20]; //field to store description of drinks
    int drink_quantity; //field to store quantity of drinks
}Drinks;

//structure for meals
struct Meals
{
    struct Burger *Burgers_ptr; //pointer to store burger
    struct Chips *Chips_ptr; //pointer to store chips
    struct Drinks *Drinks_ptr; //pointer to store drinks
}Meals;

//structure for order
struct order
{
    char receipt_no[5]; //field to store receipt number
    double order_price; //field to store order price
    struct Meals *Meals_ptr; //pointer to store meals
    struct Burger *Burgers_ptr; //pointer to store burger
    struct Chips *Chips_ptr; //pointer to store chips
    struct Drinks *Drinks_ptr; //pointer to store drinks
}order;

//function to order meals
void meals (struct order**order_count, int order_number)
{
    char meal_choice,order_more;
    int amount=0;

    //loop to allow user to select meal type and quantity
    do 
    {
		printf("-------------------------- \n");
        printf("Select the Meal Type\n");
        printf("A - Big Chicken Meal - $20\n");
        printf("B - Big Ham Meal - $22\n");
        printf("C - Big Vegie Meal - $18\n");
        printf("X - To return to Main Menu\n");
        scanf(" %c", &meal_choice);
        
        //switch statement to process user's choice
        switch (meal_choice)
        {
            case 'A':
			case 'a':
                printf("\nYou have selected Big Chicken Meal. How many meals do you wish to order? \n");
                scanf("%d", &amount);
                //increment burger quantity and order price
                order_count[order_number]->Burgers_ptr->burger_quantity += amount;
                order_count[order_number]->order_price += amount * 20;
                break;
				
            case 'B':
			case 'b':
                printf("\nYou have selected Big Ham Meal. How many meals do you wish to order? \n");
                scanf("%d", &amount);
                //increment burger quantity and order price
                order_count[order_number]->Burgers_ptr->burger_quantity += amount;
                order_count[order_number]->order_price += amount * 22;
				break;
				
	        case 'C':
			case 'c':
				printf("\nYou have selected Big Vegie Meal. How many meals do you wish to order? \n");
				scanf("%d", &amount);
				//increment burger quantity and order price
				order_count[order_number]->Burgers_ptr->burger_quantity += amount;
				order_count[order_number]->order_price += amount * 18;
				break;
				
			case 'X':
			case 'x':
				return; //exit the function
				
			default : 
				printf("Wrong option. Please try again. \n");
				break;
		}

		printf("Your current bill value is $%.2lf\n", order_count[order_number]->order_price); //display current bill value
		
		//ask user if they want to add more meals to the order
		printf("Press 'Y' to add more meals into your order or Press 'X' to go back to the previous menu. \n");
		scanf(" %c", &order_more);  

		switch(order_more)
		{
			case 'Y':
			case 'y':
				break;
			
			case 'X':
			case 'x':
				return; //exit the function
				break;
			
			default:
				printf("Wrong option. Please try again. \n");
				break;
		}
	}while(order_more=='Y'||order_more=='y');
}
//creating function for order burger
void burgers (struct order**order_count, int order_number)
{
    char burger_choice,order_more; // Declare two variables, burger_choice and order_more, as character data types
    int burger_price, current_burger_amount=0; // Declare two variables, burger_price and current_burger_amount, as integer data types and initialize current_burger_amount to 0
        
    do
    {
		printf("--------------------------\n"); // Prints a line of dashes as a separator
		printf("Select the Burger Type \n"); // Prints a prompt asking the user to select a burger type
		printf("A - Chicken Burger - 15$ \n"); // Prints the option for a chicken burger with its price
		printf("B - Ham Burger - 17$ \n"); // Prints the option for a ham burger with its price
		printf("C - Vegie Burger - 13$  \n"); // Prints the option for a vegie burger with its price
        printf("X - To return to Main Menu \n"); // Prints the option to return to the main menu
		printf("Select your option: \n"); // Prints a prompt asking the user to select an option
		scanf(" %c", &burger_choice); // Reads the user's input and stores it in the variable burger_choice
        
        switch (burger_choice) // Using a switch statement to check the value of burger_choice
        {
 			case 'A':
			case 'a': // If the user selects 'A' or 'a'
				order_count[order_number]->Burgers_ptr->btype = Chicken; // Set the btype of the order to Chicken
				burger_price = 15; // Set the burger price to 15
				break;

			case 'B':
			case 'b': // If the user selects 'B' or 'b'
				order_count[order_number]->Burgers_ptr->btype = Ham; // Set the btype of the order to Ham
				burger_price = 17; // Set the burger price to 17
				break;

			case 'C':
			case 'c': // If the user selects 'C' or 'c'
				order_count[order_number]->Burgers_ptr->btype = Vegie; // Set the btype of the order to Vegie
				burger_price = 13; // Set the burger price to 13
				break;
				
			case 'X':
			case 'x': // If the user selects 'X' or 'x'
				return; // Exit the function
				break;

			default:
				printf("Wrong option. Please try again. \n"); // If the user enters an invalid option
				return; // Exit the function
				break;
		}
		printf("--------------------------\n"); 	
		//This print sentence will print out the burger type according to user's choice.
		printf("You have selected a %s burger. How many burgers you wish you order? \n", order_count[order_number]->Burgers_ptr->btype == Chicken ? "Chicken" : order_count[order_number]->Burgers_ptr->btype == Ham ? "Ham" : "Vegie"); 

		scanf("%d", &current_burger_amount); // Reads the user's input and stores it in the variable current_burger_amount
		order_count[order_number]->Burgers_ptr->burger_quantity += current_burger_amount; // Add the current_burger_amount to the burger_quantity of the order
		order_count[order_number]->order_price += current_burger_amount * burger_price; // Calculate the price of the order by adding the current_burger_amount multiplied by the burger_price
		
		printf("Your current bill value is $%.2lf\n", order_count[order_number]->order_price); // Prints the current value of the order
		
		printf("Press 'Y' to add more burgers into your order or Press 'X' to go back to the previous menu. \n"); // Prompts the user to either add more burgers or return to the previous menu
		scanf(" %c", &order_more); // Reads the user's input and stores it in the variable order_more

		switch(order_more) // Using a switch statement to check the value of order_more
		{
			case 'Y':
			case 'y': // If the user selects 'Y' or 'y'
			break; // Continue the loop
			
			case 'X':
			case 'x': // If the user selects 'X' or 'x'
			return; // Exit the function
			break;
			
			default:
			printf("Wrong option. Please try again. \n"); // If the user enters an invalid option
			return; // Exit the function
			break;
		}		
	}while(order_more=='Y'||order_more=='y'); // Repeat the loop as long as the user selects 'Y' or 'y' to add more burgers
}

//creating function for order chips
void chips (struct order**order_count, int order_number)
{
    order_count[order_number]->Chips_ptr = (struct Chips*)malloc(sizeof(Chips));  // Allocate memory for the chips struct using malloc and assign the address to the Chips_ptr of the order
	
    strcpy(order_count[order_number]->Chips_ptr->chip_desc, "Chips"); // Copy the string "Chips" to the chip_desc field of the chips struct
    printf("You have selected %s. How many chips do you wish to order?\n", order_count[order_number]->Chips_ptr->chip_desc); // Prints a statement that shows the chips the user has selected and prompts the user to enter the number of chips they wish to order
    scanf("%d", &order_count[order_number]->Chips_ptr->chips_quantity); // Reads the user's input and stores it in the variable chips_quantity of the chips struct

    order_count[order_number]->order_price += order_count[order_number]->Chips_ptr->chips_quantity * 5; // Calculate the price of the order by adding the chips_quantity multiplied by the price of each chip
    printf("Your current bill value is $%.2lf\n", order_count[order_number]->order_price); // Prints the current value of the order
}

//creating function for order drinks
void drinks (struct order**order_count, int order_number)
{
    order_count[order_number]->Drinks_ptr = (struct Drinks*)malloc(sizeof(Drinks)); // Allocate memory for the drinks struct using malloc and assign the address to the Drinks_ptr of the order

    strcpy(order_count[order_number]->Drinks_ptr->drink_desc, "Cold Drinks"); // Copy the string "Cold Drinks" to the drink_desc field of the drinks struct
    printf("You have selected %s. How many cold drinks do you wish to order?\n", order_count[order_number]->Drinks_ptr->drink_desc); // Prints a statement that shows the drinks the user has selected and prompts the user to enter the number of drinks they wish to order
    scanf("%d", &order_count[order_number]->Drinks_ptr->drink_quantity); // Reads the user's input and stores it in the variable drink_quantity of the drinks struct

    order_count[order_number]->order_price += order_count[order_number]->Drinks_ptr->drink_quantity * 3.5; // Calculate the price of the order by adding the drink_quantity multiplied by the price of each drink
    printf("Your current bill value is $%.2lf\n\n", order_count[order_number]->order_price); // Prints the current value of the order
}

//creating function for process order
double process_order (struct order**order_count, int order_number)
{
	//if the system cannot find any order from the user
    if (order_count[order_number]->order_price == 0)
    {
        printf("You don't have any order at the moment. \n");
        return 0;
    }
    
	//print out the total bill for the current order
    printf("\nYour total bill is $%.2lf\n", order_count[order_number]->order_price);
    
	//if condition: the total order bill is more than or equal to 100
    if (order_count[order_number]->order_price >= 100)
    {
        printf("Discount 15%% for bills over $100: $%.2lf.\n", (order_count[order_number]->order_price/100)*15); //generate the discount 15% of the order
		
        order_count[order_number]->order_price = order_count[order_number]->order_price - ((order_count[order_number]->order_price/100)*15); //caculate the final bill value after discount (old bill value - discount)
		
	    printf("\nThe final bill value is $%.2lf.\n", order_count[order_number]->order_price); //print out the final price
    }
	
	//else if condition: if the order has more than 5 burgers in the order
    else if (order_count[order_number]->Burgers_ptr->burger_quantity >= 5)
    {
        printf("Discount 10%% for 5 or more burger orders: $%.2lf.\n", (order_count[order_number]->order_price/100)*10); //generate the discount 10% of the order
		
        order_count[order_number]->order_price = order_count[order_number]->order_price - ((order_count[order_number]->order_price/100)*10); //caculate the final bill value after discount (old bill value - discount)
		
		printf("\nThe final bill value is $%.2lf.\n", order_count[order_number]->order_price);  //print out the final price
    }
    
	//create the receipt number format "Bxxx", order will auto generated from B001.
    sprintf(order_count[order_number]->receipt_no, "B%03d", order_number+1);
    printf("Your receipt number is %s.\n", order_count[order_number]->receipt_no);
    printf("Please go to a register and make the payment by quoting the Receipt Number - %s.\n", order_count[order_number]->receipt_no);
	
    printf("<<Press any key to show the main menu>>\n");
    getchar();
	getchar();
    return order_count[order_number]->order_price;
}

//function for cancel order
void cancel_order (struct order**order_count, double* total_sales)
{
    char input [5];
    printf("Please enter your Receipt Number:\n");
    scanf("%s", input); //read the input of the customer (the receipt number they want to delete)
    
    for (int order_number = 0; order_number < 25; order_number++)
    {
        if (strcmp(input, order_count[order_number]->receipt_no)== 0) //if condition: if the input and the receipet number in the memory is the same.
        {
            *total_sales -= order_count[order_number]->order_price; //the new total sale = old total sale - final bill of the order that was cancelled
            printf("\nYour order has been cancelled. Thank you.\n");
			
			//free the data from the cancelled order (delete from the memory)
            free(order_count[order_number]);
            free(order_count[order_number]->Meals_ptr);
            free(order_count[order_number]->Burgers_ptr);
            free(order_count[order_number]->Chips_ptr);
            free(order_count[order_number]->Drinks_ptr);
            printf("<<Press any key to show the main menu>>\n");
            getchar();
            getchar();
            return;
        }
    }
	//if the system cannot find the matching value of the receipt number and the user's input, print out "no order found".
    printf("\nOrder not found.\n");
    printf("<<Press any key to show the main menu>>\n");
    getchar();
    getchar();
}

//function to calculate total_revenue (for case 9 in the main function)
double total_revenue (struct order**order_count, int order_number)
{
    if (order_number == 0)
	{
		return order_count[order_number]->order_price;
	}
	else
	{
		return order_count[order_number]->order_price + total_revenue(order_count,order_number-1);
	}
}

//creating main function 
void main()
{
	//declare variable type 
    char choice;
    int order_number = 0;
    double total_sales = 0;
    double current_order = 0;
    
	//allocate an array of 25 pointers to order structure
    struct order**order_count=(struct order**)malloc(25*sizeof(struct order*)); 
    
    for (int order_number = 0; order_number < 25 ; order_number++)
    {
		//create the memory for order structure
        order_count[order_number] = (struct order*)malloc(sizeof(order));
        order_count[order_number]->order_price = 0;
        order_count[order_number]->Burgers_ptr = (struct Burger*)malloc(sizeof(Burger));
        order_count[order_number]->Burgers_ptr->burger_quantity = 0;
    };
   
   //do-while loop to generate the main menu
    do 
    {
		printf("-------------------------- \n");
		printf("Welcome to Tasty Burgers \n");
		printf("Place your order here... \n");
		printf("1. Order Meals \n");
		printf("2. Order Burgers \n");
		printf("3. Order Chips \n");
		printf("4. Order Cold Drinks \n");
		printf("5. Process Order \n");
		printf("6. Cancel \n");
		printf("7. Exit \n");
		printf("Select your option: \n");
        scanf(" %c", &choice);
       
        switch (choice)
        {
            case '1':
                meals(order_count,order_number); //run the meals function if customer choose case 1
                break;
            
            case '2':
                burgers(order_count,order_number); //run the burgers function if customer choose case 2
                break;
            
            case '3':
                chips(order_count,order_number); //run the chips function if customer choose case 3
                break;
            
            case '4':
                drinks(order_count,order_number); //run the drinks function if customer choose case 4
                break;
                
            case '5':
                total_sales += process_order(order_count,order_number); //run the process order function if customer choose case 5
                order_number++;
                break;
                
            case '6':
                cancel_order (order_count,&total_sales); //run the cancel order function if customer choose case 6
                break;
                
            case '7': //blank, but if customer choose 7. The program will end.
                break;
            
            case '9': //hidden function for the manager: display the total revenue
            	printf("Enter the password: ");
            	char input [30];
            	scanf("%s", input); //read the input (password) from the user
            	
            	if (strcmp("TastyBurger", input) == 0) //comparision if the input of the user is the same as the "TastyBurger"
            	{
            		printf("\nPassword Accepted\nYour total revenue is: ");
            		printf("$%.2lf", total_revenue (order_count, order_number)); //print out the total revenue
            		printf("\n\n<<Press Any Key to show the main menu>>");
            		getchar();
					getchar();
            	}
            	else //if the input is not the same as "TastyBurger"            	
            	{
            		printf("Incorrect password.\n");
            	}
				break;
			
			default: //if the user choose any other choice, both integer and varchar.
			printf("Wrong choice.Please try again.\n\n");
				break;			
        }
    }while (choice!= 7); //the program will run as long as the customer doesn't choose case 7
}
