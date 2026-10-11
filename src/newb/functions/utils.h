#ifndef UTILS_H
#define UTILS_H

#define PI 3.141592
#define PI_HALF 1.570796
#define PI_QUART 0.785398

#include "newb/config.h"

mat2 rmat2(float t) {
  float sint = sin(t);
  float cost = cos(t);
  return mtxFromRows(vec2(cost, -sint), vec2(sint, cost));
}

float degToRad(float t) { return 0.0174533*t; }

float luminance(vec3 x) { return dot(x, vec3(0.21, 0.71, 0.08)); }

vec3 colorCorrection(vec3 col) {
  col = pow(col, vec3_splat(1.0 / NL_GAMMA));
  col = mix(vec3_splat(luminance(col)), col, 1.18);
  col = col * col * (3.0 - 2.0 * col);
  return col;
}

vec3 colorCorrectionInv(vec3 col) {
  col = mix(vec3_splat(dot(col, vec3(0.21, 0.71, 0.08))), col, 1.0 / 1.18);
  float ws = 0.7966;
  col = pow(col, vec3_splat(NL_GAMMA));
  col = col * (ws + col) / (ws + col * (1.0 - ws));
  return col;
}

#endif
