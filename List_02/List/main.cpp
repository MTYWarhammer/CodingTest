#include <iostream>

//NAMESPACE
using namespace std;


//VARIABLE
typedef struct tagNode 
{
	tagNode* Front;
	int Value;
	tagNode* Back;
} NODE;
NODE* _pList;

//FUNCTION
void push_back(NODE* parent, int value);
NODE* front(NODE* pList);
NODE* back(NODE* pList);
void Delete(NODE* pList, int index);


//MAIN
int main() 
{
	_pList = new NODE;

	_pList->Front = nullptr;
	_pList->Value = 10;
	_pList->Back = nullptr;

	//EXAMPLE 1
	{
		cout << "EXAMPLE 1" << endl;
		push_back(_pList, 20);
		push_back(_pList, 30);
		push_back(_pList, 40);
		push_back(_pList, 50);
		push_back(_pList, 60);
		push_back(_pList, 70);

		//Delete(_pList, 1);
		Delete(_pList, 5);

		cout << "first: " << front(_pList)->Value << endl;
		cout << _pList->Value << endl;
		cout << _pList->Back->Back->Value << endl;
		cout << _pList->Back->Back->Back->Value << endl;
		cout << _pList->Back->Back->Back->Back->Value << endl;
		cout << "last: " << back(_pList)->Value << endl;
		cout << endl;
	}
	
	//EXAMPLE 2 
	{
		cout << "EXAMPLE 2" << endl;

		cout << endl;
	}
	return 0;
}

//FUNCTION
void push_back(NODE* node, int value)
{
	if (node->Back == nullptr) {
		NODE* currNode = new NODE;
		//�������ɷ� ������
		currNode->Front = node;
		currNode->Value = value;
		currNode->Back = nullptr;
		back(node)->Back = currNode;
	}
	else push_back(node->Back, value);
}

NODE* front(NODE* node)
{
	return node;
}

NODE* back(NODE* node)
{
	if (node->Back == nullptr) {
		return node;
	}
	else {
		back(node->Back);
	}
}

void Delete(NODE* node, int index)
{
	if (index-1 == 1) {
		NODE* frontNode = node->Front;
		NODE* backNode = node->Back;
		//��� ������ 
		
		//�ڿ� ��尡�������
		if (backNode != nullptr) {
			//�ճ�尡 ���� ��� 
			if (frontNode != nullptr)  { 
				frontNode->Back = node->Back; //�ճ�� �����Ϳ���
				backNode->Front = node->Front; //�޳�� �����Ϳ���
			}
			else backNode->Front = nullptr; //�޳�� �����Ϳ���
		}
		else { //�ڿ� ��尡 ���� ���
			//�ճ�尡 ���� ���
			if (frontNode != nullptr)	frontNode->Back = nullptr	
		
		}

		//����
		delete node;
	}
	else {
		Delete(node->Back, index + (-1));
	}
}