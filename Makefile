DEBUG=no
#DEBUG=yes
CC=g++
EXEC=passwordGenerator

#################################
###### SETUP FLAGS COMPILE ######
#################################

ifeq ($(DEBUG), yes)
	CXXFLAGS = -std=c++17 -Wall -Wextra -g
else
	CXXFLAGS = -std=c++17 -Ofast
endif

#################################
###### COMPILATION PROJECT ######
#################################

all: build $(EXEC) run

build:
	./build.sh

$(EXEC): Main.o PasswordGenerator.o Menu.o
	$(CC) target/Main.o target/PasswordGenerator.o target/Menu.o -o bin/$@

#################################
#############  RUN  #############
#################################

run: 
	./bin/$(EXEC)

#################################
########## COMPILE FILE #########
#################################

Main.o: src/main/Main.cpp
	$(CC) -c $(CXXFLAGS) $< -o target/$@

PasswordGenerator.o: src/lib/PasswordGenerator.cpp
	$(CC) -c $(CXXFLAGS) $< -o target/$@

Menu.o: src/lib/Menu.cpp src/lib/Menu.hpp
	$(CC) -c $(CXXFLAGS) $< -o target/$@

#################################
######## VALGRIND AND DGB #######
#################################

vg:
	valgrind ./bin/$(EXEC)

vg2:
	valgrind --leak-check=full --show-leak-kinds=all ./bin/$(EXEC)

vg3:
	valgrind -v ./bin/$(EXEC)

gdb:
	gdb .bin/$(EXEC)

#################################
############  CLEAN  ############
#################################

cleanTarget:
	rm target/*.o
	rmdir target

clean: cleanTarget

mrproper: clean
	rm bin/$(EXEC)
	rmdir bin
