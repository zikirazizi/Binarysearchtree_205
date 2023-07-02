#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = NULL; // Instializing Root to null
	}

	void insert(string element) // insert a node in the binary search tree
	{
		Node* newNode = new Node(element, NULL, NULL); // Allocate memory for the new node
		newNode->info = element; // Assign value to data field of the new node 
		newNode->leftchild = NULL; // Make the left child of the new node point to NULL
		newNode->rightchild = NULL; // Make the right child of the new node point to NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); // Locate the node which will be the parent of the new node to be inserted

		if (parent == NULL) // If the parent is NULL  (tree is empty)
		{
			ROOT = newNode; // Mark the new node as ROOT
			return; // exit
		}
		if (element < parent->info)// If value in the data field of the new node is less than that of parent
		{
			parent->leftchild = newNode; // Make the left child of the parent point to the new node
		}
		else if (element > parent->info) // if the value in the data field dof the new node is greater then that of the parent
		{
			parent->rightchild = newNode; // Make the right child of the parent point to the new node 
		}
	}


	void search(string element, Node*& parent, Node*& currentNode)
	{
		//This function searches the currentNode of the specified Node as well as the current  Node its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is emty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}
	void preorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr)
	{
		// Performs the postorder traversal of the tree
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};
int main()
{
	BinaryTree obj;
	while (true)
	{
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operational" << endl;
		cout << "2. Perfrom inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << " \nEnter your choise (1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "enter a word";
			string word;
			cin >> word;
			obj.insert(word);
			break;
		}
		case'2':
		{
			obj.inorder(obj.ROOT);
			break;
		}
		case '3':
		{
			obj.preorder(obj.ROOT);
			break;
		}
		case '4':
		{
			obj.postorder(obj.ROOT);
			break;
		}
		case '5':
			return 0;
		default:
		{
			cout << "Invailid option" << endl;
			break;
		}
		}
	}
}






















		