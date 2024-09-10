#include <iostream>
#include "funciones.h"
#include <string.h>

using namespace std;
void menu()
{
    cout << "-------------------------------------" << endl;
    cout << "C - Cargar LOTE 1 y 2                " << endl;
    cout << "-------------------------------------" << endl;
    cout << "A - Mostrar articulo mas vendido     " << endl;
    cout << "B - Mostrar recaudacion total del mes" << endl;
    cout << "-------------------------------------" << endl;    cout << "S - Salir" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Elija una opcion: ";
}

void cargarArticulos(tArticulo vArticulos[], int tam, int vTotalVentas[], float *recaudacion)
{
    /// DECLARACION DE VARIABLES
    char codigoArticulo[7];
    int  diaVenta, cantidadArticulosVendidos, indice;

    cout << "LOTE 1" << endl;

    for(int i = 0; i < tam; i++)
    {
        cin.ignore();

        cout << "Ingrese codigo articulo: ";
        cin.getline(vArticulos[i].codigoArticulo,7);

        cout << "Ingrese precio: ";
        cin >> vArticulos[i].precioArticulo;

        cout << "Ingrese stock: ";
        cin >> vArticulos[i].stockArticulo;

        cout << "Ingrese rubro: ";
        cin >> vArticulos[i].rubroArticulo;

    }

    cout << "LOTE 2 " << endl;

    cin.ignore();

    cout << "Ingrese codigo articulo: ";
    cin.getline(codigoArticulo,7);

    while(!(strcmp(codigoArticulo,"0")==0))
    {
        cout << "Ingrese dia venta: ";
        cin >> diaVenta;

        cout << "Ingrese cantidad vendida: ";
        cin >> cantidadArticulosVendidos;

        /// PTO A
        indice = obtenerIndice(vArticulos, tam, codigoArticulo);
        if(indice != -1){
            vTotalVentas[indice]++;
        }

        /// PTO B
        *recaudacion += vArticulos[indice].precioArticulo*cantidadArticulosVendidos;

        cin.ignore();

        /// LEER EL SIGUIENTE ARTICULO
        cout << "Ingrese codigo articulo: ";
        cin.getline(codigoArticulo,7);
    }

    cout << "FIN de ingreso de datos" << endl;
}

void mostrarArticulos(tArticulo vArticulos[],int tam)
{
    for(int i = 0; i < tam; i++)
    {
        cout << "Articulo: " << vArticulos[i].codigoArticulo << endl;
        cout << "Precio: " << vArticulos[i].precioArticulo << endl;
        cout << "Stock: " << vArticulos[i].stockArticulo << endl;
        cout << "Rubro: " << vArticulos[i].rubroArticulo << endl;
        cout << endl;
    }
}

int obtenerIndice(tArticulo vArticulos[], int tam, char codigo[]){
     for(int i = 0; i < tam; i++){
        if(strcmp(vArticulos[i].codigoArticulo,codigo) == 0){
            return i;
        }
     }
    return -1;
}

int obtenerIndiceMaximoValor(int vec[], int tam){
    int maximo = 0;
    for(int i = 1; i < tam; i++){
        if(vec[i]>vec[maximo]) {
            maximo = i;
        }
    }
    return maximo;
}
