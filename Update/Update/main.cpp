#include "Headers.h"
#include "MainUpdate.h"

using namespace std;

int main() 
{
	//update의 로직 과정
	//Main->MainUpdate->Scene->Object(Player)
	MainUpdate main;

	main.Start(); //여러번 실행가능, Awake최초1회만 실행
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
	main.Destory(); //destroy는 함수내용이 있나 없나 확인 위치는 while 안

	return 0;
}