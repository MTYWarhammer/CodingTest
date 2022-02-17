#pragma once
#include "Object.h"
class Scene : public Object
{
public:
	PlayerController* player;

	void Start();
	void Update();
	void LateUpdate();
	void Render();
	void Destory();
	Scene();
	~Scene();
private:
};

