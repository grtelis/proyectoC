/*
	Programa: heladeria.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. L?pez Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Mostrar el men? principal de la helader?a HEL-ARTE.
*/

//Bibliotecas
#include "FuncionesPantalla.h"
#include "Validaciones.h"
#include "Interfaces.h"
#include "Almacen.c"
// Archivos de funciones
#include "MenuProductos.c"
//#include "MenuVentas.c"
//#include "MenuCompras.c"
#include "MenuAlmacen.c"
#include "MenuCategorias.c"
#include "logo.c"

typedef struct {
	
	TrListaArticulos rListaArticulos;
	TrLista rLista;
//	TrListaCategoria rListaCategoria;
//	TrListaVenta rListaVenta;
	
} TrRegistroDeListas;

//Funci?n principal
int main (void) {
	
	//variables locales
	TrRegistroDeListas rRegistroDeListas;
	int eOpcion;
	
//	Logo();
	//Men?
	do {
		
		system("cls");
		
		MargenPantalla ();
		MargenMenu ();
		MensajesDelSistema ();
		
		CentrarTexto("HELADER?A HEL-ARTE", 2);
		gotoxy(2, 6);
		printf("1. Men? de productos");
		gotoxy(2, 8);
		printf("2. Men? de ventas");
		gotoxy(2, 10);
		printf("3. Men? de compras");
		gotoxy(2, 12);
		printf("4. Men? de almac?n");
		gotoxy(2, 14);
		printf("5. Menu de categorias");
		gotoxy(2, 16);
		printf("6. Salir");
			
		gotoxy(2, 20);
		printf("Ingrese una opci?n: ");	
		scanf("%d", &eOpcion);
		
		
		switch(eOpcion) {
			
			case 1: rRegistroDeListas.rLista = MenuProductos(rRegistroDeListas.rListaArticulos);
					break;
//			case 2: MenuVentas();
					break;
//			case 3: MenuCompras();
					break;
			case 4: MenuAlmacen();
					break;			
			case 5: MenuCategorias();
				break;		
			case 6: CentrarTexto("Adi?s.", 23);
				break;
			default: CentrarTexto("Error, escoja una opci?n v?lida.", 23);
				break;
		}

//		getchar();
		
	} while (eOpcion != 6);
	
}
