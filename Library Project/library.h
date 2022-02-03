/********************************************************************************
 * File        : Library.h
 * Description : Library Interface
 * Author      : Omar Mohamed Ali
 * Date        : 28/12/20201
 * Version     : 1.0
 *********************************************************************************/
 
/*********************************************************************************
                             << File Guard >>
**********************************************************************************/
#ifndef Library_H_
#define Library_H_

/*********************************************************************************
                           << File Inclusions >>
**********************************************************************************/
#include "library_config.h"


/*********************************************************************************
                        << User Defined Data Types >>
**********************************************************************************/
typedef struct
{
	u16   Book_Number;
	char *Author_Name[30];
	char *Name[30] ;
	u32   Price ;
}Book_t; 

typedef struct
{
	LIBRARY_ENTRY entry[MAX_LIBRARY_SIZE];
	u32 size;
}Library_t; 

/*********************************************************************************
                           << Function Prototypes >>
**********************************************************************************/

/********************************************************************* 
 * Prototype   : Function_Status_t LibraryInit(Library_t *ptr);
 * Description : Initialize My Library.
 * Arguments   : Library_t *ptr
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t LibraryInit(Library_t *ptr);

/********************************************************************* 
 * Prototype   : LibraryState_t LibraryEmpty(Library_t *ptr);
 * Description : this function check if library is empty or not. 
 * Arguments   : Library_t *ptr
 * return      : LibraryState_t
 **********************************************************************/
LibraryState_t LibraryEmpty(Library_t *ptr);

/********************************************************************* 
 * Prototype   : LibraryState_t LibraryFull(Library_t *ptr);
 * Description : this function check if library is full or not. 
 * Arguments   : Library_t *ptr
 * return      : LibraryState_t
 **********************************************************************/
LibraryState_t LibraryFull(Library_t *ptr);

/********************************************************************* 
 * Prototype   : Function_Status_t DeleteAllBooks(Library_t *ptr);
 * Description : this function delete all books in library.
 * Arguments   : Library_t *ptr
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t DeleteAllBooks(Library_t *ptr);

/********************************************************************* 
 * Prototype   : Function_Status_t AddBookToLibrary(Library_t *ptr , s32 p);
 * Description : this function Add Book To Library.
 * Arguments   : Library_t *ptr and  s32 p
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t AddBookToLibrary(Library_t *ptr , s32 p);

/********************************************************************* 
 * Prototype   : Function_Status_t NumberOfBooksInMyLibrary(Library_t *ptr, u32 *size_ptr);
 * Description : this function get Number Of Books In My Library.
 * Arguments   : Library_t *ptr and  u32 *size_ptr
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t NumberOfBooksInMyLibrary(Library_t *ptr, u32 *size_ptr);

/********************************************************************* 
 * Prototype   : Function_Status_t ViewAllBooks(Library_t *ptr);
 * Description : this function to View All Books.
 * Arguments   : Library_t *ptr
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t ViewAllBooks(Library_t *ptr);

/********************************************************************* 
 * Prototype   : Function_Status_t DeleteSpecificBook(Library_t *ptr, s32 p);
 * Description : this function to Delete Specific Book.
 * Arguments   : Library_t *ptr and s32 p
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t DeleteSpecificBook(Library_t *ptr, s32 p);

/********************************************************************* 
 * Prototype   : Function_Status_t ReplaceBook(Library_t *ptr, s32 p);
 * Description : this function to Replace Book.
 * Arguments   : Library_t *ptr and s32 p
 * return      : Function_Status_t
 **********************************************************************/
Function_Status_t ReplaceBook(Library_t *ptr, s32 p);

#endif