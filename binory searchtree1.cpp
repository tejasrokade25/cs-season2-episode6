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

class BiST
{
	public:
	Node *root;

	BiST() { root = NULL; }

	void insert(int value)
	{ insertHelper(root, value);}

	void insertHelper(Node *curr, int value)
	{
		if (root == NULL)
		{
			root = new Node(value);
		}
		// Else compare the curr data with value
		else if (value < curr->data)
		{
			// else move left and call insertH
			if (curr->left == NULL)
				curr->left = new Node(value);
			else
				insertHelper(curr->left, value);
		}
		else
		{
			// Else move right and call insertH
			if (curr->right == NULL)
				curr->right = new Node(value);
			else
				insertHelper(curr->right, value);
		}
  	}

  	void display()
	{displayHelper(root);}

  	void displayHelper(Node *curr)
	{
		// Base condition
		if (curr == NULL)
			return;
		// Display left.
		displayHelper(curr->left);
		// Display current
		cout << curr->data << ",";
		// Display right
		displayHelper(curr->right);
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
	BiST lol;
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
