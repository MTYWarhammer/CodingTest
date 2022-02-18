#include <iostream>
#include "MainUpdate.h"
#include "Scene.h"

void MainUpdate::Start()
{
	m_pScene = new Scene;
	m_pScene->Start();
}

void MainUpdate::Update()
{
	m_pScene->Update();
}

void MainUpdate::LateUpdate()
{
	m_pScene->LateUpdate();
}

void MainUpdate::FixedUpdate()
{
	cout << "FixedUpdate" << endl;
}

void MainUpdate::Render()
{
	m_pScene->Render();
}

void MainUpdate::Destory()
{
	m_pScene->Destory();
}

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
}
