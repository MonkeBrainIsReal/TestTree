//"C:\\Users\\83532\\source\\repos\\OOP_pw1\\Project2\\test.txt"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

class Node
{
public:
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
    int data;
    Node* left;
    Node* right;
};


class BinaryTree
{
private:
    Node* root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insert(int x)
    {
        root = InsertRec(root, x);
    }

    Node* InsertRec(Node* node, int x)
    {
        if (node == nullptr)
        {
            return new Node(x); // всегда первым значением скрафтится корень
        }

        if (x < node->data) // распихиваем по ветвям
        {
            node->left = InsertRec(node->left, x);
        }
        else if (x > node->data)
        {
            node->right = InsertRec(node->right, x);
        }

        return node;
    }

    bool isBinaryTree(Node* node, int minValue, int maxValue)
    {
        if (node == nullptr)
        {
            return true;
        }

        if (node->data < minValue || node->data > maxValue)
        {
            return false;
        }

        return isBinaryTree(node->left, minValue, node->data - 1) &&
            isBinaryTree(node->right, node->data + 1, maxValue);
    }

    bool isValidInputChar(char ch)
    {
        return isdigit(ch) || ch == '(' || ch == ')' || ch == ' ';
    }

    void buildTreeFromString(const string& str)
    {
        stringstream ss(str);
        if (!isValidInput(ss.str()))
        {
            cerr << "Invalid input format." << endl;
            return;
        }

        buildTree(ss, root);
    }

    bool isValidInput(const string& str)
    {
        for (char ch : str)
        {
            if (!isValidInputChar(ch))
            {
                return false;
            }
        }
        return true;
    }

    void buildTree(stringstream& ss, Node*& node)
    {
        char ch;
        ss >> ch;

        // крафтим корень
        int value;
        ss >> value;
        node = new Node(value);

        if (ss.eof() || ss.peek() == ')')
        {
            ss >> ch; // считываем )
            return;
        }

        buildTree(ss, node->left);

        if (ss.eof() || ss.peek() == ')')
        {
            ss >> ch; // считываем )
            return;
        }

        buildTree(ss, node->right);

        ss >> ch; // считываем )
    }

    void DFS(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }

        cout << node->data << " ";

        DFS(node->left);
        DFS(node->right);
    }

    void PrintDFS()
    {
        DFS(root);
        cout << "\n";
    }

    bool isValidBinaryTree()
    {
        return isBinaryTree(root, INT_MIN, INT_MAX);
    }
};

int main()
{
    BinaryTree tree;
    string inputString;
    ifstream inputFile("C:\\Users\\83532\\source\\repos\\OOP_pw1\\Project2\\test.txt");
    string line;
    getline(inputFile, line);

    if (!tree.isValidInput(line))
    {
        cerr << "Invalid input format." << endl;
        return 1;
    }

    tree.buildTreeFromString(line);

    

    tree.PrintDFS();

    return 0;
}