#ifndef FOG_H
#define FOG_H

float nlRenderFogFade(float relativeDist, vec3 FOG_COLOR, vec2 FOG_CONTROL) {
  #ifdef NL_FOG
    #if defined(NL_FOG_START) && defined(NL_FOG_END)
      float fade = smoothstep(NL_FOG_START, NL_FOG_END, relativeDist);
    #else
      float fade = smoothstep(FOG_CONTROL.x, FOG_CONTROL.y, relativeDist);
    #endif
    return NL_FOG * fade;
  #else
    return 0.0;
  #endif
}

float nlRenderGodRayIntensity(vec3 cPos, vec3 worldPos, float t, vec2 uv1, float relativeDist, vec3 FOG_COLOR) {
  return 0.0;
}

#endif
