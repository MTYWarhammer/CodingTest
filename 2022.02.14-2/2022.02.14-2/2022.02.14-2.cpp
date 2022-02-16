#include <iostream>
//#include <list>

using namespace std;

typedef struct tagNode
{
    int Value;
    tagNode* Next;

}Node;
Node* pList = new Node;

Node* back(Node* pNode) 
{
    if (pNode->Next != nullptr) back(pNode->Next);
    else return pNode;
}

void push_back(Node* obj, Node* pNode = pList) 
{
    Node* last = back(pNode);
    last->Next = obj;
}

int main(void)
{
    //EXAMPLE 1
    {
        cout << "EXAMPLE 1" << endl;
        int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int* iIter = nullptr;

        iIter = iArray;

        //cout << (*iIter) << endl;

        for (int i = 0; i < 10; ++i)
            cout << (*(iIter + i)) << endl;
        cout << endl;
    }



    //EXAMPLE 2
    //{
    //      cout << "EXAMPLE 2" << endl;
    //      list<int> NumberList = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    //
    //      for (list<int>::iterator iter = NumberList.begin();
    //          iter != NumberList.end(); ++iter)
    //      {
    //          cout << *iter << endl;
    //      }
    //      cout << endl;
    //}


    //EXAMPLE 3
    {
        cout << "EXAMPLE 3" << endl;
        int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, NULL };

        for (int* iIter = iArray; (*iIter) != NULL; ++iIter)
            cout << (*iIter) << endl;
        cout << endl;
    }


    //EXAMPLE 4
    {
        cout << "EXAMPLE 4" << endl;
        pList->Value = 0;
        pList->Next = nullptr;

        for (int  i = 0; i < 10; i++) {
            Node* pNode = new Node;
            pNode->Value = 1 + i;
            pNode->Next = nullptr;
            Node* BackNode = back(pList);
            BackNode->Next = pNode;
        }
        cout << back(pList)->Value << endl;
        Node* temp = new Node;
        temp->Value = 99;
        temp->Next = nullptr;
        push_back(temp);
        cout << back(pList)->Value << endl;
    }

    //EXAMPLE 5 : 두변수의 값 바꾸기
    {
        int i = 10;
        int j = 20;

        //답: int형만가능
        i ^= j;
        j ^= i;
        i ^= j;

        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
        cout << endl;
    }
    
    return 0;
}

