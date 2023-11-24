//"C:\\Users\\83532\\source\\repos\\OOP_pw1\\Project2\\test.txt"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree
{

    

public:
    node* root;
    BinaryTree()
    {
        root = nullptr;
    }

    void add(int data) // Метод для вставки значения в дерево 
    {
        root = AddRec(root,data);

    }


    node* AddRec(node* root,int val) // Рекурсивная функция для вставки значения в дерево 
    {
        if (root == nullptr) {
            return new node(val);
        }
        if (val < root->data) {
            root->left = AddRec(root->left, val);
        }
        if (val > root->data) {
            root->right = AddRec(root->right, val);
        }
        return root;
    }


    void ReadString(string& str)
    {
        istringstream iss(str);
        BuildTreeRec(iss);
    }


    node* BuildTreeRec(istringstream& iss)
    {
        string token;
        iss >> token;

        if (token == "(") {
            iss >> token;
            int val = strToNum(token);
            node* newNode = new node(val);

            newNode->left = BuildTreeRec(iss);
            newNode->right = BuildTreeRec(iss);

            iss >> token;

            return newNode;
        }
        else if (token == ")") {
            return nullptr;
        }
        else {
            int val = strToNum(token);
            return new node(val);
        }
    }

    int strToNum(const string& str)
    {
        int result = 0;
        stringstream ss(str);
        ss >> result;
        return result;
    }

    void depthFirstSearch()
    {
        cout << "Depth-First Search:" << endl;
        depthFirstSearchRec(root);
        cout << endl;
    }

    void depthFirstSearchRec(node* current)
    {
        if (current != nullptr)
        {
            // Рекурсивно обходим левое поддерево
            depthFirstSearchRec(current->left);

            // Выводим значение текущего узла
            cout << current->data << " ";

            // Рекурсивно обходим правое поддерево
            depthFirstSearchRec(current->right);
        }
    }
};

int main()
{
    BinaryTree tree;
    string inputString;
    ifstream inputFile("C:\\Users\\83532\\source\\repos\\OOP_pw1\\Project2\\test.txt"); 


    if (inputFile.is_open())
    {
        getline(inputFile, inputString);
        inputFile.close();
        tree.ReadString(inputString);
        tree.depthFirstSearch();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    return 0;
}