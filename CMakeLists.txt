cmake_minimum_required(VERSION 2.8)

# VitaSDK defines
if( NOT DEFINED CMAKE_TOOLCHAIN_FILE )
  if( DEFINED ENV{VITASDK} )
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

# Project start
set(VITA_APPNAME SDLPoP-Vita)
set(VITA_TITLEID "SPOP00001")
set(VITA_VERSION "01.00")

project(${VITA_APPNAME})
include("${VITASDK}/share/vita.cmake" REQUIRED)

# Flags and includes
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DVITA -fno-exceptions")

link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

# Builds
add_executable(${VITA_APPNAME}
  src/data.c
  src/main.c
  src/lighting.c
  src/options.c
  src/seg000.c
  src/seg001.c
  src/seg002.c
  src/seg003.c
  src/seg004.c
  src/seg005.c
  src/seg006.c
  src/seg007.c
  src/seg008.c
  src/seg009.c
  src/seqtbl.c
)

target_link_libraries(${VITA_APPNAME}
  SDL2_image
  SDL2_mixer
  SDL2
  vorbisfile
  vorbis
  ogg
  jpeg
  png
  vita2d
  kbdvita
  z
  m
  SceAppUtil_stub
  SceAudio_stub
  SceCommonDialog_stub
  SceCtrl_stub
  SceDisplay_stub
  SceGxm_stub
  SceSysmodule_stub
  SceTouch_stub
)

# Create Vita artifacts
vita_create_self(eboot.bin ${VITA_APPNAME} SAFE)
vita_create_vpk(${VITA_APPNAME}.vpk ${VITA_TITLEID} eboot.bin
  VERSION ${VITA_VERSION}
  NAME ${VITA_APPNAME}
  FILE res/icon0.png sce_sys/icon0.png
  FILE res/bg.png sce_sys/livearea/contents/bg.png
  FILE res/startup.png sce_sys/livearea/contents/startup.png
  FILE res/template.xml sce_sys/livearea/contents/template.xml
)
