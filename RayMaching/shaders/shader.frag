#version 330 core
out vec4 FragColor;
uniform float iTime;

float sphereSDF(vec3 p, float r) {
    return length(p) - r;
}

float planeSDF(vec3 p) {
    return p.y;
}

float sceneSDF(vec3 p) {
    return min(sphereSDF(p - vec3(0.0, 1.0, 4.0), 1.0), planeSDF(p));
}

vec3 getNormal(vec3 p) {
    float d = sceneSDF(p);
    vec2 e = vec2(0.001, 0);
    vec3 n = d - vec3(
        sceneSDF(p - e.xyy),
        sceneSDF(p - e.yxy),
        sceneSDF(p - e.yyx)
    );
    return normalize(n);
}

void main() {
    vec2 uv = (gl_FragCoord.xy / vec2(800, 600)) * 2.0 - 1.0;
    vec3 ro = vec3(0.0, 1.0, -5.0);
    vec3 rd = normalize(vec3(uv.x, uv.y, 1.5));

    float t = 0.0;
    for (int i = 0; i < 100; i++) {
        vec3 p = ro + t * rd;
        float d = sceneSDF(p);
        if (d < 0.001) {
            vec3 n = getNormal(p);
            float light = dot(n, normalize(vec3(1.0, 1.0, -1.0)));
            FragColor = vec4(vec3(light), 1.0);
            return;
        }
        t += d;
        if (t > 100.0) break;
    }
    FragColor = vec4(0.0);
}
