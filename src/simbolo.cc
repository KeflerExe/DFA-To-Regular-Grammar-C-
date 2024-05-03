/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: simbolo.cc
/// Contiene la implementación de la clase Simbolo encargada de proporcionar métodos para los objetos tipo simbolo.

#include "simbolo.h"

/// Sobrecarga del operador de salida
std::ofstream& operator<<(std::ofstream& salida, const Simbolo& simbolo) {
  salida << simbolo.simbolo_;
  return salida;
}

/// Devuelve true si el simbolo es mayuscula, false si no lo es
bool Simbolo::EsMayuscula() const {
  return isupper(simbolo_);
}