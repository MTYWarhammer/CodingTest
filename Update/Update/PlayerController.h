#pragma once
#include "Object.h"

class PlayerController : public Object
{
public:
	
	void Start();
	void Update();
	void LateUpdate();
	void Render();
	void Destory();
	PlayerController();
	~PlayerController();
private:
};

