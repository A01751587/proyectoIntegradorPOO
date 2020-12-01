//Jorge Isidro Blanco Martínez A01745907
#ifndef TICKETI_C
#define TICKETI_C

#include <string>
#include <ctime>
#include "Cliente.h"
#include "Internacional.h"
#include <iostream>

using namespace std;

class TicketI{
    private:
        int numeroPed;
    public:
        TicketI(){
            numeroPed = 0;
        }
        
        int numeroPedido(){
            numeroPed = rand() % (100000 - 10000);
            return numeroPed;
        }
        

        void mandarPorCorreo(Cliente cliente){
          cout << "Se ha mandado el ticket al correo: " << cliente.getCorreo() << endl;
        }
        void datosTicket(Internacional internacional){
            cout << "\tTicket de tu compra;" << endl;
            cout << "Empresa del Producto: " << internacional.getEmpresa() << endl;
            cout << "Producto: " << internacional.getTipo() << endl;
            cout << "Costo total: " << to_string(internacional.getPrecioTotal()) << endl;
            cout << to_string(numeroPed) << endl;
        }
}; //clase ticket
#endif