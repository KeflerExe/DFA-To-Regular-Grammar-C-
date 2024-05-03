/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 7: Gramáticas
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 14/11/2022
/// Archivo: automata.cc
/// Contiene la implementacion de la clase Automata encargada de proporcionar métodos para los objetos tipo autómata.

#include "automata.h"

/// Método encargado de recibir un identificador de un estado y de buscar dicho estado en el vector de estados_ para retornarlo
Estado Automata::RetornaEstadoPorIdentificador(const int identificador) const {
  Estado estado_auxiliar;
  for (int iterador = 0; iterador < estados_.size(); iterador++) {
    estado_auxiliar = estados_[iterador];
    if (estado_auxiliar.get_identificador() == identificador) {
      return estado_auxiliar;
    }
  }
  return estado_auxiliar;
}

/// Comprueba que el símbolo recibido por argumento se encuentre en el alfabeto del autómata
bool Automata::CompruebaQueElSimboloEstaEnAlfabeto(const char simbolo_extraido) const {
  if (simbolo_extraido == '&') {
    return true;
  }
  bool simbolo_encontrado = false;
  for (int iterador = 0; iterador < alfabeto_.TamanioAlfabeto(); ++iterador) {
    if (alfabeto_[iterador] == simbolo_extraido) {
      simbolo_encontrado = true;
    }
  }
  if (simbolo_encontrado == true) {
    return true;
  } else {
    return false;
  }
}

/// Recibe una string por parámetro que es analizada para comprobar si esta es aceptada o rechazada por el autómata
bool Automata::EvaluaString(const std::string& cadena_extraida) {
  std::set<Estado> estados_actuales_;
  char simbolo_cadena;
  bool epsilon_transicion_realizada{false};
  bool transicion_realizada{false};
  Estado estado_auxiliar;
  Transicion transiciones_auxiliar;
  estados_actuales_.insert(estado_arranque_);
  std::set<Estado> estados_siguientes;
  for (int iterador = 0; iterador < cadena_extraida.size(); ++iterador) {
    simbolo_cadena = cadena_extraida[iterador];
    std::set<Estado>::iterator iterador_set = estados_actuales_.begin();
    for (int iterador2 = 0; iterador2 < estados_actuales_.size(); ++iterador2) {
      estado_auxiliar = *iterador_set;
      for (int iterador3 = 0; iterador3 < estado_auxiliar.TamanioVectorTransiciones(); ++iterador3) {
        transiciones_auxiliar = estado_auxiliar[iterador3];
        if (transiciones_auxiliar.get_simbolo() == '&') {
          epsilon_transicion_realizada = true;
          estados_siguientes.insert(RetornaEstadoPorIdentificador(transiciones_auxiliar.get_destino()));
        } else {
          if (simbolo_cadena == '&') {
            if (estado_arranque_.get_aceptacion() == true) {
              return true;
            } else {
              return false;
            }
          } else {
            if (transiciones_auxiliar.get_simbolo() == simbolo_cadena) {
              estados_siguientes.insert(RetornaEstadoPorIdentificador(transiciones_auxiliar.get_destino()));
              transicion_realizada = true;
            }
          }
        } 
      }
      std::advance(iterador_set, 1);
    }
    if (epsilon_transicion_realizada == true && transicion_realizada == false) {
      iterador -= 1;
    }
    epsilon_transicion_realizada = false;
    transicion_realizada = false;
    estados_actuales_.clear();
    estados_actuales_ = estados_siguientes;
    estados_siguientes.clear();
  }
  std::set<Estado>::iterator iterador_set;
  for (iterador_set = estados_actuales_.begin(); iterador_set != estados_actuales_.end(); iterador_set++) {
    estado_auxiliar = *iterador_set;
    if (estado_auxiliar.get_aceptacion() == true) {
      return true;
    }
  }
  return false;
}

/// Llama al método InsertaElAlfabeto de la clase Alfabeto para definir el alfabeto del autómata
void Automata::InsertaElAlfabeto(const std::string& linea_extraida) {
  alfabeto_.InsertaElAlfabeto(linea_extraida);
}

/// Método encargado de insertar los estados del automata en el vector estados_ y de establecer cual de ellos es el de arranque
void Automata::InsertaEstados(const std::string& linea_extraida, const int identificador_estado_arranque, const int numero_total_estados) {
  char identificador_estado_char = linea_extraida[0];
  int identificador_estado = identificador_estado_char - 48;
  bool aceptacion = false;
  char aceptacion_char = linea_extraida[2];
  if (aceptacion_char - 48 == 1) {
    aceptacion = true;
  }
  char numero_transiciones_char = linea_extraida[4];
  int numero_transiciones = numero_transiciones_char - 48;
  Estado estado_auxiliar{identificador_estado, aceptacion};
  if (numero_transiciones != 0) {
    for (int iterador = 6; iterador < linea_extraida.size(); ++iterador) {
      char simbolo_extraido = linea_extraida[iterador];
      if (CompruebaQueElSimboloEstaEnAlfabeto(simbolo_extraido) == false) {
        std::cout << "Error crítico: no se puede transicionar a un símbolo no presente en el alfabeto." << std::endl;
        exit(EXIT_FAILURE);
      }
      char estado_destino_char = linea_extraida[iterador + 2];
      int estado_destino = estado_destino_char - 48;
      if (estado_destino >= numero_total_estados) {
        std::cout << "Error crítico: no se puede transicionar a un estado no perteneciente al autómata." << std::endl;
        exit(EXIT_FAILURE);
      }
      Transicion transiciones_auxiliar{simbolo_extraido, estado_destino};
      estado_auxiliar.InsertaLasTransiciones(transiciones_auxiliar);
      iterador += 3;
    }
  }
  if (identificador_estado_arranque == identificador_estado) {
    estado_arranque_ = estado_auxiliar;
  }
  estados_.push_back(estado_auxiliar);
}

/// Método encargado de comprobar si el autómata es un DFA, retorna true si lo es, false si no lo es.
bool Automata::CompruebaSiEsUnDFA() const {
  Estado estado_auxiliar;
  Transicion transicion_auxiliar;
  int cantidad_simbolos = alfabeto_.TamanioAlfabeto();
  for (int iterador = 0; iterador < estados_.size(); ++iterador) {
    estado_auxiliar = estados_[iterador];
    if (estado_auxiliar.TamanioVectorTransiciones() != cantidad_simbolos) {
      return false;
    }
    for (int iterador2 = 0; iterador2 < alfabeto_.TamanioAlfabeto(); ++iterador2) {
      char simbolo_alfabeto = alfabeto_[iterador2];
      bool mismo_simbolo_encontrado{false};
      for (int iterador3 = 0; iterador3 < estado_auxiliar.TamanioVectorTransiciones(); ++iterador3) {
        transicion_auxiliar = estado_auxiliar[iterador3];
        if (transicion_auxiliar.get_simbolo() == '&') {
          return false;
        }
        if (simbolo_alfabeto == transicion_auxiliar.get_simbolo()) {
          mismo_simbolo_encontrado = true;
        }      
      }
      if (mismo_simbolo_encontrado == false) {
        return false;
      }
    }
  }
  return true;
}

/// Método encargado de convertir el DFA obtenido en una grámatica 
Gramatica Automata::ConvierteAGramatica() const {
  if (CompruebaSiEsUnDFA() == false) {
    std::cout << "Error crítico: para obtener una grámatica el autómata definido ha de ser un DFA" << std::endl;
    exit(EXIT_FAILURE);
  }
  Gramatica gramatica_resultado;
  Estado estado_auxiliar;
  std::string no_terminales = "SABCDEFGHIJKLMNOPQRTUVXYZ";
  for (int iterador = 0; iterador < estados_.size(); ++iterador) {
    gramatica_resultado.InsertaLosNoTerminales(no_terminales[iterador]);
  }
  for (int iterador = 0; iterador < alfabeto_.TamanioAlfabeto(); ++iterador) {
    gramatica_resultado.InsertaLosTerminales(alfabeto_[iterador]);
  }
  gramatica_resultado.DefineSimboloArranque(no_terminales[0]);
  Produccion produccion_auxiliar;
  Simbolo simbolo_auxiliar;
  for (int iterador = 0; iterador < estados_.size(); ++iterador) {
    estado_auxiliar = RetornaEstadoPorIdentificador(iterador);    
    simbolo_auxiliar = no_terminales[iterador];
    produccion_auxiliar.InsertaOrigen(simbolo_auxiliar);
    for (int iterador2 = 0; iterador2 < estado_auxiliar.TamanioVectorTransiciones(); ++iterador2) {
      Transicion transiciones_auxiliar = estado_auxiliar[iterador2];
      simbolo_auxiliar = transiciones_auxiliar.get_simbolo();
      produccion_auxiliar.InsertaDestinoProduccion(simbolo_auxiliar);
      simbolo_auxiliar = no_terminales[transiciones_auxiliar.get_destino()];
      produccion_auxiliar.InsertaDestinoProduccion(simbolo_auxiliar);
    }
    gramatica_resultado.InsertaProduccion(produccion_auxiliar);
    produccion_auxiliar.LimpiaDestinoProduccion();
  }
  return gramatica_resultado;
}

/// Método encargado de construir el objeto tipo autómata
void Automata::ConstruyeElAutomata(const std::string& nombre_archivo_automata) {
  std::string linea_extraida_automata;
  std::ifstream archivo_automata;
  archivo_automata.open(nombre_archivo_automata);
  getline(archivo_automata, linea_extraida_automata);
  InsertaElAlfabeto(linea_extraida_automata);
  getline(archivo_automata, linea_extraida_automata);
  int numero_total_estados = std::stoi(linea_extraida_automata);
  getline(archivo_automata, linea_extraida_automata);
  int identific_estado_arranque{0};
  if (linea_extraida_automata.size() == 1) {
    identific_estado_arranque = std::stoi(linea_extraida_automata);
  } else {
    std::cout << "Error crítico: debe existir uno y sólo un estado inicial para el autómata." << std::endl;
    exit(EXIT_SUCCESS);
  }
  int contador_lineas_automata{0};
  while (getline(archivo_automata, linea_extraida_automata)) {
    InsertaEstados(linea_extraida_automata, identific_estado_arranque, numero_total_estados);
    contador_lineas_automata += 1;
  }
  if (contador_lineas_automata != numero_total_estados) {
    std::cout << "Error crítico: debe existir una sola línea en el fichero para cada uno de los estados del autómata." << std::endl;
    exit(EXIT_SUCCESS);  
  }
  archivo_automata.close();
}