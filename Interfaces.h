/*
	Programa: Interfaces.h
	Autores:
		1. Guerrero Torres Elizabeth
		2. L�pez Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Mostrar el men� principal de la helader�a HEL-ARTE.
*/

//Header
#include "FuncionesPantalla.h"

//Prototipos
//Procedimientos
void InterfazDeRegistrarProducto ();
void InterfazBorrarProducto ();
void InterfazProductosPorCategoria ();
void InterfazListarTodosLosProductos ();
void InterfazDeRegistrarArticulo ();
void InterfazBorrarArticulo ();
void InterfazModificarArticuloUno ();
void InterfazModificarArticuloDos ();
void LimpiarMensajesDelSistema ();
void SinElementos ();
void LaListaEstaLlena ();
void MensajesDelSistema ();

void LimpiarMensajesDelSistema () {
	
	gotoxy (4, 24);
	printf ("                                                                                  ");
	gotoxy (4, 25);
	printf ("                                                                                  ");
	
}

void InterfazDeRegistrarProducto () {
	
	CentrarTexto("REGISTRO DE PRODUCTOS", 2);
	CentrarTexto("Nombre del producto: ", 5);
	CentrarTextoEnCuadroChicoIzquierdo("ID de la categoria: ", 10);
	CentrarTextoEnCuadroChicoIzquierdo("ID del art�culo que consume: ", 12);
	CentrarTextoEnCuadroChicoIzquierdo("Precio: ", 15);
	CentrarTextoEnCuadroChicoIzquierdo("Costo: ", 17);
}

void InterfazConsultarProducto () {
	
	system("cls");
	
	MargenPantalla ();
	MensajesDelSistema ();

	CentrarTexto("CONSULTAR PRODUCTO", 2);
	LineaHorizontal (4);
	CentrarTexto("ID del producto: ", 5);
	LineaHorizontal (6);
	CentrarTexto ("-Datos del producto-", 7);
	
	CentrarTexto ("ID: ", 9);
	CentrarTexto ("Nombre del producto: ", 11);
	CentrarTexto ("Precio: ", 13);
	CentrarTexto ("Costo: ", 15);
	CentrarTexto ("Categoria: ", 17);
	CentrarTexto ("ID de los art�culos necesarios", 19);
	CentrarTexto ("para elaborar el producto: ", 20);
	LineaHorizontal (22);
	
	getchar ();
}

void InterfazBorrarProducto () {
	
	system ("cls");
	
	MargenPantalla ();
	MargenConDosCuadros ();
	MensajesDelSistema ();

	CentrarTexto("BORRAR PRODUCTO", 2);
	CentrarTexto("ID del producto: ", 5);

	CentrarTextoEnCuadroChicoIzquierdo ("-Datos del producto-", 8);
	CentrarTextoEnCuadroChicoIzquierdo ("ID: ", 10);
	CentrarTextoEnCuadroChicoIzquierdo ("Producto: ", 12);
	CentrarTextoEnCuadroChicoIzquierdo ("Precio: ", 14);
	CentrarTextoEnCuadroChicoIzquierdo ("Costo: ", 16);
	CentrarTextoEnCuadroChicoIzquierdo ("Categoria: ", 18);
	CentrarTextoEnCuadroChicoIzquierdo ("Art�culos necesarios para", 20);
	CentrarTextoEnCuadroChicoIzquierdo ("elaborar el producto: ", 21);
	
	getchar ();
}

void InterfazModificarProductoUno () {
	
	system("cls");
	
	MargenPantalla ();
	MargenConDosCuadros ();
	MensajesDelSistema ();

	CentrarTexto("MODIFICAR DATOS DE UN PRODUCTO", 2);
	CentrarTexto("ID del producto: ", 5);

	CentrarTextoEnCuadroChicoIzquierdo ("-Datos del producto-", 8);
	CentrarTextoEnCuadroChicoIzquierdo ("ID: ", 10);
	CentrarTextoEnCuadroChicoIzquierdo ("Producto: ", 12);
	CentrarTextoEnCuadroChicoIzquierdo ("Categoria: ", 14);
	CentrarTextoEnCuadroChicoIzquierdo ("Precio: ", 16);
	CentrarTextoEnCuadroChicoIzquierdo ("Costo: ", 18);
	CentrarTextoEnCuadroChicoIzquierdo ("Art�culos necesarios para", 20);
	CentrarTextoEnCuadroChicoIzquierdo ("elaborar el producto: ", 21);
	
	getchar();
}

void InterfazModificarProductoDos () {
	
	system("cls");
	
	MargenPantalla ();
	MargenConDosCuadros ();
	MensajesDelSistema ();
	
	CentrarTexto("MODIFICAR DATOS DE UN PRODUCTO", 2);
	CentrarTexto("�Que dato desea modificar?: ", 5);

	gotoxy(2, 10);
	printf("1. Nombre");
	
	gotoxy(2, 12);
	printf("2. Categoria");
	
	gotoxy(2, 14);
	printf("3. Precio");
	
	gotoxy(2, 16);
	printf("4. Costo");
	
	gotoxy(2, 17);
	printf("5. Art�culos necesarios para elaborar el");
	gotoxy(2, 19);
	printf("   producto");
	
	gotoxy (2, 21);
	printf ("6. Salir");

	CentrarTextoEnCuadroChicoDerecho ("Escriba la nueva informaci�n:", 10);
	MitadDeLineaHorizontalDerecha ();
	
	fflush (stdin);
	
	getchar();
}

void InterfazProductosPorCategoria () {
	
	CentrarTexto("LISTADO DE PRODUCTOS POR CATEGORIA", 2);
	LineaHorizontal (4);
	CentrarTexto("ID de la categoria: ", 5);
	LineaHorizontal (6);
	
	LineaHorizontal (8);
	
	gotoxy (1,7);
	printf (" ID !       Producto             Precio       Costo        ID Categor�a      A.N.E.L");
	          
	
	LineaHorizontal (22);
	MensajesDelSistema ();
	gotoxy(4, 25);
    printf("A.N.E.L: Articulos necesarios para elaborar el producto");
	
	
	LineaVertical (5,1);
	LineaVertical (30,1);
	LineaVertical (43,1);
	LineaVertical (55,1);
	LineaVertical (75,1);
	
}

void InterfazListarTodosLosProductos () {
	
	system("cls");
	
	MargenPantalla ();
	CentrarTexto("LISTADO DE TODOS LOS PRODUCTOS", 2);
	LineaHorizontal (4);
	gotoxy (1, 5);
	printf (" ID !       Producto             Precio       Costo        ID Categor�a      A.N.E.L");
	LineaHorizontal (6);
	
	LineaHorizontal (22);
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	gotoxy(4, 25);
    printf("A.N.E.L: Articulos necesarios para elaborar el producto");
	
	
	LineaVertical (5, 2);
	LineaVertical (30, 2);
	LineaVertical (43, 2);
	LineaVertical (55, 2);
	LineaVertical (75, 2);
	
	getchar ();
}

void InterfazDeRegistrarArticulo () {
	
	CentrarTexto("REGISTRO DE ART�CULOS", 2);
	CentrarTextoEnCuadroChicoIzquierdo("Nombre del art�culo: ", 5);
	CentrarTextoEnCuadroChicoDerecho ("ID de la categor�a: ", 5);
	
	CentrarTextoEnCuadroChicoIzquierdo ("Existencias m�nimas: ", 11);
	CentrarTextoEnCuadroChicoIzquierdo ("Existencias m�ximas: ", 13);
	CentrarTextoEnCuadroChicoIzquierdo ("Cantidad en existencias: ", 15);
	
//	CentrarTextoEnCuadroChicoDerecho ("El ID del art�culo es : ", 13);
	
}

void InterfazBorrarArticulo () {
	
	system("cls");
	
	MargenPantalla ();
	MargenConDosCuadros ();
	MensajesDelSistema ();
	
	CentrarTexto("BORRAR ART�CULO", 2);
	CentrarTexto("ID del art�culo", 5);
	
	CentrarTextoEnCuadroChicoIzquierdo ("- Datos del art�culo -", 8);
	CentrarTextoEnCuadroChicoIzquierdo ("ID: ", 10);
	CentrarTextoEnCuadroChicoIzquierdo ("Art�culo: ", 12);
	CentrarTextoEnCuadroChicoIzquierdo ("Categoria: ", 14);
	CentrarTextoEnCuadroChicoIzquierdo ("Existencias m�nimas: ", 16);
	CentrarTextoEnCuadroChicoIzquierdo ("Existencias m�ximas: ", 18);
	CentrarTextoEnCuadroChicoIzquierdo ("Cantidad en existencias: ", 20);

	getchar ();
}

void InterfazModificarArticuloUno () {
	
	system("cls");
	MargenPantalla ();
	MargenConDosCuadros ();
	MensajesDelSistema ();
	
	CentrarTexto("MODIFICAR ARTICULO", 2);
	CentrarTexto("ID del articulo: ", 5);
	
	CentrarTextoEnCuadroChicoIzquierdo ("- Datos del articulo -: ", 8);
	CentrarTextoEnCuadroChicoIzquierdo ("ID: ", 10);
	CentrarTextoEnCuadroChicoIzquierdo ("Articulo: ", 12);
	CentrarTextoEnCuadroChicoIzquierdo ("Categor�a: ", 14);
	CentrarTextoEnCuadroChicoIzquierdo ("Existencias m�nimas: ", 16);
	CentrarTextoEnCuadroChicoIzquierdo ("Existencias m�ximas: ", 18);
	CentrarTextoEnCuadroChicoIzquierdo ("Cantidad en existencias: ", 20);
	
	getchar();
	
}

void InterfazModificarArticuloDos () {

	system("cls");
	MargenPantalla ();
	MargenConDosCuadros ();
	MitadDeLineaHorizontalDerecha ();
	
	MensajesDelSistema ();
	
	CentrarTexto("MODIFICAR DATOS DE UN ARTICULO", 2);
	CentrarTexto("�Qu� dato desea modificar?", 5);
	
	gotoxy (2, 10);
	printf ("1. Nombre del art�culo: ");
	gotoxy (2, 12);
	printf ("2. Categoria: ");
	gotoxy (2, 14);
	printf ("3. Existencias m�nimas: ");
	gotoxy (2, 16);
	printf ("4. Existencias m�ximas: ");
	gotoxy (2, 18);
	printf ("5. Salir ");
	
	CentrarTextoEnCuadroChicoDerecho ("Escriba la informaci�n nueva: ", 10);
	
	getchar();
	
}

void InterfazConsultarArticulo () {
	
	system("cls");
	MargenPantalla ();
	
	MensajesDelSistema ();
	
	CentrarTexto("CONSULTAR ART�CULO", 2);
	LineaHorizontal (4);
	CentrarTexto("ID del art�culo: ", 5);
	LineaHorizontal (6);
	
	CentrarTexto ("-Datos del art�culo-", 8);
	CentrarTexto ("ID: ", 10);
	CentrarTexto ("Art�culo: ", 12);
	CentrarTexto ("Categor�a: ", 14);
	CentrarTexto ("Existencias minimas: ", 16);
	CentrarTexto ("Existencias m�ximas: ", 18);
	CentrarTexto ("Cantidad en existencias: ", 20);
	LineaHorizontal (22);
	
	getchar();
}

void InterfazArticulosPorCategoria () {
	
//	system("cls");
	MargenPantalla();
	CentrarTexto ("LISTADO DE ART�CULOS POR CATEGORIA", 2);
	LineaHorizontal (4);
	CentrarTexto ("ID de la categor�a", 5);
	LineaHorizontal (6);
	
	LineaHorizontal (8);
	gotoxy(2, 7);
	printf (" ID             Art�culo        Categoria  E. m�nimas   E. m�ximas     Existencias");
	
	LineaHorizontal (22);
	MensajesDelSistema ();
	
	LineaVertical (7, 1);
	LineaVertical (33, 1);
	LineaVertical (43, 1);
	LineaVertical (57, 1);
	LineaVertical (72, 1);
	
//	getchar();
	
}

void InterfazListarTodosLosArticulos () {
	
	system("cls");
	MargenPantalla();
	
	CentrarTexto ("LISTADO DE TODOS LOS ART�CULOS ", 2);
	LineaHorizontal (4);
	LineaHorizontal (22);
	
	gotoxy(2, 5);
	printf ("ID    Art�culo   Categoria    Existencias    E. m�nimas    E. m�ximas");
	
	LineaHorizontal (6);
	LineaVertical (6, 2);
	LineaVertical (17, 2);
	LineaVertical (29, 2);
	LineaVertical (43, 2);
	LineaVertical (73, 2);
	
	MensajesDelSistema ();
	
	getchar();
}

void SinElementos () {
	
	gotoxy (4, 24);
	printf("No hay elementos en la lista.");
	gotoxy (4, 25);
	printf("                                                        ");
	gotoxy (4, 25);
	printf("Presione enter para salir.");
}

void LaListaEstaLlena () {
	
	gotoxy (4, 24);
	printf("La lista est� llena.");
	gotoxy (4, 25);
	printf("                                                        ");
	gotoxy (4, 25);
	printf("Presione enter para salir.");
}

void MensajesDelSistema () {
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
}

