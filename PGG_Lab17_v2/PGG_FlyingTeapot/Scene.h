

#include "Player.h"

// The GLM library contains vector and matrix functions and classes for us to use
// They are designed to easily work with OpenGL!
#include <GLM/glm.hpp> // This is the main GLM header
#include <GLM/gtc/matrix_transform.hpp> // This one lets us use matrix transformations
#include <GLM/gtc/type_ptr.hpp> // This one gives us access to a utility function which makes sending data to OpenGL nice and easy
#include <GLM/gtc/quaternion.hpp>

#include <string>

// The scene contains objects, the camera and light
// It is responsible for coordinating these things
class Scene
{
public:

	
	// Currently the scene is set up in the constructor
	// This means the object(s) are loaded, given materials and positions as well as the camera and light
	Scene();
	~Scene();

	// Use these to adjust the camera's orientation
	// Camera is currently set up to rotate about the world-space origin NOT the camera's origin
	void ChangeCameraAngleX( float value ) { _cameraAngleX += value; }
	void ChangeCameraAngleY( float value ) { _cameraAngleY += value; }

	// Calls update on all objects in the scene
	void Update( float deltaTs );

	// Draws the scene from the camera's point of view
	void Draw();


	Player* GetPlayer() {return _player;}


protected:

	// Currently one object, this could be a list of objects!
	GameObject *_teapotR1;
	GameObject* _teapotR2;
	GameObject* _teapotR3;
	GameObject* _teapotR4;
	GameObject* _teapotR5;
	GameObject* _teapotM1;
	GameObject* _teapotM2;
	GameObject* _teapotM3;
	GameObject* _teapotM4;
	GameObject* _teapotM5;

	GameObject* _teapotEx1;
	GameObject* _teapotEx2;
	GameObject* _teapotEx3;
	GameObject* _teapotEx4;
	GameObject* _teapotEx5;

	Player *_player;

		
	// This matrix represents the camera's position and orientation
	glm::mat4 _viewMatrix;
	
	// This matrix is like the camera's lens
	glm::mat4 _projMatrix;

	// Current rotation information about the camera
	float _cameraAngleX, _cameraAngleY;

	// Position of the single point-light in the scene
	glm::vec3 _lightPosition;

	glm::quat _cameraOrientation;


};
