#pragma once

#include "Basic.h"

typedef int T ;																// Template for understanding

typedef struct ArrayStack
{
	T * m_rgData ;
	int m_iCapacity ;														// Current capacity
	int m_iMinCapacity ;													// Minimum capacity
	int m_iCnt ;
} ArrayStack ;

void AS_CreateStack ( ArrayStack ** pArrayStack , int iCapacity ) ;			// Create stack with array
void AS_DestroyStack ( ArrayStack ** pArrayStack ) ;						// Destroy stack
void AS_Push ( ArrayStack ** pArrayStack , T Data ) ;						// Push T data into stack
void AS_ExpandIfFull ( ArrayStack ** pArrayStack ) ;						// Expand array if array is full
T AS_Pop ( ArrayStack ** pArrayStack ) ;									// Pop T
void AS_ReduceIfSmall ( ArrayStack ** pArrayStack ) ;						// Reduce array if m_iCnt * 2 <= m_iCapacity
int AS_GetSize ( ArrayStack * pArrayStack ) ;								// Return current stack size
bool AS_IsEmpty ( ArrayStack * pArrayStack ) ;								// Return true if empty