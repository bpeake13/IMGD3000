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

CC= g++ 
PLATFORM= -DCYGWIN		# uncomment for cygwin
#PLATFORM= -DMACOS  		# uncomment for macos
LDFLAGS= -lncurses -lrt	# uncomment linux/cygwin
#LDFLAGS= -lncurses 		# uncomment for macos
GAMESRC= \
         game.cpp \
         LogManager.cpp \
         Manager.cpp \
         Utility.cpp \
         Clock.cpp \
         GameManager.cpp \
	 Object.cpp \
         Position.cpp \
	 ObjectList.cpp \
	 ObjectListIterator.cpp \
	 Event.cpp \
	 EventStep.cpp \
	 WorldManager.cpp \
	 TestObject.cpp \
         GraphicsManager.cpp \
	 EventMouse.cpp \
	 EventKeyboard.cpp \
	 InputManager.cpp \
	 EventCollision.cpp \
	 EventOut.cpp \
	 Frame.cpp \
	 Sprite.cpp \
         ResourceManager.cpp \

#GAME= game.cpp 
EXECUTABLE= game		
OBJECTS= $(GAMESRC:.cpp=.o)

all: $(EXECUTABLE) Makefile

$(EXECUTABLE): $(OBJECTS) $(GAME) $(GAMESRC)
	$(CC) $(GAME) $(OBJECTS) -o $@ $(LDFLAGS) 

.cpp.o: 
	$(CC) -c $(DEBUG) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) core dragonfly.log Makefile.bak *~

depend: 
	makedepend *.cpp 2> /dev/null

# DO NOT DELETE

Clock.o: Clock.h /usr/include/time.h /usr/include/_ansi.h
Clock.o: /usr/include/newlib.h /usr/include/sys/config.h
Clock.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Clock.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Clock.o: /usr/include/machine/_types.h /usr/include/machine/_default_types.h
Clock.o: /usr/include/sys/lock.h /usr/include/machine/time.h
Clock.o: /usr/include/sys/types.h /usr/include/machine/types.h LogManager.h
Clock.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
Clock.o: /usr/include/sys/stdio.h Manager.h Event.h
Event.o: Event.h
EventCollision.o: EventCollision.h Event.h Object.h Position.h
EventKeyboard.o: EventKeyboard.h Event.h
EventMouse.o: EventMouse.h Event.h
EventOut.o: EventOut.h Event.h
EventStep.o: EventStep.h Event.h
Frame.o: Frame.h LogManager.h /usr/include/stdio.h /usr/include/_ansi.h
Frame.o: /usr/include/newlib.h /usr/include/sys/config.h
Frame.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Frame.o: /usr/include/sys/cdefs.h /usr/include/machine/_default_types.h
Frame.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Frame.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
Frame.o: /usr/include/sys/types.h /usr/include/machine/types.h
Frame.o: /usr/include/sys/stdio.h Manager.h Event.h
game.o: LogManager.h /usr/include/stdio.h /usr/include/_ansi.h
game.o: /usr/include/newlib.h /usr/include/sys/config.h
game.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
game.o: /usr/include/sys/cdefs.h /usr/include/machine/_default_types.h
game.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
game.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
game.o: /usr/include/sys/types.h /usr/include/machine/types.h
game.o: /usr/include/sys/stdio.h Manager.h Event.h Utility.h Position.h
game.o: Clock.h /usr/include/time.h /usr/include/machine/time.h GameManager.h
game.o: ObjectList.h Object.h ObjectListIterator.h TestObject.h EventStep.h
game.o: WorldManager.h GraphicsManager.h /usr/include/curses.h
game.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
game.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
game.o: /usr/include/sys/time.h Frame.h Sprite.h ResourceManager.h
GameManager.o: GameManager.h Manager.h Event.h LogManager.h
GameManager.o: /usr/include/stdio.h /usr/include/_ansi.h
GameManager.o: /usr/include/newlib.h /usr/include/sys/config.h
GameManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
GameManager.o: /usr/include/sys/cdefs.h /usr/include/machine/_default_types.h
GameManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
GameManager.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
GameManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
GameManager.o: /usr/include/sys/stdio.h Clock.h /usr/include/time.h
GameManager.o: /usr/include/machine/time.h WorldManager.h ObjectList.h
GameManager.o: Object.h Position.h ObjectListIterator.h GraphicsManager.h
GameManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
GameManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
GameManager.o: /usr/include/unctrl.h InputManager.h EventStep.h
GraphicsManager.o: GraphicsManager.h /usr/include/curses.h
GraphicsManager.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
GraphicsManager.o: /usr/include/bits/wordsize.h /usr/include/stdio.h
GraphicsManager.o: /usr/include/_ansi.h /usr/include/newlib.h
GraphicsManager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
GraphicsManager.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
GraphicsManager.o: /usr/include/machine/_default_types.h
GraphicsManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
GraphicsManager.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
GraphicsManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
GraphicsManager.o: /usr/include/sys/stdio.h /usr/include/unctrl.h Manager.h
GraphicsManager.o: Event.h Position.h LogManager.h
InputManager.o: InputManager.h Manager.h Event.h GraphicsManager.h
InputManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
InputManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
InputManager.o: /usr/include/stdio.h /usr/include/_ansi.h
InputManager.o: /usr/include/newlib.h /usr/include/sys/config.h
InputManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
InputManager.o: /usr/include/sys/cdefs.h
InputManager.o: /usr/include/machine/_default_types.h
InputManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
InputManager.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
InputManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
InputManager.o: /usr/include/sys/stdio.h /usr/include/unctrl.h Position.h
InputManager.o: LogManager.h EventKeyboard.h EventMouse.h
LogManager.o: LogManager.h /usr/include/stdio.h /usr/include/_ansi.h
LogManager.o: /usr/include/newlib.h /usr/include/sys/config.h
LogManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
LogManager.o: /usr/include/sys/cdefs.h /usr/include/machine/_default_types.h
LogManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
LogManager.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
LogManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
LogManager.o: /usr/include/sys/stdio.h Manager.h Event.h Utility.h Position.h
Manager.o: Manager.h Event.h ObjectList.h Object.h Position.h
Manager.o: ObjectListIterator.h WorldManager.h LogManager.h
Manager.o: /usr/include/stdio.h /usr/include/_ansi.h /usr/include/newlib.h
Manager.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Manager.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
Manager.o: /usr/include/machine/_default_types.h /usr/include/sys/reent.h
Manager.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Manager.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Manager.o: /usr/include/machine/types.h /usr/include/sys/stdio.h EventStep.h
Object.o: Object.h Position.h Event.h WorldManager.h Manager.h ObjectList.h
Object.o: ObjectListIterator.h LogManager.h /usr/include/stdio.h
Object.o: /usr/include/_ansi.h /usr/include/newlib.h
Object.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Object.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
Object.o: /usr/include/machine/_default_types.h /usr/include/sys/reent.h
Object.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Object.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Object.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Object.o: /usr/include/math.h
ObjectList.o: ObjectList.h Object.h Position.h Event.h ObjectListIterator.h
ObjectListIterator.o: ObjectListIterator.h ObjectList.h Object.h Position.h
ObjectListIterator.o: Event.h
Position.o: Position.h
ResourceManager.o: ResourceManager.h Manager.h Event.h Sprite.h Frame.h
ResourceManager.o: LogManager.h /usr/include/stdio.h /usr/include/_ansi.h
ResourceManager.o: /usr/include/newlib.h /usr/include/sys/config.h
ResourceManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
ResourceManager.o: /usr/include/sys/cdefs.h
ResourceManager.o: /usr/include/machine/_default_types.h
ResourceManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
ResourceManager.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
ResourceManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
ResourceManager.o: /usr/include/sys/stdio.h
Sprite.o: Sprite.h Frame.h GraphicsManager.h /usr/include/curses.h
Sprite.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
Sprite.o: /usr/include/bits/wordsize.h /usr/include/stdio.h
Sprite.o: /usr/include/_ansi.h /usr/include/newlib.h
Sprite.o: /usr/include/sys/config.h /usr/include/machine/ieeefp.h
Sprite.o: /usr/include/sys/features.h /usr/include/sys/cdefs.h
Sprite.o: /usr/include/machine/_default_types.h /usr/include/sys/reent.h
Sprite.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
Sprite.o: /usr/include/sys/lock.h /usr/include/sys/types.h
Sprite.o: /usr/include/machine/types.h /usr/include/sys/stdio.h
Sprite.o: /usr/include/unctrl.h Manager.h Event.h Position.h LogManager.h
TestObject.o: LogManager.h /usr/include/stdio.h /usr/include/_ansi.h
TestObject.o: /usr/include/newlib.h /usr/include/sys/config.h
TestObject.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
TestObject.o: /usr/include/sys/cdefs.h /usr/include/machine/_default_types.h
TestObject.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
TestObject.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
TestObject.o: /usr/include/sys/types.h /usr/include/machine/types.h
TestObject.o: /usr/include/sys/stdio.h Manager.h Event.h TestObject.h
TestObject.o: Object.h Position.h EventStep.h EventOut.h EventMouse.h
TestObject.o: EventKeyboard.h GraphicsManager.h /usr/include/curses.h
TestObject.o: /usr/include/ncurses_dll.h /usr/include/stdint.h
TestObject.o: /usr/include/bits/wordsize.h /usr/include/unctrl.h
TestObject.o: WorldManager.h ObjectList.h ObjectListIterator.h
Utility.o: Utility.h Position.h /usr/include/time.h /usr/include/_ansi.h
Utility.o: /usr/include/newlib.h /usr/include/sys/config.h
Utility.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
Utility.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
Utility.o: /usr/include/machine/_types.h
Utility.o: /usr/include/machine/_default_types.h /usr/include/sys/lock.h
Utility.o: /usr/include/machine/time.h /usr/include/sys/types.h
Utility.o: /usr/include/machine/types.h /usr/include/stdio.h
Utility.o: /usr/include/sys/cdefs.h /usr/include/sys/stdio.h
WorldManager.o: WorldManager.h Manager.h Event.h ObjectList.h Object.h
WorldManager.o: Position.h ObjectListIterator.h GraphicsManager.h
WorldManager.o: /usr/include/curses.h /usr/include/ncurses_dll.h
WorldManager.o: /usr/include/stdint.h /usr/include/bits/wordsize.h
WorldManager.o: /usr/include/stdio.h /usr/include/_ansi.h
WorldManager.o: /usr/include/newlib.h /usr/include/sys/config.h
WorldManager.o: /usr/include/machine/ieeefp.h /usr/include/sys/features.h
WorldManager.o: /usr/include/sys/cdefs.h
WorldManager.o: /usr/include/machine/_default_types.h
WorldManager.o: /usr/include/sys/reent.h /usr/include/sys/_types.h
WorldManager.o: /usr/include/machine/_types.h /usr/include/sys/lock.h
WorldManager.o: /usr/include/sys/types.h /usr/include/machine/types.h
WorldManager.o: /usr/include/sys/stdio.h /usr/include/unctrl.h EventOut.h
WorldManager.o: LogManager.h EventCollision.h Utility.h
