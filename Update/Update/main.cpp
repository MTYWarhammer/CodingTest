#include <iostream>
#include "MainUpdate.h"
using namespace std;

//�츮����mbti����
int main() 
{
	//update�� ���� ����
	MainUpdate main;
	main.Start(); //������ ���డ��, Awake����1ȸ�� ����

	while (true) {
		main.Update();
		main.LateUpdate();
		main.Render();
	}
	main.Destory();

	return 0;
}