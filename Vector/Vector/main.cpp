#include <iostream>

using namespace std;


int main()
{	
	//EXAMPLE 1: 백터
	{
		int Array[10] = { 10, 20, 30,  40, 50,  60, 70, 80, 90 }; //값이 10개인 배열
		int Array1[11];

		//배열의 크기를 늘리기 = 방의크기가 더 큰 배열을 만들고 기존의 배열에서 값 이동
		Array1[0] = Array[0];
	}
	return 0;
}