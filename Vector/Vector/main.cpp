#include <iostream>

using namespace std;


int main()
{	
	//EXAMPLE 1: ����
	{
		int Array[10] = { 10, 20, 30,  40, 50,  60, 70, 80, 90 }; //���� 10���� �迭
		int Array1[11];

		//�迭�� ũ�⸦ �ø��� = ����ũ�Ⱑ �� ū �迭�� ����� ������ �迭���� �� �̵�
		Array1[0] = Array[0];
	}
	return 0;
}