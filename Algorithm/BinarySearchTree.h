#pragma once

#include "Basic.h"

typedef int T ;											// Template for understanding

typedef struct BinarySearchTreeNode
{
	T m_Data ;
	struct BinarySearchTreeNode * m_pLeft ;
	struct BinarySearchTreeNode * m_pRight ;
} BSTNode ;

BSTNode * BST_CreateNode ( T Data ) ;											// Create BT Node and return it
void BST_DestroyNode ( BSTNode * pNode ) ;										// Destroy BT Node
void BST_DestroyTree ( BSTNode * pRoot ) ;										// Destroy tree from Root to Leaf

BSTNode * BST_SearchNode ( BSTNode * pRoot , T Data ) ;							// Search BSTNode that have Data
BSTNode * BST_SearchMinNode ( BSTNode * pRoot ) ;								// Search BSTNode that have min value
void BST_InsertNode ( BSTNode * pRoot , BSTNode * pNode ) ;						// Insert pNode into BST
BSTNode * BST_RemoveNode ( BSTNode * pRoot , BSTNode * pParent , T Data ) ;		// Remove BSTNode with Data
void BST_InorderPrintTree ( BSTNode * pRoot ) ;									// Print tree with inorder