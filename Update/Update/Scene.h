#pragma once
#include "Object.h"
#include "PlayerController.h"

class Object;
class Scene 
{
public:
	Object* player; 

	void Start();
	void Update();
	void LateUpdate();
	void Render();
	void Destory(); 
	Scene();
	~Scene();
private:
};

