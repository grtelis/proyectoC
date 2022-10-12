/*
	Programa: MenuCategoria.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. López Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Mostrar el menú de almacén de la heladería HEL-ARTE.
*/

// Archivos de funciones
#include "Categorias.c"

void MenuCategorias () {
	
	//variables locales
	int eOpcion;
	
		//Menú
	do {
		
		system("cls");
		
		MargenPantalla();
		MargenMenu ();
		
		gotoxy(2, 23);
		printf("Mensajes del sistema: ");
		
		CentrarTexto("MENÚ DE CATEGORIA", 2);
		
		gotoxy(2, 8);
		printf("1. Registrar una Categoría");
		
		gotoxy(2, 10);
		printf("2. Borrar una Categoria");
		
		gotoxy(2, 12);
		printf("3. Modificar una Categoria");
		
		gotoxy(2, 14);
		printf("4. Listado de Todas las Categorias");
		
		gotoxy(2, 16);
		printf("5. Salir");
		
		gotoxy(2, 20);
		printf ("Ingrese una opción: ");
		scanf("%d", &eOpcion);
		
		switch(eOpcion) {
			
			case 1: RegistrarCategoria();
				break;
			case 2: BorrarCategoria();
				break;
			case 3: ModificarCategoria();
				break;
			case 4: ListarTodasLasCategorias();
				break;
			case 5: CentrarTexto("Adiós. :)", 23);
				break;
			default: CentrarTexto ("Error, escoja una opción válida.", 23);
				break;
		}
		
	getchar();
	
	} while (eOpcion != 5);
	
}
