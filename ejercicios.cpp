#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

// Ejercicio 1

bool noEsContorno(const imagen &vector, pixel vector1, int k);

bool esImagenValida(const imagen& img) {
	bool resp = false;
	if(!img.empty() && !img[0].empty() && esMatrizBinaria(img)) {
		resp = true;
	}
    return resp;
}

// Ejercicio 2

bool sonPixelesConectados(const imagen& img, const pixel& p, const pixel& q, int k) {

    return estanConectados(img, p, q, k);
}

// Ejercicio 3

float devolverPromedioAreas(const imagen &A, int k){
	float prom = -1.0;
	// TODO --> cuerpo de funcion
    return prom;
}

// Ejercicio 4

sqPixel calcularContorno(const imagen &A, int k) {
    sqPixel edges = {};
    sqPixel regiones = {};
    regiones = calcularRegiones(A);
    if (regiones.size() == A.size() * A[0].size())
    {
        edges = bordes(A);
    }
    else
    {
        for (pixel p : regiones) {
            if (!noEsContorno(A, p, k)) {
                edges.push_back(p);
            }
        }
    }
    return edges;
}

// Ejercicio 5

void cerrarForma(imagen &A, const imagen &B){
	// TODO --> cuerpo de funcion
	return;
}

// Ejercicio 6

int obtenerRegionConectada(imagen &A, const pixel &semilla) {
	int ite = 0;
	// TODO --> cuerpo de funcion
	return ite;
}



