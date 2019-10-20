#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

// Ejercicio 1

bool esImagenValida(const imagen& img) {
	bool response = false;
	if(!img.empty() && !img[0].empty() && esMatriz(img) && esBinaria(img)) {
        response = true;
	}
    return response;
}

// Ejercicio 2

bool sonPixelesConectados(const imagen& img, const pixel& p, const pixel& q, int k) {
    if(q == p) {
        return true;
    }

    bool response = false;
    sqPixel regionDelPixel = obtenerRegionDelPixel(img, p, k);
    for (const pixel& r : regionDelPixel) {
        if(r == q) {
            response = true;
        }
    }

    return response;
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
    sqPixel edges = {};
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            pixel p = {i,j};
            sqPixel adyActivados = obtenerPixelesAdy(A,p,k);
            if(!adyActivados.empty() && adyActivados.size() < k && A[i][j] == 1) {
                edges.push_back(p);
            }
        }
    }
    return edges;
}

// Ejercicio 5
void cerrarForma(imagen &A, const imagen &B){
    imagen dilatada = dilatacion(A,B);
    imagen terminada = erosion(dilatada,B);
    A = terminada;
	return;
}

// Ejercicio 6

int obtenerRegionConectada(imagen &A, const pixel &semilla) {
	vector<imagen> secImagenes = {};
	imagen imagenSemilla = generarImagen(semilla, A);
    secImagenes.push_back(imagenSemilla);
	int i = 0;
	while (!proximaIteIgual(secImagenes[i], A)) {
        imagen dilatada = dilatacion(secImagenes[i], {{1,1,1},{1,1,1},{1,1,1}});
        imagen intersecada = interseccion(dilatada, A);
        secImagenes.push_back(intersecada);
        i++;
    }

    int last = secImagenes.size()-1;
	A = secImagenes[last];
	return secImagenes.size();
}



