#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node Node;
typedef struct tree Tree;

struct node
{
    Node *left;
    int data;
    Node *right;
};

struct tree
{
    Node *root;
};

//Create the tree
Tree *create_tree()
{
    Tree *new_tree = (Tree*)malloc(sizeof(Tree));
    new_tree->root = NULL;
    return new_tree;
}

//Add new values to the tree
void add_node_aux(Node *current, int value, Node *new_node)
{
    if(current == NULL)
    {
        return;
    }

	if (value < current->data)
    {
		add_node_aux(current->left, value, new_node);
		if (current->left == NULL) {
			current->left = new_node;
		}
    } else if (value > current->data)
    {
		add_node_aux(current->right, value, new_node);
		if (current->right == NULL) {
			current->right = new_node;
		}
    } else {
		if (current->left == NULL) {
			current->left = new_node;
		} else if (current->right == NULL) {
			current->right = new_node;
		} else {
			add_node_aux(current->left, value, new_node);
			if (current->left == NULL) {
				current->left = new_node;
			}
		}
    }
}

void tree_add(Tree *tree, int value)
{
    if(tree == NULL)
    {
        printf("There is no tree!\n\n");
        return;
    }

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL)
    {
        tree->root = new_node;
    } else {
        Node *current = tree->root;
        add_node_aux(current, value, new_node);
    }
}

//Free tree
// Free tree
void free_aux_recursion(Node *current)
{
    if (current == NULL) {
        return;
    }

    free_aux_recursion(current->left);
    free_aux_recursion(current->right);

    free(current);
}

void free_tree(Tree *tree)
{
    if(tree == NULL)
    {
        printf("There is no tree!\n\n");
        return;
    }

    if(tree->root != NULL) 
    {
        free_aux_recursion(tree->root);
    }

    free(tree);
}

/*
void free_aux_recursion(Node *current)
{
    if(current->left != NULL)
    {
        free_aux_recursion(current->left);
        free(current->left);
        current->left = NULL;
    } 
    if(current->right != NULL)
    {
        free_aux_recursion(current->right);
        free(current->right);
        current->right = NULL;
    } 
}

void free_tree(Tree *tree)
{
    free_aux_recursion(tree->root);
    free(tree->root);
    free(tree);
}
*/

//Pre order
void pre_order_recursion(Node *node)
{
    printf("%i  ", node->data);

    if(node->left != NULL)
    {
        pre_order_recursion(node->left);
    }
    if (node->right != NULL)
    {
        pre_order_recursion(node->right);
    }
    
}

void pre_order(Tree *tree)
{
    if(tree == NULL)
    {
        printf("There is no tree!\n\n");
        return;
    }

    if (tree->root == NULL)
    {
        printf("Empty tree\n\n");
        return;
    }

    printf("Pre Order: \n");
    printf("[  ");
    pre_order_recursion(tree->root);
    printf("]\n\n");
}

//Order
void order_recursion(Node *node)
{
    if(node->left != NULL)
    {
        order_recursion(node->left);
    }

    printf("%i  ", node->data);

    if (node->right != NULL)
    {
        order_recursion(node->right);
    }

}

void order(Tree *tree)
{
    if(tree == NULL)
    {
        printf("There is no tree!\n\n");
        return;
    }

    if (tree->root == NULL)
    {
        printf("Empty tree\n\n");
        return;
    }

    printf("Order: \n");
    printf("[  ");
    order_recursion(tree->root);
    printf("]\n\n");
}

//Post_order
void post_order_recursion(Node *node)
{
    if(node->left != NULL)
    {
        post_order_recursion(node->left);
    }
    if (node->right != NULL)
    {
        post_order_recursion(node->right);
    }
    printf("%i  ", node->data);
}

void post_order(Tree *tree)
{
    if(tree == NULL)
    {
        printf("There is no tree!\n\n");
        return;
    }

    if (tree->root == NULL)
    {
        printf("Empty tree\n\n");
        return;
    }

    printf("Post Order: \n");
    printf("[  ");
    post_order_recursion(tree->root);
    printf("]\n\n");
}

//Main
int main()
{
    Tree *tree = create_tree();

    srand(time(NULL));

    int i;
    for (i = 0; i < 20; i++)
    {
        tree_add(tree, (rand()%100));
    }

    pre_order(tree);
    order(tree);
    post_order(tree);

    free_tree(tree);

    return 0;
}