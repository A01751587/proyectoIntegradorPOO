//Paulo Ogando Gulias A01751587
#ifndef PAQUETEL_C
#define PAQUETEL_C

#include <string>
#include <ctime>
#include "Cliente.h"
#include "Local.h"
#include <iostream>

using namespace std;

class PaqueteL{
    string tamanioPaquete;
    public:
    PaqueteL(){
        tamanioPaquete = " ";
    }
    void tamanio(){
        srand(time(NULL));
        int tam = 1 + rand() % (4 - 1);
        if (tam == 1){
            tamanioPaquete = "Grande";
        } else if (tam == 2){
            tamanioPaquete = "Mediano";
        } else {
            tamanioPaquete = "Chico";
        }
    }
    void datosCliente(Cliente cliente){
        cout << "El paquete sera enviado a " << cliente.getNombre() << " y llegara en los proximos 3 días" << endl;
    }
    void crearPaquete(Local local){
        cout << "El producto " << local.getTipo() << " de la empresa " << local.getEmpresa() << " fue colocado dentro del paquete de tamaño "<< tamanioPaquete << " y procederemos a enviarselo..." << endl;
    }
    string enviarPaquete(Cliente cliente){
        return "El paquete esta siendo enviado en estos momentos a la direccion de " + cliente.getDireccion() + ", esperemos haya disfrutado de nuestros servicios";
    }
}; // Clase Paquete

#endif