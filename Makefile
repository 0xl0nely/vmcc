all: src/fsm.cpp src/lexer.cpp src/vmcc.cpp src/repl.cpp src/vm.cpp
	g++ src/fsm.cpp src/lexer.cpp src/vmcc.cpp src/repl.cpp src/vm.cpp
