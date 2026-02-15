#include <iostream>

using namespace std;

// Estados del sistema
enum Estado {
    LIBRE,
    OCUPADO,
    MOVIMIENTO
};

// Variables del sistema
Estado estado = LIBRE;
int pisoActual = 0;
int pisoDestino = 0;

// Mostrar estado actual
void mostrarEstado() {
    if (estado == LIBRE)
        cout << "Estado: ELEVADOR LIBRE\n";
    else if (estado == OCUPADO)
        cout << "Estado: ELEVADOR OCUPADO\n";
    else if (estado == MOVIMIENTO)
        cout << "Estado: ELEVADOR EN MOVIMIENTO\n";
}

// Evento: persona ingresa
void personaIngresa() {
    if (estado == LIBRE) {
        estado = OCUPADO;
        cout << "Persona ingresa al elevador.\n";
    }
    else {
        cout << "No se puede ingresar.\n";
    }
}

// Evento: presionar boton
void presionarBoton(int destino) {
    if (estado == OCUPADO) {
        pisoDestino = destino;
        estado = MOVIMIENTO;
        cout << "Boton presionado. Destino: Piso " << pisoDestino << endl;
    }
    else {
        cout << "No se puede presionar boton.\n";
    }
}

// Evento: movimiento
void moverElevador() {
    if (estado == MOVIMIENTO) {

        if (pisoDestino > pisoActual)
            cout << "Elevador subiendo...\n";
        else if (pisoDestino < pisoActual)
            cout << "Elevador bajando...\n";
        else
            cout << "Ya esta en el piso solicitado.\n";

        pisoActual = pisoDestino;

        cout << "Elevador llega al piso " << pisoActual << endl;

        estado = LIBRE;
    }
}

int main() {

    mostrarEstado();
    cout << endl;

    personaIngresa();
    mostrarEstado();
    cout << endl;

    presionarBoton(3);
    mostrarEstado();
    cout << endl;

    moverElevador();
    mostrarEstado();

    return 0;


}