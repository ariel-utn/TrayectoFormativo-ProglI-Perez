#include <iostream>
#include "funciones.h"

using namespace std;

int main()
{
    /// DECLARACION
    int const TAM = 10;
    tArticulo articulos[TAM];

    /// PTO A
    int vTotalVentas[TAM]{};

    /// PTO B
    float recTotal = 0;

    bool salir = false;
    char opcion;

    while(!salir){

        system("cls");
        menu();

        cin >> opcion;
        switch(opcion){

        case 'c':
        case 'C':
            cargarArticulos(articulos,TAM, vTotalVentas, &recTotal);
        break;
                case 'm':
        case 'M':
            mostrarArticulos(articulos,TAM);
        break;
        case 'a':
        case 'A':
            {
                int indice;
                indice = obtenerIndiceMaximoValor(vTotalVentas, TAM);
                cout << "El codigo de articulo mas vendido es : ";
                cout << articulos[indice].codigoArticulo << endl;
            }
        break;
        case 'b':
        case 'B':
            cout << "La recaudacion total es: " << recTotal << endl;
        break;
                case 's':
        case 'S':
            cout << "Salir" << endl;
            salir = true;
        break;
        default:
            cout << "Opcion invalida" << endl;
            break;

        }
        system("pause");
    }

    return 0;
}
