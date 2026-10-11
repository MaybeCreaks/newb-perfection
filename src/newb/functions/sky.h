#ifndef SKY_H
#define SKY_H

#include "detection.h"
#include "noise.h"

struct nl_skycolor {
  vec3 zenith;
  vec3 horizon;
  vec3 horizonEdge;
};

vec3 spectrum(float x) {
  vec3 s = vec3(x - 0.5, x, x + 0.5);
  s = smoothstep(1.0, 0.0, abs(s));
  return s * s;
}

vec3 getUnderwaterCol(vec3 FOG_COLOR) {
  return 2.0 * NL_UNDERWATER_TINT * FOG_COLOR * FOG_COLOR;
}

vec3 getEndZenithCol() {
  #ifdef NL_END_SKY_TOP
    return NL_END_SKY_TOP;
  #else
    return NL_END_ZENITH_COL;
  #endif
}

vec3 getEndHorizonCol() {
  #ifdef NL_END_SKY_BOTTOM
    return NL_END_SKY_BOTTOM;
  #else
    return NL_END_HORIZON_COL;
  #endif
}

nl_skycolor nlEndSkyColors(nl_environment env) {
  nl_skycolor s;
  s.zenith = getEndZenithCol();
  s.horizon = getEndHorizonCol();
  s.horizonEdge = s.horizon;
  return s;
}

nl_skycolor nlOverworldSkyColors(nl_environment env) {
  nl_skycolor s;
  float f = 1.0 + 2.0 * (1.0 - max(-env.dayFactor, 0.0));
  float nightFactor = step(env.dayFactor, 0.0);

  #if defined(NL_DAY_SKY_TOP) && defined(NL_NIGHT_SKY_TOP)
    s.zenith = mix(NL_DAY_SKY_TOP, NL_NIGHT_SKY_TOP * f, nightFactor);
    s.horizon = mix(NL_DAY_SKY_BOTTOM, NL_NIGHT_SKY_BOTTOM * f, nightFactor);
    s.horizonEdge = mix(NL_DAY_HORIZON_COL, NL_NIGHT_SKY_BOTTOM * f, nightFactor);
  #else
    s.zenith = mix(NL_DAY_ZENITH_COL, NL_NIGHT_ZENITH_COL * f, nightFactor);
    s.horizon = mix(NL_DAY_HORIZON_COL, NL_NIGHT_HORIZON_COL * f, nightFactor);
    s.horizonEdge = mix(NL_DAY_EDGE_COL, NL_NIGHT_EDGE_COL * f, nightFactor);
  #endif

  float dawnFactor = 1.0 - env.dayFactor * env.dayFactor;
  dawnFactor *= dawnFactor * dawnFactor;
  dawnFactor *= mix(1.0, dawnFactor * dawnFactor, nightFactor);

  #if defined(NL_SUNSET_TOP) && defined(NL_SUNSET_HORIZON)
    s.zenith = mix(s.zenith, NL_SUNSET_TOP, dawnFactor);
    s.horizon = mix(s.horizon, NL_SUNSET_HORIZON, dawnFactor);
    s.horizonEdge = mix(s.horizonEdge, NL_SUNSET_BOTTOM, dawnFactor);
  #else
    s.zenith = mix(s.zenith, NL_DAWN_ZENITH_COL, dawnFactor);
    s.horizon = mix(s.horizon, NL_DAWN_HORIZON_COL, dawnFactor);
    s.horizonEdge = mix(s.horizonEdge, NL_DAWN_EDGE_COL, dawnFactor);
  #endif

  float zh = dot(s.zenith, vec3_splat(0.33));
  float hh = dot(s.horizon, vec3_splat(0.33));
  float rainMix = env.rainFactor * NL_SKY_RAIN_MIX_FACTOR;
  s.zenith = mix(s.zenith, NL_RAIN_ZENITH_COL * zh, rainMix);
  s.horizon = mix(s.horizon, NL_RAIN_HORIZON_COL * hh, rainMix);
  s.horizonEdge = mix(s.horizonEdge, s.horizon, env.rainFactor);

  if (env.underwater) {
    vec3 underwaterFog = env.fogCol * env.fogCol * NL_UNDERWATER_TINT;
    s.zenith = mix(2.0 * underwaterFog, underwaterFog * zh, 0.8);
    s.horizon = mix(2.0 * underwaterFog, underwaterFog * hh, 0.8);
    s.horizonEdge = s.horizon;
  }

  return s;
}

nl_skycolor nlSkyColors(nl_environment env) {
  if (env.end) {
    return nlEndSkyColors(env);
  }
  return nlOverworldSkyColors(env);
}

vec3 nlSkyGradient(nl_skycolor skycol, vec3 viewDir) {
  float h = max(viewDir.y, 0.0);
  float e = 1.0 - abs(viewDir.y);
  e *= e;
  vec3 col = mix(skycol.horizon, skycol.zenith, h);
  return mix(col, skycol.horizonEdge, e * 0.5);
}

vec4 nlRenderSky(nl_skycolor skycol, nl_environment env, vec3 viewDir, float t, bool renderSky) {
  vec3 skyColor = nlSkyGradient(skycol, viewDir);
  return vec4(skyColor, 1.0);
}

#endif

#ifndef NL_RENDER_END_SKY_DEFINED
#define NL_RENDER_END_SKY_DEFINED
vec3 nlRenderEndSky(vec3 horizon, vec3 zenith, vec3 viewDir, float t) {
float h = clamp(1.0 - abs(viewDir.y), 0.0, 1.0);
return mix(zenith, horizon, pow(h, 2.0));
}
#endif


#ifndef NL_REFL_DEFINED
#define NL_REFL_DEFINED
vec4 nlRefl(nl_skycolor skycol, nl_environment env, vec3 viewDir, float t) {
return vec4(skycol.zenith, 1.0);
}
vec4 nlRefl(vec3 viewDir, vec3 normal, float t) {
return vec4(0.0, 0.0, 0.0, 1.0);
}
#endif


#ifndef NL_REFL_12_DEFINED
#define NL_REFL_12_DEFINED
vec4 nlRefl(vec4 col, nl_skycolor skycol, nl_environment env, vec3 viewDir, vec3 wPos, vec3 cPos, vec3 gPos, vec3 normal, vec2 light, float t, float camDis, float relativeDist) {
return col;
}
#endif
