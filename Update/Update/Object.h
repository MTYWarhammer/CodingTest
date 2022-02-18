#pragma once
#include "Headers.h"

class Object //== Monobehavior
{
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render() = 0;
	virtual void Destory() = 0;
	//순수가상함수로 선언해도 생성자 소멸자는cpp에 있어야함
	Object();
	virtual ~Object(); //object꺼질때 같이 꺼짐
private:
};

