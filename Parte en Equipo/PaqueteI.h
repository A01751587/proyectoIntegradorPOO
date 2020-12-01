//Paulo Ogando Gulias A01751587
#ifndef PAQUETEI_C
#define PAQUETEI_C

#include <string>
#include <ctime>
#include "Cliente.h"
#include "Internacional.h"
#include <iostream>

using namespace std;

class PaqueteI{
    string tamanioPaquete;
    public:
    PaqueteI(){
        tamanioPaquete = " ";
    }
    void tamaño(){
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
        cout << "El paquete sera enviado a " << cliente.getNombre() << " y llegara en los proximos 5 a 10 días" << endl;
    }
    void crearPaquete(Internacional internacional){
        cout << "El producto " << internacional.getTipo() << " de la empresa " << internacional.getEmpresa() << " fue colocado dentro del paquete de tamaño "<< tamanioPaquete << " y procederemos a enviarselo..." << endl;
    }
    string enviarPaquete(Cliente cliente){
        return "El paquete esta siendo enviado en estos momentos a la direccion de " + cliente.getDireccion() + ", esperemos haya disfrutado de nuestros servicios";
    }
}; // Clase Paquete

#endif