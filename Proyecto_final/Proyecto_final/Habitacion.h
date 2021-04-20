#pragma once
#include <string>
#include <vector>

using namespace std;

enum Cuartos
{
	Recamara,
	Banio,
	Recibidor,
	Sala,
	Cocina,
	Comedor,
};

class Habitacion
{public:
	Cuartos m_habitacion;
	bool m_b_Abierta = true;
	bool m_b_visitado = false;
	bool m_b_doblevis = false;
	vector<string> m_conexiones;
};

