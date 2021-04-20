#pragma once
#include "Habitacion.h"
#include <iostream>
#include <iterator>
#include <map>
#include "Jugador.h"

using namespace std;

typedef pair<Cuartos, string> ins_desc;

class Mapa
{
	/*Vamos a agregar una variable de tipo map con la llave de tipo de enum de cuartos y con el valor
	de tipo string con la descripcion del cuarto*/
public:
	map<Cuartos, string> m_descripciones;
	map<Cuartos, string> m_desc_visitado;
	map<Cuartos, string> m_desc_doblevis;
	Habitacion m_Recamara;
	Habitacion m_Banio;
	Habitacion m_Recibidor;
	Habitacion m_Sala;
	Habitacion m_Cocina;
	Habitacion m_Comedor;

	string moverse(string direccion);
	void iniciar();

	Jugador* m_Jugador;
};
