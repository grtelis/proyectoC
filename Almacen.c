/*
	Programa: Almacen.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. López Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Realizar todas las operaciones correspondientes de la heladería HEL-ARTE.
*/

//Tipos
typedef struct rArticulo {
	
	int eIdArticulo, eIdCategoria, eExistencias, eExistenciasMax, eExistenciasMin;
	TcCadena sNombreArticulo;
	struct rArticulo *pAnterior, *pSiguiente;
	
} TrArticulo;

typedef TrArticulo *TpArticulo;

typedef struct {
	
	TpArticulo pPrimero, pUltimo;
	
} TrListaArticulos;

// Prototipos
//1. Procedimientos
void RegistrarArticulo (TrListaArticulos *, TrArticulo *);
void BorrarArticulo (TrListaArticulos *, int, int);
void BorrarElArticulo (TrListaArticulos *, TpArticulo);
void ConsultarArticulo ();
void ListarArticulosPorCategoria ();
void ListarTodosLosArticulos ();
void ConsultarArticulo (TrListaArticulos, int);
void MostrarUnArticulo (TpArticulo, int);

//2. Funciones
int ListaVaciaArticulos (TpArticulo);
int ListaLlenaArticulos (TpArticulo *);
int IdArticulo (TpArticulo);
TrArticulo LeerArticulo (TrListaArticulos);
TpArticulo BuscarArticulo (TpArticulo, TcCadena);
TpArticulo BuscarArticuloId (TpArticulo, int);
TrArticulo ModificarArticulo (TrListaArticulos, int);

int ListaVaciaArticulos (TpArticulo pPrimero) {
	
	return pPrimero == NULL;
	
}

int ListaLlenaArticulos (TpArticulo *pNuevo) {
	
	*pNuevo = (TpArticulo) malloc(sizeof(TrArticulo));
	return *pNuevo == NULL;
	
}

int IdArticulo (TpArticulo pPrimero) {
	
	TpArticulo pPosicion;
	int eMayor = 0;
	
	pPosicion = pPrimero;
	
	while (!ListaVaciaArticulos(pPosicion)) {
		
		if (pPosicion->eIdArticulo > eMayor) {
			
			eMayor = pPosicion->eIdArticulo;
			
		}
		
		pPosicion = pPosicion->pSiguiente;
		
	}
	
	return eMayor + 1;
}

TpArticulo BuscarArticulo (TpArticulo pPrimero, TcCadena sNombreArticulo) {
	
	if (ListaVaciaArticulos (pPrimero)) {
		
		return NULL;
		
	} else {
		
		if (strcmp(sNombreArticulo, pPrimero->sNombreArticulo) == 0) {
			
			return pPrimero;
			
		} else {
			
			return BuscarArticulo (pPrimero->pSiguiente, sNombreArticulo);
			
		}
			
	}
	
}

TpArticulo BuscarArticuloId (TpArticulo pPrimero, int eIdArticulo) {
	
	if (ListaVaciaArticulos (pPrimero)) {
		
		return NULL;
		
	} else {
		
		printf ("%d \n", eIdArticulo);
		printf ("%d", pPrimero->eIdArticulo);
		
		if (eIdArticulo == pPrimero->eIdArticulo) {
			
			return pPrimero;
			
		} else {
			
			return BuscarArticuloId (pPrimero->pSiguiente, eIdArticulo);
			
		}
			
	}
	
}

void RegistrarArticulo (TrListaArticulos *rListaArticulos, TrArticulo *rArticulo) {

	TpArticulo pPosicion, pNuevo;
	
	if (ListaLlenaArticulos (&pNuevo)) {
		
		gotoxy (4, 24);
		printf("La lista está llena.");
		
	} else {
		
		pNuevo->eIdCategoria = (*rArticulo).eIdCategoria;
		pNuevo->eExistencias = (*rArticulo).eExistencias;
		pNuevo->eExistenciasMin = (*rArticulo).eExistenciasMin;
		pNuevo->eExistenciasMax = (*rArticulo).eExistenciasMax;
		strcpy(pNuevo->sNombreArticulo, (*rArticulo).sNombreArticulo);
		pNuevo->eIdArticulo = (*rArticulo).eIdArticulo;
		
		pNuevo->pSiguiente = NULL;
		pNuevo->pAnterior = NULL;
		
		if (ListaVaciaArticulos((*rListaArticulos).pPrimero)) {
			
			(*rListaArticulos).pPrimero = pNuevo;
			(*rListaArticulos).pUltimo = pNuevo;
			
		} else {
			
			if (strcmp((*rArticulo).sNombreArticulo, (*rListaArticulos).pUltimo->sNombreArticulo) > 0) {
				
				(*rListaArticulos).pUltimo->pSiguiente = pNuevo;
				pNuevo->pAnterior = (*rListaArticulos).pUltimo;
				(*rListaArticulos).pUltimo = pNuevo;
				
				
			} else {
				
				if (strcmp((*rArticulo).sNombreArticulo, (*rListaArticulos).pPrimero->sNombreArticulo) < 0) {
					
					(*rListaArticulos).pPrimero->pAnterior = pNuevo;
					pNuevo->pSiguiente = (*rListaArticulos).pPrimero;
					(*rListaArticulos).pPrimero = pNuevo;
					
				} else {
					
					pPosicion = BuscarArticulo((*rListaArticulos).pPrimero, (*rArticulo).sNombreArticulo);
					
					if (pPosicion != NULL) {
						
						free(pNuevo);
						printf("%s ya existe", (*rArticulo).sNombreArticulo);
						
					} else {
						
						pPosicion = (*rListaArticulos).pPrimero;
						
						while (strcmp((*rArticulo).sNombreArticulo, pPosicion->sNombreArticulo) > 0) {
							
							pPosicion = pPosicion->pSiguiente;
							
						}
											
						pNuevo->pSiguiente = pPosicion;
						pNuevo->pAnterior = pPosicion->pAnterior;
						pPosicion->pAnterior->pSiguiente = pNuevo;
						pPosicion->pAnterior = pNuevo;
						
					}
					
				}
				
			}
									
		}
		
	}
	
}

TrArticulo LeerArticulo (TrListaArticulos rListaArticulos) {
	
	TrArticulo rArticulo;
	int eResultado, eResultadoMax, eResultadoMin;
	char cOpcion;
	
	do {
		
		system("cls");
		MargenPantalla ();
		MargenConDosCuadros ();
		MitadDeLineaVertical ();
		InterfazDeRegistrarArticulo ();
		MensajesDelSistema ();
		
		//Nombre del artículo
		do {
			
			fflush(stdin);
			gotoxy(35, 5);
			gets(rArticulo.sNombreArticulo);
			
			if (strlen(rArticulo.sNombreArticulo) > 0 && !ValidarCadena(rArticulo.sNombreArticulo)) {
				
				gotoxy (35, 5);
				printf ("    ");
				gotoxy (4, 24);
				printf ("El nombre del artículo debe contener mínimo un caracter y sólo se aceptan letras.");
				
			} else {
				
				LimpiarMensajesDelSistema ();
				
			}
		
		} while (strlen(rArticulo.sNombreArticulo) > 0 && !ValidarCadena(rArticulo.sNombreArticulo));
		
		//Categoría			
		do {
			
			fflush(stdin);
			gotoxy(75, 5);
			eResultado = scanf("%d", &rArticulo.eIdCategoria);
						
			if (rArticulo.eIdCategoria <= 0 || eResultado == 0) {
				
				gotoxy (75, 5);
				printf ("   ");		
				gotoxy (4, 24);
				printf ("El ID de la categoría debe ser un número positivo mayor o igual a 1.");
							
			} else {
				
				LimpiarMensajesDelSistema ();
				
			}
	
		} while (rArticulo.eIdCategoria <= 0 || eResultado == 0);
			
		do {
				
			do {
						
			 	fflush(stdin);
			 	gotoxy (33, 11);
				eResultadoMin = scanf("%d", &rArticulo.eExistenciasMin);
					
				if (rArticulo.eExistenciasMin < 0 || eResultadoMin == 0) {
					
					gotoxy (33, 11);
					printf ("   ");	
					gotoxy (4, 24);
					printf ("Las existencias mínimas deben ser números positivos mayores o igual a 1.");
						
				} else {
						
					LimpiarMensajesDelSistema ();
				}
							
			} while (rArticulo.eExistenciasMin < 0 || eResultadoMin == 0);
				
			do {
			
				fflush(stdin);
				gotoxy (33, 13);
				eResultadoMax = scanf("%d", &rArticulo.eExistenciasMax);
					
				if (rArticulo.eExistenciasMax < 0 || eResultadoMax == 0 || rArticulo.eExistenciasMax < rArticulo.eExistenciasMin) {
						
					gotoxy (33, 13);
					printf ("   ");
					gotoxy (4, 24);
					printf ("Las existencias máximas deben ser números positivos mayores o igual a 1 y deben");
					gotoxy (4, 25);
					printf ("ser mayores que las existencias mínimas.");
						
				} else {
						
					LimpiarMensajesDelSistema ();
				}
							
			} while (rArticulo.eExistenciasMax <= 0 || eResultadoMax == 0);
		
		} while (rArticulo.eExistenciasMax < rArticulo.eExistenciasMin);		
			
					
		do {
				
			fflush(stdin);
			gotoxy (35, 15);
			eResultado = scanf("%d", &rArticulo.eExistencias);
				
			if (rArticulo.eExistencias < 0 || eResultado == 0) {
				
				gotoxy (33, 15);
				printf ("   ");	
				gotoxy (4, 24);
				printf ("Las cantidad en existencias debe ser un número positivo mayor o igual a 1 y debe");
				gotoxy (4, 25);
				printf ("ser menor a las existencias máximas.");
					
			} else {
					
				LimpiarMensajesDelSistema ();
			}

		} while (rArticulo.eExistencias < 0 || eResultado == 0 || rArticulo.eExistencias > rArticulo.eExistenciasMax);
		
		//ID del Artículo
		if (ListaVaciaArticulos(rListaArticulos.pPrimero)) {
			
			rArticulo.eIdArticulo = 1;
			
		} else {
			
			rArticulo.eIdArticulo = IdArticulo(rListaArticulos.pPrimero);
			
		}
			
		CentrarTextoEnCuadroChicoDerecho ("El ID del artículo registrado es", 14);
		gotoxy (82, 14);
		printf ("%d", rArticulo.eIdArticulo);
		
		//Agregar o no otro artículo	
		CentrarTextoEnCuadroChicoIzquierdo("¿Desea agregar otro artículo?", 17);
		CentrarTextoEnCuadroChicoIzquierdo("[S-s/N-n]: ", 18);
		fflush (stdin);
		cOpcion = toupper(getchar());
			
		if (cOpcion == 'S') {
				
			gotoxy (4, 24);
		    printf ("Regresando al formulario...");
				
		} 
		
		LimpiarMensajesDelSistema ();		
		gotoxy (4, 24);
		printf ("Regresando al menú de artículos...");
		
		sleep (1);
		
	} while (cOpcion == 'S');	
	
	return rArticulo;
	
}

int LeerIDArticulo () {
	
	int eIdArticulo;
	char cOpcion;
	TcCadena sIdArticulo;
		
	do {
			
		//Leer ID del producto
		fflush(stdin);
		gotoxy(52, 5);
		gets(sIdArticulo);
				
		eIdArticulo = atoi(sIdArticulo);
					
		if (strlen(sIdArticulo) > 0) {
						
				
			if (eIdArticulo > 0) {
							
				LimpiarMensajesDelSistema ();	
					
			} else {
					
				gotoxy(4, 24);
				printf ("El ID del producto debe ser un número positivo mayor o igual a 1.");
					
			}
				
			LimpiarMensajesDelSistema ();
						
		} 
			
	} while (strlen(sIdArticulo) > 0 && eIdArticulo == 0);
	
	return eIdArticulo;
	
}

TrArticulo ModificarArticulo (TrListaArticulos rListaArticulos, int eIdArticulo) {
	
	int eOpcion;
	char cOpcion;
	TpArticulo pModificar;
	TrArticulo rArticulo;
	
	if (ListaVaciaArticulos(rListaArticulos.pPrimero)) {
		
		gotoxy (4, 24);
		printf("No hay elementos para modificar.");
		
	} else {
		
		pModificar = BuscarArticuloId(rListaArticulos.pPrimero, eIdArticulo);
				
		rArticulo.eIdArticulo = pModificar->eIdArticulo; //No se modifica
		rArticulo.eIdCategoria = pModificar->eIdCategoria; //Se modifica
		rArticulo.eExistencias = pModificar->eExistencias; //No se modifica
		rArticulo.eExistenciasMin = pModificar->eExistenciasMin; //Se modifica
		rArticulo.eExistenciasMax = pModificar->eExistenciasMax; //Se modifica
		strcpy(rArticulo.sNombreArticulo, pModificar->sNombreArticulo); //Se modifica
		
		if (pModificar == NULL) {
			
			gotoxy (4, 24);
			printf("El artículo con ID %d no existe", eIdArticulo);
			
		} else {
			
			MostrarUnArticulo (pModificar, 2);
			
			CentrarTextoEnCuadroChicoDerecho ("¿Desea modificar los datos", 13);
			CentrarTextoEnCuadroChicoDerecho ("de este artículo? [S/N]", 14);
			fflush (stdin);
			gotoxy (78, 14);
			cOpcion = toupper(getchar());
			
			if (cOpcion == 'S') {
				
				do {
				
					InterfazModificarArticuloDos ();
					gotoxy (58, 5);
					scanf("%d", &eOpcion);
					
					switch (eOpcion) {
						
						case 1: fflush(stdin);
								gotoxy (65, 10);
								gets(rArticulo.sNombreArticulo);
								BorrarArticulo(&rListaArticulos, rArticulo.eIdArticulo, 2);
								RegistrarArticulo(&rListaArticulos, &rArticulo);
								gotoxy (45, 18);
								printf ("El nuevo nombre del artículo es: %s", rArticulo.sNombreArticulo);
								break;
							
						case 2: gotoxy (65, 10);
								scanf("%d", &rArticulo.eIdCategoria);
								BorrarArticulo(&rListaArticulos, rArticulo.eIdArticulo, 2);
								RegistrarArticulo(&rListaArticulos, &rArticulo);
								gotoxy (45, 18);
								printf ("El nuevo nombre de la categoría es: %d", rArticulo.eIdCategoria);
								break;
							
						case 3: gotoxy (65, 10);
								scanf("%d", &rArticulo.eExistenciasMin);
								BorrarArticulo(&rListaArticulos, rArticulo.eIdArticulo, 2);
								RegistrarArticulo(&rListaArticulos, &rArticulo);
								gotoxy (45, 18);
								printf ("El nuevo dato de las existencias mínimas es: %d", rArticulo.eExistenciasMin);										
								break;
							
						case 4: gotoxy (65, 10);
								scanf("%d", &rArticulo.eExistenciasMax);
								BorrarArticulo(&rListaArticulos, rArticulo.eIdArticulo, 2);
								RegistrarArticulo(&rListaArticulos, &rArticulo);
								gotoxy (45, 18);
								printf ("El nuevo dato de las existencias máximas es: %d", rArticulo.eExistenciasMax);
								break;
							
						case 5: LimpiarMensajesDelSistema ();
								gotoxy (4, 24);
								printf("Adiós.");
								break;
							
						default: gotoxy (4, 24);
								 printf("Ingrese una opción válida.");
								break;
					}
					
					getchar ();
					
				} while (eOpcion != 5);
				
			}
															
		}
				
	}
	
	return rArticulo;
}

void BorrarArticulo (TrListaArticulos *rListaArticulos, int eIdArticulo, int eOpcion) {
	
	char cOpcion;
	TpArticulo pBorrar;
	
	if (ListaVaciaArticulos ((*rListaArticulos).pPrimero)) {
		
		gotoxy (4, 24);
		printf("La lista está vacía");
		
	} else {
		
		pBorrar = BuscarArticuloId((*rListaArticulos).pPrimero, eIdArticulo);
		
		if (pBorrar == NULL) {
			
			gotoxy (4, 24);
			printf("El artículo con ID %d no existe", eIdArticulo);
			
		} else {
			
			switch (eOpcion) {
				
				case 1: MostrarUnArticulo (pBorrar, 2);
			
						CentrarTextoEnCuadroChicoDerecho ("¿Desea borrar este artículo? [S/N] ", 14);
						fflush (stdin);
						gotoxy (82, 14);
						cOpcion = toupper(getchar());
			
						if (cOpcion == 'S') {
							BorrarElArticulo (rListaArticulos, pBorrar);
							free (pBorrar);
						}
						break;
				case 2: BorrarElArticulo (rListaArticulos, pBorrar);
						free (pBorrar);
						break;
			}
			
		}
		
	}
	
}

void BorrarElArticulo (TrListaArticulos *rListaArticulos, TpArticulo pBorrar) {
	
	if ((*rListaArticulos).pPrimero == (*rListaArticulos).pUltimo ) {
				
		(*rListaArticulos).pPrimero = NULL;
		(*rListaArticulos).pUltimo = NULL;
				
	} else {
				
		if (pBorrar == (*rListaArticulos).pUltimo) {
				
			(*rListaArticulos).pUltimo = (*rListaArticulos).pUltimo->pAnterior;
			(*rListaArticulos).pUltimo->pSiguiente = NULL;
					
		} else {
					
			if (pBorrar == (*rListaArticulos).pPrimero) {
						
				(*rListaArticulos).pPrimero = (*rListaArticulos).pPrimero->pSiguiente;
				(*rListaArticulos).pPrimero->pAnterior = NULL;
						
			} else {
						
				pBorrar->pSiguiente->pAnterior = pBorrar->pAnterior;
				pBorrar->pAnterior->pSiguiente = pBorrar->pSiguiente;
						
			}
					
		}			
			
	}
	
}

void MostrarUnArticulo (TpArticulo pConsulta, int eOpcionListar) {
	
	switch (eOpcionListar) {
		
		case 0: gotoxy (60, 10);
				printf ("%d", pConsulta->eIdArticulo);
		
				gotoxy (65, 12);
				printf ("%s", pConsulta->sNombreArticulo);
				
				gotoxy (65, 14);
				printf ("%d", pConsulta->eIdCategoria);
			
				gotoxy (65, 16);
				printf ("%d", pConsulta->eExistenciasMin);
			
				gotoxy (65, 18);
				printf ("%d", pConsulta->eExistenciasMax);
				
				gotoxy (65, 20);
				printf("%d", pConsulta->eExistencias);
				break;
		case 1: gotoxy (2, 10);
				printf ("%d", pConsulta->eIdArticulo);
		
				gotoxy (15, 10);
				printf ("%s", pConsulta->sNombreArticulo);
				
				gotoxy (35, 10);
				printf ("%d", pConsulta->eIdCategoria);
			
				gotoxy (48, 10);
				printf ("%d", pConsulta->eExistenciasMin);
			
				gotoxy (65, 10);
				printf ("%d", pConsulta->eExistenciasMax);
				
				gotoxy (80, 10);
				printf("%d", pConsulta->eExistencias);
				break;
		case 2: gotoxy (38, 10);
				printf ("%d", pConsulta->eIdArticulo);
		
				gotoxy (38, 12);
				printf ("%s", pConsulta->sNombreArticulo);
				
				gotoxy (38, 14);
				printf ("%d", pConsulta->eIdCategoria);
			
				gotoxy (38, 16);
				printf ("%d", pConsulta->eExistenciasMin);
			
				gotoxy (38, 18);
				printf ("%d", pConsulta->eExistenciasMax);
				
				gotoxy (38, 20);
				printf("%d", pConsulta->eExistencias);
				break;
	}

}

void ConsultarArticulo (TrListaArticulos rListaArticulos, int eIdArticulo) {

	TpArticulo pConsulta;
	
	if (ListaVaciaArticulos(rListaArticulos.pPrimero)) {
		
		printf("No hay elementos en la lista");
		
	} else {
		
		pConsulta = BuscarArticuloId(rListaArticulos.pPrimero, eIdArticulo);
		
		if (pConsulta == NULL) {
			
			printf("El producto con ID %d no existe", eIdArticulo);
			
		} else {
			
			MostrarUnArticulo (pConsulta, 0);
			
		}
		
	}
	
}

void ListarArticulosPorCategoria (TrListaArticulos rListaArticulos) {
	
	int eIdCategoria;
	TpArticulo pPosicion = rListaArticulos.pPrimero;
	
	system ("cls");
	MargenPantalla ();
	InterfazArticulosPorCategoria ();
	
	if (ListaVaciaArticulos(rListaArticulos.pPrimero)) {
		
		SinElementos ();
		
	} else {
		
		gotoxy (53, 5);
		scanf("%d", &eIdCategoria);
		
		while (!ListaVaciaArticulos(pPosicion)) {
			
			if (pPosicion->eIdCategoria == eIdCategoria) {
				
				MostrarUnArticulo(pPosicion, 1);
				pPosicion = pPosicion->pSiguiente;
				
			} else {
				
				pPosicion = pPosicion->pSiguiente;
				
			}
			
		}
		
	}
	
	getchar ();
}

void ListarTodosLosArticulos (TpArticulo pPrimero) {
	
	if (!ListaVaciaArticulos(pPrimero)) {
	
		MostrarUnArticulo(pPrimero, 1);
		
		ListarTodosLosArticulos(pPrimero->pSiguiente);
		
	}
	
}
