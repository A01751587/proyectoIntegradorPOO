//Paulo Ogando Gulias A01751587\
Jorge Isidro Blanco Martínez A01745907
#ifndef LOCAL_C
#define LOCAL_C
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include "Tarjeta.h"
using namespace std;
class Local{
private:
   string tipoProd;
   string colorProd;
   int precioMax;
   int precioMin;
   string empresaProd;
   int precioProd;
   int precioEnvio;
   string fechaEntrega;
   int precioTotal;
   int pagina;
public:
    Local(){
        tipoProd = " ";
        colorProd = " ";
        empresaProd = " ";
        precioProd = 0;
        precioEnvio = 0;
        fechaEntrega = " ";
        precioTotal = 0;
        pagina = 0;
    }
   Local(string tipo,string color) : tipoProd{tipo}, colorProd{color}
   {
       // no se inicializa
   }
   void rangoPrecio(int min,int max){
       precioMin = min;
       precioMax = max;
   }
   void empresaPreferida(string empresa){
       empresaProd = empresa;
   }
   void precioProducto(){
       srand(time(NULL));
       precioProd = precioMin + rand() % (precioMax - precioMin);
   }
   void costoEnvio(){
       precioEnvio = precioProd * .05;
   }
   void costoTotal(){
       precioTotal = precioProd + precioEnvio;
   }
   void mostrarProducto(){
       cout << "Tipo: " << tipoProd << endl;
       cout << "Color: " << colorProd << endl;
       cout << "Empresa: " << empresaProd << endl;
       cout << "Precio: " << to_string(precioProd) << endl;
       cout << "Costo de envio: " << to_string(precioEnvio) << endl;
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
   string cobrarProducto(Tarjeta tarjeta){
       if (tarjeta.getSaldo() < precioTotal){
           return "Lo siento, no tiene los fondos necesarios para pagar este producto";
       }
       if(pagina < 5){
           return "El producto se cobrara en la pagina del fabricante, nosotros nos encargaremos de enviarselo\n";
       } else {
           return "Gracias por su compra, se han retirado " + to_string(precioTotal) + " de su tarjeta, ahora contiene " + to_string(tarjeta.getSaldo() - precioTotal) + ", procederemos a enviarselo\n";
   }
   }
   string getEmpresa(){return empresaProd;}
   string getTipo(){return tipoProd;}
   int getPrecioTotal(){return precioTotal;}
};//clase local
#endif