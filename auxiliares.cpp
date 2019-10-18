//
//
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

// EJERCICIO 1
bool esMatrizBinaria(const imagen& img) {
	bool resp = true;
	for (int i = 0; i < img.size(); i++) {
        if(img[i].size() != img[0].size()) {
            resp = false;
        }

        for (int j = 0; j < img[0].size(); j++) {
			if(img[i][j] != 0 && img[i][j] != 1) {
				resp = false;
			}
		}
		
	}

	return resp;
}
//END EJERCICIO 1

// EJERCICIO 2
bool estanConectados(const imagen &A, const pixel &p, const pixel &q, const int &k) {
    if(p == q) {
        return true;
    }

    sqPixel pixelesAdy = {p};

    int previousSize = 0;
    while (previousSize != pixelesAdy.size()) {
        previousSize = pixelesAdy.size();
        sqPixel nuevosPixelesAdy = {};
        for (pixel m : pixelesAdy) {
            sqPixel nuevosPixelesAdyAux = obtenerPixelesAdy(A, m, k);
            nuevosPixelesAdy.insert(nuevosPixelesAdy.end(), nuevosPixelesAdyAux.begin(), nuevosPixelesAdyAux.end());
        }
        pixelesAdy.insert(pixelesAdy.end(), nuevosPixelesAdy.begin(), nuevosPixelesAdy.end());
        pixelesAdy = deleteDuplicates(pixelesAdy);
    }

    for (pixel r : pixelesAdy) {
        if(r == q) {
            return true;
        }
    }

    return false;
}

sqPixel obtenerPixelesAdy(const imagen &A, const pixel &p, const int &k) {
    sqPixel ady = {};
    if(k == 4) {
        for (int i = -1; i <= 1; ++i) {
            if(enRango(p, A, i, 0) && A[p[0] + i][p[1]] == 1) {
                ady.push_back({p[0] + i, p[1]});
            }
            if(enRango(p, A, 0, i) && A[p[0]][p[1]+i] == 1) {
                ady.push_back({p[0], p[1] + i});
            }
        }
    } else if(k == 8) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if(enRango(p, A, i, j) && A[p[0] + i][p[1] + j] == 1) {
                    ady.push_back({p[0] + i, p[1] + j});
                }
            }
        }
    }

    return ady;
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
void erosion(imagen &A, const imagen &EE) {
    int rangoEE = ((int)EE.size() - 1) / 2;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            pixel p = {i,j};
            if(elementoEstructuranteEstaEnRegion(rangoEE, A, p)) {
                A[i][j] = 1;
            }
        }
    }
}

void dilatacion(imagen &A, const imagen &EE) {
    int rangoEE = ((int)EE.size() - 1) / 2;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            pixel p = {i,j};
            if(elementoEstructuranteTocaRegion(rangoEE, A,p)) {
                A[i][j] = 1;
            }
        }
    }
}

bool elementoEstructuranteEstaEnRegion(int radio, imagen A, pixel posicionActualEE) {
    bool response = true;
    int x = posicionActualEE[0];
    int y = posicionActualEE[1];
    for (int i = -radio; i < radio; ++i)
        for (int j = -radio; j < radio; ++j) {
            if(A[x+i][y+j] != 1) {
                response = false;
            }
        }
    return response;
}

bool elementoEstructuranteTocaRegion(int radio, imagen A, pixel posicionActualEE) {
    bool response = false;
    int x = posicionActualEE[0];
    int y = posicionActualEE[1];
    for (int i = -radio; i < radio; ++i)
        for (int j = -radio; j < radio; ++j) {
            if(A[x+i][y+j] == 1) {
                response = true;
            }
        }
    return response;
}

// END EJERCICIO 5

// EJERCICIO 6

// END EJERCICIO 6