# Copyright 2019 Grama Nicolae

.PHONY: gitignore check purge clean memory update beauty pack run
.SILENT: purge update beauty pack clean memory gitignore

# Compilation variables
CC = g++
CFLAGS = -Wno-unused-parameter -Wall -Wextra -pedantic -g -std=c++11
EXE = tema2
SRC = $(wildcard */*.cpp)
OBJ = $(SRC:.cpp=.o)

# Variables related to the archive (with the homework)
ANAME = 312CA_GramaNicolae_Tema2.zip
ACONTENTS = README Makefile sources/ headers/
AFLAGS = -FSr 

# Compiles the program
build: $(OBJ)
	$(info Compiling code...)
	@$(CC) -o $(EXE) $^ $(CFLAGS) ||:
	$(info Compilation successfull)
	-@rm -f *.o ||:
	@$(MAKE) -s gitignore ||:

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS) 

# Executes the binary
run: build
	./$(EXE)

# Archives the homework
pack:
	if [ ! -f README ]; then cp Readme.md README; fi
	zip $(AFLAGS) $(ANAME) $(ACONTENTS)
	rm README

# Deletes the binary and object files
clean:
	rm -f $(EXE) $(OBJ)
	echo "Deleted the binary and object files"

# Automatic coding style, according to homework regulations
beauty:
	clang-format -i -style=file */*.cpp
	clang-format -i -style=google */*.h

# Automatic coding style, in my personal style
beauty-development:
	clang-format -i -style=file */*.cpp
	clang-format -i -style=file */*.h

# Checks the memory for leaks
MFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
memory:build
	valgrind $(MFLAGS) ./$(EXE)

# Verifies the homework using the checker
check:build
	if [ ! -f README ]; then cp Readme.md README; fi
	./check.sh
	rm README

# Removes all files that won't appear in the git repository
purge:
	rm -f $(EXE) $(OBJ)
	rm -f checkstyle.txt
	rm -f README
	rm -f $(ANAME)
	rm -f time.out
	rm -f time.err
	echo "All files were removed"

# Adds and updates gitignore rules
gitignore:
	@echo "checkstyle.txt" > .gitignore ||:
	@echo "check.sh" >> .gitignore ||:
	@echo "out*" >> .gitignore ||:
	@echo "in*" >> .gitignore ||:
	@echo "ref*" >> .gitignore ||:
	@echo "cpplint.py" >> .gitignore ||:
	@echo "README" >> .gitignore ||:
	@echo "$(ANAME)" >> .gitignore ||:
	@echo "$(EXE)" >> .gitignore ||:
	@echo "sources/*.o" >> .gitignore ||:
	@echo ".vscode*" >> .gitignore ||:	
	@echo "time.out" >> .gitignore ||:
	@echo "time.err*" >> .gitignore ||:
	echo "Updated .gitignore"
