/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: gramatica_main.cc
/// Contiene la función main del proyecto que usa las diferentes clases y llama a otras funciones
/// para realizar las operaciones requeridas por el usuario.

#include <iostream>
#include <fstream>

#include "automata.h"

/// Función main encargada de crear el autómata correspondiente y de realizar las diferentes llamadas a funciones y métodos para obtener los resultados deseados por el usuario.
int main (int argc, char *argv[]) {
  Usage(argc, argv);
  std::string nombre_archivo_automata = argv[1];
  std::string nombre_archivo_gramatica = argv[2];
  Automata automata1{nombre_archivo_automata};
  Gramatica gramatica1;
  gramatica1 = automata1.ConvierteAGramatica();
  std::ofstream archivo_gramatica;
  archivo_gramatica.open(nombre_archivo_gramatica);
  archivo_gramatica << gramatica1;
  archivo_gramatica.close();
  return 0;
}