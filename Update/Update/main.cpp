#include "Headers.h"
#include "MainUpdate.h"

using namespace std;

int main() 
{
	//update�� ���� ����
	//Main->MainUpdate->Scene->Object(Player)
	MainUpdate main;

	main.Start(); //������ ���డ��, Awake����1ȸ�� ����
	ULONGLONG time = GetTickCount64();

	while (true) {
		if (time < GetTickCount64()) {
			time = GetTickCount64();
			system("cls");
			main.Update();
			main.LateUpdate();
			main.Render();
		}
	}
	main.Destory(); //destroy�� �Լ������� �ֳ� ���� Ȯ�� ��ġ�� while ��

	return 0;
}