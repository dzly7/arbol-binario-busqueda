#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
};

Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}

Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr) {
        return crearNodo(valor);
    }
    if (valor < raiz->dato) {
        raiz->izq = insertar(raiz->izq, valor);
    } else if (valor > raiz->dato) {
        raiz->der = insertar(raiz->der, valor);
    } else {
        cout << "El valor " << valor << " ya existe, no se inserta.\n";
    }
    return raiz;
}

bool buscar(Nodo* raiz, int valor) {
    if (raiz == nullptr) return false;
    if (valor == raiz->dato) return true;
    if (valor < raiz->dato)
        return buscar(raiz->izq, valor);
    else
        return buscar(raiz->der, valor);
}

void preorden(Nodo* raiz) {
    if (raiz != nullptr) {
        cout << raiz->dato << " ";
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(Nodo* raiz) {
    if (raiz != nullptr) {
        inorden(raiz->izq);
        cout << raiz->dato << " ";
        inorden(raiz->der);
    }
}

void postorden(Nodo* raiz) {
    if (raiz != nullptr) {
        postorden(raiz->izq);
        postorden(raiz->der);
        cout << raiz->dato << " ";
    }
}

void liberar(Nodo* raiz) {
    if (raiz != nullptr) {
        liberar(raiz->izq);
        liberar(raiz->der);
        delete raiz;
    }
}

int main() {
    Nodo* raiz = nullptr;
    int opcion, valor;

    do {
        cout << "\n===== ARBOL BINARIO DE BUSQUEDA =====\n";
        cout << "1. Insertar\n";
        cout << "2. Buscar\n";
        cout << "3. Recorrido Preorden\n";
        cout << "4. Recorrido Inorden\n";
        cout << "5. Recorrido Postorden\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        if (!(cin >> opcion)) break;

        switch (opcion) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> valor;
                raiz = insertar(raiz, valor);
                break;
            case 2:
                cout << "Valor a buscar: ";
                cin >> valor;
                if (buscar(raiz, valor))
                    cout << "El valor " << valor << " SI esta en el arbol.\n";
                else
                    cout << "El valor " << valor << " NO esta en el arbol.\n";
                break;
            case 3:
                cout << "Preorden: ";  preorden(raiz);  cout << "\n";
                break;
            case 4:
                cout << "Inorden: ";   inorden(raiz);   cout << "\n";
                break;
            case 5:
                cout << "Postorden: "; postorden(raiz); cout << "\n";
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);

    liberar(raiz);
    return 0;
}
