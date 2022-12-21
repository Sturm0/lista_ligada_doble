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
int agregar_elemento(lista* la_lista,int valor) {
	//agrega un nodo al inicio de la lista
	nodo* nuev_prim = new nodo;
	nodo* ant_prim = la_lista->cabeza; //el que anteriormente era primero
	nuev_prim->lig.pre = nullptr;
	if (la_lista->vacio) {
		nuev_prim->lig.suc = nullptr;
	} else {
		nuev_prim->lig.suc = ant_prim;	
	}
	la_lista->vacio = false;
	ant_prim->lig.pre = nuev_prim;
	la_lista->cabeza = nuev_prim;
	nuev_prim->informacion = valor; 
	return valor;
}
int main()
{

	//creo los nodos
	nodo primero;
	nodo segundo;
	nodo tercero;
	
	//les asigno informacion
	primero.informacion = 5;
	segundo.informacion = 20;
	tercero.informacion = 10;

	//hago que la lista apunte al primer elemento
	lista lista_ligada1;
	lista_ligada1.cabeza = &primero;
	//hago que el primero apunte a nullptr y al segundo
	primero.lig.pre = nullptr;
	primero.lig.suc = &segundo;
	//hago que el segundo apunte al primero y al siguiente
	segundo.lig.pre = &primero;
	segundo.lig.suc = &tercero;
	//hago que el tercero apunte al segundo y a nullptr
	tercero.lig.pre = &segundo;
	tercero.lig.suc = nullptr;
	agregar_elemento(&lista_ligada1,350);
	
	//ciclo de iteracion para recorrer la lista ligada doble
	for (nodo* ptr = lista_ligada1.cabeza; ptr ; ptr = ptr->lig.suc)
	{
		std::cout << ptr->informacion << std::endl;
	}
}