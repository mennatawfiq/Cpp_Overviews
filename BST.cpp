#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class BST
{
private:
    Node *root;

    void insert(Node *&pnode, int key)
    {
        if (pnode == NULL)
        {
            Node *newNode = new Node(key);
            pnode = newNode;
        }
        else if (key < pnode->data)
        {
            insert(pnode->left, key);
        }
        else if (key > pnode->data)
        {
            insert(pnode->right, key);
        }
    }

    Node *search(Node *pnode, int key, bool &found)
    {
        if (pnode == NULL)
        {
            found = false;
            return pnode;
        }
        else if (pnode->data == key)
        {
            found = true;
            return pnode;
        }
        else if (pnode->data > key)
        {
            return search(pnode->left, key, found);
        }
        else if (pnode->data < key)
        {
            return search(pnode->right, key, found);
        }
    }

    Node *minimum(Node *ptr)
    {
        while (ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        return ptr;
    }

    Node *maximum(Node *ptr)
    {
        while (ptr->right != NULL)
        {
            ptr = ptr->right;
        }
        return ptr;
    }

    void Delete(Node *&del, int item)
    {
        if (item < del->data)
        {
            Delete(del->left, item);
        }
        else if (item > del->data)
        {
            Delete(del->right, item);
        }
        else
        {
            if (del->left == NULL && del->right == NULL)
            { // leaf node
                del = NULL;
            }
            else if (del->left == NULL && del->right != NULL)
            { // the node has one child on the right
                del->data = del->right->data;
                delete del->right;
                del->right = NULL;
            }
            else if (del->left != NULL && del->right == NULL)
            { // the node has one child on the left
                del->data = del->left->data;
                delete del->left;
                del->left = NULL;
            }
            else if (del->left != NULL && del->right != NULL)
            { // the node has more than one child
                Node *temp = minimum(del->right);
                del->data = temp->data;
                Delete(del->right, temp->data);
            }
        }
    }

public:
    BST()
    {
        root = NULL;
    }
    Node *tree_root()
    {
        return root;
    }
    bool empty()
    {
        return root == NULL;
    }
    void add(int key)
    {
        insert(root, key);
    }
    void pre_order(Node *pnode) // root, left, right
    {
        if (pnode == NULL)
            return;
        cout << pnode->data << "   ";
        pre_order(pnode->left);
        pre_order(pnode->right);
    }
    void in_order(Node *pnode) // left, root, right
    {
        if (pnode == NULL)
            return;
        in_order(pnode->left);
        cout << pnode->data << "   ";
        in_order(pnode->right);
    }
    void post_order(Node *pnode) // left, right, root
    {
        if (pnode == NULL)
            return;
        post_order(pnode->left);
        post_order(pnode->right);
        cout << pnode->data << "   ";
    }
    bool find(int key)
    {
        bool y;
        Node *found_node = search(root, key, y);
        return y;
    }
    int find_min()
    {
        Node *temp = minimum(root);
        return temp->data;
    }
    int find_max()
    {
        Node *temp = maximum(root);
        return temp->data;
    }
    void delete_item(int item)
    {
        if (find(item))
            Delete(root, item);
        else
            cout << "the item you're trying to delete doesn't exist yet" << endl;
    }
    void BFS(){
        if(root == NULL) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            cout << node->data << "  ";
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            q.pop();
        }
    }
};

int main()
{
    BST bst;
    bst.add(50);
    bst.add(45);
    bst.add(52);
    bst.add(49);
    bst.add(51);
    bst.add(60);
    bst.add(40);
    bst.add(46);
    bst.pre_order(bst.tree_root());
    cout << endl;
    bst.in_order(bst.tree_root());
    cout << endl;
    bst.post_order(bst.tree_root());
    cout << endl;
    cout << bst.find(60) << endl;
    bst.add(30);
    cout << bst.find_min() << endl;
    cout << bst.find_max() << endl;
    bst.delete_item(40);
    bst.pre_order(bst.tree_root());
    cout << endl << endl;
    bst.BFS(); //50  45  52  30  49  51  60  46
}
/*                  50
            45              52
       30        49     51        60
              46
*/
