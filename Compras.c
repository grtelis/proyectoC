/*
	Programa: Compras.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. López Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Realizar todas las operaciones correspondientes de la heladería HEL-ARTE.
*/

// Procedimientos y funciones
void RegistrarCompra ();
void CancelarCompra ();
void ConsultarCompra ();
void ListarComprasDeUnArticulo ();
void ListarComprasEnUnPeriodo ();
void ListarCompras ();

void RegistrarCompra () {
	
	system("cls");
	MargenPantalla ();
	MargenConDosCuadros ();
	MitadDeLineaHorizontalDerecha ();
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	CentrarTexto("REGISTRO DE COMPRA", 2);
	CentrarTexto("ID del artículo comprado: ", 5);
	
	CentrarTextoEnCuadroChicoIzquierdo ("Cantidad comprada del artículo: ", 8);
	CentrarTextoEnCuadroChicoIzquierdo ("Costo unitario del artículo:", 10);
	CentrarTextoEnCuadroChicoIzquierdo ("Proveedor: ", 12);
	CentrarTextoEnCuadroChicoIzquierdo ("Compra antes de impuestos: ", 14);
	CentrarTextoEnCuadroChicoIzquierdo ("Impuesto de la compra (opcional): ", 16);
	CentrarTextoEnCuadroChicoIzquierdo ("Fecha (dd/mm/aaaa):   /  /    ", 18);
	CentrarTextoEnCuadroChicoDerecho ("Total de compra:", 10);
	CentrarTextoEnCuadroChicoDerecho ("ID de la compra:", 18);
	
	getchar ();
}

void CancelarCompra () {
	
	system("cls");
	MargenPantalla ();
	MargenConDosCuadros ();
	MitadDeLineaHorizontalDerecha ();
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	CentrarTexto("CANCELAR COMPRA", 2);
	CentrarTexto("ID de la compra: ", 5);
	
	CentrarTextoEnCuadroChicoIzquierdo ("- Datos de la compra - ", 8);
	CentrarTextoEnCuadroChicoIzquierdo ("ID de la compra:", 12);
	CentrarTextoEnCuadroChicoIzquierdo ("Número de productos: ", 14);
	CentrarTextoEnCuadroChicoIzquierdo ("Total de la compra: ", 16);
	CentrarTextoEnCuadroChicoIzquierdo ("Fecha (dd/mm/aaaa):   /  /    ", 18);
	
	CentrarTextoEnCuadroChicoDerecho ("¿Desea cancelar esta compra [S/N]?: ", 10);
	CentrarTextoEnCuadroChicoDerecho ("Motivo de la cancelación: ", 18);
	
	getchar();
}

void ConsultarCompra () {
	
	system("cls");
	MargenPantalla ();
	CentrarTexto("CONSULTAR COMPRA", 2);
	LineaHorizontal (4);
	CentrarTexto("ID de la compra: ", 5);
	LineaHorizontal (6);
	LineaHorizontal (22);
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	CentrarTexto("- Datos de la compra -", 8);
	CentrarTexto("ID de la compra: ", 12);
	CentrarTexto("Número de productos: ", 14);
	CentrarTexto("Total de la compra: ", 16);
	CentrarTexto("Fecha:   /  /    ", 18);
	
	getchar();
}

void ListarComprasDeUnArticulo () {
	
	system("cls");
	MargenPantalla ();
	CentrarTexto("LISTADO DE TODAS LAS COMPRAS DE UN ARTÍCULO", 2);
	LineaHorizontal (4);
	CentrarTexto("ID del artículo: ", 5);
	LineaHorizontal (6);
	LineaHorizontal (8);
	LineaHorizontal (22);
	
	gotoxy (2, 7);
	printf ("ID        Artículo         Costo Cantidad  Proveedor   C.A.I  Impuesto Total  Fecha ");
	
	LineaVertical (5, 1);
	LineaVertical (28, 1);
	LineaVertical (34, 1);
	LineaVertical (43, 1);
	LineaVertical (55, 1);
	LineaVertical (63, 1);
	LineaVertical (72, 1);
	LineaVertical (78, 1);
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	gotoxy(4, 25);
	printf("C.A.I: Compra Antes de Impuestos");
	
	getchar();
}

void ListarComprasEnUnPeriodo () {
	
	system("cls");
	MargenPantalla ();
	CentrarTexto("LISTADO DE TODAS LAS COMPRAS DE UN ARTÍCULO EN UN PERIODO DE TIEMPO", 2);
	LineaHorizontal (4);
	LineaHorizontal (8);
	
	
	CentrarTextoEnCuadroChicoIzquierdo("Fecha inicial (dd/mm/aaaa): ", 5);
	CentrarTextoEnCuadroChicoDerecho ("Fecha final (dd/mm/aaaa): ", 5);
	
	gotoxy (2, 7);
	printf ("ID de la compra     Número de productos      Totalde compra             Fecha");
	
	MargenConDosCuadros ();
	MitadDeLineaVertical ();
	LineaVertical (20, 1);
	LineaVertical (65, 1);
	
	gotoxy (43, 8);
	printf ("%c", 197);
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	gotoxy(4, 25);
	printf("C.A.I: Compra Antes de Impuestos");
	
	getchar();
}

void ListarCompras () {
	
	system("cls");
	MargenPantalla ();
	CentrarTexto("LISTADO DE TODAS LAS COMPRAS", 2);
	LineaHorizontal (4);
	LineaHorizontal (6);
	LineaHorizontal (22);
	
	gotoxy (2, 5);
	printf (" ID de la compra    Número de productos    Total de la compra           Fecha   ");
	
	LineaVertical (20, 2);
	LineaVertical (43, 2);
	LineaVertical (65, 2);
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	getchar();
}
