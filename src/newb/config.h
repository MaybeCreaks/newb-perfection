#ifndef NEWB_PERFECTION_CONFIG_H
#define NEWB_PERFECTION_CONFIG_H

#define NL_FOG_TYPE 0
#define NL_FOG_START 0.65
#define NL_FOG_END 0.98
#define NL_MIST_DENSITY 0.0
#define NL_CHUNK_LOAD_ANIM 1

#define NL_DAY_SKY_TOP     vec3(0.12, 0.42, 0.88)
#define NL_DAY_SKY_BOTTOM  vec3(0.55, 0.72, 0.95)
#define NL_DAY_HORIZON_COL vec3(0.70, 0.82, 0.98)

#define NL_SUNSET_TOP      vec3(0.25, 0.20, 0.45)
#define NL_SUNSET_HORIZON  vec3(0.98, 0.45, 0.22)
#define NL_SUNSET_BOTTOM   vec3(0.92, 0.65, 0.35)

#define NL_NIGHT_SKY_TOP    vec3(0.02, 0.03, 0.08)
#define NL_NIGHT_SKY_BOTTOM vec3(0.05, 0.08, 0.16)
#define NL_STAR_BRIGHTNESS 0.85
#define NL_STAR_DENSITY    1.5
#define NL_STAR_TWINKLE     0.00
#define NL_AURORA_INTENSITY 0.0

#define NL_TORCH_INTENSITY  1.45
#define NL_TORCH_COLOR      vec3(1.00, 0.52, 0.18)
#define NL_NIGHT_BRIGHTNESS 0.35
#define NL_SHADOW_INTENSITY 0.65
#define NL_SUN_INTENSITY    1.10
#define NL_SUN_GLOW        0.00
#define NL_DESATURATE_NIGHT 0.15

#define NL_ENTITY_BRIGHTNESS  1.15
#define NL_ENTITY_TORCH_LIGHT 1.20
#define NL_ENTITY_SHADOW      0.40

#define NL_CLOUD_TYPE 1
#define NL_CLOUD_COLOR vec3(0.95, 0.96, 0.98)
#define NL_CLOUD_DENSITY 0.60
#define NL_CLOUD_HEIGHT 120.0
#undef NL_CLOUD_LAYER2

#define NL_WATER_COLOR       vec3(0.08, 0.38, 0.52)
#define NL_WATER_TRANSPARENCY 0.60
#define NL_WATER_TEX_OPACITY 0.50
#undef NL_WATER_REFLECT
#undef NL_WATER_WAVE

#define NL_LAVA_INTENSITY 1.30
#define NL_LAVA_COLOR     vec3(1.00, 0.35, 0.05)
#define NL_LAVA_EMISSIVE   1.0

#define NL_NETHER_FOG_DENSITY 0.75
#define NL_NETHER_AMB_COLOR   vec3(0.35, 0.08, 0.05)

#define NL_END_SKY_TOP      vec3(0.14, 0.06, 0.22)
#define NL_END_SKY_BOTTOM   vec3(0.28, 0.12, 0.35)

#undef NL_PBR
#define NL_GLOW_ORES 1
#define NL_PLANT_WAVE 1

#ifndef NL_GAMMA
  #define NL_GAMMA 1.0
#endif
#ifndef NL_SUN_PATH_TILT
  #define NL_SUN_PATH_TILT 0.0
#endif
#ifndef NL_SUN_PATH_YAW
  #define NL_SUN_PATH_YAW 0.0
#endif
#ifndef NL_MOON_PATH_TILT
  #define NL_MOON_PATH_TILT 0.0
#endif
#ifndef NL_MOON_PATH_YAW
  #define NL_MOON_PATH_YAW 0.0
#endif
#ifndef NL_UNDERWATER_TINT
  #define NL_UNDERWATER_TINT vec3(0.8, 1.0, 0.9)
#endif
#ifndef NL_SKY_RAIN_MIX_FACTOR
  #define NL_SKY_RAIN_MIX_FACTOR 0.3
#endif
#ifndef NL_RAIN_ZENITH_COL
  #define NL_RAIN_ZENITH_COL vec3(0.5, 0.5, 0.5)
#endif
#ifndef NL_RAIN_HORIZON_COL
  #define NL_RAIN_HORIZON_COL vec3(0.5, 0.5, 0.5)
#endif
#ifndef NL_CLOUD1_SPEED
  #define NL_CLOUD1_SPEED 1.0
#endif
#ifndef NL_CLOUD1_SCALE
  #define NL_CLOUD1_SCALE 1.0
#endif
#ifndef NL_CLOUD3_SHADOW_OFFSET
  #define NL_CLOUD3_SHADOW_OFFSET 0.5
#endif
#ifndef NL_NOON_SUNLIGHT_COL
  #define NL_NOON_SUNLIGHT_COL vec3(1.0, 1.0, 1.0)
#endif
#ifndef NL_NIGHT_MOONLIGHT_COL
  #define NL_NIGHT_MOONLIGHT_COL vec3(0.2, 0.2, 0.4)
#endif
#ifndef NL_DAWN_SUNLIGHT_COL
  #define NL_DAWN_SUNLIGHT_COL vec3(1.0, 0.5, 0.2)
#endif
#ifndef NL_UNDERWATER_TORCH_COL
  #define NL_UNDERWATER_TORCH_COL vec3(0.2, 0.6, 0.8)
#endif
#ifndef NL_END_TORCH_COL
  #define NL_END_TORCH_COL vec3(0.7, 0.3, 0.9)
#endif
#ifndef NL_NETHER_TORCH_COL
  #define NL_NETHER_TORCH_COL vec3(1.0, 0.4, 0.1)
#endif
#ifndef NL_END_AMBIENT
  #define NL_END_AMBIENT vec3(0.2, 0.1, 0.3)
#endif
#ifndef NL_NETHER_AMBIENT
  #define NL_NETHER_AMBIENT vec3(0.35, 0.08, 0.05)
#endif
#ifndef NL_SUNLIGHT_INTENSITY
  #define NL_SUNLIGHT_INTENSITY 1.0
#endif
#ifndef NL_MIN_LIGHTING_BOOST
  #define NL_MIN_LIGHTING_BOOST 0.1
#endif
#ifndef NL_WATER_WAVE_SPEED
  #define NL_WATER_WAVE_SPEED 1.0
#endif
#ifndef NL_UNDERWATER_BRIGHTNESS
  #define NL_UNDERWATER_BRIGHTNESS 1.0
#endif
#ifndef NL_CAUSTIC_INTENSITY
  #define NL_CAUSTIC_INTENSITY 1.0
#endif
#ifndef NL_TORCHLIGHT_INTENSITY
  #define NL_TORCHLIGHT_INTENSITY 1.0
#endif
#ifndef NL_LAVA_NOISE_SPEED
  #define NL_LAVA_NOISE_SPEED 1.0
#endif
#ifndef NL_WAVE_RANGE
  #define NL_WAVE_RANGE 32.0
#endif
#ifndef NL_GLOW_TEX
  #define NL_GLOW_TEX 1.0
#endif

#ifndef NL_DAY_ZENITH_COL
  #define NL_DAY_ZENITH_COL vec3(0.12, 0.42, 0.88)
#endif
#ifndef NL_DAY_EDGE_COL
  #define NL_DAY_EDGE_COL vec3(0.70, 0.82, 0.98)
#endif
#ifndef NL_NIGHT_ZENITH_COL
  #define NL_NIGHT_ZENITH_COL vec3(0.02, 0.03, 0.08)
#endif
#ifndef NL_NIGHT_EDGE_COL
  #define NL_NIGHT_EDGE_COL vec3(0.05, 0.08, 0.16)
#endif
#ifndef NL_DAWN_ZENITH_COL
  #define NL_DAWN_ZENITH_COL vec3(0.25, 0.20, 0.45)
#endif
#ifndef NL_DAWN_EDGE_COL
  #define NL_DAWN_EDGE_COL vec3(0.92, 0.65, 0.35)
#endif
#ifndef NL_END_ZENITH_COL
  #define NL_END_ZENITH_COL vec3(0.14, 0.06, 0.22)
#endif
#ifndef NL_END_HORIZON_COL
  #define NL_END_HORIZON_COL vec3(0.28, 0.12, 0.35)
#endif

#if defined(NO_GLOWING_ORES)
  #undef NL_GLOW_ORES
  #define NL_GLOW_ORES 0
#endif

#if defined(NO_GLOWING_ORES_NO_WAVE)
  #undef NL_GLOW_ORES
  #define NL_GLOW_ORES 0
  #undef NL_PLANT_WAVE
  #define NL_PLANT_WAVE 0
#endif

#if defined(NO_WAVE)
  #undef NL_PLANT_WAVE
  #define NL_PLANT_WAVE 0
#endif

#endif
