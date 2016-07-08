#version 330 core

uniform sampler2D positionTex;
uniform sampler2D normalTex;

layout(std140, row_major) uniform SceneUniforms
{
    mat4 c_viewProjection;
    vec3 c_viewDir;
};

layout(std140, row_major) uniform AOUniforms
{
    float c_radius;
    float c_ambientLight;
    float c_sigma;
    float c_k;
    vec4 c_randomOffsets[16]; // 2 random pixel offsets per entry
};

const float c_depthBias = 0.001;
const float c_distEpsilon = 0.05;

out vec4 out_color;

//float ao_increment(const vec3 &v, const vec3 &n, const float sigma)
//{
//    float res = 0 > dot(v, n) ? 0 : dot(v, n);
//    res /= (len(v) + sigma);
//    return res;
//}

// Sources:
// http://www.iquilezles.org/www/articles/ssao/ssao.htm
// http://graphics.cs.williams.edu/papers/AlchemyHPG11/
void main()
{
    // center is the pixel position of the central pixel
    ivec2 center = ivec2(gl_FragCoord.xy);

    // DONE: Get position and normal of the center pixel by using texelFetch().
    vec3 position, normal;
    position =  texelFetch(positionTex, center, 0).rgb;
    normal =  texelFetch(normalTex, center, 1).rgb;

    // TODO: Compute the camera distance z for the central position. Use c_viewProjection and the
    // position to achive this.
    float z = dot((SceneUniforms.c_viewProjection * texelFetch(positionTex, center, 0)).rgb,
                  (SceneUniforms.c_viewProjection * texelFetch(positionTex, center, 0)).rgb);

    float visibility = 0.0;
    vec3 s, v;
    float res;
    for(int i = 0; i < 16; ++i)
    {
        // DONE: compute the term from Equation 1 for the two offset vectors
        // c_randomOffsets[i].xy and c_randomOffsets[i].zw. To avoid redundant source code
        // you should write a function. Add the results to visibility.
        s = texelFetch(positionTex, AOUniforms.c_randomOffsets[i].xy, 0).rgb;
        v = s - position;
        res = 0 > dot(v, normal) ? 0 : dot(v, normal);
        res /= (dot(v, v) +  AOUniforms.c_sigma);
        visibility += res;
//        visibility += ao_increment(v, normal, AOUniforms.c_sigma);
        s = texelFetch(positionTex, AOUniforms.c_randomOffsets[i].zw, 0).rgb;
        v = s - position;
        res = 0 > dot(v, normal) ? 0 : dot(v, normal);
        res /= (dot(v, v) +  AOUniforms.c_sigma);
        visibility += res;
//        visibility += ao_increment(v, normal, AOUniforms.c_sigma);
    }
    // DONE: Compute the ambient obscurance using the sum in visiblity.
//    float ambientObscurance = 0.0;
    float ambientObscurance = 1.0f - visibility / 32.0f;

    // Diffuse shading by single global light
    float directLight = dot(normal, normalize(vec3(0.4, 1.0, 0.7))) * 0.6 + 0.4;

    // The following line allows to smoothly switch between pure direct light and pure
    // ambientObscurance.
    out_color = vec4(mix(directLight, ambientObscurance, c_ambientLight));
}

