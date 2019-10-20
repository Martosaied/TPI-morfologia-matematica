//
// Created by leticia on 07/05/19.
//

#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esMatrizBinaria(const imagen &A);
sqPixel obtenerRegionDelPixel(const imagen &A, const pixel &p, const int &k);
vector<vector<int>> obtenerPixelesAdy(const imagen &A, const pixel &p, const int &k);
bool enRango(const pixel &p, const imagen &A, int i, int j);
sqPixel deleteDuplicates(const sqPixel &secP);
vector<sqPixel> deleteDuplicatesRegions(const vector<sqPixel> &secP);

imagen dilatacion(const imagen &A, const imagen &EE);
imagen erosion(const imagen &A, const imagen &EE);
bool elementoEstructuranteEstaEnRegion(int radio, imagen A, pixel posicionActualEE, imagen EE);
bool elementoEstructuranteTocaRegion(int radio, imagen A, pixel posicionActualEE, imagen EE);

float areaTotal(const imagen &A);
bool igualdadRegiones(const sqPixel& sqP, const sqPixel& sqQ);

imagen interseccion(imagen A, imagen B);
imagen generarImagen(pixel semilla, imagen A);
bool igualdadImagenes(const imagen& A, const imagen& B);
vector<imagen> deleteDuplicatesImages(vector<imagen> secImagenes);
bool proximaIteIgual(imagen B, imagen A);1


#endif //SOLUCION_AUXILIARES_H
