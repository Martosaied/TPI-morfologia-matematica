//
//
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

// EJERCICIO 1
bool esMatriz(const imagen &img) {
    bool response = true;
    for (int i = 0; i < img.size(); i++) {
        if(img[i].size() != img[0].size()) {
            response = false;
        }
    }

    return response;
}

bool esBinaria(const imagen &img) {
    bool response = true;
    for (int i = 0; i < img.size(); i++) {
        for (int j = 0; j < img[0].size(); j++) {
            if(img[i][j] != 0 && img[i][j] != 1) {
                response = false;
            }
        }
    }

    return response;
}
//END EJERCICIO 1

// EJERCICIO 2
sqPixel obtenerRegionDelPixel(const imagen &A, const pixel &p, const int &k) {
    sqPixel pixelesAdy = {p};

    int previousSize = 0;
    while (previousSize != pixelesAdy.size()) {
        previousSize = pixelesAdy.size();
        sqPixel nuevosPixelesAdy = {};
        for (const pixel& m : pixelesAdy) {
            sqPixel nuevosPixelesAdyAux = obtenerPixelesAdy(A, m, k);
            nuevosPixelesAdy.insert(nuevosPixelesAdy.end(), nuevosPixelesAdyAux.begin(), nuevosPixelesAdyAux.end());
        }

        pixelesAdy.insert(pixelesAdy.end(), nuevosPixelesAdy.begin(), nuevosPixelesAdy.end());
        pixelesAdy = deleteDuplicates(pixelesAdy);
    }

    return pixelesAdy;
}

vector<vector<int>> obtenerPixelesAdy(const imagen &A, const pixel &p, const int &k) {
    sqPixel adyacentes = {};
    if(k == 4) {
        adyacentes = obtenerPixelesAdy4(A, p);
    } else if(k == 8) {
        adyacentes = obtenerPixelesAdy8(A, p);
    }

    return adyacentes;
}

sqPixel obtenerPixelesAdy4(const imagen &A, const pixel &p) {
    sqPixel adyacentes = {};

    if(enRango(p, A, 1, 0) && A[p[0] + 1][p[1]] == 1) {
        adyacentes.push_back({p[0] + 1, p[1]});
    }
    if(enRango(p, A, -1, 0) && A[p[0] - 1][p[1]] == 1) {
        adyacentes.push_back({p[0] - 1, p[1]});
    }
    if(enRango(p, A, 0, 1) && A[p[0]][p[1] + 1] == 1) {
        adyacentes.push_back({p[0], p[1] + 1});
    }
    if(enRango(p, A, 0, -1) && A[p[0]][p[1] - 1] == 1) {
        adyacentes.push_back({p[0], p[1] - 1});
    }

    return adyacentes;
}

sqPixel obtenerPixelesAdy8(const imagen &A, const pixel &p) {
    sqPixel adyacentes = {};

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if(enRango(p, A, i, j) && A[p[0] + i][p[1] + j] == 1 && (i != 0 || j != 0)) {
                adyacentes.push_back({p[0] + i, p[1] + j});
            }
        }
    }

    return adyacentes;
}

bool enRango(const pixel &p, const imagen &A, int modificadorX, int modificadorY) {
    int x = p[0] + modificadorX;
    int y = p[1] + modificadorY;
    return (x >= 0 && x < A.size() && y >= 0 && y < A[0].size());
}

sqPixel deleteDuplicates(const sqPixel &secP) {
    sqPixel newSecP = {};
    for (const pixel& p : secP) {
        bool add = true;
        for (const pixel& q : newSecP) {
            if(q == p) {
                add = false;
            }
        }

        if(add) {
            newSecP.push_back(p);
        }
    }
    return newSecP;
}
// END EJERCICIO 2


// EJERCICIO 5
imagen erosion(const imagen &A, const imagen &EE) {
    int rangoEE = ((int)EE.size() - 1) / 2;
    imagen response = A;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            pixel p = {i,j};
            if(elementoEstructuranteEstaEnRegion(rangoEE, A, p, EE)) {
                response[i][j] = 1;
            } else {
                response[i][j] = 0;
            }
        }
    }

    return response;
}

imagen dilatacion(const imagen &A, const imagen &EE) {
    int rangoEE = ((int)EE.size() - 1) / 2;
    imagen response = A;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            pixel p = {i,j};
            if(elementoEstructuranteTocaRegion(rangoEE, A, p, EE)) {
                response[i][j] = 1;
            } else {
                response[i][j] = 0;
            }
        }
    }

    return response;
}

bool elementoEstructuranteEstaEnRegion(int radio, imagen A, pixel posicionActualEE, imagen EE) {
    bool response = true;
    int x = posicionActualEE[0];
    int y = posicionActualEE[1];
    for (int i = -radio; i <= radio; ++i)
        for (int j = -radio; j <= radio; ++j) {
            if(enRango(posicionActualEE,A,i,j) && enRango({i+radio,j+radio},A,0,0) && A[x+i][y+j] != 1 && EE[i+radio][j+radio] == 1) {
                response = false;
            }
        }
    return response;
}

bool elementoEstructuranteTocaRegion(int radio, imagen A, pixel posicionActualEE, imagen EE) {
    bool response = false;
    int x = posicionActualEE[0];
    int y = posicionActualEE[1];
    for (int i = -radio; i <= radio; ++i)
        for (int j = -radio; j <= radio; ++j) {
            if(enRango(posicionActualEE,A,i,j) && enRango({i+radio,j+radio},A,0,0) && A[x+i][y+j] == 1 && EE[i+radio][j+radio] == 1) {
                response = true;
            }
        }
    return response;
}

// END EJERCICIO 5

vector<sqPixel> deleteDuplicatesRegions(const vector<sqPixel> &secP) {
    vector<sqPixel> newSecP = {};
    for (const sqPixel& sqP : secP) {
        bool add = true;
        for (const sqPixel& sqQ : newSecP) {
            if(igualdadRegiones(sqP, sqQ)) {
                add = false;
            }
        }

        if(add) {
            newSecP.push_back(sqP);
        }
    }
    return newSecP;
}

vector<imagen> deleteDuplicatesImages(vector<imagen> secImagenes) {
    vector<imagen> sinDuplicados = {};
    for (const imagen& A : secImagenes) {
        bool add = true;
        for (const imagen& B : sinDuplicados) {
            if(igualdadImagenes(A,B)) {
                add = false;
            }
        }
        if(add) {
            sinDuplicados.push_back(A);
        }
    }

    return sinDuplicados;
}
bool igualdadRegiones(const sqPixel& sqP, const sqPixel& sqQ) {
    bool resp = true;
    for (const pixel& p : sqP) {
        bool estaEnRegion = false;
        for (const pixel& q : sqQ) {
            if(p == q) {
                estaEnRegion = true;
            }
        }

        if(!estaEnRegion) {
            resp = false;
        }
    }
    return resp;
}

bool igualdadImagenes(const imagen& A, const imagen& B) {
    bool resp = true;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(A[i][j] != B[i][j]) {
                resp = false;
            }
        }
    }

    return resp;
}

float areaTotal(const imagen& A) {
    float areaTotal = 0;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(A[i][j] == 1) {
                areaTotal++;
            }
        }
    }

    return areaTotal;
}

imagen interseccion(imagen A, imagen B) {
    imagen response = A;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(A[i][j] == 1 && B[i][j] == 1) {
                response[i][j] = 1;
            } else {
                response[i][j] = 0;
            }
        }
    }

    return response;
}

imagen generarImagen(pixel semilla, imagen A) {
    imagen imagenVacia = A;
    for (int i = 0; i < imagenVacia.size(); ++i) {
        for (int j = 0; j < imagenVacia[0].size(); ++j) {
            imagenVacia[i][j] = 0;
        }
    }
    imagenVacia[semilla[0]][semilla[1]] = 1;

    return imagenVacia;
}

bool proximaIteIgual(imagen B, imagen A) {
    imagen dilatada = dilatacion(B, {{1,1,1},{1,1,1},{1,1,1}});
    imagen intersecada = interseccion(dilatada, A);

    return igualdadImagenes(B, intersecada);
}
// END EJERCICIO 6
