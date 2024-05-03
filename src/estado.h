/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: estado.h
/// Contiene la clase Estado encargada de crear objetos tipo estado y de proporcionar métodos para los mismos.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>

#include "transiciones.h"

#ifndef ESTADO_H
#define ESTADO_H

/// Clase Estado, encargada de crear y manejar los objetos tipo Estado
class Estado {  
 public:
  /// Constructores
  Estado() : identificador_{}, aceptacion_{} {}  
  Estado(const int identificador, const bool aceptacion) : identificador_{identificador}, aceptacion_{aceptacion} {}

  /// Métodos encargados de realizar las operaciones necesarios para el funcionamiento de la clase
  void InsertaLasTransiciones(const Transicion& transicion);
  int TamanioVectorTransiciones() const;

  /// Getters
  int get_identificador() const { return identificador_; }
  bool get_aceptacion() const { return aceptacion_; }

  /// Sobrecarga de operadores
  Transicion operator[](int posicion) const;
  bool operator<(const Estado& estados) const {
    return transiciones_ < estados.transiciones_;
  }
 private:
  int identificador_; ///< Atributo int en el cual se almacena el identificador del estado 
  bool aceptacion_; ///< Atributo bool cuyo valor es true si el estado es de aceptación y false si el estado no es de aceptación.
  std::vector<Transicion> transiciones_; ///< Vector de objetos tipo Transicion en el cual son almacenadas las diferentes transiciones vinculadas a un estado
};

bool operator!=(const Estado& estado1, const Estado& estado2);
bool operator==(const Estado& estado1, const Estado& estado2);
void Usage(int argc, char *argv[]);

#endif