/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: gramatica.cc
/// Contiene la implementacion de la clase Gramatica encargada de proporcionar métodos para los objetos tipo gramatica.

#include "gramatica.h"
    
/// Inserta los simbolos terminales en el vector de simbolos terminales
void Gramatica::InsertaLosTerminales(const Simbolo& simbolo_terminal) {
  terminales_.push_back(simbolo_terminal);
}

/// Inserta los simbolos no terminales en el vector de simbolos no terminales
void Gramatica::InsertaLosNoTerminales(const Simbolo& simbolo_no_terminal) {
  no_terminales_.push_back(simbolo_no_terminal);
}

/// Inserta el simbolo de arranque en el atributo simbolo_arranque_
void Gramatica::DefineSimboloArranque(const Simbolo& simbolo_arranque) {
  simbolo_arranque_ = simbolo_arranque;
}

/// Inserta las producciones pertenecientes a la gramatica en el vector de producciones
void Gramatica::InsertaProduccion(const Produccion& produccion) {
  producciones_.push_back(produccion);
}

/// Devuelve el tamaño del vector de producciones
int Gramatica::TamanioProducciones() const {
  return producciones_.size();
}

/// Devuelve el tamaño del vector de simbolos no terminales
int Gramatica::TamanioSimbolosNoTerminales() const {
  return no_terminales_.size();
}

/// Devuelve el tamaño del vector de simbolos terminales
int Gramatica::TamanioSimbolosTerminales() const {
  return terminales_.size();
}

/// Devuelve verdadero en caso de que la gramática sea regular, falso en caso de que no
bool Gramatica::EsRegular() const {
  bool es_regular{true};
  Simbolo simbolo_auxiliar;
  Produccion produccion_auxiliar;
  for (int iterador = 0; iterador < producciones_.size(); ++iterador) {
    produccion_auxiliar = producciones_.at(iterador);
    for (int iterador2 = 0; iterador2 < produccion_auxiliar.TamanioDestinoProduccion(); ++iterador) {
      simbolo_auxiliar = produccion_auxiliar[iterador2];
      if (simbolo_auxiliar.EsMayuscula() && iterador2 == 0) {
        es_regular = false;
      }

    }

    if (es_regular = false) {
      break;
    }


  }
  return true;
}

/// Sobrecarga del operador de salida para imprimir en archivos
std::ofstream& operator<<(std::ofstream& salida, const Gramatica& gramatica) {
  Simbolo simbolo_auxiliar;
  Produccion produccion_auxiliar;
  salida << gramatica.TamanioSimbolosTerminales() << std::endl;
  for (int iterador = 0; iterador < gramatica.TamanioSimbolosTerminales(); ++iterador) {
    salida << gramatica.terminales_.at(iterador).get_simbolo() << std::endl;
  }
  salida << gramatica.TamanioSimbolosNoTerminales() << std::endl;
  for (int iterador = 0; iterador < gramatica.no_terminales_.size(); ++iterador) {
    salida << gramatica.no_terminales_[iterador].get_simbolo() << std::endl;
  }
  salida << gramatica.TamanioProducciones() << std::endl;
  for (int iterador = 0; iterador < gramatica.producciones_.size(); ++iterador) {
    produccion_auxiliar = gramatica.producciones_[iterador]; 
    salida << produccion_auxiliar.get_simbolo_origen().get_simbolo() << " ---> ";
    for (int iterador2 = 0; iterador2 < produccion_auxiliar.TamanioDestinoProduccion() - 1; ++iterador2) {
      if (produccion_auxiliar[iterador2 + 1].EsMayuscula()) {
        if (iterador2 == produccion_auxiliar.TamanioDestinoProduccion() - 2) {
          salida << produccion_auxiliar[iterador2].get_simbolo() << produccion_auxiliar[iterador2 + 1].get_simbolo();
        } else {
          salida << produccion_auxiliar[iterador2].get_simbolo() << produccion_auxiliar[iterador2 + 1].get_simbolo() << " | ";
        }
      }
      if (produccion_auxiliar[iterador2].get_simbolo() == '&') {
        salida << "& ";
      }
    }
    salida << std::endl;
  }
  return salida;
}