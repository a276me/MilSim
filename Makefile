SRCS = $(wildcard ./src/*.cpp)

default:
	make build
	make run
	
build:
	g++ $(SRCS) -I ./include -o sim.out

run:
	./sim.out
