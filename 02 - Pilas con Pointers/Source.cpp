#include <iostream>

using namespace std;

//template <class dataType>
//class Nodo {
	//private:
		//Nodo* siguiente;
		//dataType dato;
	//public:
		//Nodo* siguiente;
		//dataType dato;
		//Nodo();
		/*Nodo(dataType key) {
			dato = key;
			siguiente = NULL;
		}

};*/

//template <class dataType>
//Nodo<dataType>::Nodo() {
	//dato = key;
	//siguiente = NULL;
//}

/*template <class dataType>
Nodo<dataType>::Nodo(dataType key) {
	dato = key;
	siguiente = NULL;
}*/

template <class dataType>
class Pila {
	private:
		class Nodo {
		public:
			Nodo* siguiente;
			dataType dato;

			Nodo(dataType key) {
				dato = key;
				siguiente = NULL;
			}

		};

		Nodo *tope;
		int cantElementos;
	public:
		//Constructor
		Pila() {
			tope = NULL;
			cantElementos = 0;
		}
		
		void push(dataType key);
		dataType pop();
		const dataType topeDePila();
		const bool pilaVacia();
		bool limpiarPila();
		int getCantElements();
		void imprimirElementos();

		//Destructor
		~Pila() {
			limpiarPila();
		}
};

template <class dataType>
const bool Pila<dataType>::pilaVacia() {
	if (tope == NULL) {
		return true;
	}
	
	return false;
}

template <class dataType>
bool Pila<dataType>::limpiarPila() {
	Nodo *aux;
	if (pilaVacia()) {
		cerr << "Error: La pila ya se encuentra vacia." << endl;
		return false;
	}

	while (!pilaVacia()) {
		aux = tope;
		tope = tope->siguiente;
		delete aux;
		cantElementos--;
	}
	return true;
}

template <class dataType>
void Pila<dataType>::push(dataType key) {
	Nodo *nuevoElemento;

	nuevoElemento = new Nodo(key);
	nuevoElemento->siguiente = tope;
	tope = nuevoElemento;

	cantElementos++;
}

template <class dataType>
dataType Pila<dataType>::pop() {
	if (pilaVacia()) {
		cerr << "ERROR: UNDERFLOW - Pila vacia, no se puede extraer el elemento." << endl;
		return NULL;
	}

	dataType aux = tope->dato;
	tope = tope->siguiente;

	cantElementos--;
	return aux;
}

template <class dataType>
const dataType Pila<dataType>::topeDePila() {
	if (pilaVacia()) {
		cerr << "ERROR: UNDERFLOW - Pila vacia, no se puede leer el elemento en el tope de la pila" << endl;
		return NULL;
	}

	return tope->dato;
}

template <class dataType>
int Pila<dataType>::getCantElements() {
	return cantElementos;
}

template <class dataType>
void Pila<dataType>::imprimirElementos() {
	if (pilaVacia()) {
		cerr << "Error: La pila se encuentra vacia." << endl;
	}

	Nodo *aux = tope;
	int auxCant = cantElementos;

	while (aux != NULL) {
		cout << "Elemento " << auxCant << " : " << aux->dato << endl;
		auxCant--;
		aux = aux->siguiente;
	}
}

int main() {
	int opc;
	do {
		cout << "Bienvenido! Seleccione el tipo de dato con el que quiere trabajar la pila." << endl;
		cout << "1 - Int" << endl;
		cout << "2 - Char" << endl;
		cout << "3 - Float" << endl;
		cout << "0 - Salir del programa" << endl;
		cin >> opc;

		if (opc > 3 || opc < 0) {
			cerr << "Opcion invalida... Intente de nuevo." << endl;
			continue;
		}

		if (opc == 1) {
			Pila<int> pila;
			cout << "Una pila de tipo Int ha sido creada" << endl;

			do {
				cout << "Seleccione la operacion que desea realizar con la pila:" << endl;
				cout << "1 - Ingresar un elemento." << endl;
				cout << "2 - Extraer un elemento." << endl;
				cout << "3 - Vaciar la pila." << endl;
				cout << "4 - Ver la cantidad de elementos que estan en la pila." << endl;
				cout << "5 - Ver el elemento que esta en el tope de la pila sin extraerlo." << endl;
				cout << "6 - Imprimir todos los elementos dentro de la pila sin extraerlos." << endl;
				cout << "0 - Salir del programa" << endl;
				cin >> opc;

				if (opc == 0) {
					pila.~Pila();
					break;
				}

				if (opc == 1) {
					int aux;

					cout << "Escriba el elemento a ingresar en la pila: ";
					cin >> aux;
					cout << endl;

					try {
						pila.push(aux);
					}
					catch (int e) {
						cout << "ERROR: " << e << endl;
					}
				}

				if (opc == 2) {
					int aux;
					try {
						aux = pila.pop();

						if (aux == NULL) {
							continue;
						}
						else {
							cout << "El elemento extraido de la pila es: " << aux << endl;
						}
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}
				}

				if (opc == 3) {
					try {
						if (pila.limpiarPila()) {
							cout << "Pila limpiada exitosamente" << endl;
						}
						else {
							cout << "Error al intentar limpiar la pila" << endl;
						}
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}
				}

				if (opc == 4) {
					int aux;

					try {
						aux = pila.getCantElements();
					}
					catch (int e) {
						cerr << "Error: " << e << endl;
					}

					if (aux == 1) {
						cout << "Un elemento disponible en la pila" << endl;
					}
					else {
						cout << aux << " elementos disponibles en la pila" << endl;
					}
				}

				if (opc == 5) {
					int aux;

					try {
						aux = pila.topeDePila();
						if (aux == NULL) {
							continue;
						}
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}

					cout << "El elemento en el tope de la pila es: " << aux << endl;
				}

				if (opc == 6) {
					try {
						pila.imprimirElementos();
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}
				}
			} while (true);
		}

		if (opc == 2) {
			Pila<char> pila;
			cout << "Una pila de tipo Char ha sido creada" << endl;

			do {
				cout << "Seleccione la operacion que desea realizar con la pila:" << endl;
				cout << "1 - Ingresar un elemento." << endl;
				cout << "2 - Extraer un elemento." << endl;
				cout << "3 - Vaciar la pila." << endl;
				cout << "4 - Ver la cantidad de elementos que estan en la pila." << endl;
				cout << "5 - Ver el elemento que esta en el tope de la pila sin extraerlo." << endl;
				cout << "6 - Imprimir todos los elementos dentro de la pila sin extraerlos." << endl;
				cout << "0 - Salir del programa" << endl;
				cin >> opc;

				if (opc == 0) {
					pila.~Pila();
					break;
				}

				if (opc == 1) {
					char aux;

					cout << "Escriba el elemento a ingresar en la pila: ";
					cin >> aux;
					cout << endl;

					try {
						pila.push(aux);
					}
					catch (int e) {
						cout << "ERROR: " << e << endl;
					}
				}

				if (opc == 2) {
					char aux;
					try {
						aux = pila.pop();

						if (aux == NULL) {
							continue;
						}
						else {
							cout << "El elemento extraido de la pila es: " << aux << endl;
						}
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}
				}

				if (opc == 3) {
					try {
						if (pila.limpiarPila()) {
							cout << "Pila limpiada exitosamente" << endl;
						}
						else {
							cout << "Error al intentar limpiar la pila" << endl;
						}
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}
				}

				if (opc == 4) {
					char aux;

					try {
						aux = pila.getCantElements();
					}
					catch (int e) {
						cerr << "Error: " << e << endl;
					}

					if (aux == 1) {
						cout << "Un elemento disponible en la pila" << endl;
					}
					else {
						cout << aux << " elementos disponibles en la pila" << endl;
					}
				}

				if (opc == 5) {
					char aux;

					try {
						aux = pila.topeDePila();

						if (aux == NULL) {
							continue;
						}
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}

					cout << "El elemento en el tope de la pila es: " << aux << endl;
				}

				if (opc == 6) {
					try {
						pila.imprimirElementos();
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}
				}
			} while (true);
		}

		if (opc == 3) {
			Pila<float> pila;
			cout << "Una pila de tipo Float ha sido creada" << endl;

			do {
				cout << "Seleccione la operacion que desea realizar con la pila:" << endl;
				cout << "1 - Ingresar un elemento." << endl;
				cout << "2 - Extraer un elemento." << endl;
				cout << "3 - Vaciar la pila." << endl;
				cout << "4 - Ver la cantidad de elementos que estan en la pila." << endl;
				cout << "5 - Ver el elemento que esta en el tope de la pila sin extraerlo." << endl;
				cout << "6 - Imprimir todos los elementos dentro de la pila sin extraerlos." << endl;
				cout << "0 - Salir del programa" << endl;
				cin >> opc;

				if (opc == 0) {
					pila.~Pila();
					break;
				}

				if (opc == 1) {
					float aux;

					cout << "Escriba el elemento a ingresar en la pila: ";
					cin >> aux;
					cout << endl;

					try {
						pila.push(aux);
					}
					catch (int e) {
						cout << "ERROR: " << e << endl;
					}
				}

				if (opc == 2) {
					float aux;
					try {
						aux = pila.pop();

						if (aux == NULL) {
							continue;
						}
						else {
							cout << "El elemento extraido de la pila es: " << aux << endl;
						}
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}
				}

				if (opc == 3) {
					try {
						if (pila.limpiarPila()) {
							cout << "Pila limpiada exitosamente" << endl;
						}
						else {
							cout << "Error al intentar limpiar la pila" << endl;
						}
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}
				}

				if (opc == 4) {
					int aux;

					try {
						aux = pila.getCantElements();
					}
					catch (int e) {
						cerr << "Error: " << e << endl;
					}

					if (aux == 1) {
						cout << "Un elemento disponible en la pila" << endl;
					}
					else {
						cout << aux << " elementos disponibles en la pila" << endl;
					}
				}

				if (opc == 5) {
					float aux;

					try {
						aux = pila.topeDePila();
						if (aux == NULL) {
							continue;
						}
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}

					cout << "El elemento en el tope de la pila es: " << aux << endl;
				}

				if (opc == 6) {
					try {
						pila.imprimirElementos();
					}
					catch (int e) {
						cerr << "ERROR: " << e << endl;
					}
				}
			} while (true);
		}

		if (opc == 0) {
			cout << "Hasta luego!!" << endl;
			break;
		}
	} while (true);
	return 0;
}