#pragma once
#include"RBTNode.h"
class BST
{
public:

	void insertElement(int data, BSTNode *& root);
	void checkCases(BSTNode * temp);
	void preOrder(BSTNode * temp);
	void inOrder(BSTNode * temp);
	void postOrder(BSTNode * temp);
	BSTNode * searchElement(BSTNode *root, int num);
	BSTNode * findParent(BSTNode * root, int num);
	BSTNode * findUncle(int num);
	int findMax(BSTNode * temp);
	void Case2(BSTNode * temp, BSTNode * gP, BSTNode * P, BSTNode * U);
	void Case3(BSTNode * temp, BSTNode * gP, BSTNode * P, BSTNode * U);
	void Case4(BSTNode * temp, BSTNode * gP, BSTNode * P, BSTNode * U);

	


	void changeColor(BSTNode *& temp)
	{
		if (temp->color = 'R')
		{
			temp->color = 'B';
		}
		else
		{
			temp->color = 'R';
		}
	}

	void Swap(int & a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	void nodeDeletion(BSTNode * root, int num);
	BST()
	{
		root = nullptr;
	}

};


void BST::insertElement(int data, BSTNode * & root)
{
	BSTNode * temp = new BSTNode;
	temp->data = data;
	temp->color = 'R';

	if (root == nullptr)
	{
		temp->right = nullptr;
		temp->left = nullptr;
		root = temp;
		root->color = 'B';
	}

	else
	{

		BSTNode * search = root;

		while (search != nullptr)
		{
			if (data > search->data)
			{
				if (search->right != nullptr)
				{
					search = search->right;
				}
				else if (search->right == nullptr)
				{
					search->right = temp;
					temp->right = nullptr;
					temp->left = nullptr;
					
					checkCases(temp);
					return;
				}

				else if (data < search->data)
				{
					if (search->left != nullptr)
					{
						search = search->left;
					}
					else if (search->left == nullptr)
					{
						search->left = temp;
						temp->right = nullptr;
						temp->left = nullptr;
						
						checkCases(temp);
						return;
					}

				}



			}



			else if (data < search->data)
			{
				if (search->left != nullptr)
				{
					search = search->left;
				}
				else if (search->left == nullptr)
				{
					search->left = temp;
					temp->right = nullptr;
					temp->left = nullptr;
					
					checkCases(temp);
					return;
				}

				else if (data > search->data)
				{
					if (search->right != nullptr)
					{
						search = search->right;
					}
					else if (search->right == nullptr)
					{
						search->right = temp;
						temp->right = nullptr;
						temp->left = nullptr;
						
						checkCases(temp);
						return;
					}

				}



			}


		}




	}
}



BSTNode * BST::findParent(BSTNode * root, int num)
{
	BSTNode * ptr = root;

	int count = 0;
	int count2 = 0;
	while (ptr != NULL)
	{

		if (num == root->data)
		{
			cout << "Have No parent \n\n";
			return 0;
		}
		else if (num > ptr->data)
		{
			if (count > 0)
			{
				ptr = ptr->right;
			}
			count++;

			if (num == ptr->right->data)
				return ptr;
		}


		else if (num < ptr->data)
		{
			if (count2 > 0)
			{
				ptr = ptr->left;
			}
			count2++;

			if (num == ptr->left->data)
				return ptr;

		}
	}
}

BSTNode *BST::findUncle(int num)
{
	BSTNode * Parent = findParent(root, num);
	BSTNode * gParent = findParent(root, Parent->data);
	if (num > gParent->data)
	{
		gParent = gParent->left;
		return gParent;
	}
	else
	{

		gParent = gParent->right;
		return gParent;

	}
}


BSTNode * BST::searchElement(BSTNode * root, int num)
{
	BSTNode * ptr = root;

	while (ptr != NULL)
	{
		if (num == root->data)
		{
			return root;
		}
		else if (num > ptr->data)
		{
			ptr = ptr->right;
			if (num == ptr->data)
				return ptr;
		}
		else
		{

			ptr = ptr->left;
			if (num == ptr->data)
				return ptr;

		}
	}
}


int BST::findMax(BSTNode * temp)
{
	if (root == NULL)
	{
		cout << "Tree Is Empty ";
		return 0;
	}

	if (temp->right == NULL)
	{
		return temp->data;
	}
	return findMax(temp->right);
}


void BST::checkCases(BSTNode * temp)
{
	BSTNode * Parent = findParent(root, temp->data);
	BSTNode * gParent = findParent(root, Parent->data);
	BSTNode * uncle = findUncle(temp->data);

	if (temp->color == Parent->color && uncle->color=='R')  //  Case 2 
	{
		changeColor(Parent);
		changeColor(uncle);
		if (gParent != root)
		{
			changeColor(gParent);
		}
	}

	else if (((Parent == gParent->right && temp == Parent->left) || (Parent == gParent->left && temp == Parent->right)) && temp->color == Parent->color && (uncle->color == 'B' || gParent->left == nullptr || gParent->right == nullptr)) // Case 3
	{

		if (temp->data < Parent->data)
		{
			Parent->right = Parent->left;
			Parent->left = NULL;
		}
		else
		{
			Parent->left = Parent->right;
			Parent->right = NULL;
		}

		Swap(temp->data, Parent->data);

	}

	else if (((Parent == gParent->right && temp == Parent->right) || (Parent == gParent->left && temp == Parent->left)) && temp->color == Parent->color && (uncle->color == 'B' || gParent->left == nullptr || gParent->right == nullptr)) // Case 4
	{
		if (temp->data > gParent->data)
		{
			if (gParent == root)
			{

				Parent->left = gParent;
				changeColor(Parent);
				changeColor(gParent);
				root = Parent;
				if (root->color == 'R')
					changeColor(root);
			}
			else
			{
				Parent->left = gParent;
				changeColor(Parent);
				changeColor(gParent);
			}
		}
		else if (temp->data < gParent->data)
		{
			if (gParent == root)
			{

				Parent->right = gParent;
				changeColor(Parent);
				changeColor(gParent);
				root = Parent;
				if (root->color == 'R')
					changeColor(root);
			}
			else
			{
				Parent->right = gParent;
				changeColor(Parent);
				changeColor(gParent);
			}
		}
	}
}


//void BST::nodeDeletion(BSTNode * root, int num)
//{
//
//	BSTNode * ptr = new BSTNode;
//	ptr = searchElement(root, num);
//	BSTNode * par;
//	par = findParent(root, num);
//	if (ptr->right == NULL && ptr->left == NULL)//0 child
//	{
//
//
//		if (ptr->data < par->data)
//		{
//
//			delete ptr;
//
//			par->left = NULL;
//
//			return;
//		}
//		else
//		{
//			delete ptr;
//
//			par->right = NULL;
//
//			return;
//		}
//	}
//
//
//	else if (ptr->right == NULL && ptr->left != NULL || ptr->right != NULL && ptr->left == NULL)//One Child Deletion
//	{
//
//
//		if (ptr->right != NULL)
//		{
//			par->right = ptr->right;
//			delete ptr;
//			return;
//		}
//		else if (ptr->left != NULL)
//		{
//			par->left = ptr->left;
//			delete ptr;
//			return;
//		}
//
//
//
//	}
//
//
//	else if (ptr->left != NULL && ptr->right != NULL)    //2 Child Deletion
//	{
//		int max = findMax(searchElement(root, num)->left);
//		BSTNode * N = searchElement(root, max);
//		BSTNode * newParent = findParent(root, max);
//		Swap(N->data, ptr->data);
//
//		if (N->right != NULL)
//		{
//			newParent->right = N->right;
//			delete N;
//			return;
//		}
//		else
//		{
//			newParent->left = N->left;
//			delete N;
//			return;
//		}

		/*if (N->data < N->right->data)
		{*/
		/*newParent->right = N->right;
		newParent->left = N->left;
		delete N;
		return;*/
		//}
		/*else
		{
		newParent->left = N->left;
		delete N;
		return;
		}*/



	//}

//}

void BST::preOrder(BSTNode * ptr)
{


	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		cout << ptr->data << "  ";
		preOrder(ptr->left);
		preOrder(ptr->right);

	}

}

void BST::inOrder(BSTNode * ptr)
{


	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		inOrder(ptr->left);

		cout << ptr->data << "  ";

		inOrder(ptr->right);

	}

}


void BST::postOrder(BSTNode * ptr)
{

	if (root == NULL)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	if (ptr != NULL)
	{
		inOrder(ptr->left);
		inOrder(ptr->right);
		cout << ptr->data << "  ";



	}

}