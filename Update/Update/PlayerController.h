#pragma once
#include "Object.h"

class PlayerController : public Object
{
public:
	//가상함수와 순수가상함수의 차이 virtual void Func(); <-> virtual void Func() = 0;
	virtual void Start();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
	virtual void Destory();
	PlayerController();
	~PlayerController();
private:
};

