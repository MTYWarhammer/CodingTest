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
	//���������Լ��� �����ص� ������ �Ҹ��ڴ�cpp�� �־����
	Object();
	virtual ~Object(); //object������ ���� ����
private:
};

