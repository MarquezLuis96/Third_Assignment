//Headers
#include <iostream>

//Constante para declarar el tamaño del arreglo
const int SIZE = 10;

//Declarando namespaces
using namespace std;

//Clase pila
template <class dataType> class Stack {
	private:
		//Arreglo que se convertirá en la pila
		dataType stack[SIZE];

		//Cima o tope, indica en que posición del arrego se encuentra el último dato ingresado
		int top;

	public:
		//Constructor
		Stack();

		//Retorna true si la pila está llena
		bool isFull();

		//Retorna true si la pila está vacía
		bool isEmpty();

		//Inserta un elemento en el tope de la pila
		void push(dataType key);

		//Extrae el elemento que se encuentre en el tope de la pila
		void pop();

		//Limpia toda la pila dejándola vacía
		void clean();

		//Obtiene el elemento en el tope de la pila y lo imprime sin extraerlo
		void topStack();

		//Obtiene el número de elemtos que tiene la pila
		void length();

		//Imprime toda la pila sin extraer los elementos
		void print();
};

//Constructor
template <class dataType> Stack<dataType>::Stack() {
	top = -1;

	for (int i = 0; i < SIZE; i++) {
		stack[i] = NULL;
	}
}

//Retorna true si la pila está llena
template <class dataType> bool Stack<dataType>::isFull() {
	if (top != SIZE-1) {
		return false;
	}

	return true;
}

//Retorna true si la pila está vacía
template <class dataType> bool Stack<dataType>::isEmpty() {
	if (top != -1) {
		return false;
	}
	
	return true;
}

//Inserta un elemento en el tope de la pila
template <class dataType> void Stack<dataType>::push(dataType key) {
	if (this->isFull()) {
		cerr << "ERROR: Error de OVERFLOW en la pila." << endl;
		return;
	}

	top++;
	stack[top] = key;
	cout << "Elemento " << key << " insertado con exito." << endl;
}

//Extrae el elemento que se encuentre en el tope de la pila
template <class dataType> void Stack<dataType>::pop() {
	if (isEmpty()) {
		cerr << "Error: Error de UNDERFLOW en la pila." << endl;
		return;
	}
	
	dataType key;

	key = stack[top];
	top--;

	cout << "Elemento " << key << " extraido con exito." << endl;
}

//Limpia toda la pila dejándola vacía
template <class dataType> void Stack<dataType>::clean() {
	if (this->isEmpty()) {
		cerr << "Error: Error de UNDERFLOW en la pila." << endl;
	}

	//Pone tope en -1, de esta forma no se pueden acceder a los datos ya escritos y reescribiendo si quisieran guardar nuevos datos
	top = -1;

	cout << "La pila ha sido limpiada" << endl;
}

template <class dataType> void Stack<dataType>::topStack() {
	if (this->isEmpty()) {
		cerr << "Error: Error de UNDERFLOW en la pila." << endl;
	}

	cout << "El elemento en el tope de la pila es: " << stack[top] << endl;
}

template <class dataType> void Stack<dataType>::length() {
	if (this->isEmpty()) {
		cerr << "Error: Error la pila se encuentra vacía." << endl;
	}

	cout << "La pila tiene " << (top + 1) << " elementos." << endl;
}

//Imprime toda la pila sin extraer los elementos
template <class dataType> void Stack<dataType>::print() {
	if (isEmpty()) {
		cerr << "Error: Error de UNDERFLOW en la pila." << endl;
	}
	for (int i = top; i >= 0; i--) {
		if (stack[i] != NULL) {
			cout << "Pos: " << i << ": " << stack[i] << endl;
		}
	}
}

int main(int args, char* argsv[]) {
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
			Stack<int> pila;
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
					break;
				}

				if (opc == 1) {
					if (pila.isFull()) {
						cerr << "Error: No se puede agregar ningun elemento ya que la pila se encuentra llena." << endl;
						continue;
					}

					int data;
					cout << "Escriba el elemento que quiere ingresar a la pila: ";
					cin >> data;
					cout << endl;

					pila.push(data);
				}

				if (opc == 2) {
					if (pila.isEmpty()) {
						cerr << "Error: No se puede extraer ningun elemento ya que la pila se encuentra vacia." << endl;
						continue;
					}
					pila.pop();
				}

				if (opc == 3) {
					if (pila.isEmpty()) {
						cerr << "Error: No se puede vaciar la pila ya que se encuentra vacia." << endl;
						continue;
					}
					pila.clean();
				}

				if (opc == 4) {
					if (pila.isEmpty()) {
						cerr << "Error: La pila se encuentra vacia." << endl;
						continue;
					}
					pila.length();
				}

				if (opc == 5) {
					if (pila.isEmpty()) {
						cerr << "Error: La pila se encuentra vacia." << endl;
						continue;
					}
					pila.topStack();
				}

				if (opc == 6) {
					if (pila.isEmpty()) {
						cerr << "Error: La pila se encuentra vacia." << endl;
						continue;
					}
					pila.print();
				}
			} while (true);
		}

		if (opc == 2) {
			Stack<char> pila;
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
					break;
				}

				if (opc == 1) {
					if (pila.isFull()) {
						cerr << "Error: No se puede agregar ningun elemento ya que la pila se encuentra llena." << endl;
						continue;
					}

					char data;
					cout << "Escriba el elemento que quiere ingresar a la pila: ";
					cin >> data;
					cout << endl;

					pila.push(data);
				}

				if (opc == 2) {
					if (pila.isEmpty()) {
						cerr << "Error: No se puede extraer ningun elemento ya que la pila se encuentra vacia." << endl;
						continue;
					}
					pila.pop();
				}

				if (opc == 3) {
					if (pila.isEmpty()) {
						cerr << "Error: No se puede vaciar la pila ya que se encuentra vacia." << endl;
						continue;
					}
					pila.clean();
				}

				if (opc == 4) {
					if (pila.isEmpty()) {
						cerr << "Error: La pila se encuentra vacia." << endl;
						continue;
					}
					pila.length();
				}

				if (opc == 5) {
					if (pila.isEmpty()) {
						cerr << "Error: La pila se encuentra vacia." << endl;
						continue;
					}
					pila.topStack();
				}

				if (opc == 6) {
					if (pila.isEmpty()) {
						cerr << "Error: La pila se encuentra vacia." << endl;
						continue;
					}
					pila.print();
				}
			} while (true);
		}

		if (opc == 3) {
			Stack<float> pila;
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
					break;
				}

				if (opc == 1) {
					if (pila.isFull()) {
						cerr << "Error: No se puede agregar ningun elemento ya que la pila se encuentra llena." << endl;
						continue;
					}

					float data;
					cout << "Escriba el elemento que quiere ingresar a la pila: ";
					cin >> data;
					cout << endl;

					pila.push(data);
				}

				if (opc == 2) {
					if (pila.isEmpty()) {
						cerr << "Error: No se puede extraer ningun elemento ya que la pila se encuentra vacia." << endl;
						continue;
					}
					pila.pop();
				}

				if (opc == 3) {
					if (pila.isEmpty()) {
						cerr << "Error: No se puede vaciar la pila ya que se encuentra vacia." << endl;
						continue;
					}
					pila.clean();
				}

				if (opc == 4) {
					if (pila.isEmpty()) {
						cerr << "Error: La pila se encuentra vacia." << endl;
						continue;
					}
					pila.length();
				}

				if (opc == 5) {
					if (pila.isEmpty()) {
						cerr << "Error: La pila se encuentra vacia." << endl;
						continue;
					}
					pila.topStack();
				}

				if (opc == 6) {
					if (pila.isEmpty()) {
						cerr << "Error: La pila se encuentra vacia." << endl;
						continue;
					}
					pila.print();
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