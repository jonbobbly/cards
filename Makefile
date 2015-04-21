all:
	g++ -o cards -Iinclude src/*.cpp

clean:
	rm cards
