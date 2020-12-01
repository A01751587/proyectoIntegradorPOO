//Paulo Ogando Gulias A01751587\
Jorge Isidro Blanco Martínez A01745907
#ifndef TARJETA_C
#define TARJETA_C

#include <string>
#include <iostream>
using namespace std;

class Tarjeta{
    int numeroTarjeta;
    int cvvTarjeta;
    string titularTarjeta;
    int saldoTar;
    int anioVencimientoTarjeta;

    public:
        Tarjeta(){
            numeroTarjeta = 000;
            cvvTarjeta = 000;
            titularTarjeta = " ";
            saldoTar = 0;
            anioVencimientoTarjeta = 1900;
        }
        Tarjeta(int num, int cvv, string titular, int anio) : numeroTarjeta{num}, cvvTarjeta{cvv}, titularTarjeta{titular}, anioVencimientoTarjeta{anio}
        {
            // no se inicializa
        }

        void saldoTarjeta(){
            srand(time(NULL));
            int saldo = 0 + rand() % (15000);
            saldoTar = saldo;
        }
        void setSaldo(int s){saldoTar = s;}

        int getSaldo(){return saldoTar;}

        void confirmacionDatos(){
            cout << "Tarjeta de crédito de: " << titularTarjeta << endl;
            cout << "Numero de Tarjeta: " << to_string(numeroTarjeta) << endl;
            cout << "CVV: " << to_string(cvvTarjeta) << endl;
            cout << "Año de Vencimiento: " << to_string(anioVencimientoTarjeta) << endl;
            cout << "Saldo de la Tarjeta: " << to_string(saldoTar) << endl;
        }

        int getAño(){return anioVencimientoTarjeta;}
        
        string eliminarTarjeta(){
            return "La Tarjeta ha sido eliminada del sistema por su seguridad";
        }
};//clase Tarjeta

#endif