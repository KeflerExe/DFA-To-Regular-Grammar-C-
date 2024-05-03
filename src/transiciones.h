/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Autómatas finitos
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 07/11/2022
/// Archivo: transiciones.h
/// Contiene la clase Transiciones encargada de crear objetos tipo transiciones y de proporcionar métodos para los mismos.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#ifndef TRANSICION_H
#define TRANSICION_H

/// Clase Transiciones, encargada de crear y manejar los objetos tipo transiciones
class Transicion {  
 public:
  /// Constructor 
  Transicion() : simbolo_{}, destino_{} {}  
  Transicion(const char simbolo, const int estado_destino) : simbolo_{simbolo}, destino_{estado_destino} {}  
 
  /// Getters
  char get_simbolo() const { return simbolo_; }
  int get_destino() const { return destino_; }

  /// Sobrecarga de operadores
  bool operator<(const Transicion& transicion) const {
    return destino_ < transicion.destino_;
  }
 private:
  char simbolo_; ///< Atributo char que almacena el símbolo con el cual se realiza una transición
  int destino_; ///< Atributo int que define el identificador del estado al cual se transita en caso de que se realice la transición
};

void Usage(int argc, char *argv[]);

#endif