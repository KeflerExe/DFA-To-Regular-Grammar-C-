/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: gramatica.h
/// Contiene la clase Gramatica encargada de crear objetos tipo gramatica y de proporcionar métodos para los mismos.

#include <fstream>
#include <iostream>
#include <set>
#include <vector>

#include "simbolo.h"
#include "produccion.h"

#ifndef GRAMATICA_H
#define GRAMATICA_H

/// Clase Gramatica, encargada de crear y manejar los objetos tipo gramatica
class Gramatica {  
 public:
  /// Constructor 
  Gramatica() : terminales_{}, no_terminales_{}, simbolo_arranque_{}, producciones_{} {}

  /// Métodos que modifican los atributos de la clase Gramatica
  void InsertaLosTerminales(const Simbolo& simbolo_terminal);
  void InsertaLosNoTerminales(const Simbolo& simbolo_no_terminal);
  void DefineSimboloArranque(const Simbolo& simbolo_arranque);
  void InsertaProduccion(const Produccion& produccion);

  /// Métodos que proporcionarn información sobre los atributos de la clase Gramatica
  int TamanioSimbolosTerminales() const;
  int TamanioSimbolosNoTerminales() const;
  int TamanioProducciones() const;
  bool EsRegular() const;

  /// Sobrecarga de operadores
  friend std::ofstream& operator<<(std::ofstream& salida, const Gramatica& gramatica);
 private:
  std::vector<Simbolo> terminales_; ///< Atributo vector que contiene los símbolos terminales que posee la gramática
  std::vector<Simbolo> no_terminales_; ///< Atributo vector que contiene los símbolos no terminales de la gramática
  Simbolo simbolo_arranque_; ///< Atributo tipo Simbolo que contiene el simbolo de arranque de la gramática
  std::vector<Produccion> producciones_; ///< Vector que contiene todas las producciones pertenecientes a la gramática
};

#endif