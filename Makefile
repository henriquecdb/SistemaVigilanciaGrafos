all:
	g++ src/main.cpp include/Classe.cpp -Iinclude -o bin/progGrafos
clean:
	rm bin/progGrafos
run:
	mkdir -p bin
	./bin/progGrafos
