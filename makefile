all: gramatica_main

gramatica_main: gramatica_main.o gramatica_func.o transiciones.o alfabeto.o automata.o estado.o gramatica.o produccion.o simbolo.o
	g++ -o gramatica_main gramatica_main.o gramatica_func.o transiciones.o alfabeto.o automata.o estado.o gramatica.o produccion.o simbolo.o -std=c++2a

gramatica_func.o: gramatica_func.cc
	g++ -c -o gramatica_func.o gramatica_func.cc -std=c++2a

gramatica_main.o: gramatica_main.cc
	g++ -c -o gramatica_main.o gramatica_main.cc -std=c++2a

transiciones.o: transiciones.cc
	g++ -c -o transiciones.o transiciones.cc -std=c++2a

alfabeto.o: alfabeto.cc
	g++ -c -o alfabeto.o alfabeto.cc -std=c++2a

automata.o: automata.cc
	g++ -c -o automata.o automata.cc -std=c++2a

estado.o: estado.cc
	g++ -c -o estado.o estado.cc -std=c++2a

gramatica.o: gramatica.cc
	g++ -c -o gramatica.o gramatica.cc -std=c++2a

produccion.o: produccion.cc
	g++ -c -o produccion.o produccion.cc -std=c++2a

simbolo.o: simbolo.cc
	g++ -c -o simbolo.o simbolo.cc -std=c++2a

clean:
	-rm gramatica_main.o gramatica_func.o transiciones.o alfabeto.o automata.o estado.o gramatica.o produccion.o simbolo.o gramatica_main