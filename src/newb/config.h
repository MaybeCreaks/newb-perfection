
#define NL_FOG_TYPE 0
#define NL_FOG_START 0.6
#define NL_FOG_END 0.95
#define NL_CHUNK_LOAD_ANIM 1

#if defined(NO_GLOWING_ORES) || defined(NO_GLOWING_ORES_NO_WAVE)
  #undef NL_GLOW_ORES
  #define NL_GLOW_ORES 0
#endif

#if defined(NO_WAVE) || defined(NO_GLOWING_ORES_NO_WAVE)
  #undef NL_PLANT_WAVE
  #define NL_PLANT_WAVE 0
#endif


#define NL_DAY_SKY_TOP     vec3(0.12, 0.42, 0.88)
#define NL_DAY_SKY_BOTTOM  vec3(0.55, 0.72, 0.95)


#define NL_SUNSET_TOP      vec3(0.25, 0.20, 0.45)
#define NL_SUNSET_HORIZON  vec3(0.98, 0.45, 0.22)
#define NL_SUNSET_BOTTOM   vec3(0.92, 0.65, 0.35)


#define NL_NIGHT_SKY_TOP    vec3(0.02, 0.03, 0.08)
#define NL_NIGHT_SKY_BOTTOM vec3(0.05, 0.08, 0.16)
#define NL_STAR_BRIGHTNESS 0.85
#define NL_STAR_DENSITY    1.5

#define NL_TORCH_INTENSITY  1.45
#define NL_TORCH_COLOR      vec3(1.00, 0.52, 0.18)
#define NL_NIGHT_BRIGHTNESS 0.22
#define NL_SHADOW_INTENSITY 0.65
#define NL_ENTITY_BRIGHTNESS 1.15
#define NL_ENTITY_TORCH_LIGHT 1.20

#define NL_NETHER_FOG_DENSITY 0.75
#define NL_NETHER_AMB_COLOR   vec3(0.35, 0.08, 0.05)

#define NL_END_SKY_TOP      vec3(0.14, 0.06, 0.22)
#define NL_END_SKY_BOTTOM   vec3(0.28, 0.12, 0.35)

#define NL_WATER_COLOR       vec3(0.08, 0.38, 0.52)
#define NL_WATER_TRANSPARENCY 0.65
#undef NL_WATER_REFLECT
#undef NL_WATER_WAVE

#define NL_CLOUD_TYPE 1
#define NL_CLOUD_COLOR vec3(0.95, 0.96, 0.98)
#define NL_CLOUD_DENSITY 0.6
#undef NL_CLOUD_LAYER2

#define NL_LAVA_INTENSITY 1.3
#define NL_LAVA_COLOR     vec3(1.00, 0.35, 0.05)
#undef NL_PBR

#define NL_PLANT_WAVE 1
#define NL_GLOW_ORES 1
