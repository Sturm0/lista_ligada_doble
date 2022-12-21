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
};
int agregar_elemento(lista* la_lista,int valor) {
	//agrega un nodo al inicio de la lista
	nodo* ant_prim = la_lista->cabeza; //el que anteriormente era primero
	std::cout << ant_prim << std::endl;
	nodo primero;
	primero.lig.pre = nullptr;
	primero.lig.suc = ant_prim;
	ant_prim->lig.pre = &primero;
	la_lista->cabeza = &primero;

	primero.informacion = valor; 
	std::cout << ant_prim << std::endl;
	std::cout << "PRIMERO info: " << primero.informacion << std::endl;
	//puede ser el problema que aca muere primero
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
	agregar_elemento(&lista_ligada1,200);
	lista_ligada1.cabeza->informacion = 35;
	std::cout << lista_ligada1.cabeza->lig.suc->informacion << std::endl;
	std::cout << "recorcholis: " << lista_ligada1.cabeza->informacion << std::endl;
	std::cout << "tamano del recorcholis: " << sizeof(lista_ligada1.cabeza->informacion) << std::endl;
	std::cout << "tamano entero: " << sizeof(int) << std::endl;
	std::cout << "tamano entero: " << sizeof(int*) << std::endl;

	
	//ciclo de iteracion para recorrer la lista ligada doble
	for (nodo* ptr = lista_ligada1.cabeza; ptr ; ptr = ptr->lig.suc)
	{
		std::cout << ptr->informacion << std::endl;
	}
	
	/*
	std::cout << "-----------------" << std::endl;
	lista otra_lista;
	agregar_elemento(&otra_lista,150);
	std::cout << otra_lista.cabeza->lig.suc << std::endl;
	*/

}