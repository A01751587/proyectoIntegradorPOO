//Jorge Isidro Blanco Martínez A01745907
#ifndef TICKETL_C
#define TICKETL_C

#include <string>
#include <ctime>
#include "Cliente.h"
#include "Local.h"
#include <iostream>

using namespace std;

class TicketL{
    private:
        int numeroPed;
    public:
        TicketL(){
            numeroPed = 0;
        }
        
        int numeroPedido(){
            numeroPed = rand() % (100000 - 10000);
            return numeroPed;
        }
        

        void mandarPorCorreo(Cliente cliente){
          cout << "Se ha mandado el ticket al correo: " << cliente.getCorreo() << endl;
        }
        void datosTicket(Local local){
            cout << "\tTicket de tu compra;" << endl;
            cout << "Empresa del Producto: " << local.getEmpresa() << endl;
            cout << "Producto: " << local.getTipo() << endl;
            cout << "Costo total: " << to_string(local.getPrecioTotal()) << endl;
            cout << to_string(numeroPed) << endl;
        }
}; //clase ticket
#endif
