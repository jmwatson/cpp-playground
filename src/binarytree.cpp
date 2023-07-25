#include <bits/stdc++.h>

using namespace std;

struct Node
{
public:
    char value;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(char value, Node* left, Node* right) :
        value(value),
        left(left),
        right(right) {};
    
    ~Node()
    {
        if (left != nullptr)
            delete left;
        if (right != nullptr)
            delete right;
        
        cout << "Deleting memory for value: " << value << endl;
    }

    bool BFS(char ch)
    {
        if (value == ch)
            return true;

        if (left != nullptr && right != nullptr)
            return left->BFS(ch) || right->BFS(ch);

        if (left != nullptr)
            return left->BFS(ch);
        
        if (right != nullptr)
            return right->BFS(ch);

        return false;
    }

    bool DFS(char ch)
    {
        if (left != nullptr)
            return left->DFS(ch);
        
        if (right != nullptr)
            return right->DFS(ch);

        return value == ch;
    }
};

Node* BuildTree()
{
    Node* h = new Node('h', nullptr, nullptr);
    Node* g = new Node('g', nullptr, nullptr);
    Node* f = new Node('f', nullptr, h);
    Node* e = new Node('e', g, nullptr);
    Node* d = new Node('d', nullptr, nullptr);
    Node* c = new Node('c', nullptr, f);
    Node* b = new Node('b', d, e);
    Node* a = new Node('a', b, c);

    return a;
}

void breadthFirstValues(Node* root)
{
    queue<Node*> _queue;
    _queue.push(root);

    cout << "Breadth First Values:" << endl;

    while (_queue.size() > 0)
    {
        Node* current = _queue.front();
        _queue.pop();
        cout << current->value << endl;

        if (current->left != nullptr)
            _queue.push(current->left);
        if (current->right != nullptr)
            _queue.push(current->right);
    }

    cout << endl;
}

void depthFirstValues(Node* root)
{
    stack<Node*> _stack;
    _stack.push(root);

    cout << "Depth First Values:" << endl;

    while (_stack.size() > 0)
    {
        Node* current = _stack.top();
        _stack.pop();
        cout << current->value << endl;

        if (current->right != nullptr)
            _stack.push(current->right);
        if (current->left != nullptr)
            _stack.push(current->left);
    }

    cout << endl;
}

bool isValueInTreeDFS(Node* root)
{

}

// bool isValueInTreeBFS(Node* root, char testVal)
// {
//     queue<Node*> _queue;
//     _queue.push(root);
//     bool retVal = false;

//     while (_queue.size() > 0)
//     {
//         Node* current = _queue.front();
//         _queue.pop();

//         if (current->value != testVal)
//         {

//         }
//     }
// }

int main()
{
    Node* root = BuildTree();
    depthFirstValues(root);
    breadthFirstValues(root);

    cout << "BFS for 'e': " << root->BFS('e') << endl;
    cout << "DFS for 'd': " << root->DFS('d') << endl;
    cout << "BFS for 'z': " << root->BFS('z') << endl;
    cout << "DFS for 'z': " << root->DFS('z') << endl;
    
    delete root;
}