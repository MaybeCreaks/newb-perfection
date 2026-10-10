#ifndef TONEMAP_H
#define TONEMAP_H

#include "utils.h"

vec3 colorCorrection(vec3 col) {
  #ifdef NL_EXPOSURE
    col *= NL_EXPOSURE;
  #endif

  #if NL_TONEMAP_TYPE == 3
    const float whiteScale = 0.063;
    col = col * (1.0 + col * whiteScale) / (1.0 + col);
  #elif NL_TONEMAP_TYPE == 4
    const float a = 1.04;
    const float b = 0.03;
    const float c = 0.93;
    const float d = 0.56;
    const float e = 0.14;
    col *= 0.92;
    col = clamp((col * (a * col + b)) / (col * (c * col + d) + e), 0.0, 1.0);
  #elif NL_TONEMAP_TYPE == 2
    col = col / (1.0 + col);
  #elif NL_TONEMAP_TYPE == 1
    col = 1.0 - exp(-col * 0.85);
  #endif

  col = pow(col, vec3_splat(1.0 / NL_GAMMA));

  #ifdef NL_SATURATION
    col = mix(vec3_splat(luminance(col)), col, NL_SATURATION * 1.25);
  #else
    col = mix(vec3_splat(luminance(col)), col, 1.18);
  #endif

  col = col * col * (3.0 - 2.0 * col);

  #ifdef NL_TINT
    col *= mix(NL_TINT_LOW, NL_TINT_HIGH, col);
  #endif

  return col;
}

vec3 colorCorrectionInv(vec3 col) {
  #ifdef NL_TINT
    col /= mix(NL_TINT_LOW, NL_TINT_HIGH, col);
  #endif

  #ifdef NL_SATURATION
    col = mix(vec3_splat(dot(col, vec3(0.21, 0.71, 0.08))), col, 1.0 / (NL_SATURATION * 1.25));
  #else
    col = mix(vec3_splat(dot(col, vec3(0.21, 0.71, 0.08))), col, 1.0 / 1.18);
  #endif

  float ws = 0.7966;
  col = pow(col, vec3_splat(NL_GAMMA));
  col = col * (ws + col) / (ws + col * (1.0 - ws));

  #ifdef NL_EXPOSURE
    col /= NL_EXPOSURE;
  #endif

  return col;
}

#endif
