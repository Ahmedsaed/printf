application := printf
build_dir := build
src_dir := src
inculde_dir := include

CC := gcc
CFlags := -Wall -Werror -Wextra -pedantic -std=gnu89

FILES = ./tests/main.c *.c
SOURCES = $(FILES:%.cpp=$(src_dir)/%.cpp)

all: build run

build: setup_dirs
	clear
	${CC} ${CFlags} ${SOURCES} -o ./$(build_dir)/${application}.out

run:
	./${build_dir}/${application}.out

clean:
	rm ./${build_dir}/*.out

setup_dirs:
	@mkdir -p ./build