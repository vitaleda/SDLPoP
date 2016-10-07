TARGET   := SDLPoP-Vita
TITLE_ID := SPOP00001
SOURCES  := src
DATA     := data
INCLUDES := include

LIBS = -lSDL2_image -lSDL2_mixer -lSDL2 -lvorbisfile -logg -lvorbis -lmodplug \
	-lvita2d -lkbdvita -lSceCommonDialog_stub -lSceAudio_stub -lSceKernel_stub \
	-lSceNet_stub -lSceNetCtl_stub -lpng -lz -lSceDisplay_stub -lSceGxm_stub \
	-lSceSysmodule_stub -lSceCtrl_stub -lSceTouch_stub -lm -lc \
	-lSceAppUtil_stub -lScePgf_stub -ljpeg -lSceRtc_stub -lScePower_stub

COMMON_OBJS = src/data.o \
	src/main.o \
	src/options.o \
	src/seg000.o \
	src/seg001.o \
	src/seg002.o \
	src/seg003.o \
	src/seg004.o \
	src/seg005.o \
	src/seg006.o \
	src/seg007.o \
	src/seg008.o \
	src/seg009.o \
	src/seqtbl.o

CFILES   := $(COMMON_OBJS)
BINFILES := $(foreach dir,$(DATA), $(wildcard $(dir)/*.bin))
OBJS     := $(addsuffix .o,$(BINFILES)) $(CFILES:.c=.o) $(CPPFILES:.cpp=.o)

PREFIX   = arm-vita-eabi
CC       = $(PREFIX)-gcc
CXX      = $(PREFIX)-c++
CFLAGS   = -Wl,-q -O3 -g -DVITA
CXXFLAGS = $(CFLAGS) -fno-exceptions
ASFLAGS  = $(CFLAGS)

all: $(TARGET).vpk

$(TARGET).vpk: eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE_ID) "$(TARGET)" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin \
	-a res/icon0.png=sce_sys/icon0.png \
	-a res/bg.png=sce_sys/livearea/contents/bg.png \
	-a res/startup.png=sce_sys/livearea/contents/startup.png \
	-a res/template.xml=sce_sys/livearea/contents/template.xml $@

eboot.bin: $(TARGET).velf
	vita-make-fself -s $< eboot.bin

%.velf: %.elf
	cp $< $<.unstripped.elf
	$(PREFIX)-strip -g $<
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

vpksend: $(TARGET).vpk
	curl -T $(TARGET).vpk ftp://$(PSVITAIP):1337/ux0:/
	@echo "Sent."

send: eboot.bin
	curl -T eboot.bin ftp://$(PSVITAIP):1337/ux0:/app/$(TITLE_ID)/
	@echo "Sent."

clean:
	@rm -rf $(TARGET).velf $(TARGET).elf $(OBJS) $(TARGET).elf.unstripped.elf $(TARGET).vpk eboot.bin param.sfo
