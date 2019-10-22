//
//
#include "definiciones.h"
#include "auxiliares.h"
#include <algorithm>
#include <vector>


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

// EJERCICIO 4
sqPixel calcularRegiones(imagen A)
{
    sqPixel regiones {};
    pixel px = {};

    for (int i = 0; i < A.size(); ++i) //columnas
    {
        for (int j = 0; j < A[i].size(); ++j) //filas
        {
            if (A[i][j] == 1)
            {
                px = {i,j};
               regiones.push_back(px);
            }
        }
    }
    return regiones;
}

bool noEsContorno(const imagen &vector, pixel vector1, int k) {
    bool res = false;
    sqPixel vAux = obtenerPixelesAdy(vector, vector1, k);
    if ((k==4 && vAux.size() > 4) || (k==8 && vAux.size()>8))
    {
        res = true;
    }
    return  res;
}

sqPixel bordes(const imagen &A) {
    sqPixel bordes = {};
    pixel auxPixel;
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < A[i].size(); ++j)
        {
            if(i==0 && j < A[0].size())
            {
                auxPixel = {0,j};
                bordes.push_back(auxPixel);
            }
            else if(i < A.size() && j == 0)
            {
                auxPixel = {i,0};
                bordes.push_back(auxPixel);
            }
            else if (i == A.size()-1 && j < A[i].size())
            {
                auxPixel = {i,j};
                bordes.push_back(auxPixel);
            }
            else if (i < A.size() && j == A[i].size()-1)
            {
                auxPixel = {i,j};
                bordes.push_back(auxPixel);
            }
        }

    }

    return bordes;
}



//END EJERCICIO 4