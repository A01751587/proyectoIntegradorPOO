//Paulo Ogando Gulias A01751587\
Jorge Isidro Blanco Martínez A01745907
#include "Cliente.h"
#include "Local.h"
#include "PaqueteL.h"
#include "PaqueteI.h"
#include "Internacional.h"
#include "Tarjeta.h"
#include "TicketL.h"
#include "TicketI.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
int main(){
    cout << "\t Prueba Cliente" << endl;
    Cliente cliente1;
    cliente1.imprimirDatosCliente();
    cout << "\t" << endl;  

    Cliente cliente2("Raul", "Dubai");
    cout << cliente2.ingresarPlataforma() << endl;
    cliente2.registroCliente("123@gmail.com", 2000);
    cout << cliente2.getNombre() << endl;
    cout << cliente2.getCorreo() << endl;
    cout << cliente2.getDireccion() << endl;
    cliente2.imprimirDatosCliente();
    cout << cliente2.verificarEdad() << endl;
    cliente2.ingresarDatosTarjeta(23412,432,"Raul",2023);
    cout << cliente2.validarTarjeta() << endl;
    cliente2.comprarProductoLocal("Silla","Roja",300,900,"Louis Vuitton",cliente2.getTarjeta());
    cliente2.comprarProductoInternacional("Kigutumi","Negro",1500,2500,"Como entrenar a tu dragon",cliente2.getTarjeta());
    cliente2.recibirPaquete();
    cout << "\t" << endl;
    Cliente cliente3("Pedro", "Berlin");
    cout << cliente3.ingresarPlataforma() << endl;
    cliente3.registroCliente("456@gmail.com", 2009);
    cout << cliente3.verificarEdad() << endl;
    cliente3.ingresarDatosTarjeta(23412,432,"Raul",2000);
    cout << cliente3.validarTarjeta() << endl;
    cout << "\t" << endl;


    cout << "\t Prueba Local" << endl;
    Local producto1;
    producto1.mostrarProducto();
    cout << "\t" << endl;  
    Local producto2{"silla", "morada"};
    producto2.rangoPrecio(150, 200);
    producto2.empresaPreferida("Riot");
    producto2.precioProducto();
    producto2.costoEnvio();
    producto2.costoTotal();
    producto2.mostrarProducto();
    cout << producto2.redireccionar();
    cout << producto2.cobrarProducto(cliente2.getTarjeta()) << endl;
    cout << producto2.getEmpresa();
    cout << producto2.getTipo();
    cout << producto2.getPrecioTotal();
    producto2.rangoPrecio(17000, 200000);
    producto2.precioProducto();
    producto2.costoEnvio();
    producto2.costoTotal();
    producto2.mostrarProducto();
    cout << producto2.cobrarProducto(cliente2.getTarjeta()) << endl;
    cout << "\t" << endl;

    cout << "\t Prueba Paquete Local Paulo Ogando Gulias" << endl;
    PaqueteL paquete1;
    paquete1.tamaño();
    paquete1.crearPaquete(cliente2.getLocal());
    paquete1.datosCliente(cliente2);
    cout << paquete1.enviarPaquete(cliente2) << endl;
    cout << "\t" << endl;

    cout << "\t Prueba Ticket Local Jorge Isidro Blanco" << endl;
    TicketL ticket1;
    ticket1.numeroPedido();
    ticket1.mandarPorCorreo(cliente2);
    ticket1.datosTicket(cliente2.getLocal());
    cout << "\t" << endl;

    cout << "\t Prueba Internacional" << endl;
    Internacional producto3{"Kigurumi", "Negro"};
    producto3.rangoPrecioInt(500, 550);
    producto3.empresaPreferidaInt("Palome Inc.");
    producto3.precioProductoInt();
    producto3.costoEnvioInt();
    producto3.costoTotalInt();
    producto3.mostrarProductoInt();
    cout << producto3.redireccionar();
    cout << producto3.cobrarProductoInt(cliente2.getTarjeta()) << endl;
    cout << producto3.getEmpresa();
    cout << producto3.getTipo();
    cout << producto3.getPrecioTotal();
    cout << "\t" << endl;
    Internacional producto4;
    producto4.mostrarProductoInt();
    cout << "\t" << endl;  

    cout << "\t Prueba Paquete Internacional Paulo Ogando Gulias" << endl;
    PaqueteI paquete2;
    paquete2.tamaño();
    paquete2.crearPaquete(cliente2.getInternacional());
    paquete2.datosCliente(cliente2);
    cout << paquete2.enviarPaquete(cliente2);
    cout << "\t" << endl;

    cout << "\t Prueba Ticket Internacional Jorge Isidro Blanco" << endl;
    TicketI ticket2;
    ticket2.numeroPedido();
    ticket2.mandarPorCorreo(cliente2);
    ticket2.datosTicket(cliente2.getInternacional());
    cout << "\t" << endl;

    cout << "\tPrueba clase Tarjeta" << endl;
    Tarjeta t1(54678,4433,"Squanchy",2019);
    t1.saldoTarjeta();
    cout << t1.getSaldo() << endl;
    t1.confirmacionDatos();
    cout << t1.getAño() << endl;
    cout << t1.eliminarTarjeta() << endl;
    cout << "\t" << endl; 
    Tarjeta t2(54678,4433,"Squanchy",2023);
    t2.saldoTarjeta();
    t2.setSaldo(2);
    cout << t2.getSaldo() << endl;
    t2.confirmacionDatos();
    cout << t2.getAño() << endl;
    cout << t2.eliminarTarjeta() << endl;
    cout << "\t" << endl; 
    Tarjeta t3;
    t3.confirmacionDatos();
    cout << t3.eliminarTarjeta() << endl;
}