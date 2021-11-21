#include<iostream>
#include<fstream>
#include<string>
const int TAMANIO = 10;

using namespace std;

typedef int TipoDeDato;

class nodo {
	private:
		int valor;
		nodo *siguiente;

	public:
		nodo(int v, nodo *sig) {
			valor = v;
			siguiente = sig;
		}

		int getValor() {
			return valor;
		}

		nodo* getSiguiente() {
			return(siguiente);
		}
};

class Pila {
	private:
		nodo* tope;
	public:
		Pila();
		~Pila();

		bool pilaVacia();
		bool pilaLlena();
		void push(int v);
		int pop();
		int cimaPila();
		bool limpiarPila();
};

Pila::Pila() {
	tope = NULL;
}

Pila::~Pila() {	
	nodo *aux;
	while(tope!=NULL) {
		aux = tope;
		tope = (*tope).getSiguiente();
		delete aux;
	}
}

bool Pila::pilaVacia() {
	if (tope == NULL) {
		return true;
	}
	return false;
}

bool Pila::pilaLlena() {
	int aux = tope->getValor();
	if (aux == TAMANIO) {
		return true;
	}
	return false;
}

void Pila::push(int v) {
	if (pilaLlena()) {
		return;
	}
	nodo *n = new nodo(v, tope);/* Crear un nodo nuevo */
	/* el comienzo de la pila es el nuevo nodo */
	tope = n;
}

int Pila::pop() {
	int v; /*variable aux para retorno*/
	/*Si la pila está vacía,regresar 0*/
	
	if(pilaVacia())
			return NULL;
	nodo *n = tope; /* nodo apunta al primer elemento de la pila */

	tope = (*n).getSiguiente(); /* el nuevo tope es el siguiente del tope actual.Con esto nos lo saltamos*/
	v = (*n).getValor(); /* Guardamos el valor de retorno que es el contenido del antiguo tope */
	delete n; /* Borrar el nodo */
	return v;
}

int Pila::cimaPila() {
	if (pilaVacia()) {
		return NULL;
	}
	return tope->getValor();
}

bool Pila::limpiarPila() {
	if (pilaVacia()) {
		return false;
	}

	while (!pilaVacia()) {
		pop();
	}

	return true;
}

int main() {

	Pila pila;
	int opc, aux;

	do {
		cout << "Seleccione la operacion que desea realizar: " << endl;
		cout << "1 - Agregar un elemento a la pila." << endl;
		cout << "2 - Extraer un elemento a la pila." << endl;
		cout << "3 - Ver el elemento en la cima de la pila." << endl;
		cout << "4 - Imprimir la pila completa." << endl;
		cout << "0 - Salir del programa." << endl;
		cin >> opc;

		switch (opc) {
			case 0:
				cout << "Hasta Luego!" << endl;
				break;
			case 1:
				cout << "Escriba el elemento a ingresar a la pila: ";
				cin >> aux;
				cout << endl;
				pila.push(aux);
				break;
			case 2:
				aux = pila.pop();
				if (aux == NULL) {
					cerr << "Error: La pila esta vacia." << endl;
					continue;
				}
				cout << "El elemento extraido es: " << aux << endl;
				break;
			case 3:
				aux = pila.cimaPila();
				if (aux == NULL) {
					cerr << "Error: La pila esta vacia." << endl;
					continue;
				}
				cout << "El elemento en el tope de la pila es: " << aux << endl;
				break;
			case 4:
				break;
			default:
				cout << "Error: Opcion invalida" << endl;
				break;
		}

		if (opc == 0) {
			break;
		}

	} while (true);

	/*pila Pila;
	Pila.Push(20);
	cout << "Push(20)" << endl;
	Pila.Push(10);
	cout << "Push(10)" << endl;
	cout << "Pop() = " << Pila.Pop() << endl;
	Pila.Push(40);
	Pila.Push(40);
	cout << "Push(40)" << endl;
	Pila.Push(30);
	cout << "Push(30)" << endl;
	cout << "Pop() = " << Pila.Pop() << endl;
	cout << "Pop() = " << Pila.Pop() << endl;
	Pila.Push(90);
	cout << "Push(90)" << endl;
	cout << "Pop() = " << Pila.Pop() << endl;
	cout << "Pop() = " << Pila.Pop() << endl;
	cin.get();*/
return 0;
}