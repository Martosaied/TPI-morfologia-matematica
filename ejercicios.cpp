#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

// Ejercicio 1

bool esImagenValida(const imagen& img) {
	bool resp = false;
	if(!img.empty() && !img[0].empty() && esMatrizBinaria(img)) {
		resp = true;
	}
    return resp;
}

// Ejercicio 2

bool sonPixelesConectados(const imagen& img, const pixel& p, const pixel& q, int k) {
    if(q == p) {
        return true;
    }

    sqPixel regionDelPixel = obtenerRegionDelPixel(img, p, k);

    for (pixel r : regionDelPixel) {
        if(r == q) {
            return true;
        }
    }

    return false;
}

// Ejercicio 3

float devolverPromedioAreas(const imagen &A, int k) {
    vector<sqPixel> regiones = {};
	for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(A[i][j] == 1) {
                sqPixel region = obtenerRegionDelPixel(A, {i, j}, k);
                regiones.push_back(region);
            }
        }
    }
	regiones = deleteDuplicatesRegions(regiones);
	float area = areaTotal(A);

    return area != 0 ? area/regiones.size() : 0;
}

// Ejercicio 4

sqPixel calcularContorno(const imagen &A, int k){
    sqPixel edges = {{}};
	// TODO --> cuerpo de funcion
    return edges;
}
1
// Ejercicio 5
//TODO: NO funciona bien
void cerrarForma(imagen &A, const imagen &B){
    imagen dilatada = dilatacion(A,B);
    imagen terminada = erosion(dilatada,B);
    A = terminada;
	return;
}

// Ejercicio 6

int obtenerRegionConectada(imagen &A, const pixel &semilla) {
	int ite = 0;

	return ite;
}



