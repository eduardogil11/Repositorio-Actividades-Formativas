/*
 * sorts.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
  int auxbin(std::vector<T>&, int, int, int);
public:
	std::vector<T> ordenaSeleccion(std::vector<T>&);
  std::vector<T> ordenaBurbuja(std::vector<T>&);
	std::vector<T> ordenaMerge(std::vector<T>&);

	int busqSecuencial(std::vector<T>&, int);
	int busqBinaria(std::vector<T>&, int);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &prueba, int i, int j) {
	T aux = prueba[i];
	prueba[i] = prueba[j];
	prueba[j] = aux;
}

template <class T>
std::vector<T> Sorts<T>::ordenaSeleccion(std::vector<T> &prueba) {
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
std::vector<T> Sorts<T>:: ordenaBurbuja(std::vector<T> &prueba) {
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
std::vector<T> Sorts<T>:: ordenaMerge(std::vector<T> &prueba) {
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

#endif /* SORTS_H_ */