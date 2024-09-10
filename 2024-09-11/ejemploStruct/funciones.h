#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/// STRUCT
struct tArticulo{
      char codigoArticulo[7];    /// CARACTER TERMINADOR '\n'
      float precioArticulo;
      int stockArticulo;
      char rubroArticulo;
};

/// PROTOTIPOS
void menu();
void cargarArticulos(tArticulo vArticulos[], int tam, int vTotalVentas[], float *recaudacion);
void mostrarArticulos(tArticulo vArticulos[],int tam);
/// PTO A
int obtenerIndice(tArticulo vArticulos[], int tam, char codigo[]);
int obtenerIndiceMaximoValor(int vTotalVentas[], int tam);


#endif // FUNCIONES_H_INCLUDED
