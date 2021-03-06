/********************************************************************************
 * File        : Error States.h
 * Description : Error States
 * Author      : Omar Mohamed Ali
 * Date        : 28/12/20201
 * Version     : 1.0
 *********************************************************************************/
 
/*********************************************************************************
                               << File Guard >>
**********************************************************************************/
#ifndef Error_States_H_
#define Error_States_H_

/*********************************************************************************
                             << File Inclusions >>
**********************************************************************************/
#include "std_types.h"

/*********************************************************************************
                        << Error User Defined Data Types >>
**********************************************************************************/
typedef enum 
{
	LIBRARY_EMPTY,
	LIBRARY_NEMPTY,
	LIBRARY_FULL,
	LIBRARY_NFULL
}LibraryState_t;


typedef enum
{
	RET_OK,
	RET_NOK,
	RET_NULL_PTR,
	RET_OUT_OF_RANGE
}Function_Status_t;

#endif