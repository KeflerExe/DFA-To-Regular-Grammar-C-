/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: alfabeto.h
/// Contiene la clase Alfabeto encargada de crear objetos tipo alfabeto y de proporcionar métodos para los mismos.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#ifndef ALFABETO_H
#define ALFABETO_H

/// Clase Alfabeto, encargada de crear y manejar los objetos tipo alfabeto
class Alfabeto {  
 public:
  /// Constructor 
  Alfabeto() : alfabeto_{} {}
  
  /// Métodos de la clase encargados de realizar diferentes funciones
  void InsertaElAlfabeto(const std::string& linea_extraida);
  int TamanioAlfabeto() const;

  /// Sobrecarga de operadores
  char operator[](int posicion) const;
 private:
  std::vector<char> alfabeto_; ///< Estructura de datos tipo vector que almacena los diferentes caracteres del alfabeto
};

void Usage(int argc, char *argv[]);

#endif