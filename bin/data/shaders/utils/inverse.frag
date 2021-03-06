#version 150
uniform sampler2DRect tex0;

in vec2 texCoordVarying;
uniform float u_time;

out vec4 fragColor;

void main(){
    vec4 textureColor = texture(tex0, vec2(gl_FragCoord.x, gl_FragCoord.y));
    fragColor = vec4(1.0 - textureColor.r, 1.0 - textureColor.g, 1.0 - textureColor.b, textureColor.a);
    // fragColor = vec4(1, 0, 0, 1);
}