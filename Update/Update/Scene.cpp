#include "Scene.h"
#include "PlayerController.h"

//너무빠름 만든거 다시 보고 적기
void Scene::Start()
{
	player = new PlayerController;
	player->Update();
}

void Scene::Update()
{
	player->Update();
}

void Scene::LateUpdate()
{
	player->LateUpdate();
}

void Scene::Render()
{
	player->Render();
}

void Scene::Destory()
{
	player->Destory();
}

Scene::~Scene()
{
}
Scene::Scene()
{
}
