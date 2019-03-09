output: main.o file-manager.o trainer.o
	rm -rf ./build
	mkdir build
	g++ *.o -o ./build/neural-network
	rm ./*.o

main.o:
	g++ -c *.cpp
	g++ -c ./src/*.cpp

clean: 
	rm *.o