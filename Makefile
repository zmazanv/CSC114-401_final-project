.PHONY: run
.DEFAULT_GOAL := run

run: grader
	@./grader

grader: grader.cpp
	@{ command -v &>/dev/null 'g++' && g++ -o 'grader' 'grader.cpp'; } || { command -v &>/dev/null 'clang++' && clang++ -o 'grader' 'grader.cpp'; } || exit 1
