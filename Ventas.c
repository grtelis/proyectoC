/*
	Programa: Ventas.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. López Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Realizar todas las operaciones correspondientes de la heladería HEL-ARTE.
*/

// Procedimientos y funciones
void RegistrarVenta ();
void CancelarVenta ();
void ConsultarVenta ();
void ListarVentasDeUnProducto ();
void ListarVentasEnUnPeriodo ();
void ListarVentas ();

void RegistrarVenta () {
	
	system("cls");
	MargenPantalla ();
	MargenConDosCuadros ();
	MitadDeLineaHorizontalDerecha ();
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	CentrarTexto("REGISTRO DE VENTA", 2);
	CentrarTexto("Nombre del producto: ", 5);
	
	CentrarTextoEnCuadroChicoIzquierdo ("Cantidad vendida: ", 10);
	CentrarTextoEnCuadroChicoIzquierdo ("Importe: ", 14);
	CentrarTextoEnCuadroChicoIzquierdo ("Fecha (dd/mm/aaaa):   /  /    ", 17);
	CentrarTextoEnCuadroChicoDerecho ("ID de la venta: ", 10);
	CentrarTextoEnCuadroChicoDerecho ("Total de venta: ", 18);
	
	getchar();
}

void CancelarVenta () {
	
    system("cls");
	MargenPantalla ();
	MargenConDosCuadros ();
	MitadDeLineaHorizontalDerecha ();
	
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	CentrarTexto("CANCELAR VENTA", 2);
	CentrarTexto("ID de la venta: ", 5);
	
	CentrarTextoEnCuadroChicoIzquierdo ("-Datos de la venta-: ", 7);
	CentrarTextoEnCuadroChicoIzquierdo ("ID de la venta: ", 10);
	CentrarTextoEnCuadroChicoIzquierdo ("Numero de productos: ", 12);
	CentrarTextoEnCuadroChicoIzquierdo ("Total de venta: ", 14);
	CentrarTextoEnCuadroChicoIzquierdo ("Cantidad pagada: ", 16);
	CentrarTextoEnCuadroChicoIzquierdo ("Cantidad pagada: ", 18);
	CentrarTextoEnCuadroChicoIzquierdo ("Fecha (dd/mm/aaaa):   /  /    ", 20);
	
	CentrarTextoEnCuadroChicoDerecho ("¿Desea cancelar este producto? [S/N]: ", 10);
	CentrarTextoEnCuadroChicoDerecho ("Motivo de cancelacion: ", 18);
	
	getchar();
	
}

void ConsultarVenta () {
	
	system("cls");
	MargenPantalla ();
	
	CentrarTexto("CONSULTAR VENTA", 2);
	LineaHorizontal (4);
	CentrarTexto("ID de la venta: ", 5);
	LineaHorizontal (6);
		
	CentrarTexto ("-Datos de la venta-: ", 8);
	
	CentrarTexto ("ID: ", 10);
	
	CentrarTexto ("Numero de productos", 12);
	
	CentrarTexto ("Total de venta: ", 14);
	
	CentrarTexto ("Cantidad pagada: ", 16);
	
	CentrarTexto ("Cambio:", 18);
	
	CentrarTexto ("Fecha (dd/mm/aaaa):   /  /    ", 20);	

	LineaHorizontal (22);
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	
	getchar();
	
}

void ListarVentasDeUnProducto () {
	
	system("cls");
	MargenPantalla ();
	
	CentrarTexto("LISTADO DE TODAS LAS VENTAS DE UN PRODUCTO", 2);
	LineaHorizontal (4);
	CentrarTexto("ID del producto: ", 5);
	LineaHorizontal (6);
	
	LineaHorizontal (8);
	
	gotoxy (1,7);
	printf (" ID !      Producto      !# Productos!Precio!Cantidad vendida!Importe!Total!  Fecha  ");
	
	LineaHorizontal (22);
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	LineaVertical (5,1);
	LineaVertical (26,1);
	LineaVertical (38,1);
	LineaVertical (45,1);
	LineaVertical (62,1);
	LineaVertical (70,1);
	LineaVertical (76,1);
	
	getchar();
}

void ListarVentasEnUnPeriodo () {
	
	system("cls");
	MargenPantalla ();
	
	CentrarTexto("LISTADO DE TODAS LAS VENTAS EN UN PERIODO DE TIEMPO", 2);
	LineaHorizontal (4);
	CentrarTextoEnCuadroChicoIzquierdo ("Fecha inicial (dd/mm/aaaa): ",5);
	CentrarTextoEnCuadroChicoDerecho ("Fecha inicial (dd/mm/aaaa): ",5);
	
	LineaHorizontal (6);
	LineaHorizontal (8);
	
	gotoxy (1,7);
	printf (" ID !    # Productos     ! Total de venta ! Cantidad Pagada ! Cambio !     Fecha  ");	

	LineaHorizontal (22);
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	LineaVertical (5,1);
	LineaVertical (26,1);
	LineaVertical (43,1);
	LineaVertical (61,1);
	LineaVertical (70,1);
	
	gotoxy(43, 4);
	printf("%c", 194);
	gotoxy(43, 5);
	printf("%c", 179);
	gotoxy(43, 6);
	printf("%c", 197);
	
	getchar();
}

void ListarVentas () {
	
	system("cls");
	MargenPantalla ();
	
	CentrarTexto("LISTADO DE TODAS LAS VENTAS", 2);
	LineaHorizontal (4);
	gotoxy (1,5);
	printf (" ID !    # Productos     ! Total de venta ! Cantidad Pagada ! Cambio !     Fecha  ");
	LineaHorizontal (6);

	LineaHorizontal (22);
	gotoxy(2, 23);
	printf("Mensajes del sistema: ");
	
	LineaVertical (5,2);
	LineaVertical (26,2);
	LineaVertical (43,2);
	LineaVertical (61,2);
	LineaVertical (70,2);
	
	getchar();
}
