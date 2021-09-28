SRCS = $(wildcard ./src/*.cpp)

default:
	make build
	make run

mac:
	g++ $(SRCS) -I ./include -L ./lib -lraylib -o sim.out
	make run
	
build:
	g++ $(SRCS) -I ./include -lraylib -o sim.out

run:
	./sim.out

git:
	git add .
	git commit -m "another commit"
	git push
