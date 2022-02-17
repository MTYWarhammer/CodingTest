#include "Scene.h"
#include "PlayerController.h"

//너무빠름 만든거 다시 보고 적기
void Scene::Start()
{
	player = new PlayerController;
}

void Scene::Update()
{
}

void Scene::LateUpdate()
{
}

void Scene::Render()
{
}

void Scene::Destory()
{
}

Scene::~Scene()
{
}
