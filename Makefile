BINARY  =run.exe# exec file
CXXFILES=$(wildcard lib/*.cpp)
INCDIR  =lib

MAIN    =main.cpp
OBJDIR  =shared# dir for compiled lib
OBJECTS =$(patsubst lib/%.cpp,shared/%.o,$(CXXFILES))

CXX     =g++
OPTS    =
FLAGS   =-Wall -Wextra -g3 -I$(INCDIR) $(OPTS)
STATIC  =-static -static-libstdc++


all: $(BINARY)
	
quick:
	$(CXX) $(FLAGS) -o $(BINARY) $(MAIN) $(CXXFILES)

$(BINARY): $(OBJECTS)
	@echo.
	@echo     [++ Linking ++]
	$(CXX) $(FLAGS) -o $@ $(MAIN) $^
	@echo   [++ Build Completed ++]

$(OBJDIR)/%.o: lib/%.cpp | $(OBJDIR)
	@$(CXX) $(FLAGS) -c $< -o $@
	@echo Compiled: $<

$(OBJDIR):
	@mkdir $@

clean:
	powershell -c "rm -r $(OBJDIR),$(BINARY) -ea ignore"

# ignore check state - to strict exec
.PHONY: all clean