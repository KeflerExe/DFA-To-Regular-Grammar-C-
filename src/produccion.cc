/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: produccion.cc
/// Contiene la implementación de la clase Produccion encargada de proporcionar métodos para los objetos tipo produccion..

#include "produccion.h"

/// Inserta los simbolos en el vector de destino de la produccion
void Produccion::InsertaDestinoProduccion(const Simbolo& simbolo) {
  destino_produccion_.push_back(simbolo);
}

/// Inserta los el "simbolo de arranque" de la produccion
void Produccion::InsertaOrigen(const Simbolo& simbolo) {
  simbolo_origen_ = simbolo;
}

/// Sobrecarga del operador [] que retorna el valor del destino de la produccion en una determinada posición
Simbolo Produccion::operator[](int posicion) const {
  return destino_produccion_.at(posicion);
}

/// Retorna el tamaño del destino de la producción
int Produccion::TamanioDestinoProduccion() const {
  return destino_produccion_.size();
}

/// Elimina el contenido del destino de la producción
void Produccion::LimpiaDestinoProduccion() {
  destino_produccion_.clear();
  Simbolo simbolo_auxiliar;
  simbolo_origen_ = simbolo_auxiliar;
}