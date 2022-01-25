
#ifndef __MATERIAL__
#define __MATERIAL__

#include <string>
#include <GLM/glm.hpp>
#include "glew.h"

// Encapsulates shaders and textures
class Material
{
public:
	Material();
	~Material();

	// Loads shaders from file
	// Returns false if there was an error - it will also print out messages to console
	bool LoadShaders( std::string vertFilename, std::string fragFilename );

	// For setting the standard matrices needed by the shader
	void SetMatrices(glm::mat4 &modelMatrix, glm::mat4 &invModelMatrix, glm::mat4 &viewMatrix, glm::mat4 &projMatrix);
	
	// For setting material properties
	void SetEmissiveColour( glm::vec3 input ) { _emissiveColour = input;}
	void SetDiffuseColour( glm::vec3 input ) { _diffuseColour = input;}
	void SetSpecularColour( glm::vec3 input ) { _specularColour = input;}
	void SetAlbedo( glm::vec3 input ) { _albedo = input; }
	void SetMetallic(float input) { _metallic = input; }
	void SetRoughness(float input) { _roughness = input; }
	void SetAo(float input) { _ao = input; }


	// Set light position in world space
	void SetLightPosition( glm::vec3 input ) { _lightPosition = input;}


	// Sets texture
	// This applies to ambient, diffuse and specular colours
	bool SetTexture( std::string filename ) {_texture1 = LoadTexture(filename); return _texture1>0;}
	bool SetAlbedoMap(std::string filename) { _albedoMap = LoadTexture(filename); return _albedoMap > 0; }
	bool SetMetallicMap(std::string filename) { _metallicMap = LoadTexture(filename); return _metallicMap > 0; }
	bool SetRoughnessMap(std::string filename) { _roughnessMap = LoadTexture(filename); return _roughnessMap > 0; }
	bool SetAOMap(std::string filename) { _aoMap = LoadTexture(filename); return _aoMap > 0; }


	// Sets the material, applying the shaders
	void Apply();

protected:

	// Utility function
	bool CheckShaderCompiled( GLint shader );
	
	// The OpenGL shader program handle
	int _shaderProgram;

	// Locations of Uniforms in the vertex shader
	int _shaderModelMatLocation;
	int _shaderInvModelMatLocation;
	int _shaderViewMatLocation;
	int _shaderProjMatLocation;

	// Location of Uniforms in the fragment shader
	//blinn
	int _shaderDiffuseColLocation, _shaderEmissiveColLocation, _shaderSpecularColLocation;
	//pbr
	int _shaderAlbedoColLocation, _shaderMetallicColLocation, _shaderRoughnessColLocation, _shaderAoColLocation;
	//textured pbr
	int _shaderAlbedoMapSamplerLocation, _shaderMetallicMapSamplerLocation, _shaderRoughnessMapSamplerLocation, _shaderAoMapSamplerLocation;
	
	//light
	int _shaderWSLightPosLocation;
	
	int _shaderTex1SamplerLocation;
	
	// Local store of material properties to be sent to the shader
	glm::vec3 _emissiveColour, _diffuseColour, _specularColour, _albedo;
	float _metallic, _roughness, _ao;
	glm::vec3 _lightPosition;


	// Loads a .bmp from file
	unsigned int LoadTexture( std::string filename );
	
	// OpenGL handle for the texture
	unsigned int _texture1, _albedoMap, _metallicMap, _roughnessMap, _aoMap;

};

#endif