BINARY  =run.exe# exec file
CXXFILES=$(wildcard *.cpp)
INCDIR  =lib

CXX     =g++
OPTS    =
FLAGS   =-Wall -Wextra -g3 -I$(INCDIR) $(OPTS)

OBJDIR  =shared# dir for compiled lib
OBJECTS =$(patsubst %.cpp,shared/%.o,$(CXXFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	@echo     [++ Linking ++]
	@echo.
	$(CXX) -o $@ $^
	@echo   [++ Build Completed ++]

$(OBJDIR)/%.o: %.cpp
	@mkdir $(OBJDIR)
	$(CXX) $(FLAGS) -c -o $@ $^
	@echo [++ Objects Created ++]
	@echo -----------------------

clean:
	powershell -c "rm -force $(OBJECTS),$(OBJDIR),$(BINARY) -ea ignore"

# ignore check state - to strict exec
.PHONY: all clean