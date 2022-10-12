/*
	Programa: Categorias.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. López Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Realizar todas las operaciones correspondientes de la heladería HEL-ARTE.
*/

// Procedimientos y funciones
void RegistrarCategoria ();
void ModificarCategoria ();
void BorrarCategoria ();
void ListarTodasLasCategorias();

void RegistrarCategoria () {
	
	system("cls");
	MargenPantalla ();
	LineaHorizontal (4);
	LineaHorizontal (22);
	LineaVertical (43, 3);
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	CentrarTexto("REGISTRO DE ARTÍCULOS", 2);
	CentrarTextoEnCuadroChicoIzquierdo("Nombre de la categoria: ", 12);
	CentrarTextoEnCuadroChicoDerecho ("ID de la categoría registrada: ", 12);

	getchar();
	
}

void ModificarCategoria (){
	
	system("cls");
	MargenPantalla ();
	MargenConDosCuadros ();
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	CentrarTexto("MODIFICAR DATOS DE UNA CATEGORIA", 2);
	CentrarTexto("ID de la categoria: ", 5);
	
	CentrarTextoEnCuadroChicoIzquierdo ("--Datos de la categoria-- ", 11);
	CentrarTextoEnCuadroChicoIzquierdo ("ID: ", 14);
	CentrarTextoEnCuadroChicoIzquierdo ("Nombre de la categoria: ", 17);
	
	MitadDeLineaHorizontalDerecha ();
	
	CentrarTextoEnCuadroChicoDerecho ("¿ Desea modificar los dato de ", 10);
	CentrarTextoEnCuadroChicoDerecho ("este producto?[S/N] ", 11);
	
	CentrarTextoEnCuadroChicoDerecho ("Escriba la informacion nueva: ", 17);
	
	fflush(stdin);
	getchar();
}

void BorrarCategoria () {

	system("cls");
	MargenPantalla ();
	MargenConDosCuadros ();
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	CentrarTexto("BORRAR CATEGORIA", 2);
	CentrarTexto("ID de la categoria: ", 5);
	
	CentrarTextoEnCuadroChicoIzquierdo ("--Datos de la categoria-- ", 11);
	CentrarTextoEnCuadroChicoIzquierdo ("ID: ", 14);
	CentrarTextoEnCuadroChicoIzquierdo ("Nombre de la categoria: ", 17);
	
	CentrarTextoEnCuadroChicoDerecho ("¿Desea borrar esta categoria?", 14);
	CentrarTextoEnCuadroChicoDerecho ("[S/N]", 15);
	
	getchar();
	

}

void ListarTodasLasCategorias(){
	
	system("cls");
	MargenPantalla();
	
	CentrarTexto ("LISTADO DE TODOS TODAS LAS CATEGORIAS", 2);
	LineaHorizontal (4);
	
	LineaHorizontal (22);
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	gotoxy(2, 5);
	printf ("ID ! Categoria ! ID ! Categoria ! ID ! Categoria ! ID ! Categoria ! ID ! Categoria");
	LineaHorizontal (6);
	
	LineaVertical (5,2);
	LineaVertical (17,2);
	LineaVertical (22,2);
	LineaVertical (34,2);
	LineaVertical (39,2);
	LineaVertical (51,2);
	LineaVertical (56,2);
	LineaVertical (68,2);
	LineaVertical (73,2);
	
	getchar();
}
