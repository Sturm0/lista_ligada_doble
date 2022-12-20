#include <iostream>
//la idea de este programa es intentar implementar una version basica de una lista ligada doble
struct nodo;
struct liga {
	nodo* pre;
	nodo* suc;	
};
struct nodo {
	liga lig;
	int informacion;
};
struct lista {
	nodo* cabeza;
};
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

	//ciclo de iteracion para recorrer la lista ligada doble
	for (nodo* ptr = lista_ligada1.cabeza; ptr ; ptr = ptr->lig.suc)
	{
		std::cout << ptr->informacion << std::endl;
	}
	//accedo al ultimo elemento sabiendo el segundo
	//std::cout << segundo.lig.suc->informacion << std::endl;

}