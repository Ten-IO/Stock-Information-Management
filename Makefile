CXX = g++ 
FLAGS =-Wall -Wextra -g3
libs := libs

OBJDIR=shared
OBJECTS=$(OBJDIR)/main.o
CXXFILES=main.cpp
BINARY =run.exe # exec file

all: $(BINARY)

$(BINARY): $(OBJECTS)
	@echo [++ Linking ++]
	$(CXX) $(FLAGS) $^ -o $@
	@echo [++ Build Completed ++]

$(OBJDIR)/%.o: %.cpp
	@mkdir $(OBJDIR)
	$(CXX) $(FLAGS) -c -o $@ $^
	@echo [++ Objects Created ++]
	@echo -----------------------

clean:
	powershell -c "rm -force $(OBJECTS),$(OBJDIR),$(BINARY)"