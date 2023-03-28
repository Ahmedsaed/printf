application := printf
build_dir := build
src_dir := .
include_dir := include

CC := gcc
CFlags := -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89

FILES = ./tests/main.c *.c *.h

all: clear_screen check_style build run

build: setup_dirs 
	${CC} ${CFlags} ${FILES} -o ./$(build_dir)/${application}.out

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
