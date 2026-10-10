#ifndef WATER_H
#define WATER_H

#include "detection.h"
#include "sky.h"

vec4 nlWater(vec4 texCol, vec3 waterCol, vec2 lit, float depth, float alpha) {
  #ifdef NL_WATER_COLOR
    vec3 col = mix(texCol.rgb, NL_WATER_COLOR, 0.65);
  #else
    vec3 col = mix(texCol.rgb, waterCol, 0.65);
  #endif

  col *= 0.6 + 0.4 * lit.y;

  #ifdef NL_WATER_TRANSPARENCY
    float finalAlpha = NL_WATER_TRANSPARENCY;
  #else
    float finalAlpha = alpha;
  #endif

  return vec4(col, finalAlpha);
}

vec3 nlWaterReflection(vec3 viewDir, vec3 horizonCol, vec3 zenithCol) {
  return horizonCol;
}

#endif
