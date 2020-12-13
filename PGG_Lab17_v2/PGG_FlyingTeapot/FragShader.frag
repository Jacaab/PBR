#version 430 core

// Input per-fragment data
// These must correspond to the varying outputs from the vertex shader
in vec3 vNormalV;
in vec3 eyeSpaceLightPosV;
in vec3 eyeSpaceVertPosV;
in vec2 texCoord;


// Input uniform data - these have values that will be the same for every fragment
uniform vec3 lightColour = {0.8,0.8,0.8};
uniform vec3 emissiveColour = {0,0,0};
uniform vec3 ambientColour  = {0.1f,0.1f,0.2f};
uniform vec3 diffuseColour  = {1.0f,1.0f,1.0f};
uniform vec3 specularColour = {1.0f,1.0f,1.0f};
uniform float shininess     = 90.0f;
uniform float alpha         = 1.0f;

// The output of the fragment shader is the fragment's colour
out vec4 fragColour;

// This is another input to allow us to access a texture
uniform sampler2D tex1;


void main()
{
	// create a normal unit
	vec3 normal = normalize( vNormalV );

	// the direction from the surface position to the light position
	vec3 lightDir = normalize( eyeSpaceLightPosV - eyeSpaceVertPosV );

	// Direction from the eye to sample of the surface
	vec3 eyeDir = normalize( -eyeSpaceVertPosV );

	// half way between eye direction and light direction
	vec3 halfVec = normalize( eyeDir + lightDir );

	// Retrieve colour from texture
	vec3 texColour = vec3(texture(tex1,vec2(texCoord.x,1-texCoord.y)));
	
	// Calculate diffuse lighting
	vec3 diffuse = diffuseColour * lightColour * max( dot( normal, lightDir ), 0);
	
	// Put specular lighting code here!
	vec3 specular = vec3(0);

	// Final colour uses the texture colour for all components
	// If you want a separate texture for specular you will need to change this
	fragColour = vec4( emissiveColour + texColour*(ambientColour + diffuse + specular), alpha);
}
