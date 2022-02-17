#include <iostream>
#include <list>

//NAMESPACE
using namespace std;

//VARIABLE
typedef struct tagNode {
	tagNode* Front;
	int Value;
	tagNode* Back;
} NODE;
typedef struct tagIterator {
	tagNode* begin;
	tagNode* pThis;
	tagNode* end;
} Iterator;

//FUNCTION
void push_back(NODE* node, int value);
NODE* front(NODE* node);
NODE* back(NODE* node);
void Delete(NODE* node, int index);
NODE* erase(NODE* node, int index);
int size(NODE* node);
Iterator begin(NODE* node);
Iterator end(NODE* node);

//MAIN
int main() 
{
	//EXAMPLE 1: list ����, push_back, Delete
	{
		cout << "EXAMPLE 1" << endl;
		NODE* _pList = new NODE; //DIY List
		_pList->Front = nullptr;
		_pList->Value = 10;
		_pList->Back = nullptr;
		list<int> listNum; //STL List
	
		
		//�� �߰�
		for (int i = 1; i <= 5; i++) {
			push_back(_pList, 10 * i);
			listNum.push_back(10 * i);
		}
	
		//����
		Delete(_pList, 1);
		Delete(_pList, 3);
	
		//���
		cout << "first: " << front(_pList)->Value << endl;
		for (NODE* itr = _pList; itr != nullptr; itr = itr->Back) {
			cout << "DIY List: " << itr->Value << endl;
		}
		for (list<int>::iterator itr = listNum.begin(); itr != listNum.end(); ++itr) {
			cout << "STL List: "  << *itr << endl;
		}
		cout << "last: " << back(_pList)->Value << endl;
		cout << endl;
	}
	
	//EXAMPLE 2: erase,
	{
		cout << "EXAMPLE 2" << endl;
		NODE* _pList = new NODE;
		_pList->Front = nullptr;
		_pList->Value = 10;
		_pList->Back = nullptr;
		
		//�� �߰�
		for (int i = 1; i <= 10; i++) {
			push_back(_pList, 10 * i);
		}
		
		//����
		int a = 0;
		//���� delete�� �����ϸ� ����node�� for itr�� ã�� �� ���� �׷��� erase�Ἥ ������带 ��ȯ
		for (NODE* itr = _pList; itr != nullptr; itr = itr->Back) {
			++a;
			if (a == 1) itr = erase(_pList, 2);
		}

		//���
		for (NODE* itr = _pList; itr != nullptr; itr = itr->Back) {
			cout << "DIY List: " << itr->Value << endl;
		}
		cout << endl;
	}

	//EXAMPLE 3
	//{
	//	cout << "EXAMPLE 3" << endl;
	//	NODE* _pList = new NODE;
	//	_pList->Front = nullptr;
	//	_pList->Value = 10;
	//	_pList->Back = nullptr;
	//
	//	//���߰�
	//	push_back(_pList, 20);
	//	push_back(_pList, 30);
	//	push_back(_pList, 40);
	//	push_back(_pList, 50);
	//	push_back(_pList, 60);
	//	push_back(_pList, 70);
	//
	//	//���
	//	cout << size(_pList) << endl;
	//	cout << endl;
	//}

	//EXAMPLE 4
	//{
	//	cout << "EXAMPLE 4" << endl;
	//	NODE* _pList = new NODE;
	//	_pList->Front = nullptr;
	//	_pList->Value = 10;
	//	_pList->Back = nullptr;
	//	//�� �߰�
	//	for (int i = 1; i <= 10; i++) {
	//		push_back(_pList, 10 * i);
	//	}
	//	
	//	cout << endl;
	//}
	return 0;
}

//WORLD FUNCTION

//LOCAL FUNCTION
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

void Delete(NODE* node, int index) //��ȯ���� ����
{
	if (index == 0) {
		NODE* frontNode = node->Front;
		NODE* backNode = node->Back;
		
		//�ڿ� ��尡�������
		if (backNode != nullptr) {
			//�ճ�尡 ���� ��� 
			if (frontNode != nullptr)  { 
				frontNode->Back = node->Back; //�ճ�� �����Ϳ���
				backNode->Front = node->Front; //�޳�� �����Ϳ���
			}
			else backNode->Front = nullptr; //�޳�� �����Ϳ���
		}
		//�ڿ� ��尡 ���� ���
		else { 
			//�ճ�尡 ���� ���
			if (frontNode != nullptr)	frontNode->Back = nullptr;
		}

		//����
		delete node;
	}
	else {
		Delete(node->Back, index + (-1));
	}
}

NODE* erase(NODE* node, int index) //��ȯ�ִ� ����
{
	if (index == 0) {
		//��ȯ�ϴ� ����: �ٸ��Լ����� ����Ϸ���
		NODE* back = node->Back;
		node->Front->Back = node->Back;
		node->Back->Front = node->Front;

		//����
		delete node;

		return back;
	}
	else {
		erase(node->Back, --index);
	}
}

int size(NODE* node)
{
	int size = 0;
	for (NODE* itr = node; itr != nullptr; itr = itr->Back) {
		++size;
	}
	return size;
}

Iterator begin(NODE* node)
{
	if (node->Front == nullptr) {
		Iterator itr;
		itr.pThis = new NODE;
		itr.begin = node;
		return itr;
	} 
	else  begin(node->Front);
		
	return Iterator();
}

Iterator end(NODE* node)
{
	Iterator itr;
	itr.pThis = new NODE;
	itr.end = back(node)->Back;
	return itr;
}
