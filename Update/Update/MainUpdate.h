#pragma once

class Scene;
class MainUpdate
{
private:
	Scene* m_pScene;
public: 
	//SYSTEM FUNTION
	void Start();
	void Update();
	void LateUpdate();
	void FixedUpdate();
	void Render();
	void Destory();
	MainUpdate(); // == Awake()
	~MainUpdate();
private:
	
};

