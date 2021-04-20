#pragma once
#include <string>
#include "Habitacion.h"

using namespace std;

class Jugador
{public:
	string m_Nombre;
	Cuartos m_Cuarto_actual = Recamara;
	bool m_b_visitado_recamara = true;
	bool m_b_visitado_banio = false;
	bool m_b_visitado_recibidor = false;
	bool m_b_visitado_cocina = false;
	bool m_b_visitado_sala = false;
	bool m_b_visitado_comedor = false;
	bool m_b_doblevis_recamara = false;
	bool m_b_doblevis_banio = false;
	bool m_b_doblevis_recibidor = false;
	bool m_b_doblevis_cocina = false;
	bool m_b_doblevis_sala = false;
	bool m_b_doblevis_comedor = false;
};

