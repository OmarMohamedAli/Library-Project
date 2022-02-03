/********************************************************************************
 * File        : main.c
 * Description : Main Library Programm
 * Author      : Omar Mohamed Ali
 * Date        : 30/12/20201
 * Version     : 1.0
 *********************************************************************************/

/*********************************************************************************
                           << File Inclusions >>
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "library.h"

/*********************************************************************************
                           << Entry Point>>
**********************************************************************************/
void main()
{
	u8 State=0;
	Library_t Library;
	LibraryInit(&Library);
	
	printf("#################################################################\n");
	printf(" ---------------------> [HELLO TO MY APP] <--------------------- \n");
	printf("#################################################################\n");
	printf("#################################################################\n");
	printf("Welcome to My Library App\n");
	
	while(1)
	{
		printf("#################################################################\n");
		printf("(1) to ADD an New Book          : Please Enter Number -> 1\n");
		printf("(2) to Replace a Book           : Please Enter Number -> 2\n");
		printf("(3) to Delelte a Book           : Please Enter Number -> 3\n");
		printf("(4) to View All Books           : Please Enter Number -> 4\n");
		printf("(5) to Delelte All Books        : Please Enter Number -> 5\n");
		printf("(6) to show Number of Books     : Please Enter Number -> 6\n");
		printf("(7) to show if Library is Empty : Please Enter Number -> 7\n");
		printf("(8) to show if Library is Full  : Please Enter Number -> 8\n");
		printf("(9) to Exit Library App         : Please Enter Number -> 9\n");
		printf("#################################################################\n");
		printf("Please Enter Your Choice:");
		scanf("%d",&State);
		printf("#################################################################\n");
		
		u8 Number;
		u32 size;
		
		switch(State)
		{
			case 1:
			    printf("#################################################################\n");
				AddBookToLibrary(&Library,Library.size);
				printf(".................... [THANKS] ..................\n");
				printf("#################################################################\n");
				break;
				
			case 2:
				printf("#################################################################\n");
				printf("YOUR BOOKS BEFORE REPLACEMENT\n");
				printf("----------------------------------------------\n");
				ViewAllBooks(&Library);
				printf("Please Enter your Book Number To be Replaced: ");
				scanf("%d",&Number);
				printf("**********************************************\n");
				ReplaceBook(&Library,Number);
				printf("YOUR BOOKS AFTER REPLACEMENT\n");
				ViewAllBooks(&Library);
				printf("#################################################################\n");
				break;
				
			case 3:
				printf("#################################################################\n");
			    printf("YOUR BOOKS BEFORE DELETE\n");
				printf("----------------------------------------------\n");
				ViewAllBooks(&Library);
				printf("Please Enter your Book Number To be Deleted: ");
				scanf("%d",&Number);
				printf("**********************************************\n");
				DeleteSpecificBook(&Library,Number);
				printf("**********************************************\n");
				printf("YOUR BOOKS AFTER DELETE\n");
				ViewAllBooks(&Library);
				printf("#################################################################\n");
				break;
				
			case 4:
			    printf("#################################################################\n");
				ViewAllBooks(&Library);
				printf("#################################################################\n");
				break;
				
			case 5:
			    printf("#################################################################\n");
				DeleteAllBooks(&Library);
				//printf("#################################################################\n");
				break;
				
			case 6:
			    printf("#################################################################\n");
				NumberOfBooksInMyLibrary(&Library,&size);
				printf("Number of Books in your Library:%d \n",size);
				//printf("#################################################################\n");
				break;
				
			case 7:
			    printf("#################################################################\n");
				LibraryEmpty(&Library);
				//printf("#################################################################\n");
				break;
				
			case 8:
			    printf("#################################################################\n");
				LibraryFull(&Library);
				//printf("#################################################################\n");
				break;
				
			case 9:
				exit(0);
				break;
				
			default:
				printf("Incorrect Choice\n");
				break;
				
		}
	}
}

