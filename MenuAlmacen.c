/*
	Programa: MenuAlmacen.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. L�pez Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Mostrar el men� de almac�n de la helader�a HEL-ARTE.
*/

// Archivos de funciones
//#include "Almacen.c"

void MenuAlmacen () {
	
	//variables locales
	int eOpcion, eIdArticulo, eResultado;
	TcCadena sIdArticulo;
	TrArticulo rArticulo;
	TpProducto pPrimero, pConsulta;
	TrListaArticulos rListaArticulos;
	
	//Inicializaci�n de los apuntadores
	rListaArticulos.pPrimero = NULL;
	rListaArticulos.pUltimo = NULL;
	
	//Men�
	do {
		
		system("cls");
		
		MargenPantalla();
		MargenMenu ();
		
		gotoxy(2, 23);
		printf("Mensajes del sistema: ");
		
		CentrarTexto("MEN� DE ALMAC�N", 2);
		gotoxy(2, 6);
		printf("1. Registrar un art�culo");
		gotoxy(2, 8);
		printf("2. Borrar un art�culo");
		gotoxy(2, 10);
		printf("3. Modificar un art�culo");
		gotoxy(2, 12);
		printf("4. Consultar un art�culo por identificador �nico");
		gotoxy(2, 14);
		printf("5. Listado de art�culos por categor�a");
		gotoxy(2, 16);
		printf("6. Listado de todos los art�culos");
		gotoxy(2, 18);
		printf("7. Salir");
		
		gotoxy(2, 20);
		printf ("Ingrese una opci�n: ");
		scanf("%d", &eOpcion);
		
		switch(eOpcion) {
			
			case 1: rArticulo = LeerArticulo (rListaArticulos);
					RegistrarArticulo(&rListaArticulos, &rArticulo);
					break;
				
			case 2: InterfazBorrarArticulo ();
					eIdArticulo = LeerIDArticulo ();
					BorrarArticulo (&rListaArticulos, eIdArticulo, 1);
					break;
				
			case 3: InterfazModificarArticuloUno ();
					eIdArticulo = LeerIDArticulo ();
					rArticulo = ModificarArticulo(rListaArticulos, eIdArticulo);
					break;
					
			case 4: InterfazConsultarArticulo ();
					eIdArticulo = LeerIDArticulo ();
					ConsultarArticulo(rListaArticulos, eIdArticulo);
					break;
					
			case 5: InterfazArticulosPorCategoria ();
					ListarArticulosPorCategoria(rListaArticulos);
					break;
					
			case 6: InterfazListarTodosLosArticulos ();
					ListarTodosLosArticulos(rListaArticulos.pPrimero);
					break;
					
			case 7: CentrarTexto("Adi�s. :)", 23);
				break;
				
			default: CentrarTexto ("Error, escoja una opci�n v�lida.", 23);
				break;
		}
		
		getchar();
	
	} while (eOpcion != 7);
	
}
