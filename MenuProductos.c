/*
	Programa: MenuProductos.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. L�pez Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Mostrar el men� de productos de la helader�a HEL-ARTE.
*/

// Archivos de funciones
//#include "Almacen.c"
#include "Productos.c"

TrLista MenuProductos (TrListaArticulos rListaArticulos) {
	
	//variables locales
	int eOpcion, eIdProducto, eResultado, ePosY;
	TcCadena sIdProducto;
	TrProducto rProducto;
	TpProducto pPrimero, pConsulta;
	TrLista rLista;
	
	//Inicializaci�n de los apuntadores
	rLista.pPrimero = NULL;
	rLista.pUltimo = NULL;
	
	//Men�
	do {
		
		system("cls");
		
		MargenPantalla();
		MargenMenu ();
		
		MensajesDelSistema ();
		
		CentrarTexto("MEN� DE PRODUCTOS", 2);
		gotoxy(2, 6);
		printf("1. Registrar un producto", 4);
		gotoxy(2, 8);
		printf("2. Borrar un producto", 5);
		gotoxy(2, 10);
		printf("3. Modificar datos de un producto", 6);
		gotoxy(2, 12);
		printf("4. Consultar un producto por identificador �nico");
		gotoxy(2, 14);
		printf("5. Listar productos por categor�a");
		gotoxy(2, 16);
		printf("6. Listado de todos los productos");
		gotoxy(2, 18);
		printf("7. Salir");
		
		gotoxy(2, 20);
		printf ("Ingrese una opci�n: ");
		scanf("%d", &eOpcion);
		
		switch(eOpcion) {
			
			case 1: rProducto = LeerProducto (&rLista, &rListaArticulos);
					break;
				
			case 2: InterfazBorrarProducto ();
					eIdProducto = LeerIDProducto ();
					BorrarProducto (&rLista, eIdProducto, 1);
					break;
				
			case 3: InterfazModificarProductoUno ();
					eIdProducto = LeerIDProducto ();
					rProducto = ModificarProducto(rLista, eIdProducto);
					break;
					
			case 4: InterfazConsultarProducto ();
					eIdProducto = LeerIDProducto ();
				    ConsultarProducto(rLista, eIdProducto);
					break;
					
			case 5: InterfazProductosPorCategoria ();
					ListarProductosPorCategoria(rLista);
					break;
					
			case 6: InterfazListarTodosLosProductos ();
					ePosY = -2;
					ListarTodosLosProductos(rLista.pPrimero, ePosY);
					break;
					
			case 7: CentrarTexto ("Adi�s. :)", 23);
					break;
					
			default: CentrarTexto ("Error, escoja una opci�n v�lida.", 23);
					break;
		}
		
		getchar();
	
	} while (eOpcion != 7);
	
	return rLista;
}
