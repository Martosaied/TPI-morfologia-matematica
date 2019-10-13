//
//
#include <cstdlib>
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

bool esMatrizBinaria(const imagen& img) {
	bool resp = true;
	int imgSize = img.size();
	for (int i = 0; i < img.size(); i++) {
        if(img[i].size() != imgSize) {
            resp = false;
        }

        for (int j = 0; i < img[0].size(); j++) {
			if(img[i][j] != 0 && img[i][j] != 1) {
				resp = false;
			}
		}
		
	}

	return resp;
}

bool estanConectados(const imagen &A, const pixel &p, const pixel &q, const int &k) {
    if(p == q) {
        return true;
    }

    int imgSize = A.size();
    sqPixel pixelesAdy = {p};
    for (int i = 0; i < imgSize; ++i) {
        for (int j = 0; j < imgSize; ++j) {
            sqPixel nuevosPixelesAdy = obtenerPixelesAdy(A, p);
            pixelesAdy.insert(pixelesAdy.end(), nuevosPixelesAdy.begin(), nuevosPixelesAdy.end())
        }
    }
}

sqPixel obtenerPixelesAdy(const imagen &A, const pixel &p, const int &k) {
    sqPixel ady = {};
    if(k == 4) {
        //TODO: Verificar si el indice se encuentra en la matriz para no romper todo
        //TODO: Agregar funcion al .h
        //TODO: Mejorar esto aslkdjhfkasdjg
        for (int i = -1; i <= 1; ++i) {
            if(A[p[0]][p[1]+i] == 1) {
                ady.push_back({p[0], p[1]+i});
            }
            if(A[p[0]+i][p[i]] == 1) {
                ady.push_back({p[0]+i, p[1]});
            }
        }
    }
}

