output: barbarian.o character.o medusa.o main.o harrypotter.o vampire.o bluemen.o menu.o queue.o
	g++ barbarian.o character.o medusa.o main.o harrypotter.o vampire.o bluemen.o menu.o queue.o -o output

menu.o: menu.cpp menu.hpp
	g++ -std=c++11 -g -Wall -c menu.cpp

bluemen.o: bluemen.cpp bluemen.hpp
	g++ -std=c++11 -g -Wall -c bluemen.cpp

vampire.o: vampire.cpp vampire.hpp
	g++ -std=c++11 -g -Wall -c vampire.cpp

harrypotter.o: harrypotter.cpp harrypotter.hpp
	g++ -std=c++11 -g -Wall -c harrypotter.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -std=c++11 -g -Wall -c medusa.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -std=c++11 -g -Wall -c barbarian.cpp

character.o: character.cpp character.hpp
	g++ -std=c++11 -g -Wall -c character.cpp

queue.o: queue.cpp queue.hpp
	g++ -std=c++11 -g -Wall -c queue.cpp
	
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp


clean:
	rm *.o output