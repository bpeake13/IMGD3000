#
# Makefile for development of game using Dragonfly
#
# 'make' to build executable
# 'make depend' to generate new dependency list
# 'make clean' to remove all constructed files
#
# Variables of interest:
#   GAMESRC is the source code files for the game being developed
#   GAME is the game main() source
#   DEBUG can be set to -DDEBUG to enable various debug flags
#

CC= g++# -std=c++11
PLATFORM= -DCYGWIN		# uncomment for cygwin
#PLATFORM= -DMACOS  		# uncomment for macos
LDFLAGS= -lncurses -lrt	# uncomment linux/cygwin
#LDFLAGS= -lncurses 		# uncomment for macos
INCPATH= include		# path to engine includes
SRC := src
DIRS:= $(addprefix -I, $(shell find $(SRC) -type d))
BUILDDIR := obj
GAMESRC := $(shell find $(SRC) -name '*.cpp')
GAME= game.cpp
EXECUTABLE= game		
OBJECTS := $(addprefix $(BUILDDIR)/,$(GAMESRC:%.cpp=%.o))

ENG= libdragonfly-cygwin32.a		# dragonfly engine
ENGSRC := $(shell find lib/$(SRC) -name '*.cpp')
ENGDIRS := $(addprefix -I, $(shell find lib/$(SRC) -type d))
ENGOBJECTS := $(addprefix lib/$(BUILDDIR)/,$(ENGSRC:%.cpp=%.o))
ENGLDFLAGS= -lncurses -lrt -shared	# uncomment linux/cygwin


all: $(EXECUTABLE) Makefile

$(EXECUTABLE): $(ENG) $(OBJECTS) $(GAME) $(GAMESRC)
	$(CC) $(GAME) $(OBJECTS) -static-libgcc $(ENG) -o $@ -I$(INCPATH) $(DIRS) $(LDFLAGS)
	
$(ENG): $(ENGOBJECTS) $(ENGSRC)
	$(CC) $(ENGOBJECTS) -o $@ -I$(INCPATH) $(ENGDIRS) $(ENGLDFLAGS)

$(BUILDDIR)/%.o:%.cpp
	mkdir -p $(dir $@) 
	$(CC) $(PLATFORM) -c $(DEBUG) -I$(INCPATH) $(DIRS) $< -o $@
	
lib/$(BUILDDIR)/%.o:%.cpp
	mkdir -p $(dir $@) 
	$(CC) $(PLATFORM) -c $(DEBUG) -I$(INCPATH) $(ENGDIRS) $< -o $@

clean:
	rm -rf $(BUILDDIR)/* lib/$(BUILDDIR)/* $(EXECUTABLE) $(ENG)

depend: 
	makedepend *.cpp 2> /dev/null

# DO NOT DELETE
