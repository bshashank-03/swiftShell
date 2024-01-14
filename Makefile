CC=g++
CFLAGS=-Wall -Werror

all: SwiftShell

SwiftShell: SwiftShell.cpp Execute.cpp Parser.cpp EnvironmentVariablesManager.cpp
	$(CC) $(CFLAGS) SwiftShell.cpp Execute.cpp Parser.cpp EnvironmentVariablesManager.cpp -o SwiftShell

rebuild: clean all

clean:
	rm -f SwiftShell