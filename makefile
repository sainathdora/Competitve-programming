# Define the executable name and source file
EXECUTABLE = main
SOURCE = main.cpp

# Default target: Compile and run
all: compile run

# Compile the C++ program
compile:
	g++ $(SOURCE) -o $(EXECUTABLE)

# Run the compiled program
run:
	./$(EXECUTABLE)

# Clean up the generated executable
clean:
	rm -f $(EXECUTABLE)
