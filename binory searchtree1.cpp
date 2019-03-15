/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	// Children
	Node *left;
	Node *right;

	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

class binory
{
	public:
	Node *root;

	binory() { root = NULL; }

	void insert(int value)
	{ insertHelper(root, value);}

	void insertHelper(Node *current, int value)
	{
		if (root == NULL)
		{
			root = new Node(value);
		}
		// Else compare the curr data with value
		else if (value < current->data)
		{
			// else move left and call insertH
			if (current->left == NULL)
				current->left = new Node(value);
			else
				insertHelper(current->left, value);
		}
		else
		{
			// Else move right and call insertH
			if (current->right == NULL)
				current->right = new Node(value);
			else
				insertHelper(current->right, value);
		}
  	}

  	void display()
	{displayHelper(root);}

  	void displayHelper(Node *current)
	{
		// Base condition
		if (current == NULL)
			return;
		// Display left.
		displayHelper(current->left);
		// Display current
		cout << current->data << ",";
		// Display right
		displayHelper(current->right);
	}

	void displayFancy()
	{
		displayFancyHelper(root,0);
	}

	void displayFancyHelper(Node * cur,int s)
	{
		//when at the end of a trail return
		if(cur==NULL)
		{return;}
		//go left and increase the number of spaces
		displayFancyHelper(cur->left,s+1);
		//print the spaces
		for(int i=0;i<4*s;i++){cout<<" ";}
		//print the data
		cout<<cur->data<<endl;
		//go right and increase the number of spaces
		displayFancyHelper(cur->right,s+1);
  	}

	Node* search(Node * cur,int value)
	{
		if(cur==NULL)
		{return NULL;}
		if(cur->data==value)
		{return cur;}
		if(cur->data<value)
		{return search(cur->right,value);}
		else
		{return search(cur->left,value);}
	}
};

int main()
{
	binory lol;
	lol.insert(4);
	lol.insert(8);
	lol.insert(2);
	lol.insert(3);
	lol.insert(1);
	lol.insert(78);
	lol.insert(5);
	lol.insert(67);
	lol.insert(6);
	lol.displayFancy();
	if ( lol.search ( lol.root , 2) == NULL)
	{
		cout << "Not Found"<<endl;
	}
	else
	{
		cout<<"Found"<<endl;
	}
}
