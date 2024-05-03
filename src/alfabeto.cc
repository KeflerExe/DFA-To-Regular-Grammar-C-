/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: alfabeto.cc
/// Contiene la implementacion de la clase Alfabeto encargada de proporcionar métodos para los objetos tipo alfabeto..

#include "alfabeto.h"

/// Extrae e inserta los elementos en el alfabeto
void Alfabeto::InsertaElAlfabeto(const std::string& linea_extraida) {
  for (int iterador = 0; iterador < linea_extraida.size(); ++iterador) {
    alfabeto_.push_back(linea_extraida[iterador]);
    ++iterador;
  }
}

/// Retorna el tamaño del alfabeto
int Alfabeto::TamanioAlfabeto() const {
  return alfabeto_.size();
}

/// Sobrecarga del operador [] el cual retorna el valor del alfabeto en la posicion indicada
char Alfabeto::operator[](int posicion) const {
  return alfabeto_.at(posicion);
}