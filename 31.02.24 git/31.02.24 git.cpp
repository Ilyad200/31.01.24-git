#include <iostream>
using namespace std;
template <class T>
struct Node
{
    Node* head = NULL;
    T data;
    bool b = 0;
    int level;
    Node* left = NULL;
    Node* right = NULL;
};

template <class T>
class Bin_Tree {
    Node<T>* node;
    int size = 0;
    T summ = 0;
public:
    void create(Node<T>* head, Node<T>*& nodes, int in, int& j) {

        if (in <= 0) { return; }
        nodes = new Node<T>;
        nodes->head = head;
        nodes->data = ++j;
        summ += nodes->data;
        in--;
        create(nodes, nodes->left, in, j);
        create(nodes, nodes->right, in, j);
    }
    Bin_Tree(int in) {
        create(NULL, node, in, size);
    }

    Node<T>* getNode() {
        return node;
    }

    void print(ostream& ost, Node<T>* node) {
        ost << node->data << endl;
        if (node->right != NULL) {
            print(ost, node->right);
        }
        if (node->left != NULL) {
            print(ost, node->left);
        }

    }
    friend ostream& operator<< (ostream& ost, Bin_Tree& bt) {
        bt.print(ost, bt.node);
        return ost;
    }

    void add(int data) {

    }
    T summNode()
    {
        return summ;
    }
};

int main()
{
    Bin_Tree<int> BT(4);
    cout << BT;
    cout << BT.summNode();
}