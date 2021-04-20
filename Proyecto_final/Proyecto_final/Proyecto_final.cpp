// Proyecto_final.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Mapa.h"

int main()
{
    Jugador Player1;
    Mapa Casa;
    Casa.m_Jugador = &Player1;
    Casa.iniciar();
    string mensaje;
    string linea;

    fstream archivoInicio("LaCasaScarlet.txt");
    if (!archivoInicio.is_open()) {
        archivoInicio.open("LaCasaScarlet.txt", ios::in);
    }
    while (getline(archivoInicio, linea)) {
        cout << linea << endl;
    }
    
    archivoInicio.close();

    cout << "\nEstas en la recamara" << endl;
    cout << "-Mi cama esta destendida y hay ropa en el suelo, tendre que limpiar maniana,\nugh que asco babee sobre mi escritorio." << endl;

    while (true) {
        string direccion;

        // El usuario da la direccion a la que se movera
        cin >> direccion;

        // Convierte lo que el usuario escriba a minusculas
        for (int i = 0; i < direccion.size(); i++)
        {
            direccion[i] = tolower(direccion[i]);
        }

        mensaje = Casa.moverse(direccion);
        cout << mensaje << endl;
    }
}
