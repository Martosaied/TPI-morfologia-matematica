//
//
#include <cstdlib>
#include "definiciones.h"
#include "auxiliares.h"

using namespace std;

bool esMatriz(const imagen& img) {
	int imgSize = img.size();
	bool resp = true;
	for (int i = 0; i < img.size(); i++) {
		if(!img[i].size() == imgSize) {
			resp = false;
		} 
	}	

	return resp;
}

bool esBinaria(const imagen& img) {
	bool resp = true;
	for (int i = 0; i < img.size(); i++) {
		for (int j = 0; i < img[0].size(); j++) {
			if(img[i][j] != 0 || img[i][j] != 1) {
				resp = false;
			}
		}
		
	}

	return resp;
}

