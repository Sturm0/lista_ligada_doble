#include <iostream>
//la idea de este programa es intentar implementar una version basica de una lista ligada doble
struct nodo;
struct liga {
	nodo* pre; //predecesor
	nodo* suc; //sucesor
};
struct nodo {
	liga lig;
	int informacion;
};
struct lista {
	nodo* cabeza;
	bool vacio = true;
};
int agregar_elemento(lista& la_lista,int valor) {
	//agrega un nodo al inicio de la lista
	nodo* nuev_prim = new nodo;
	nuev_prim->lig.pre = nullptr;
	if (la_lista.vacio) {
		nuev_prim->lig.suc = nullptr;
	} else {
		nodo* ant_prim = la_lista.cabeza; //el que anteriormente era primero
		nuev_prim->lig.suc = ant_prim;	
		ant_prim->lig.pre = nuev_prim;
	}
	la_lista.vacio = false;
	la_lista.cabeza = nuev_prim;
	nuev_prim->informacion = valor; 
	return valor;
}
int main()
{
	lista prueba;
	agregar_elemento(prueba,20);
	agregar_elemento(prueba,50);
	agregar_elemento(prueba,30);
	
	//ciclo de iteracion para recorrer la lista ligada doble
	for (nodo* ptr = prueba.cabeza; ptr ; ptr = ptr->lig.suc)
	{
		std::cout << ptr->informacion << std::endl;
	}
}