#include "Scene.h"
#include "PlayerController.h"

//�ʹ����� ����� �ٽ� ���� ����
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
