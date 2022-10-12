/*
	Programa: MenuCompras.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. López Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Mostrar el menú de compras de la heladería HEL-ARTE.
*/

// Archivos de funciones
#include "Compras.c"

void MenuCompras () {
	
	//variables locales
	int eOpcion;
	
		//Menú
	do {
		
		system("cls");
		
		MargenPantalla();
		MargenMenu ();
		
		gotoxy(2, 23);
		printf("Mensajes del sistema: ");
		
		CentrarTexto("MENÚ DE COMPRAS", 2);
		gotoxy(2, 6);
		printf("1. Registrar una compra");
		gotoxy(2, 8);
		printf("2. Cancelar una compra");
		gotoxy(2, 10);
		printf("3. Consultar una compra por identificador único");
		gotoxy(2, 12);
		printf("4. Listar todas las compras de un artículo");
		gotoxy(2, 14);
		printf("5. Listar las compras en un periodo de tiempo");
		gotoxy(2, 16);
		printf("6. Listado de todas las compras");
		gotoxy(2, 18);
		printf("7. Salir");
		
		gotoxy(2, 20);
		printf ("Ingrese una opción: ");
		scanf("%d", &eOpcion);
		
		switch(eOpcion) {
			
			case 1: RegistrarCompra();
				break;
			case 2: CancelarCompra();
				break;
			case 3: ConsultarCompra();
				break;
			case 4: ListarComprasDeUnArticulo();
				break;
			case 5: ListarComprasEnUnPeriodo();
				break;
			case 6: ListarCompras();
				break;
			case 7: CentrarTexto("Adiós. :)", 23);
				break;
			default: CentrarTexto("Error, escoja una opción válida.", 23);
				break;
		}
		
	getchar();
	
	} while (eOpcion != 7);
	
}
