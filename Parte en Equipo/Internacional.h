//Paulo Ogando Gulias A01751587\
Jorge Isidro Blanco Martínez A01745907
#ifndef INTERNACIONAL_C
#define INTERNACIONAL_C
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include "Tarjeta.h"
using namespace std;
class Internacional{
private:
   string tipoProd;
   string colorProd;
   int precioMaxInt;
   int precioMinInt;
   string empresaProd;
   int precioProdInt;
   int precioEnvioInt;
   string fechaEntrega;
   int precioTotalInt;
   int pagina;
public:
    Internacional(){
        tipoProd = " ";
        colorProd = " ";
        empresaProd = " ";
        precioProdInt = 0;
        precioEnvioInt = 0;
        fechaEntrega = " ";
        precioTotalInt = 0;
        pagina = 0;
    }
   Internacional(string tipo,string color) : tipoProd{tipo}, colorProd{color}
   {
       // no se inicializa
   }
   void rangoPrecioInt(int min,int max){
       precioMinInt = min;
       precioMaxInt = max;
   }
   void empresaPreferidaInt(string empresa){
       empresaProd = empresa;
   }
   void precioProductoInt(){
       srand(time(NULL));
       int precio = precioMinInt + rand() % (precioMaxInt - precioMinInt);
       precioProdInt = precio;
   }
   void costoEnvioInt(){
       precioEnvioInt = precioProdInt * .1;
   }
   void costoTotalInt(){
       precioTotalInt = precioProdInt + precioEnvioInt;
   }
   void mostrarProductoInt(){
       cout << "Tipo: " << tipoProd << endl;
       cout << "Color: " << colorProd << endl;
       cout << "Empresa: " << empresaProd << endl;
       cout << "Precio: " << to_string(precioProdInt) << endl;
       cout << "Costo de envio: " << to_string(precioEnvioInt) << endl;
   }
   string redireccionar(){
       srand(time(NULL));
       pagina = 1 + rand() % (11 - 1);
       if(pagina <= 5){
           return "El producto que buscas lo vende la pagina desarrolladora del mismo, en estos momentos te estamos redirigiendo...\n";
       } else {
           return "El producto no tiene pagina web del fabricante, procederemos a cobrarte el producto\n";
       }
   }
   string cobrarProductoInt(Tarjeta tarjeta){
       if (tarjeta.getSaldo() < precioTotalInt){
           return "Lo siento, no tiene los fondos necesarios para pagar este producto";
       }
       if(pagina < 5){
           return "El producto se cobrara en la pagina del fabricante, nosotros nos encargaremos de enviarselo\n";
       } else {
           return "Gracias por su compra, se han retirado " + to_string(precioTotalInt) + " de su tarjeta, ahora contiene " + to_string(tarjeta.getSaldo() - precioTotalInt) + ", procederemos a enviarselo\n";
   }
   }
   string getEmpresa(){return empresaProd;}
   string getTipo(){return tipoProd;}
   int getPrecioTotal(){return precioTotalInt;}
};//clase local
#endif