//Paulo Ogando Gulias A01751587\
Jorge Isidro Blanco Martínez A01745907
#ifndef CLIENTE_C
#define CLIENTE_C

#include "Internacional.h"
#include "Local.h"
#include "Tarjeta.h"

#include <string>
#include <iostream>

class Cliente{
    string nombreCliente;
    string correoCliente;
    string direccionCliente;
    int añoNacimientoCliente;
    Local local;
    Internacional internacional;
    Tarjeta tarjeta;


    public:
        Cliente (){
            nombreCliente = " ";
            correoCliente = " ";
            direccionCliente = " ";
            añoNacimientoCliente = 1900;
            local = Local{};
            internacional = Internacional{};
            tarjeta = Tarjeta{};
        }
        Cliente(string nom, string direccion) : nombreCliente{nom}, direccionCliente{direccion}
        {
            // no se inicializa
        }
        string ingresarPlataforma(){
            return "Bienvenido a la Plataforma " + nombreCliente + "!";
        }
        void registroCliente(string correo, int año){
            correoCliente = correo;
            añoNacimientoCliente = año;
        }
        string getNombre(){return nombreCliente;}
        string getCorreo(){return correoCliente;}
        string getDireccion(){return direccionCliente;}

        void imprimirDatosCliente(){
            cout << "Nombre del Cliente: " << nombreCliente << endl;
            cout << "Correo electronico: " << correoCliente << endl;
            cout << "Direccion del Cliente: " << direccionCliente << endl;
            cout << "Año de Nacimiento del Cliente: " << añoNacimientoCliente << endl;
        }
        bool verificarEdad(){
            if(añoNacimientoCliente < 2002){
                return true;
            } else {
                return false;
            }
        }
        void ingresarDatosTarjeta(int num, int cvv, string titular, int año){
            tarjeta = Tarjeta(num, cvv, titular, año);
            tarjeta.saldoTarjeta();
            tarjeta.confirmacionDatos();
        }

        bool validarTarjeta(){
            if(tarjeta.getAño() < 2020){
                return false;
            } else {
                return true;
            }
        }

        Tarjeta getTarjeta(){return tarjeta;}

        void comprarProductoLocal(string tipo, string color, int min, int max, string empresa, Tarjeta tarjeta){
            local = Local(tipo, color);
            local.rangoPrecio(min, max);
            local.empresaPreferida(empresa);
            local.precioProducto();
            local.costoEnvio();
            local.costoTotal();
            local.mostrarProducto();
            cout << local.redireccionar() << endl;
            cout << local.cobrarProducto(tarjeta) << endl;
        }

        Local getLocal(){return local;}

        void comprarProductoInternacional(string tipo, string color, int min, int max, string empresa, Tarjeta tarjeta){
            internacional = Internacional(tipo, color);
            internacional.rangoPrecioInt(min, max);
            internacional.empresaPreferidaInt(empresa);
            internacional.precioProductoInt();
            internacional.costoEnvioInt();
            internacional.costoTotalInt();
            internacional.mostrarProductoInt();
            cout << internacional.redireccionar() << endl;
            cout << internacional.cobrarProductoInt(tarjeta) << endl;
        }
        Internacional getInternacional(){return internacional;}

        void recibirPaquete(){
            cout << "El paquete fue recibido" << endl;
        }
};// clase Cliente

#endif