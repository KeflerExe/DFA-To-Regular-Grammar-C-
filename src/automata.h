/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: automata.h
/// Contiene la clase Automata encargada de crear objetos tipo automata y de proporcionar métodos para los mismos.

#include <iostream>

#include "alfabeto.h"
#include "estado.h"
#include "transiciones.h"
#include "gramatica.h"

#ifndef AUTOMATA_H
#define AUTOMATA_H

/// Clase Automata, encargada de crear y manejar los objetos tipo automata
class Automata {  
 public:
  /// Constructor 
  Automata() : alfabeto_{}, estados_{}, estado_arranque_{} {}
  Automata(const std::string& nombre_archivo_automata) { ConstruyeElAutomata(nombre_archivo_automata); } 

  /// Métodos que modifican los atributos de la clase autómata
  void InsertaElAlfabeto(const std::string& linea_extraida);
  void InsertaEstados(const std::string& linea_extraida, const int identificador_estado_arranque, const int numero_total_estados);
  void ConstruyeElAutomata(const std::string& nombre_archivo_automata);

  /// Métodos encargados de realizar las operaciones necesarias para el correcto funcionamiento del programa.
  Estado RetornaEstadoPorIdentificador(const int identificador) const;
  bool CompruebaQueElSimboloEstaEnAlfabeto(const char simbolo_extraido) const;
  bool EvaluaString(const std::string& linea_extraida);
  bool CompruebaSiEsUnDFA() const;
  Gramatica ConvierteAGramatica() const;

  /// Sobrecarga de operadores
  bool operator<(const Automata& automatas) const {
    return estados_ < automatas.estados_;
  }
 private:
  Alfabeto alfabeto_; ///< Atributo tipo alfabeto en cual son almacenados los símbolos del lenguaje que reconoce el autómata
  std::vector<Estado> estados_; ///< Vector de estados en el cual se almacenarán todos los estados que componen el autómata
  Estado estado_arranque_; ///< Atributo tipo estado que almacena el estado de arranque del autómata
};

void Usage(int argc, char *argv[]);

#endif