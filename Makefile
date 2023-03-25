application := printf
build_dir := build
src_dir := src
include_dir := include

CC := gcc
CFlags := -Wall -Werror -Wextra -pedantic -std=gnu89

FILES = ./tests/main.c *.c
SOURCES = $(FILES:%.cpp=$(src_dir)/%.cpp)

all: clear_screen check_style build run

build: setup_dirs 
	${CC} ${CFlags} ${SOURCES} -o ./$(build_dir)/${application}.out

run:
	./${build_dir}/${application}.out

clean:
	rm ./${build_dir}/*.out

setup_dirs:
	@mkdir -p ./build

check_style:
	betty ${FILES}

clear_screen:
	clear