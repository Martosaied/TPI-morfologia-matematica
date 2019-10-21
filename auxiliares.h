//
// Created by leticia on 07/05/19.
//

#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esMatrizBinaria(const imagen &A);
bool estanConectados(const imagen &A, const pixel &p, const pixel &q, const int &k);
sqPixel obtenerPixelesAdy(const imagen &A, const pixel &p, const int &k);
sqPixel obtenerPixelesAdyInactivos(const imagen &A, const pixel &p, const int &k);
bool enRango(const pixel &p, const imagen &A, int i, int j);
sqPixel deleteDuplicates(const sqPixel &secP);
sqPixel calcularRegiones(const imagen &A);

#endif //SOLUCION_AUXILIARES_H
