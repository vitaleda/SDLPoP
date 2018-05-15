cmake_minimum_required(VERSION 3.0)

if( NOT DEFINED CMAKE_TOOLCHAIN_FILE )
  set(CMAKE_TOOLCHAIN_FILE "Toolchain.cmake" CACHE PATH "Toolchain file")
endif()

project(SDLPoP)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__SWITCH__ -fno-exceptions -O2")

link_directories(
  ${DEVKITPRO}/libnx/lib
  ${DEVKITPRO}/portlibs/switch/lib
)

file(GLOB SRCS src/*.c)
add_executable(${CMAKE_PROJECT_NAME}.elf
  ${SRCS}
)

target_link_libraries(${CMAKE_PROJECT_NAME}.elf
  SDL2_image
  SDL2
  jpeg
  png
  z
  nx
  m
 -specs=${DEVKITPRO}/libnx/switch.specs
)

add_custom_target(${CMAKE_PROJECT_NAME}.nro
  DEPENDS ${CMAKE_PROJECT_NAME}.elf
  COMMAND nacptool --create "${CMAKE_PROJECT_NAME}" "usineur" "1.0" ${CMAKE_PROJECT_NAME}.nacp
  COMMAND elf2nro ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.nro --icon=${CMAKE_SOURCE_DIR}/res/icon.jpg --nacp=${CMAKE_PROJECT_NAME}.nacp
)
