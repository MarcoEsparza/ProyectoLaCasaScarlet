#include "Mapa.h"

string Mapa::moverse(string direccion)
{
	string mensaje = "No puedes moverte ahi";

	// Vemos las conexiones de cuarto a cuarto
	switch (m_Jugador->m_Cuarto_actual) {
	case Recamara:
		for (int i = 0; i < m_Recamara.m_conexiones.size(); i++)
		{
			// Checamos cada conexion
			if (m_Recamara.m_conexiones[i] == direccion) {
				// Si es igual a una conexion vemos cual es
				if (direccion == "banio") {
					// Igualamos el cuarto actual al nuevo cuarto
					m_Jugador->m_Cuarto_actual = Banio;		
					if (m_Banio.m_b_visitado) {
						mensaje = m_desc_visitado[Banio];
					}
					else if (m_Banio.m_b_doblevis) {
						mensaje = m_desc_doblevis[Banio];
					}
					else {
						mensaje = m_descripciones[Banio];
						m_Jugador->m_b_visitado_banio = true;
						m_Banio.m_b_visitado = true;
					}
				}
				else if (direccion == "sala") {
					m_Jugador->m_Cuarto_actual = Sala;
					if (m_Sala.m_b_visitado) {
						mensaje = m_desc_visitado[Sala];
					}
					else {
						mensaje = m_descripciones[Sala];
						m_Jugador->m_b_visitado_sala = true;
						m_Sala.m_b_visitado = true;
					}
				}
			}
		}
		break;
	case Banio:
		for (int i = 0; i < m_Banio.m_conexiones.size(); i++)
		{
			if (m_Banio.m_conexiones[i] == direccion) {
				if (direccion == "recamara") {
					m_Jugador->m_Cuarto_actual = Recamara;
					if (m_Recamara.m_b_visitado) {
						mensaje = m_desc_visitado[Recamara];
					}
					else {
						mensaje = m_descripciones[Recamara];
						m_Jugador->m_b_visitado_recamara = true;
						m_Recamara.m_b_visitado = true;
					}
				}
				else if (direccion == "recibidor") {
					m_Jugador->m_Cuarto_actual = Recibidor;
					if (m_Recibidor.m_b_visitado) {
						mensaje = m_desc_visitado[Recibidor];
					}
					else {
						mensaje = m_descripciones[Recibidor];
						m_Jugador->m_b_visitado_recibidor = true;
						m_Recibidor.m_b_visitado = true;
					}
				}
			}
		}
		break;
	case Recibidor:
		for (int i = 0; i < m_Recibidor.m_conexiones.size(); i++)
		{
			if (m_Recibidor.m_conexiones[i] == direccion) {
				if (direccion == "banio") {
					m_Jugador->m_Cuarto_actual = Banio;
					if (m_Banio.m_b_visitado) {
						mensaje = m_desc_visitado[Banio];
					}
					else {
						mensaje = m_descripciones[Banio];
						m_Jugador->m_b_visitado_banio = true;
						m_Banio.m_b_visitado = true;
					}
				}
				else if (direccion == "sala") {
					m_Jugador->m_Cuarto_actual = Sala;
					if (m_Sala.m_b_visitado) {
						mensaje = m_desc_visitado[Sala];
					}
					else {
						mensaje = m_descripciones[Sala];
						m_Jugador->m_b_visitado_sala = true;
						m_Sala.m_b_visitado = true;
					}
				}
				else if (direccion == "cocina") {
					m_Jugador->m_Cuarto_actual = Cocina;
					if (m_Cocina.m_b_Abierta==false) {
						mensaje = "\nLa puerta esta cerrada con llave\nSigues en el recibidor";
						m_Jugador->m_Cuarto_actual = Recibidor;
					}
					else if (m_Cocina.m_b_visitado) {
						mensaje = m_desc_visitado[Cocina];
					}
					else {
						mensaje = m_descripciones[Cocina];
						m_Jugador->m_b_visitado_cocina = true;
						m_Cocina.m_b_visitado = true;
					}
				}
			}
		}
		break;
	case Cocina:
		for (int i = 0; i < m_Cocina.m_conexiones.size(); i++)
		{
			if (m_Cocina.m_conexiones[i] == direccion) {
				if (direccion == "recibidor") {
					m_Jugador->m_Cuarto_actual = Recibidor;
					if (m_Recibidor.m_b_visitado) {
						mensaje = m_desc_visitado[Recibidor];
					}
					else {
						mensaje = m_descripciones[Recibidor];
						m_Jugador->m_b_visitado_recibidor = true;
						m_Recibidor.m_b_visitado = true;
					}
				}
				else if (direccion == "sala") {
					m_Jugador->m_Cuarto_actual = Sala;
					if (m_Sala.m_b_visitado) {
						mensaje = m_desc_visitado[Sala];
					}
					else {
						mensaje = m_descripciones[Sala];
						m_Jugador->m_b_visitado_sala = true;
						m_Sala.m_b_visitado = true;
					}
				}
				else if (direccion == "comedor") {
					m_Jugador->m_Cuarto_actual = Comedor;
					if (m_Comedor.m_b_Abierta == false) {
						mensaje = "\nLa chapa esta atascada, tendras que romperla para pasar\nSigues en la cocina";
						m_Jugador->m_Cuarto_actual = Cocina;
					}
					else if (m_Comedor.m_b_visitado) {
						mensaje = m_desc_visitado[Comedor];
					}
					else {
						mensaje = m_descripciones[Comedor];
						m_Jugador->m_b_visitado_comedor = true;
						m_Comedor.m_b_visitado = true;
					}
				}
			}
		}
		break;
	case Sala:
		for (int i = 0; i < m_Sala.m_conexiones.size(); i++)
		{
			if (m_Sala.m_conexiones[i] == direccion) {
				if (direccion == "recamara") {
					m_Jugador->m_Cuarto_actual = Recamara;
					if (m_Recamara.m_b_visitado) {
						mensaje = m_desc_visitado[Recamara];
					}
					else {
						mensaje = m_descripciones[Recamara];
						m_Jugador->m_b_visitado_recamara = true;
						m_Recamara.m_b_visitado = true;
					}
				}
				else if (direccion == "recibidor") {
					m_Jugador->m_Cuarto_actual = Recibidor;
					if (m_Recibidor.m_b_visitado) {
						mensaje = m_desc_visitado[Recibidor];
					}
					else {
						mensaje = m_descripciones[Recibidor];
						m_Jugador->m_b_visitado_recibidor = true;
						m_Recibidor.m_b_visitado = true;
					}
				}
				else if (direccion == "cocina") {
					m_Jugador->m_Cuarto_actual = Cocina;
					if (m_Cocina.m_b_Abierta == false) {
						mensaje = "\nLa puerta esta cerrada con llave\nSigues en la sala";
						m_Jugador->m_Cuarto_actual = Sala;
					}
					else if (m_Cocina.m_b_visitado) {
						mensaje = m_desc_visitado[Cocina];
					}
					else {
						mensaje = m_descripciones[Cocina];
						m_Jugador->m_b_visitado_cocina = true;
						m_Cocina.m_b_visitado = true;
					}
				}
				else if (direccion == "comedor") {
					m_Jugador->m_Cuarto_actual = Comedor;
					if (m_Comedor.m_b_Abierta == false) {
						mensaje = "\nLa chapa esta atascada, tendras que romperla para pasar\nSigues en la sala";
						m_Jugador->m_Cuarto_actual = Sala;
					}
					else if (m_Comedor.m_b_visitado) {
						mensaje = m_desc_visitado[Comedor];
					}
					else {
						mensaje = m_descripciones[Comedor];
						m_Jugador->m_b_visitado_comedor = true;
						m_Comedor.m_b_visitado = true;
					}
				}
			}
		}
		break;
	case Comedor:
		for (int i = 0; i < m_Comedor.m_conexiones.size(); i++)
		{
			if (m_Comedor.m_conexiones[i] == direccion) {
				if (direccion == "sala") {
					m_Jugador->m_Cuarto_actual = Sala;
					if (m_Sala.m_b_visitado) {
						mensaje = m_desc_visitado[Sala];
					}
					else {
						mensaje = m_descripciones[Sala];
						m_Jugador->m_b_visitado_sala = true;
						m_Sala.m_b_visitado = true;
					}
				}
				else if (direccion == "cocina") {
					m_Jugador->m_Cuarto_actual = Cocina;
					if (m_Cocina.m_b_Abierta == false) {
						mensaje = "\nLa puerta esta cerrada con llave\nSigues en el comedor";
						m_Jugador->m_Cuarto_actual = Comedor;
					}
					else if (m_Cocina.m_b_visitado) {
						mensaje = m_desc_visitado[Cocina];
					}
					else {
						mensaje = m_descripciones[Cocina];
						m_Jugador->m_b_visitado_cocina = true;
						m_Cocina.m_b_visitado = true;
					}
				}
			}
		}
		break;
	default:
		break;
	}

	return mensaje;
}

void Mapa::iniciar()
{
	// Descripcion que ira cambiando la descripcion que tiene cada cuarto
	string desc = "Entras a la recamara";	
	// Agregamos la descripcion a cada cuarto
	m_descripciones.insert(ins_desc(Recamara, desc));		
	desc = "\nEntras al banio\n*Te lavas la cara*\n- Ugh me duele la cabeza, y sigue estando ese horrible olor.";
	m_descripciones.insert(ins_desc(Banio, desc));
	desc = "\nEntras al recibidor\nLa puerta esta sellada con tablas de madera y la cerradura esta atascada, ademas\nfalta el florero que tanto te gusta.";
	m_descripciones.insert(ins_desc(Recibidor, desc));
	desc = "\nEntras a la sala\nAqui parece estar todo en orden, a excepcion del gran pentagrama en el suelo, y en\nuna mesita esta la llave de la cocina.\n* Agarras la llave *";
	m_descripciones.insert(ins_desc(Sala, desc));
	desc = "\nEntras a la cocina\nLa estufa estaba prendida y la puerta del refrigerador abierta, adentro hay tripas\npero te niegas a ver si son de algun animal o de un humano.\nHay una vela roja flotando en medio del cuarto.\n* Agarras la vela *";
	m_descripciones.insert(ins_desc(Cocina, desc));
	desc = "\nEntras al comedorEl comedor desprende un olor horrible, hay sangre por todos lados y cuerpos calcinados arrodillados.\nEn medio del comedor ves a un hombre de alrededor de un 1.90 metros de altura, desnudo\ny blanco como la nieve, tiene grandes ojos, su pupila es negra y su iris rojo, y tiene patas de cabra.\nAl ver la vela el demonio retrocede, te armas de valor y te acercas a él haciendo que huya\ny desaparezca de momento, pero la vela se consumió por completo, no hay segundas\noportunidades, si te lo vuelves a topar, te matara.\nVes que hay una palanca atrás de donde estaba el demonio.\n* Agarras la palanca *";
	m_descripciones.insert(ins_desc(Comedor, desc));
	
	// Descripcion de los cuartos si ya fueron visitados
	desc = "\nVolviste a la recamara\n-Mi cama esta llena de sangre, que paso aqui? Hace un momento no estaba asi, tambien\nesta el florero sobre mi escritorio.\n* Agarras el florero *";
	m_desc_visitado.insert(ins_desc(Recamara, desc));
	desc = "\nVolviste al banio\n- Que esta haciendo aqui mi martillo? Oh por Dios hay sangre en las paredes.\n* Agarras el martillo *";
	m_desc_visitado.insert(ins_desc(Banio, desc));
	desc = "\nVolviste al recibidor\nEste cuarto esta igual que antes.";
	m_desc_visitado.insert(ins_desc(Recibidor, desc));
	desc = "\nVolviste a la sala\nNo hay ningun mueble y el suelo esta pegajoso\n- En serio, que esta pasando aqui?";
	m_desc_visitado.insert(ins_desc(Sala, desc));
	desc = "\nVolviste a la cocina\nEste cuarto esta igual que antes.";
	m_desc_visitado.insert(ins_desc(Cocina, desc));
	desc = "\nVolviste al comedor\nEl demonio aparece otra vez y como ya no tienes la vela te toma del cuello y se come tu alma.";
	m_desc_visitado.insert(ins_desc(Comedor, desc));

	// Descripcion de los cuartos si ya fueron visitados 2 o mas veces
	desc = "\nVolviste a la recamara\nEste cuarto esta igual que antes.";
	m_desc_doblevis.insert(ins_desc(Recamara, desc));
	desc = "\nVolviste al banio\nEste cuarto esta igual que antes.";
	m_desc_doblevis.insert(ins_desc(Banio, desc));
	desc = "\nVolviste al recibidor\nEste cuarto esta igual que antes.";
	m_desc_doblevis.insert(ins_desc(Recibidor, desc));
	desc = "\nVolviste a la sala\nEste cuarto esta igual que antes.";
	m_desc_doblevis.insert(ins_desc(Sala, desc));
	desc = "\nVolviste a la cocina\nEste cuarto esta igual que antes.";
	m_desc_doblevis.insert(ins_desc(Cocina, desc));
	desc = "\nVolviste al comedor\nEste cuarto esta igual que antes.";
	m_desc_doblevis.insert(ins_desc(Comedor, desc));

	// Agregamos las conexiones entre cuartos
	m_Recamara.m_conexiones.push_back("banio");		
	m_Recamara.m_conexiones.push_back("sala");
	m_Banio.m_conexiones.push_back("recamara");
	m_Banio.m_conexiones.push_back("recibidor");
	m_Recibidor.m_conexiones.push_back("banio");
	m_Recibidor.m_conexiones.push_back("sala");
	m_Recibidor.m_conexiones.push_back("cocina");
	m_Cocina.m_conexiones.push_back("recibidor");
	m_Cocina.m_conexiones.push_back("sala");
	m_Cocina.m_conexiones.push_back("comedor");
	m_Sala.m_conexiones.push_back("recibidor");
	m_Sala.m_conexiones.push_back("cocina");
	m_Sala.m_conexiones.push_back("comedor");
	m_Sala.m_conexiones.push_back("recamara");
	m_Comedor.m_conexiones.push_back("sala");
	m_Comedor.m_conexiones.push_back("cocina");

	// Marca el cuarto como visitado si el jugador ya estuvo ahi
	m_Recamara.m_b_visitado = m_Jugador->m_b_visitado_recamara;
	m_Banio.m_b_visitado = m_Jugador->m_b_visitado_banio;
	m_Recibidor.m_b_visitado = m_Jugador->m_b_visitado_recibidor;
	m_Cocina.m_b_visitado = m_Jugador->m_b_visitado_cocina;
	m_Sala.m_b_visitado = m_Jugador->m_b_visitado_sala;
	m_Comedor.m_b_visitado = m_Jugador->m_b_visitado_comedor;

	// Marca si el cuarto ya fue visitado 2 o mas veces
	m_Recamara.m_b_doblevis = m_Jugador->m_b_doblevis_recamara;
	m_Banio.m_b_doblevis = m_Jugador->m_b_doblevis_banio;
	m_Recibidor.m_b_doblevis = m_Jugador->m_b_doblevis_recibidor;
	m_Cocina.m_b_doblevis = m_Jugador->m_b_doblevis_cocina;
	m_Sala.m_b_doblevis = m_Jugador->m_b_doblevis_sala;
	m_Comedor.m_b_doblevis = m_Jugador->m_b_doblevis_comedor;

	// La cocina y el comedor estan cerrados
	m_Cocina.m_b_Abierta = false;
	m_Comedor.m_b_Abierta = false;
}
