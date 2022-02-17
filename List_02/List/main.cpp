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
	//EXAMPLE 1: list 선언, push_back, Delete
	{
		cout << "EXAMPLE 1" << endl;
		NODE* _pList = new NODE; //DIY List
		_pList->Front = nullptr;
		_pList->Value = 10;
		_pList->Back = nullptr;
		list<int> listNum; //STL List
	
		
		//값 추가
		for (int i = 1; i <= 5; i++) {
			push_back(_pList, 10 * i);
			listNum.push_back(10 * i);
		}
	
		//삭제
		Delete(_pList, 1);
		Delete(_pList, 3);
	
		//출력
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
		
		//값 추가
		for (int i = 1; i <= 10; i++) {
			push_back(_pList, 10 * i);
		}
		
		//삭제
		int a = 0;
		//기존 delete는 삭제하면 다음node를 for itr가 찾을 수 없음 그래서 erase써서 다음노드를 반환
		for (NODE* itr = _pList; itr != nullptr; itr = itr->Back) {
			++a;
			if (a == 1) itr = erase(_pList, 2);
		}

		//출력
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
	//	//값추가
	//	push_back(_pList, 20);
	//	push_back(_pList, 30);
	//	push_back(_pList, 40);
	//	push_back(_pList, 50);
	//	push_back(_pList, 60);
	//	push_back(_pList, 70);
	//
	//	//출력
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
	//	//값 추가
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
		//값받은걸로 노드생성
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

void Delete(NODE* node, int index) //반환없는 삭제
{
	if (index == 0) {
		NODE* frontNode = node->Front;
		NODE* backNode = node->Back;
		
		//뒤에 노드가있을경우
		if (backNode != nullptr) {
			//앞노드가 있을 경우 
			if (frontNode != nullptr)  { 
				frontNode->Back = node->Back; //앞노드 포인터연결
				backNode->Front = node->Front; //뒷노드 포인터연결
			}
			else backNode->Front = nullptr; //뒷노드 포인터연결
		}
		//뒤에 노드가 없는 경우
		else { 
			//앞노드가 있을 경우
			if (frontNode != nullptr)	frontNode->Back = nullptr;
		}

		//삭제
		delete node;
	}
	else {
		Delete(node->Back, index + (-1));
	}
}

NODE* erase(NODE* node, int index) //반환있는 삭제
{
	if (index == 0) {
		//반환하는 이유: 다른함수에서 사용하려고
		NODE* back = node->Back;
		node->Front->Back = node->Back;
		node->Back->Front = node->Front;

		//삭제
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
