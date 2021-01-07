DEBUG=true
CC=g++
EXEC=main

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

all: build $(EXEC)

build:
	./build.sh

$(EXEC): Main.o PasswordGenerator.o
	$(CC) target/Main.o PasswordGenerator.o -o bin/$@

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

#################################
######## VALGRIND AND DGB #######
#################################

vg:
	valgrind .bin/$(EXEC)

vg2:
	valgrind --leak-check=full --show-leak-kinds=all .bin/$(EXEC)

vg3:
	valgrind -v .bin/$(EXEC)

gdb:
	gdb .bin/$(EXEC)

#################################
############  CLEAN  ############
#################################

cleanTarget:
	rm target/*.o
	rmdir target

cleanOut:
	rm out/*.o
	rmdir out

clean: cleanTarget cleanOut

mrproper: clean
	rm bin/$(EXEC)
	rmdir bin