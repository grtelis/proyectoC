/*
	Programa: heladeria.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. López Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Mostrar el menú principal de la heladería HEL-ARTE.
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

//Función principal
int main (void) {
	
	//variables locales
	TrRegistroDeListas rRegistroDeListas;
	int eOpcion;
	
//	Logo();
	//Menú
	do {
		
		system("cls");
		
		MargenPantalla ();
		MargenMenu ();
		MensajesDelSistema ();
		
		CentrarTexto("HELADERÍA HEL-ARTE", 2);
		gotoxy(2, 6);
		printf("1. Menú de productos");
		gotoxy(2, 8);
		printf("2. Menú de ventas");
		gotoxy(2, 10);
		printf("3. Menú de compras");
		gotoxy(2, 12);
		printf("4. Menú de almacén");
		gotoxy(2, 14);
		printf("5. Menu de categorias");
		gotoxy(2, 16);
		printf("6. Salir");
			
		gotoxy(2, 20);
		printf("Ingrese una opción: ");	
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
			case 6: CentrarTexto("Adiós.", 23);
				break;
			default: CentrarTexto("Error, escoja una opción válida.", 23);
				break;
		}

//		getchar();
		
	} while (eOpcion != 6);
	
}
