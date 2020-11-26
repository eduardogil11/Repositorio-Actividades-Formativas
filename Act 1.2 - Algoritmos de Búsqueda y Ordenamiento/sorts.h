 /*
 * sorts.h
 *
 *  Created on: 10/09/2020
 *      Author: Eduardo Rodríguez Gil
 */
#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <list>

using namespace std;

template <class T>
class Sorts {
private:
	void swap(vector<T>&, int, int);
	void copyArray(vector<T>&,vector<T>&, int, int);
	void mergeArray(vector<T>&,vector<T>&, int, int, int);
	void mergeSplit(vector<T>&,vector<T>&, int, int);
  int auxbin(vector<T>&, int, int, int);
public:
	vector<T> ordenaSeleccion(vector<T>&);
  vector<T> ordenaBurbuja(vector<T>&);
	vector<T> ordenaMerge(vector<T>&);
  int busqSecuencial(vector<T>&, T);
  int busqBinaria(vector<T>&, T);
};

template <class T>
void Sorts<T>::swap(vector<T> &prueba, int i, int j) {
	T aux = prueba[i];
	prueba[i] = prueba[j];
	prueba[j] = aux;
}

template <class T>
vector<T> Sorts<T>::ordenaSeleccion(vector<T> &prueba) {
	int pos;
  for (int i = 0; i < prueba.size(); i++) {
    pos = i;
		for (int j = i + 1; j < prueba.size(); j++) {
			if (prueba[j] < prueba[pos]) {
				pos = j;
			}
		}
    if(pos != i){
    swap(prueba, i, pos);
    }
	}
	return prueba;
}

template <class T>
vector<T> Sorts<T>:: ordenaBurbuja(vector<T> &prueba) {
	int pos;
  for (int i = 0; i < prueba.size(); i++) {
    pos = i;
		for (int j = i + 1; j < prueba.size(); j++) {
			if (prueba[j] < prueba[pos]) {
				pos = j;
			}
		}
    if(pos != i){
    swap(prueba, i, pos);
    }
	}
	return prueba;
}

template <class T>
vector<T> Sorts<T>:: ordenaMerge(vector<T> &prueba) {
	int pos;
  for (int i = 0; i < prueba.size(); i++) {
    pos = i;
		for (int j = i + 1; j < prueba.size(); j++) {
			if (prueba[j] < prueba[pos]) {
				pos = j;
			}
		}
    if(pos != i){
    swap(prueba, i, pos);
    }
	}
	return prueba;
}
template <class T>
int Sorts<T>::busqSecuencial(vector<T> &fuente, T valor){
  int confirm = 0;
  for(int i = 0; i < fuente.size(); i++){
    if(fuente[i] == valor){
      confirm = i;
    }
  }
  if(confirm != 0){
    return confirm;
  }
  else{
    return -1;
  }
}

template <class T>
int Sorts<T>::busqBinaria(vector<T> &fuente, T valor){
  int mid;
  int low = 0;
  int high = fuente.size() - 1;

  while (low < high){
    mid = (high + low) / 2;
    if (valor == fuente[mid]){
      return mid;
    } else if (valor < fuente[mid]){
      high = mid - 1;
    } else if (valor > fuente[mid]){
      low = mid + 1;
    }
  }
  return low;
}

#endif /* SORTS_H */