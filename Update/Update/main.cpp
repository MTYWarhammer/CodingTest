#include "Headers.h"
#include "MainUpdate.h"

using namespace std;

//Upate�� ���� ����
//Main->MainUpdate->Scene->Object(Player)
int main() 
{
	//INITIALIZATION
	MainUpdate main;
	ULONGLONG time = GetTickCount64();
	float  DeltaTime = 0;
	float startTime = 0;
	float endTime = 0;

	main.Start(); //������ ���డ��, Awake����1ȸ�� ����(cpp�� �����ڷ� ��ä)
	while (true) {
		//DeltaTime = GetTickCount64();
		startTime = float(GetTickCount64() % 1000) / 1000; //c++�ð��� int�� ������ ������

		if (time + DeltaTime < GetTickCount64()) {
			//system("cls");
			time = GetTickCount64();
			main.FixedUpdate();
			cout << DeltaTime << endl;
		} 
		else {
			//system("cls");
			main.Update();
			main.LateUpdate();
			main.Render();
		}
		endTime = float (GetTickCount64() % 1000) / 1000;
		DeltaTime = endTime - startTime;
	}
	main.Destory(); //destroy�� �Լ������� �ֳ� ���� Ȯ�� c# ��ġ�� while ��

	return 0;
}