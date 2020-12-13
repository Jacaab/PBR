#version 430 core

// unput per fragment data
//correspond to the output in vert
in vec3 vNormalV;
in vec3 eyeSpaceLightPosV;
in vec3 eyeSpaceVertPosV;
in vec2 texCoord;

//input uniform data - pbr parameters
uniform vec3 lightColour = {0.8f, 0.8f, 0.8f};
uniform vec3 albedo = {0.8f,0.0f,0.0f};
uniform float metallic = 0.0f;
uniform float roughness = 0.2f;
uniform float ao = 1.0f;
uniform float alpha = 1.0f;

//constant PI
const float PI = 3.14159265359;

out vec4 fragColour;

uniform sampler2D tex1;

//functions for calculating BRDF using the Cook-Torrance model
float DistributionGGX(vec3 N, vec3 H, float roughness);
float GeometrySchlickGGX(float NdotV, float roughness);
float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness);
vec3 fresnelSchlick(float cosTheta, vec3 F0);

void main()
{
	//normal units
	vec3 normal = normalize(vNormalV);

	//eye to surface
	vec3 viewDir = normalize( -eyeSpaceVertPosV );

	// retrieve texture colour
	vec3 texColour = vec3(texture(tex1,vec2(texCoord.x,1-texCoord.y)));

	//reflectance
	vec3 F0 = vec3(0.04); // plastic
	F0 = mix(F0, albedo, metallic);

	vec3 Lo = vec3(0.0);

	// radiance
	vec3 lightDir = normalize( eyeSpaceLightPosV - eyeSpaceVertPosV );		//surface to light
	vec3 halfVector = normalize(viewDir + lightDir);						// half way between eye direction and light direction
	float distance = length( eyeSpaceLightPosV - eyeSpaceVertPosV );
	float attenuation = 1.0 / (distance * distance);
	vec3 radiance = lightColour * attenuation;

	// BRDF (Cook-Torrance)
	float NDF = DistributionGGX(normal, halfVector, roughness);
	float G = GeometrySmith(normal, viewDir, lightDir, roughness);
	vec3 F = fresnelSchlick(clamp(dot(halfVector, viewDir), 0.0, 1.0), F0);

	//specular
	vec3 nominator    = NDF * G * F; 
	float denominator = 4 * max(dot(normal, viewDir), 0.0) * max(dot(normal, lightDir), 0.0);
	vec3 specular = nominator / max(denominator, 0.001); // !/0 

	//energy conservation
	//kS thesame as fresnel
	vec3 kS = F;

	// 1.0 so doesnt emit light
	vec3 kD = vec3(1.0) - kS;

	//make non metals have diffuse lighting
	kD *= 1.0 - metallic;

	//scale the light
	float NdotL = max(dot(normal,lightDir), 0.0);

	//combine with radiance
	Lo += (kD * albedo / PI + specular) * radiance * NdotL;

	vec3 ambient = vec3(0.03) * albedo * ao;

	vec3 colour = ambient + Lo;
	
	colour = texColour*colour;

	colour = colour / (colour +vec3(1.0));
	//gamma
	colour = pow(colour, vec3(0.1));   //   Previous  was 1.0/2.2

	fragColour = vec4(colour, alpha);
}

float DistributionGGX(vec3 N, vec3 H, float roughness)
{
    float a = roughness*roughness;
    float a2 = a*a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH*NdotH;

    float nom   = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;

    return nom / max(denom, 0.001); // stops divide by zero instances for roughness and NdotH
}

float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r*r) / 8.0;

    float nom   = NdotV;
    float denom = NdotV * (1.0 - k) + k;

    return nom / denom;
}

float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);

    return ggx1 * ggx2;
}

vec3 fresnelSchlick(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(1.0 - cosTheta, 5.0);
}