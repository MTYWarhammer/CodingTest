#pragma once
#include "Object.h"
#include "PlayerController.h"

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

