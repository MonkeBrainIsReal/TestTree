#include <iostream>
#include <fstream>

using namespace std;

struct node 
{
	int data;
	struct node* left;
	struct node* right;

public:
	node(int data)//�������� ������ ����� ������
	{
		data = data;
		right = left = nullptr;
	}
};

class BinaryTree 
{


};