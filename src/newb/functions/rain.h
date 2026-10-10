#ifndef RAIN_H
#define RAIN_H

#include "detection.h"
#include "noise.h"
#include "sky.h"

float nlRainStreak(vec2 uv, float t) {
  uv.x += uv.y * 0.12;
  uv.y *= 0.08;
  uv.y -= t * 14.0;

  vec2 p = floor(uv);
  vec2 f = fract(uv);

  float n = rand(p);
  float streak = smoothstep(0.82, 0.97, n);
  streak *= smoothstep(0.0, 0.15, f.x) * smoothstep(1.0, 0.75, f.x);
  streak *= smoothstep(0.0, 0.25, f.y) * smoothstep(1.0, 0.2, f.y);

  return streak;
}

vec3 nlRainParticle(vec3 p, float t, float rain) {
  vec3 p0 = floor(p);
  vec3 u = fract(p);

  float n = rand(p0.xz + vec2(p0.y, 0.0));
  float spark = smoothstep(0.91, 0.99, n);

  float phase = fract(t * 3.5 + n * 6.2831);
  spark *= smoothstep(0.0, 0.18, phase) * (1.0 - phase);

  vec3 particleCol = mix(vec3(0.55, 0.72, 0.95), vec3(0.9, 0.95, 1.0), spark);
  return particleCol * spark * rain * 1.8;
}

vec4 nlRenderRain(vec3 pos, float t, float rain, vec3 fogCol) {
  if (rain <= 0.001) {
    return vec4(0.0);
  }

  vec2 uv = pos.xz + pos.y * 0.08;
  float streaks = nlRainStreak(uv * 7.5, t);
  streaks += 0.5 * nlRainStreak(uv * 15.0 + vec2(1.3, 2.7), t * 1.25);

  vec3 particleGlow = nlRainParticle(pos * 4.0, t, rain);
  vec3 col = mix(fogCol, vec3(0.82, 0.91, 1.0), 0.55) + particleGlow;

  float alpha = streaks * rain * 0.42 + length(particleGlow) * 0.3;

  return vec4(col, clamp(alpha, 0.0, 0.85));
}

vec3 nlWetnessReflection(vec3 color, float wetness, vec3 skyCol, float lightMask) {
  if (wetness <= 0.001) {
    return color;
  }
  vec3 wetCol = color * 0.65;
  wetCol += skyCol * wetness * lightMask * 0.40;
  return mix(color, wetCol, wetness);
}

#endif
