cmake_minimum_required(VERSION 3.0)

set(CMAKE_SYSTEM_NAME "Generic")
set(DEVKITPRO $ENV{DEVKITPRO})
set(CMAKE_SYSTEM_PROCESSOR "armv8-a")
set(CMAKE_C_COMPILER "${DEVKITPRO}/devkitA64/bin/aarch64-none-elf-gcc")
set(CMAKE_CXX_COMPILER "${DEVKITPRO}/devkitA64/bin/aarch64-none-elf-g++")
set(CMAKE_ASM_COMPILER "${DEVKITPRO}/devkitA64/bin/aarch64-none-elf-as")
set(CMAKE_AR "${DEVKITPRO}/devkitA64/bin/aarch64-none-elf-gcc-ar" CACHE STRING "")
set(CMAKE_RANLIB "${DEVKITPRO}/devkitA64/bin/aarch64-none-elf-gcc-ranlib" CACHE STRING "")
set(CMAKE_C_FLAGS "-march=armv8-a -mtune=cortex-a57 -mtp=soft -fPIE -ffast-math -ffunction-sections -fdata-sections -I${DEVKITPRO}/libnx/include -I${DEVKITPRO}/portlibs/switch/include" CACHE STRING "C flags")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -fpermissive -fno-rtti -fno-exceptions -std=gnu++11" CACHE STRING "C++ flags")
set(CMAKE_FIND_ROOT_PATH ${DEVKITPRO} ${DEVKITPRO}/devkitA64 ${DEVKITPRO}/libnx ${DEVKITPRO}/portlibs/switch)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "Shared libs not available")
link_directories(${DEVKITPRO}/libnx/lib ${DEVKITPRO}/portlibs/switch/lib)

project(SDLPoP)

file(GLOB SRCS src/*.c)

set(POP_INC src)
set(POP_CFLAGS -fno-exceptions -O2)
set(POP_LDFLAGS SDL2_image SDL2 jpeg png z)

#list(REMOVE_ITEM SRCS ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
#list(REMOVE_ITEM SRCS ${CMAKE_CURRENT_SOURCE_DIR}/dynlib.cpp)
#list(APPEND SRCS switch/main_switch.cpp switch/switch.c)
list(APPEND POP_CFLAGS -D__SWITCH__ -I${DEVKITPRO}/portlibs/switch/include/SDL2)
list(APPEND POP_LDFLAGS nx m -specs=${DEVKITPRO}/libnx/switch.specs)

add_executable(${CMAKE_PROJECT_NAME}.elf
  ${SRCS}
)
target_include_directories(${CMAKE_PROJECT_NAME}.elf PRIVATE ${POP_INC})
target_compile_options(${CMAKE_PROJECT_NAME}.elf PRIVATE ${POP_CFLAGS})
target_link_libraries(${CMAKE_PROJECT_NAME}.elf ${POP_LDFLAGS})

add_custom_target(${CMAKE_PROJECT_NAME}.nro
  DEPENDS ${CMAKE_PROJECT_NAME}.elf
  COMMAND nacptool --create "${CMAKE_PROJECT_NAME}" "usineur" "1.0" ${CMAKE_PROJECT_NAME}.nacp
  COMMAND elf2nro ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.nro --icon=${CMAKE_SOURCE_DIR}/res/icon.jpg --nacp=${CMAKE_PROJECT_NAME}.nacp
)
