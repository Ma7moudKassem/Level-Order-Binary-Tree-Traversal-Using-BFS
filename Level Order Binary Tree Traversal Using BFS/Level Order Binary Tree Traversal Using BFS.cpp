#include <iostream>
using namespace std;

#pragma region Tree Implementation

struct tree_node
{
public:
	int value;
	tree_node* left, * right;
};
tree_node* newNode(int value)
{
	tree_node* node = new tree_node();

	node->value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

#pragma endregion

int height(tree_node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int left_hight = height(node->left);
		int right_hight = height(node->right);

		if (left_hight > right_hight)
			return (left_hight + 1);
		else
		{
			return (right_hight + 1);
		}
	}
}
int printCurrentLevel(tree_node* root, int level)
{
	if (root == NULL)
		return 0;
	if (level == 1)
		return root->value;
	else if (level > 1)
	{
		return (printCurrentLevel(root->left, level - 1) + printCurrentLevel(root->right, level - 1));
	}
}

int printLevelOrder(tree_node* root)
{
	int h = height(root);

	return printCurrentLevel(root, h);
}

int main()
{
#pragma region BuildTree

	tree_node* tree6 = newNode(6);
	tree_node* tree7 = newNode(7);
	tree_node* tree8 = newNode(8);
	tree_node* tree2 = newNode(2);
	tree_node* tree7_1 = newNode(7);
	tree_node* tree1 = newNode(1);
	tree_node* tree1_1 = newNode(1);
	tree_node* tree3 = newNode(3);
	tree_node* tree4 = newNode(4);
	tree_node* tree5 = newNode(5);
	tree_node* tree9 = newNode(9);

	tree6->right = tree8;
	tree6->left = tree7;

	tree7->left = tree2;
	tree7->right = tree7_1;

	tree2->left = tree9;

	tree7_1->right = tree4;
	tree7_1->left = tree1;


	tree8->right = tree3;
	tree8->left = tree1_1;

	tree3->right = tree5;

#pragma endregion

	cout << printLevelOrder(tree6);
}