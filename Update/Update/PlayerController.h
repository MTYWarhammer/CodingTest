#pragma once
#include "Object.h"

class PlayerController : public Object
{
public:
	//�����Լ��� ���������Լ��� ���� virtual void Func(); <-> virtual void Func() = 0;
	virtual void Start();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
	virtual void Destory();
	PlayerController();
	~PlayerController();
private:
};

