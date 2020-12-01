//Paulo Ogando Gulias A01751587\
Jorge Isidro Blanco Martínez A01745907

#include "Cliente.h"
#include "Local.h"
#include "PaqueteL.h" //Paulo Ogando Gulias
#include "PaqueteI.h" // Paulo Ogando Gulias
#include "Internacional.h"
#include "Tarjeta.h"
#include "TicketL.h" //Jorge Isidro Blanco Martinez
#include "TicketI.h" //Jorge Isidro Blanco Martinez
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

Cliente registro(){
    string nom, domicilio, correo, cdatos {"n"};
    Cliente cliente = Cliente{};
    int anio;
    cout << "\t" << endl;
    cout << "Bienvenido a Ekko, el mejor sistema de ventas!" << endl;
    cout << "\t" << endl;
    while(cdatos == "n"){
        cout << "Por favor ingrese su nombre completo y su direccion" << endl;
        cout << "Nombre: ";getline(cin, nom);
        cout << "Domicilio: ";getline(cin, domicilio);
        cliente = Cliente{nom,domicilio};
        cout << cliente.ingresarPlataforma() << endl;
        cout << "Por favor, registre su correo electronico y su año de nacimiento (SOLO EL AÑO)" << endl;
        cout << "Correo Electronico: "; getline(cin, correo);
        cout << "Año de Nacimiento: "; cin >> anio;
        cliente.registroCliente(correo, anio);
        cout << "\t" << endl;
        cliente.imprimirDatosCliente();
        cout << "\t" << endl;
        cout << "Sus datos estan correctos? y/n" << endl; cin >> cdatos;
        while(cdatos != "y" && cdatos != "n"){
            cout << "Sus datos estan correctos? y/n" << endl; cin >> cdatos;
        }
        cin.ignore(32767,'\n');
    }
    return cliente;
}

Cliente tarjeta(Cliente cliente){
    int num, cvv, anioV;
    string titular;
    cout << "\t" << endl;
    cout << "Para comprar en este sitio, requerimos de los datos de su tarjeta de credito..." << endl;
    cout << "Ingrese el numero de su tarjeta: "; cin >> num;
    cout << "Ingrese el cvv de su tarjeta: "; cin >> cvv;
    titular = cliente.getNombre();
    cout << "Ingrese el año de vencimiento de su tarjeta: "; cin >> anioV;
    cout << "\t" << endl;
    cout << "Espere mientras procesamos sus datos..." << endl;
    cout << "\t" << endl;
    cliente.ingresarDatosTarjeta(num,cvv,titular,anioV);
    cout << "\t" << endl;
    return cliente;
}

Cliente comprarLocal(Cliente cliente, Tarjeta tarjeta){
    string tipo, color, empresa;
    int min, max;

    cin.ignore(32767,'\n');
    cout << "¿Que producto deseas adquirir? " << endl;
    getline(cin,tipo);
    cout << "¿De que color deseas ese producto? " << endl; 
    getline(cin,color);
    cout << "Dame el rango de precio con el que deseas buscar el producto: " << endl;
    cout << "Precio minimo (precio sin centavos): "; cin >> min;
    cout << "Precio máximo (precio sin centavos): "; cin >> max;
    cout << "Por ultimo ¿De que empresa deseas tu producto? " << endl;
    cout << "Empresa: "; cin >> empresa;
    cout << "\t" << endl;
    cout << "Recuerda que usaremos los datos de tu tarjeta para cobrar el producto, si no tienes fondos suficientes, la accion no se realizara..." << endl;
    cout << "\t" << endl;
    cliente.comprarProductoLocal(tipo,color,min,max,empresa, tarjeta);
    return cliente;
}

Cliente comprarInter(Cliente cliente, Tarjeta tarjeta){
    string tipo, color, empresa;
    int min, max;

    cin.ignore(32767,'\n');
    cout << "¿Que producto deseas adquirir? " << endl;
    getline(cin,tipo);
    cout << "¿De que color deseas ese producto? " << endl; 
    getline(cin,color);
    cout << "Dame el rango de precio con el que deseas buscar el producto: " << endl;
    cout << "Precio minimo (precio sin centavos): "; cin >> min;
    cout << "Precio máximo (precio sin centavos): "; cin >> max;
    cout << "Por ultimo ¿De que empresa deseas tu producto? " << endl;
    cout << "Empresa: "; cin >> empresa;
    cout << "\t" << endl;
    cout << "Recuerda que usaremos los datos de tu tarjeta para cobrar el producto, si no tienes fondos suficientes, la accion no se realizara..." << endl;
    cout << "\t" << endl;
    cliente.comprarProductoInternacional(tipo,color,min,max,empresa, tarjeta);
    return cliente;
}

TicketL generarTicketL(Cliente cliente){ // Jorge Isidro Blanco Martinez
    TicketL ticket = TicketL{};
    ticket.numeroPedido();
    ticket.mandarPorCorreo(cliente);
    cout << "\t" << endl;
    ticket.datosTicket(cliente.getLocal());
    cout << "\t" << endl;
    return ticket;
}

PaqueteL generarPaqueteL(Cliente cliente){//Paulo Ogando Gulias
    PaqueteL paquete = PaqueteL{};
    paquete.tamaño();
    paquete.crearPaquete(cliente.getLocal());
    paquete.datosCliente(cliente);
    cout << paquete.enviarPaquete(cliente) << endl;
    return paquete;
}

TicketI generarTicketI(Cliente cliente){ // Jorge Isidro Blanco Martinez
    TicketI ticket = TicketI{};
    ticket.numeroPedido();
    ticket.mandarPorCorreo(cliente);
    cout << "\t" << endl;
    ticket.datosTicket(cliente.getInternacional());
    cout << "\t" << endl;
    return ticket;
}

PaqueteI generarPaqueteI(Cliente cliente){//Paulo Ogando Gulias
    PaqueteI paquete = PaqueteI{};
    paquete.tamaño();
    paquete.crearPaquete(cliente.getInternacional());
    paquete.datosCliente(cliente);
    cout << paquete.enviarPaquete(cliente) << endl;
    return paquete;
}


int main(){
    int producto, saldo;
    string revision, otraCompra{"y"};
    bool edad, tarjetaVerificada;
    Local local;
    Internacional internacional;
    Cliente cliente;
    Tarjeta tarjetaCreada;
    TicketL ticketL;
    PaqueteL paqueteL;
    TicketI ticketI;
    PaqueteI paqueteI;
    

    cliente = registro();
    edad = cliente.verificarEdad();
    while(edad == false){
        cout << "Lo sentimos, usted no tiene la edad para comprar en este sitio." << endl;;
        cliente = registro();
        edad = cliente.verificarEdad();
    } 
    cliente = tarjeta(cliente);
    tarjetaVerificada = cliente.validarTarjeta();
    while(tarjetaVerificada == false){
        cout << "Esta tarjeta no es valida, debe ingresar otra" << endl;
        cliente = tarjeta(cliente);
        tarjetaVerificada = cliente.validarTarjeta();
    }
    tarjetaCreada= cliente.getTarjeta();
    saldo = tarjetaCreada.getSaldo();
    cout << "¿Quieres revisar los datos que ingresaste? y/n "; cin >> revision;
    while(revision != "y" && revision != "n"){
        cout << "¿Quieres revisar los datos que ingresaste? y/n "; cin >> revision;
    }
    if(revision == "y"){
        cout << "\t" << endl;
        cliente.imprimirDatosCliente();
        cout << "\t" << endl;
        tarjetaCreada.confirmacionDatos();
        cout << "\t" << endl;
    }
    while(otraCompra == "y"){
        cout << "Saldo restante: " << to_string(tarjetaCreada.getSaldo()) << endl;
        cout << "Que tipo de Producto desea comprar?" << endl;
        cout << "1.- Local" << endl;
        cout << "2.- Internacional" << endl;
        cin >> producto;
        if(producto == 1){
            cliente = comprarLocal(cliente,tarjetaCreada);
            local = cliente.getLocal();
            if(tarjetaCreada.getSaldo() < local.getPrecioTotal()){
                cout << "No tiene saldo, Vuelva pronto" << endl;
            } else {
                ticketL = generarTicketL(cliente);
                paqueteL = generarPaqueteL(cliente);
                cout << "\t" << endl;
                tarjetaCreada.setSaldo(saldo - local.getPrecioTotal());
                cout << "Saldo restante: " << to_string(tarjetaCreada.getSaldo()) << endl;
            }
        } else if(producto == 2){
            cliente = comprarInter(cliente,tarjetaCreada);
            internacional = cliente.getInternacional();
            if(tarjetaCreada.getSaldo() < internacional.getPrecioTotal()){
                cout << "No tiene saldo, Vuelva pronto" << endl;
            } else {
                ticketI = generarTicketI(cliente);
                paqueteI = generarPaqueteI(cliente);
                cout << "\t" << endl;
                tarjetaCreada.setSaldo(saldo - internacional.getPrecioTotal());
                cout << "Saldo restante: " << to_string(tarjetaCreada.getSaldo()) << endl;
            }
        }
        cout << "\t" << endl;
        cout << "¿Desea comprar otro producto? y/n" << endl;
        cin >> otraCompra;
        cin.ignore(32767,'\n');
    }
    cout << tarjetaCreada.eliminarTarjeta() << endl;
    cout << "Vuelva pronto!" << endl;
    cliente.recibirPaquete();
}