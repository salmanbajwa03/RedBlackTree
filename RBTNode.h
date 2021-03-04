#pragma once

#include<iostream>
using namespace std;


class BSTNode
{
public:

	int data;
	BSTNode * left;
	BSTNode * right;
	char color;
	BSTNode();
	void insertElement(int data);

}*root;


BSTNode::BSTNode()
{
	data = 0;
	left = nullptr;
	right = nullptr;
	
}