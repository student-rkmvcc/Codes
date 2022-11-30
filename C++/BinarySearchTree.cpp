#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
};
void InOrder(node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->data << "\t";
        InOrder(root->right);
    }
}
node *Insertion(node *root, int data)
{
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        cout << "Memory Error\n";
        return NULL;
    }
    n->data = data;
    n->left = n->right = NULL;
    if (root == NULL)
        root = n;
    else if (root->data > data)
        root->left = Insertion(root->left, data);
    else if (root->data < data)
        root->right = Insertion(root->right, data);
    else if (root->data == data)
        cout << "Same data can't allowed\n";
    return root;
}
node *BinarySearch(node *root, int data)
{
    if (root == NULL)
        cout << "Data is not found\n";
    if (root->data == data)
        return root;
    else if (root->data > data)
        return BinarySearch(root->left, data);
    else if (root->data < data)
        return BinarySearch(root->right, data);
    return root;
}
node *Min(node *root)
{
    node *p = root;
    while (p->left != NULL && p != NULL)
        p = p->left;
    return p;
}
node *DeleteNode(node *root, int data)
{
    if (root == NULL)
    {
        cout << data << " is not present\n";
        return root;
    }
    if (root->data > data)
        root->left = DeleteNode(root->left, data);
    else if (root->data < data)
        root->right = DeleteNode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *temp = Min(root->right);
        root->data = temp->data;
        root->right = DeleteNode(root->right, temp->data);
    }
    return root;
}
int Hight(node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lhight = Hight(root->left);
        int rhight = Hight(root->right);
        if (lhight < rhight)
            return (rhight + 1);
        else
            return (lhight + 1);
    }
}
void CurrentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << "\t";
    else
    {
        CurrentLevel(root->left, level - 1);
        CurrentLevel(root->right, level - 1);
    }
}
void LevelOrderTravertion(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty\n";
        return;
    }
    for (int i = 1; i <= Hight(root); i++)
        CurrentLevel(root, i);
    cout << endl;
}
int main()
{
    node *root = NULL;
    root = Insertion(root, 10);
    root = Insertion(root, 20);
    root = Insertion(root, 30);
    root = Insertion(root, 40);
    root = Insertion(root, 25);
    root = Insertion(root, 15);
    root = Insertion(root, 11);
    root = Insertion(root, 17);
    root = Insertion(root, 175);
    root = Insertion(root, 10);
    root = Insertion(root, 19);
    InOrder(root);
    cout << endl;
    cout << "Hight of BST is = " << Hight(root) << endl;
    cout << "Minimum node = " << Min(root)->data << endl;
    root = DeleteNode(root, 30);
    InOrder(root);
    cout << endl;
    cout << "Level Order Traversion :\n";
    LevelOrderTravertion(root);
    return 0;
}
