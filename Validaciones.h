/*
	Programa: Validaciones.h
	Autores:
		1. Guerrero Torres Elizabeth
		2. López Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Mostrar el menú principal de la heladería HEL-ARTE.
*/

//Biblioteca
#include <string.h>

//Tipos
typedef char TcCadena [20];

//Prototipos
int ValidarCadena (TcCadena);

int ValidarCadena (TcCadena sNombreProducto) {
	
	int eLongitud, eContador, eContador2, eResultado;
	
	eLongitud = strlen(sNombreProducto);
	eContador = 0;
	eResultado = 1;
	eContador2 = 0;
			
	while (eContador < eLongitud && eResultado != 0) {
				
		eResultado = isalpha(sNombreProducto[eContador]);
				
		if ( eResultado == 0) {
					
			return eResultado;
					
		} else {
					
			eContador2 ++;
					
			if (eContador2 == eLongitud) {
						
				return eResultado;
						
			}
					
		}
			
		eContador ++;
				
	}
	
	return eResultado;
	
}

