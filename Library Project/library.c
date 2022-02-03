/********************************************************************************
 * File        : Library.c.c
 * Description : Library.c Programm
 * Author      : Omar Mohamed Ali
 * Date        : 28/12/20201
 * Version     : 1.0
 *********************************************************************************/

/*********************************************************************************
                           << File Inclusions >>
**********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "library.h"

/*********************************************************************************
                           << Function Implementation >>
**********************************************************************************/

/********************************************************************* 
 * Prototype   : Function_Status_t LibraryInit(Library_t *ptr);
 * Description : Initialize My Library.
 * Arguments   : Library_t *ptr
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t LibraryInit(Library_t *ptr)
{
	Function_Status_t ReturnValue;
	// Input Pararmeter Check
	if(NULL == ptr)               
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		// at size ZERO ,No Book.
		ptr->size=0; 
		ReturnValue = RET_OK;
	}
	return ReturnValue;
}

/********************************************************************* 
 * Prototype   : LibraryState_t LibraryEmpty(Library_t *ptr);
 * Description : this function check if library is empty or not. 
 * Arguments   : Library_t *ptr
 * return      : LibraryState_t
 **********************************************************************/
LibraryState_t LibraryEmpty(Library_t *ptr)
{
	Function_Status_t ReturnValue;
	// Input Pararmeter Check
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
	}
	else
	{
		if( 0 == ptr->size)
		{
			ReturnValue = LIBRARY_EMPTY;
			printf("Library is Empty \n");
		}
		else
		{
			ReturnValue = LIBRARY_NEMPTY;
			printf("Library is Not Empty \n");
		}
	}
	return ReturnValue;
}

/********************************************************************* 
 * Prototype   : LibraryState_t LibraryFull(Library_t *ptr);
 * Description : this function check if library is full or not. 
 * Arguments   : Library_t *ptr
 * return      : LibraryState_t
 **********************************************************************/
LibraryState_t LibraryFull(Library_t *ptr)
{
	Function_Status_t ReturnValue;
	// Input Pararmeter Check
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
	}
	else
	{
		if( MAX_LIBRARY_SIZE == ptr->size)
		{
			ReturnValue = LIBRARY_FULL;
			printf("Library is Full \n");
		}
		else
		{
			ReturnValue = LIBRARY_NFULL;
			printf("Library is Not Full \n");
		}
	}
	return ReturnValue;
}

/********************************************************************* 
 * Prototype   : Function_Status_t DeleteAllBooks(Library_t *ptr);
 * Description : this function delete all books in library.
 * Arguments   : Library_t *ptr
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t DeleteAllBooks(Library_t *ptr)
{
	Function_Status_t ReturnValue;
	// Input Pararmeter Check
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		ptr->size = 0;
		ReturnValue = RET_OK;
	}
	return ReturnValue;
}

/********************************************************************* 
 * Prototype   : Function_Status_t AddBookToLibrary(Library_t *ptr , s32 p);
 * Description : this function Add Book To Library.
 * Arguments   : Library_t *ptr and  s32 p
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t AddBookToLibrary(Library_t *ptr , s32 p)  
{
	Function_Status_t ReturnValue;
	// Input Pararmeter Check
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		if((p >= 0) && (p <= (ptr->size)))
		{
			s32 counter=0;
			for(counter = (ptr->size)-1 ; counter>=p ; counter--)
			{
				ptr->entry[counter+1] = ptr->entry[counter];
			
			}
			
			printf("Please Enter Book Name: ");
			scanf(" %s",&(ptr->entry[p].Name));
			
			
			printf("Please Enter Author Name: ");
			scanf(" %s",&(ptr->entry[p].Author_Name));
		
			
			printf("Please Enter Book Price: ");
			scanf(" %d",&(ptr->entry[p].Price));
			
			ptr->size++;
			ReturnValue = RET_OK;
		}
		else
		{
			printf("Error position Out of Renge\n");
			ReturnValue = RET_OUT_OF_RANGE;
		}
	}
	return ReturnValue;
}

/********************************************************************* 
 * Prototype   : Function_Status_t NumberOfBooksInMyLibrary(Library_t *ptr, u32 *size_ptr);
 * Description : this function get Number Of Books In My Library.
 * Arguments   : Library_t *ptr and  u32 *size_ptr
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t NumberOfBooksInMyLibrary(Library_t *ptr, u32 *size_ptr)
{
	Function_Status_t ReturnValue;
	// Input Pararmeter Check
	if(NULL == ptr || NULL == size_ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		*size_ptr = ptr->size;
		ReturnValue = RET_OK;
	}
	return ReturnValue;
}

/********************************************************************* 
 * Prototype   : Function_Status_t ViewAllBooks(Library_t *ptr);
 * Description : this function to View All Books.
 * Arguments   : Library_t *ptr
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t ViewAllBooks(Library_t *ptr)
{
	Function_Status_t ReturnValue;
	// Input Pararmeter Check
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		if(ptr->size > 0)
		{
			u32 counter;
			for(counter=0 ; counter<(ptr->size) ; counter++)
			{
				printf("Book Number:%d\n",counter);
				printf("Book Name:%s\n",ptr->entry[counter].Name);
				printf("Author Name:%s\n",ptr->entry[counter].Author_Name);
				printf("Price:%d$\n",ptr->entry[counter].Price);
				printf("----------------------------------------------\n");
			}
			ReturnValue = RET_OK;
		}
		else 
		{
			printf("Library is Empty\n");
			ReturnValue = LIBRARY_EMPTY;
		}
	}
	return ReturnValue;	
}

/********************************************************************* 
 * Prototype   : Function_Status_t DeleteSpecificBook(Library_t *ptr, s32 p);
 * Description : this function to Delete Specific Book.
 * Arguments   : Library_t *ptr and s32 p
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t DeleteSpecificBook(Library_t *ptr, s32 p)          // problem
{
	Function_Status_t ReturnValue;
	// Input Pararmeter Check
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		
		if((p >= 0) && (p <= (ptr->size-1)) && (ptr->size >0))
		{
			for(s32 counter = p+1 ; (counter<=ptr->size-1) ; counter++)
			{
				ptr->entry[counter-1] = ptr->entry[counter]; 
			}
			ptr->size--;
			ReturnValue = RET_OK;
		}
		else
		{
			printf("Error position Out of Renge\n");
			ReturnValue = RET_OUT_OF_RANGE;
		}
	}
	return ReturnValue;
}

/********************************************************************* 
 * Prototype   : Function_Status_t ReplaceBook(Library_t *ptr, s32 p);
 * Description : this function to Replace Book.
 * Arguments   : Library_t *ptr and s32 p
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t ReplaceBook(Library_t *ptr, s32 p)         // problem
{
	Function_Status_t ReturnValue;
	// Input Pararmeter Check
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		if((p >= 0) && (p <= (ptr->size-1))  && (ptr->size >0))
		{
			printf("Please Enter Book Name: ");
			scanf(" %s",&(ptr->entry[p].Name));
			
			printf("Please Enter Author Name: ");
			scanf(" %s",&(ptr->entry[p].Author_Name));
			
			printf("Please Enter Book Price: ");
			scanf(" %d",&(ptr->entry[p].Price));
			
			ReturnValue = RET_OK;
		}
		else
		{
			printf("Error position Out of Range\n");
			ReturnValue = RET_OUT_OF_RANGE;
		}
	}
	return ReturnValue;	
} 


