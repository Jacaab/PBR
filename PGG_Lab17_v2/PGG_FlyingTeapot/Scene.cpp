
#include "Scene.h"

#include <iostream>
#include <SDL/SDL.h>



Scene::Scene()
{
	_cameraAngleX = 0.3f, _cameraAngleY = 1.5f;

	// Set up the viewing matrix
	// This represents the camera's orientation and position
	_viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3.5f));


	// Set up a projection matrix
	_projMatrix = glm::perspective(45.0f, 1.0f, 0.1f, 10000.0f);




	// Set up your scene here

	// Position of the light, in world-space
	_lightPosition = glm::vec3(1, 0, 1);

	// Create a game object
	// This needs a material and a mesh
	_player = new Player();
	_player->SetPosition(0.0f, 0.0f, 0.0f);


	//creating a bunch of game objects with varrying properties
	//Rougness
	//Teapot R1
	_teapotR1 = new GameObject();
	Material* teapotR1Material = new Material();
	teapotR1Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotR1Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotR1Material->SetRoughness(0.1f);
	teapotR1Material->SetMetallic(0.0f);
	teapotR1Material->SetAo(0.5f);
	teapotR1Material->SetLightPosition(_lightPosition);
	_teapotR1->SetMaterial(teapotR1Material);
	Mesh* teapotR1Mesh = new Mesh();
	teapotR1Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotR1->SetMesh(teapotR1Mesh);
	_teapotR1->SetPosition(0.0f, 0.0f, 2.0f);

	//Teapot R2
	_teapotR2 = new GameObject();
	Material* teapotR2Material = new Material();
	teapotR2Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotR2Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotR2Material->SetRoughness(0.3f);
	teapotR2Material->SetMetallic(0.0f);
	teapotR2Material->SetAo(0.5f);
	teapotR2Material->SetLightPosition(_lightPosition);
	_teapotR2->SetMaterial(teapotR2Material);
	Mesh* teapotR2Mesh = new Mesh();
	teapotR2Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotR2->SetMesh(teapotR2Mesh);
	_teapotR2->SetPosition(0.0f, 0.0f, 4.0f);

	//Teapot R3
	_teapotR3 = new GameObject();
	Material* teapotR3Material = new Material();
	teapotR3Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotR3Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotR3Material->SetRoughness(0.5f);
	teapotR3Material->SetMetallic(0.0f);
	teapotR3Material->SetAo(0.5f);
	teapotR3Material->SetLightPosition(_lightPosition);
	_teapotR3->SetMaterial(teapotR3Material);
	Mesh* teapotR3Mesh = new Mesh();
	teapotR3Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotR3->SetMesh(teapotR3Mesh);
	_teapotR3->SetPosition(0.0f, 0.0f, 6.0f);

	//Teapot R4
	_teapotR4 = new GameObject();
	Material* teapotR4Material = new Material();
	teapotR4Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotR4Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotR4Material->SetRoughness(0.7f);
	teapotR4Material->SetMetallic(0.0f);
	teapotR4Material->SetAo(0.5f);
	teapotR4Material->SetLightPosition(_lightPosition);
	_teapotR4->SetMaterial(teapotR4Material);
	Mesh* teapotR4Mesh = new Mesh();
	teapotR4Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotR4->SetMesh(teapotR4Mesh);
	_teapotR4->SetPosition(0.0f, 0.0f, 8.0f);

	//Teapot R5
	_teapotR5 = new GameObject();
	Material* teapotR5Material = new Material();
	teapotR5Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotR5Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotR5Material->SetRoughness(0.9f);
	teapotR5Material->SetMetallic(0.0f);
	teapotR5Material->SetAo(0.5f);
	teapotR5Material->SetLightPosition(_lightPosition);
	_teapotR5->SetMaterial(teapotR5Material);
	Mesh* teapotR5Mesh = new Mesh();
	teapotR5Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotR5->SetMesh(teapotR5Mesh);
	_teapotR5->SetPosition(0.0f, 0.0f, 10.0f);

	//Metallic
	//Teapot M1
	_teapotM1 = new GameObject();
	Material* teapotM1Material = new Material();
	teapotM1Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotM1Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotM1Material->SetRoughness(0.4f);
	teapotM1Material->SetMetallic(0.2f);
	teapotM1Material->SetAo(0.5f);
	teapotM1Material->SetLightPosition(_lightPosition);
	_teapotM1->SetMaterial(teapotM1Material);
	Mesh* teapotM1Mesh = new Mesh();
	teapotM1Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotM1->SetMesh(teapotM1Mesh);
	_teapotM1->SetPosition(0.0f, 2.0f, 2.0f);

	//Teapot M2
	_teapotM2 = new GameObject();
	Material* teapotM2Material = new Material();
	teapotM2Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotM2Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotM2Material->SetRoughness(0.4f);
	teapotM2Material->SetMetallic(0.04f);
	teapotM2Material->SetAo(0.5f);
	teapotM2Material->SetLightPosition(_lightPosition);
	_teapotM2->SetMaterial(teapotM2Material);
	Mesh* teapotM2Mesh = new Mesh();
	teapotM2Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotM2->SetMesh(teapotM2Mesh);
	_teapotM2->SetPosition(0.0f, 2.0f, 4.0f);

	//Teapot M3
	_teapotM3 = new GameObject();
	Material* teapotM3Material = new Material();
	teapotM3Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotM3Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotM3Material->SetRoughness(0.4f);
	teapotM3Material->SetMetallic(0.6f);
	teapotM3Material->SetAo(0.5f);
	teapotM3Material->SetLightPosition(_lightPosition);
	_teapotM3->SetMaterial(teapotM3Material);
	Mesh* teapotM3Mesh = new Mesh();
	teapotM3Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotM3->SetMesh(teapotM3Mesh);
	_teapotM3->SetPosition(0.0f, 2.0f, 6.0f);

	//Teapot M4
	_teapotM4 = new GameObject();
	Material* teapotM4Material = new Material();
	teapotM4Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotM4Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotM4Material->SetRoughness(0.4f);
	teapotM4Material->SetMetallic(0.8f);
	teapotM4Material->SetAo(0.5f);
	teapotM4Material->SetLightPosition(_lightPosition);
	_teapotM4->SetMaterial(teapotM4Material);
	Mesh* teapotM4Mesh = new Mesh();
	teapotM4Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotM4->SetMesh(teapotM4Mesh);
	_teapotM4->SetPosition(0.0f, 2.0f, 8.0f);

	//Teapot M5
	_teapotM5 = new GameObject();
	Material* teapotM5Material = new Material();
	teapotM5Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotM5Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotM5Material->SetRoughness(0.4f);
	teapotM5Material->SetMetallic(1.0f);
	teapotM5Material->SetAo(0.5f);
	teapotM5Material->SetLightPosition(_lightPosition);
	_teapotM5->SetMaterial(teapotM5Material);
	Mesh* teapotM5Mesh = new Mesh();
	teapotM5Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotM5->SetMesh(teapotM5Mesh);
	_teapotM5->SetPosition(0.0f, 2.0f, 10.0f);


	//material examples
	//steel
	_teapotEx1 = new GameObject();
	Material* teapotEx1Material = new Material();
	teapotEx1Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotEx1Material->SetAlbedo(glm::vec3(0.26f, 0.26f, 0.26f));
	teapotEx1Material->SetRoughness(0.65f);
	teapotEx1Material->SetMetallic(0.93f);
	teapotEx1Material->SetAo(0.2f);
	teapotEx1Material->SetLightPosition(_lightPosition);
	_teapotEx1->SetMaterial(teapotEx1Material);
	Mesh* teapotEx1Mesh = new Mesh();
	teapotEx1Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotEx1->SetMesh(teapotEx1Mesh);
	_teapotEx1->SetPosition(5.0f, 0.0f, 0.0f);

	//plastic rough
	_teapotEx2 = new GameObject();
	Material* teapotEx2Material = new Material();
	teapotEx2Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotEx2Material->SetAlbedo(glm::vec3(0.75f, 0.45f, 0.0f));
	teapotEx2Material->SetRoughness(0.4f);
	teapotEx2Material->SetMetallic(0.0f);
	teapotEx2Material->SetAo(0.5f);
	teapotEx2Material->SetLightPosition(_lightPosition);
	_teapotEx2->SetMaterial(teapotEx2Material);
	Mesh* teapotEx2Mesh = new Mesh();
	teapotEx2Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotEx2->SetMesh(teapotEx2Mesh);
	_teapotEx2->SetPosition(5.0f, 0.0f, 2.5f);

	//blinn
	_teapotEx3 = new GameObject();
	Material* teapotEx3Material = new Material();
	teapotEx3Material->LoadShaders("VertShader.vert", "FragShader.frag");
	teapotEx3Material->SetDiffuseColour(glm::vec3(1.0f));
	teapotEx3Material->SetTexture("FlyingTeapotColour.bmp");
	teapotEx3Material->SetLightPosition(_lightPosition);
	_teapotEx3->SetMaterial(teapotEx3Material);
	Mesh* teapotEx3Mesh = new Mesh();
	teapotEx3Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotEx3->SetMesh(teapotEx3Mesh);
	_teapotEx3->SetPosition(5.0f, 0.0f, -2.5f);

	//Gold
	_teapotEx4 = new GameObject();
	Material* teapotEx4Material = new Material();
	teapotEx4Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotEx4Material->SetAlbedo(glm::vec3(1.0f, 0.3f, 0.05f));
	teapotEx4Material->SetRoughness(0.3f);
	teapotEx4Material->SetMetallic(0.93f);
	teapotEx4Material->SetAo(0.5f);
	teapotEx4Material->SetLightPosition(_lightPosition);
	_teapotEx4->SetMaterial(teapotEx4Material);
	Mesh* teapotEx4Mesh = new Mesh();
	teapotEx4Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotEx4->SetMesh(teapotEx4Mesh);
	_teapotEx4->SetPosition(5.0f, 0.0f, 5.0f);

	//plastic shiny
	_teapotEx5 = new GameObject();
	Material* teapotEx5Material = new Material();
	teapotEx5Material->LoadShaders("VertShader.vert", "PBRfragShader.frag");
	teapotEx5Material->SetAlbedo(glm::vec3(0.5f, 0.0f, 0.0f));
	teapotEx5Material->SetRoughness(0.2f);
	teapotEx5Material->SetMetallic(0.0f);
	teapotEx5Material->SetAo(0.5f);
	teapotEx5Material->SetLightPosition(_lightPosition);
	_teapotEx5->SetMaterial(teapotEx5Material);
	Mesh* teapotEx5Mesh = new Mesh();
	teapotEx5Mesh->LoadOBJ("wingedTeapot.obj");
	_teapotEx5->SetMesh(teapotEx5Mesh);
	_teapotEx5->SetPosition(5.0f, 0.0f, 7.5f);

	Mesh* teapotEx6Mesh = new Mesh();
	teapotEx6Mesh->LoadOBJ("wingedTeapot.obj");
	Mesh* teapotEx7Mesh = new Mesh();
	teapotEx7Mesh->LoadOBJ("wingedTeapot.obj");
	Mesh* teapotEx8Mesh = new Mesh();
	teapotEx8Mesh->LoadOBJ("wingedTeapot.obj");
	Mesh* teapotEx9Mesh = new Mesh();
	teapotEx9Mesh->LoadOBJ("wingedTeapot.obj");
}

Scene::~Scene()
{
	// You should neatly clean everything up here
	delete _player;
	delete _teapotR1;
	delete _teapotR2;
	delete _teapotR3;
	delete _teapotR4;
	delete _teapotR5;
	delete _teapotM1;
	delete _teapotM2;
	delete _teapotM3;
	delete _teapotM4;
	delete _teapotM5;

	delete _teapotEx1;
	delete _teapotEx2;
	delete _teapotEx3;
	delete _teapotEx4;
	delete _teapotEx5;
}

void Scene::Update(float deltaTs)
{
	// Update the game object
	_player->Update(deltaTs);
	_teapotR1->Update(deltaTs);
	_teapotR2->Update(deltaTs);
	_teapotR3->Update(deltaTs);
	_teapotR4->Update(deltaTs);
	_teapotR5->Update(deltaTs);
	_teapotM1->Update(deltaTs);
	_teapotM2->Update(deltaTs);
	_teapotM3->Update(deltaTs);
	_teapotM4->Update(deltaTs);
	_teapotM5->Update(deltaTs);

	_teapotEx1->Update(deltaTs);
	_teapotEx2->Update(deltaTs);
	_teapotEx3->Update(deltaTs);
	_teapotEx4->Update(deltaTs);
	_teapotEx5->Update(deltaTs);

	glm::vec3 playerPos = _player->GetPosition();
	glm::quat playerOrientation = _player->GetOrientation();


	// This updates the camera's position and orientation based on those of the player


	// We change the camera's orientation to be part-way between its previous orientation and the player's orientation
	// deltaTs is very small, so the multiplier needs to be >1 if you want it to quickly snap
	_cameraOrientation = glm::slerp(_cameraOrientation, -playerOrientation, 0.8f * deltaTs);

	// Build the viewing matrix:
	_viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -5.0f)); // Provides offset away from player object
	_viewMatrix = glm::rotate(_viewMatrix, _cameraAngleX, glm::vec3(1, 0, 0)); // Allows player to rotate camera using player object as pivot
	_viewMatrix = glm::rotate(_viewMatrix, _cameraAngleY, glm::vec3(0, 1, 0));
	_viewMatrix = _viewMatrix * glm::mat4_cast(glm::inverse(_cameraOrientation)); // Orient towards player direction
	_viewMatrix = glm::translate(_viewMatrix, -playerPos); // Move to player's position
	// done :)


	// This commented-out version just tracks the player, without orienting to their direction of movement:
	//_viewMatrix = glm::translate( glm::rotate( glm::rotate( glm::translate(glm::mat4(1.0f), glm::vec3(0,0,-3.5)), _cameraAngleX, glm::vec3(1,0,0) ), _cameraAngleY, glm::vec3(0,1,0) ), -playerPos );
}

void Scene::Draw()
{
	// Draw that model, giving it the camera's position and projection
	_player->Draw(_viewMatrix, _projMatrix);
	_teapotR1->Draw(_viewMatrix, _projMatrix);
	_teapotR2->Draw(_viewMatrix, _projMatrix);
	_teapotR3->Draw(_viewMatrix, _projMatrix);
	_teapotR4->Draw(_viewMatrix, _projMatrix);
	_teapotR5->Draw(_viewMatrix, _projMatrix);
	_teapotM1->Draw(_viewMatrix, _projMatrix);
	_teapotM2->Draw(_viewMatrix, _projMatrix);
	_teapotM3->Draw(_viewMatrix, _projMatrix);
	_teapotM4->Draw(_viewMatrix, _projMatrix);
	_teapotM5->Draw(_viewMatrix, _projMatrix);

	_teapotEx1->Draw(_viewMatrix, _projMatrix);
	_teapotEx2->Draw(_viewMatrix, _projMatrix);
	_teapotEx3->Draw(_viewMatrix, _projMatrix);
	_teapotEx4->Draw(_viewMatrix, _projMatrix);
	_teapotEx5->Draw(_viewMatrix, _projMatrix);
}



