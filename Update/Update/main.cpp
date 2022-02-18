#include "Headers.h"
#include "MainUpdate.h"

using namespace std;

//Upate의 로직 과정
//Main->MainUpdate->Scene->Object(Player)
int main() 
{
	//INITIALIZATION
	MainUpdate main;
	ULONGLONG time = GetTickCount64();
	float  DeltaTime = 0;
	float startTime = 0;
	float endTime = 0;

	main.Start(); //여러번 실행가능, Awake최초1회만 실행(cpp는 생성자로 대채)
	while (true) {
		//DeltaTime = GetTickCount64();
		startTime = float(GetTickCount64() % 1000) / 1000; //c++시간이 int라 이지랄 쿠루루삥뽕

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
	main.Destory(); //destroy는 함수내용이 있나 없나 확인 c# 위치는 while 안

	return 0;
}