  /*
 * main.cpp
 *
 *  Created on: 28/09/2020
 *      Author: Eduardo Rodríguez Gil
 */
#ifndef LIST_H
#define LIST_H

#include <sstream>
#include <string>

using namespace std;

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
  Link(const Link<T>&);
	T	    value;
	Link<T> *next;
	friend class List<T>;
  friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

template <class T>
class List{
	public:
		List();
		List(const List<T>&);
		~List();
    void add_first(T);
		void add(T);
    T find(T);
    void update(T,T);
    T remove(int);
    T removeFirst ();
		bool empty() const;
		string toString() const;
    
	private:
		Link<T> *head;
		int size;

    friend class ListIterator<T>;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
void List<T>::add_first(T val) {
	Link<T> *newLink;
	
	newLink = new Link<T>(val);
	
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::add(T val){
	Link<T> *newLink, *p;
	
	newLink = new Link<T>(val);
	if(empty()){
		add_first(val);
		return;
	}
	
	p = head;
	while (p->next != 0) {
		p = p->next;
	}
	
	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
T List<T>::find(T val){
	int pos = 0;
	Link<T> *p;
	
	p = head;
	while(p != 0){
		if (p->value == val){
			return pos;
		}
		p = p->next;
		pos++;
	}
	
	return -1;
}

template <class T>
void List<T>::update(T pos,T val){
	int i = 0;
	Link<T> *p;
	
	p = head;
	while (p != 0){
		if (i == pos){
			p->value = val;
		}
		p = p->next;
		i++;
	}
}

template <class T>
T List<T>::remove(int index) {
  T val;
    Link<T> *p, *q;
    int pos;

    if (index < 0 || index >= size) {
        cout<< "Indice ilegal" << endl;
    }

    if (index == 0) {
    return removeFirst();
    }

    pos = 0;
    p = head;
    q = 0;
    while (pos != index) {
        q = p;
        p = p->next;
        pos++;
    }

    val= p->value;
    q->next = p->next;

    delete p;
    return val;
    size--;
}

template <class T>
T List<T>::removeFirst() {
    T val;
    Link<T> *p;

    if (empty()) {
        cout<<"Inexistentes"<< endl;
    }

    p = head;

    head = p->next;
    val = p->value;

    delete p;
    size--;

    return val;
}

template <class T>
string List<T>::toString() const {
	stringstream help;
	Link<T> *p;

	p = head;
	help << "[";
	while (p != 0) {
		help << p->value;
		if (p->next != 0) {
			help << ", ";
		}
		p = p->next;
	}
	help << "]";
	return help.str();
}

#endif /*LIST_H*/