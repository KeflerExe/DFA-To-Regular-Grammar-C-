/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: estado.cc
/// Contiene la implementacion de la clase Estado encargada de proporcionar métodos para los objetos tipo estado.

#include "estado.h"

/// Método encargado de insertar las diferentes transiciones en el vector de transiciones transiciones_
void Estado::InsertaLasTransiciones(const Transicion& transicion) {
  transiciones_.push_back(transicion);
}

/// Método que devuelve el tamaño del vector de transiciones para saber cuantas transiciones tiene cada estado
int Estado::TamanioVectorTransiciones() const {
  return transiciones_.size();
}

/// Sobrecarga del operador [] que devuelve el valor de el vector transiciones_ en una determinada posición
Transicion Estado::operator[](int posicion) const {
  return transiciones_.at(posicion);
}

/// Sobrecarga del operador != para comprar si dos estados son distintos
bool operator!=(const Estado& estado1, const Estado& estado2) {
  if (estado1.get_identificador() != estado2.get_identificador()) {
    return true;
  } else {
    return false;
  }
}

/// Sobrecarga del operador == para comprar si dos estados son distintos
bool operator==(const Estado& estado1, const Estado& estado2) {
  if (estado1.get_identificador() == estado2.get_identificador()) {
    return true;
  } else {
    return false;
  }
}