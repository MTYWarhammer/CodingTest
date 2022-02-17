#include <iostream>
#include "MainUpdate.h"
using namespace std;

//우리모임mbti궁합
int main() 
{
	//update의 로직 과정
	MainUpdate main;
	main.Start(); //여러번 실행가능, Awake최초1회만 실행

	while (true) {
		main.Update();
		main.LateUpdate();
		main.Render();
	}
	main.Destory();

	return 0;
}