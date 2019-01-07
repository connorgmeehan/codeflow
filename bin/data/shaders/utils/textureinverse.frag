#version 150

uniform sampler2DRect tex0;
uniform sampler2DRect tex1;

in vec2 texCoordVarying;
uniform float u_time;

out vec4 fragColor;

void main(){
    vec4 bgColor = texture(tex0, vec2(gl_FragCoord.x, 768 - gl_FragCoord.y));
    vec4 foregroundColor = texture(tex1, vec2(gl_FragCoord.x, 768 - gl_FragCoord.y));
    vec3 color = bgColor.rgb - foregroundColor.rgb;
    // vec3 color = mix(bgColor.rgb, foregroundColor.rgb, foregroundColor.a);
    fragColor = vec4(color, bgColor.a);
}