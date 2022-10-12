/*
	Programa: FuncionesPantalla.h
	Autores:
		1. Guerrero Torres Elizabeth
		2. López Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Mostrar el menú principal de la heladería HEL-ARTE.
*/

#ifndef _FUNCIONESPANTALLA_H
#define _FUNCIONESPANTALLA_H

#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void gotoxy (int, int);
void MargenPantalla ();
void MargenMenu ();
void MargenConDosCuadros ();
void MitadDeLineaHorizontalDerecha ();
void MitadDeLineaVertical ();
void LineaHorizontal (int);
void LineaVertical (int, int);
void CentrarTexto (char *, int);
void CentrarTextoEnCuadroChicoIzquierdo (char *, int);
void CentrarTextoEnCuadroChicoDerecho (char *, int);
int LimpiarPantalla (int);

void gotoxy (int x, int y) {
	
	HANDLE salidaVentana;
	COORD coordenadas;
	
	salidaVentana = GetStdHandle(STD_OUTPUT_HANDLE);
	coordenadas.X = x;
	coordenadas.Y = y;
	
	SetConsoleCursorPosition (salidaVentana, coordenadas);
}

void MargenPantalla () {
	
	int eRenglones, eColumnas;
	
	for (eRenglones = 1; eRenglones <= 85; eRenglones ++) {
		
		gotoxy (eRenglones, 0);
		printf ("%c", 196);
		
		gotoxy (eRenglones, 26);
		printf ("%c", 196);
	}
	
	for (eColumnas = 1; eColumnas < 26; eColumnas ++) {
		
		gotoxy (0, eColumnas);
		printf ("%c", 179);
		
		gotoxy (86, eColumnas);
		printf ("%c", 179);
	}
	
	gotoxy (0, 0);
	printf ("%c", 218);
	
	gotoxy (0, 26);
	printf ("%c", 192);
	
	gotoxy (86, 26);
	printf ("%c", 217);
	
	gotoxy (86, 0);
	printf ("%c", 191);
	
}

void MargenMenu () {
	
	int eRenglones;
	
	for (eRenglones = 1; eRenglones <= 85; eRenglones ++) {
		
		gotoxy (eRenglones, 4);
		printf ("%c", 196);
		
		gotoxy (eRenglones, 19);
		printf ("%c", 196);
		
		gotoxy (eRenglones, 21);
		printf ("%c", 196);
	}
	
	gotoxy (0, 4);
	printf ("%c", 195);
	gotoxy (86, 4);
	printf ("%c", 180);
	gotoxy (0, 19);
	printf ("%c", 195);
	gotoxy (86, 19);
	printf ("%c", 180);
	gotoxy (0, 21);
	printf ("%c", 195);
	gotoxy (86, 21);
	printf ("%c", 180);
}

void LineaHorizontal (int y) {
	
	int eRenglones;
	
	for (eRenglones = 1; eRenglones <= 85; eRenglones ++) {
		
		gotoxy (eRenglones, y);
		printf ("%c", 196);
		
	}
	
	gotoxy (0, y);
	printf ("%c", 195);
	gotoxy (86, y);
	printf ("%c", 180);
	
}

void LineaVertical (int x, int eOpcion) {
	
	int eColumnas;
	
	switch (eOpcion){
	
		case 1: 
		
			for (eColumnas = 6; eColumnas <= 22; eColumnas ++) {
			
				gotoxy (x, eColumnas);
				printf ("%c", 179);
			}
			
			gotoxy (x, 6);
			printf ("%c", 194);
			gotoxy (x, 8);
			printf ("%c", 197);
			gotoxy (x, 22);
			printf ("%c", 193);
		
		break;
		
		case 2: 
		
			for (eColumnas = 4; eColumnas <= 22; eColumnas ++) {
			
				gotoxy (x, eColumnas);
				printf ("%c", 179);
			}
			
			gotoxy (x, 4);
			printf ("%c", 194);
			gotoxy (x, 6);
			printf ("%c", 197);
			gotoxy (x, 22);
			printf ("%c", 193);
	
		break;
	
	case 3: 
	
		for (eColumnas = 4; eColumnas <= 22; eColumnas ++) {
			
				gotoxy (x, eColumnas);
				printf ("%c", 179);
			}
		
		gotoxy (x, 4);
		printf ("%c", 194);
		gotoxy (x, 22);
		printf ("%c", 193);
		
	break;
	
	}
	
}

void MargenConDosCuadros () {
	
	int eRenglones, eColumnas;
	
	for (eRenglones = 1; eRenglones <= 85; eRenglones ++) {
		
		gotoxy (eRenglones, 4);
		printf ("%c", 196);
		
		gotoxy (eRenglones, 6);
		printf ("%c", 196);
		
		gotoxy (eRenglones, 22);
		printf ("%c", 196);
	
	}
	
	gotoxy (0, 4);
	printf ("%c", 195);
	gotoxy (86, 4);
	printf ("%c", 180);
	gotoxy (0, 6);
	printf ("%c", 195);
	gotoxy (86, 6);
	printf ("%c", 180);
	gotoxy (0, 22);
	printf ("%c", 195);
	gotoxy (86, 22);
	printf ("%c", 180);
	
	for (eColumnas = 7; eColumnas < 22; eColumnas ++) {
		
		gotoxy (43, eColumnas);
		printf ("%c", 179);
		
	}
	
	gotoxy (43, 6);
	printf ("%c", 194);
	gotoxy (43, 22);
	printf ("%c", 193);
}

void MitadDeLineaHorizontalDerecha () {
	
	int eRenglones;
	
	for (eRenglones = 44; eRenglones <= 85; eRenglones ++) {
		
		gotoxy (eRenglones, 14);
		printf ("%c", 196);
		
	}
	
	gotoxy (86, 14);
	printf ("%c", 180);
	gotoxy (43, 14);
	printf ("%c", 195);
}

void MitadDeLineaVertical () {
	
	int eColumnas;
	
	for (eColumnas = 4; eColumnas < 21; eColumnas ++) {
		
		gotoxy (43, eColumnas);
		printf ("%c", 179);
		
	}
	
	gotoxy (43, 4);
	printf ("%c", 194);
	gotoxy (43, 6);
	printf ("%c", 197);
	
}

void CentrarTexto (char *sMensaje, int y) {
	
	int eTamanioMensaje = strlen (sMensaje);
	gotoxy (43 - (eTamanioMensaje / 2), y);
	printf ("%s", sMensaje);
	
}

void CentrarTextoEnCuadroChicoIzquierdo (char *sMensaje, int y) {
	
	int eTamanioMensaje = strlen (sMensaje);
	gotoxy (22 - (eTamanioMensaje / 2), y);
	printf ("%s", sMensaje);
	
}

void CentrarTextoEnCuadroChicoDerecho (char *sMensaje, int y) {
	
	int eTamanioMensaje = strlen (sMensaje);
	gotoxy (65 - (eTamanioMensaje / 2), y);
	printf ("%s", sMensaje);
	
}

int LimpiarPantalla (int eOpcion) {
	
	return eOpcion == 0;
}

#endif //_FUNCIONESPANTALLA_H
