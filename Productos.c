/*
	Programa: Productos.c
	Autores:
		1. Guerrero Torres Elizabeth
		2. Lï¿½pez Monares Gail Keegan
		3. Rivera Alvarez Jonathan Charly
	Fecha: 17/11/2020
	Objetivo: Realizar todas las operaciones correspondientes de la heladerï¿½a HEL-ARTE.
*/

//Tipos
typedef struct rProducto {
	
	int eIdArticulo [20];
	int eIdCategoria, eIdProducto;
	float fPrecioProducto, fCostoProducto;
	TcCadena sNombreProducto;
	struct rProducto *pAnterior, *pSiguiente;
	
} TrProducto;

typedef TrProducto *TpProducto;

typedef struct {
	
	TpProducto pPrimero, pUltimo;
	
} TrLista;

// Prototipos
// 1. Procedimientos
void RegistrarProducto ();
void ModificarProductoUno ();
void ModificarProductoDos ();
void BorrarProducto (TrLista *, int, int);
void ConsultarProducto (TrLista, int);
void ListarProductosPorCategoria (TrLista);
void ListarTodosLosProductos (TpProducto, int);
void MostrarConsultaDelProducto (TpProducto, int, int);
void Borrar (TrLista *, TpProducto);

// 2. Funciones
int ListaVacia (TpProducto);
int ListaLlena (TpProducto *);
int IdProducto (TpProducto);
int LeerIDProducto ();
TrProducto LeerProducto (TrLista *, TrListaArticulos *);
TpProducto BuscarProducto (TpProducto, TcCadena);
TpProducto BuscarProductoId (TpProducto, int);
TrProducto ModificarProducto (TrLista, int);

int ListaVacia (TpProducto pPrimero) {
	
	return pPrimero == NULL;
	
}

int ListaLlena (TpProducto *pNuevo) {
	
	*pNuevo = (TpProducto) malloc(sizeof(TrProducto));
	return *pNuevo == NULL;
	
}

int IdProducto (TpProducto pPrimero){
	
	TpProducto pPos;
	int eMayor = 0;
	
	pPos = pPrimero;
	
	
	while (!ListaVacia(pPos)) {
		
		if (pPos->eIdProducto > eMayor) {
			
			eMayor = pPos->eIdProducto;
			
			
		}
		
		pPos = pPos->pSiguiente;
		
	}
	
	return eMayor + 1;
	
}

TpProducto BuscarProducto (TpProducto pPrimero, TcCadena sNombreProducto) {
	
	if (ListaVacia(pPrimero)) {
		
		return NULL;
		
	} else {
		
		if (strcmp(sNombreProducto, pPrimero->sNombreProducto) == 0) {
			
			return pPrimero;
			
		} else {
			
			return BuscarProducto(pPrimero->pSiguiente, sNombreProducto);
			
		}
			
	}
	
}

void RegistrarProducto (TrLista *rLista, TrProducto *rProducto) {

	TpProducto pPos, pNuevo;
	
	if (ListaLlena(&pNuevo)) {
		
		LaListaEstaLlena ();
		
	} else {
		
		pNuevo->eIdArticulo[0] = (*rProducto).eIdArticulo[0];
		pNuevo->eIdCategoria = (*rProducto).eIdCategoria;
		pNuevo->fPrecioProducto= (*rProducto).fPrecioProducto;
		pNuevo->fCostoProducto = (*rProducto).fCostoProducto;
		strcpy(pNuevo->sNombreProducto, (*rProducto).sNombreProducto);
		pNuevo->eIdProducto = (*rProducto).eIdProducto;
		
		pNuevo->pSiguiente = NULL;
		pNuevo->pAnterior = NULL;
		
		if (ListaVacia((*rLista).pPrimero)) {
			
			(*rLista).pPrimero = pNuevo;
			(*rLista).pUltimo = pNuevo;
			
		} else {
			
			if (strcmp((*rProducto).sNombreProducto, (*rLista).pUltimo->sNombreProducto) > 0) {
				
				(*rLista).pUltimo->pSiguiente = pNuevo;
				pNuevo->pAnterior = (*rLista).pUltimo;
				(*rLista).pUltimo = pNuevo;
				
				
			} else {
				
				if (strcmp((*rProducto).sNombreProducto, (*rLista).pPrimero->sNombreProducto) < 0) {
					
					(*rLista).pPrimero->pAnterior = pNuevo;
					pNuevo->pSiguiente = (*rLista).pPrimero;
					(*rLista).pPrimero = pNuevo;
					
				} else {
					
					pPos = BuscarProducto((*rLista).pPrimero, (*rProducto).sNombreProducto);
					
					if (pPos != NULL) {
						
						free(pNuevo);
						printf("%s ya existe", (*rProducto).sNombreProducto);
						
					} else {
						
						pPos = (*rLista).pPrimero;
						
						while (strcmp((*rProducto).sNombreProducto, pPos->sNombreProducto) > 0) {
							
							pPos = pPos->pSiguiente;
							
						}
											
						pNuevo->pSiguiente = pPos;
						pNuevo->pAnterior = pPos->pAnterior;
						pPos->pAnterior->pSiguiente = pNuevo;
						pPos->pAnterior = pNuevo;
						
					}
					
					
				}
				
			}
									
		}
		
	}
}

TrProducto LeerProducto (TrLista *rLista, TrListaArticulos *rListaArticulos) {
	
	TpArticulo pBuscarArticulo;
	TrProducto rProducto;
	int ePosIdArticulo, eResultado;
	char cOpcionArticulo, cOpcion;
	
	do {
		
		system("cls");
		MargenPantalla ();
		MargenConDosCuadros ();
		InterfazDeRegistrarProducto ();
		MensajesDelSistema ();
		
		//Nombre del producto
		do {
			
			fflush(stdin);
			gotoxy(54, 5);
			gets(rProducto.sNombreProducto);
			
			if (strlen(rProducto.sNombreProducto) > 0 && !ValidarCadena(rProducto.sNombreProducto)) {
				
				gotoxy (4, 24);
				printf ("El nombre del producto debe contener mínimo un caracter y sólo se aceptan letras.");
				
			} else {
				
				LimpiarMensajesDelSistema ();
			}
		
		} while (strlen(rProducto.sNombreProducto) > 0 && !ValidarCadena(rProducto.sNombreProducto));
		
		//Categoría		
		do {
	
			fflush(stdin);
			gotoxy(32, 10);
			eResultado = scanf("%d", &rProducto.eIdCategoria);
						
			if (rProducto.eIdCategoria <= 0 || eResultado == 0) {
							
				gotoxy (4, 24);
				printf ("El ID de la categoría debe ser un número positivo mayor o igual a 1.");
							
			} else {
				
				LimpiarMensajesDelSistema ();
				
			}
	
		} while (rProducto.eIdCategoria <= 0 || eResultado == 0);
		
		//Artículos
		for (ePosIdArticulo = 0; ePosIdArticulo < 20; ePosIdArticulo ++) {
	
			rProducto.eIdArticulo[ePosIdArticulo] = 0;
	
		}
	
		ePosIdArticulo = 0;
	
		do {
	
			do {
	
				fflush (stdin);
				gotoxy(37, 12);
				eResultado = scanf("%d", &rProducto.eIdArticulo[ePosIdArticulo]);
				
				if (rProducto.eIdArticulo[ePosIdArticulo] != 0) {
					
					pBuscarArticulo = BuscarArticuloId((*rListaArticulos).pPrimero, rProducto.eIdArticulo[ePosIdArticulo]);
//					printf ("%p", pBuscarArticulo);
					if (pBuscarArticulo != NULL) {
						
//						gotoxy (4, 24);	
						
						printf("El articulo que consume es: %s \n", pBuscarArticulo->sNombreArticulo);
								
					} else {
							
//						gotoxy (4, 24);
						printf("El articulo que desea agregar no existe.");
								
					}
					
				}
							
			} while (rProducto.eIdArticulo[0] == 0 || eResultado == 0);
	
			ePosIdArticulo ++;
	
		} while (ePosIdArticulo != 0 && rProducto.eIdArticulo[ePosIdArticulo -1 ] != 0);
		
		//Precio del producto			
		do {
	
			fflush(stdin);
			gotoxy(27, 15);
			eResultado = scanf("%f", &rProducto.fPrecioProducto);
			
			if (rProducto.fPrecioProducto <= 0 || eResultado == 0) {
				
				gotoxy (4, 24);
				printf ("El precio del artículo debe ser un número positivo mayor o igual a 1.");
				
			} else {
				
				LimpiarMensajesDelSistema ();
			}
	
		} while (rProducto.fPrecioProducto <= 0 || eResultado == 0);
	
		//Costo del producto (¿para qué se va a ocupar?)
		do {
						
			fflush(stdin);
			gotoxy(26, 17);
			eResultado = scanf("%f", &rProducto.fCostoProducto);
			
			if (rProducto.fCostoProducto <= 0 || eResultado == 0) {
				
				gotoxy (4, 24);
				printf ("El costo del artículo debe ser un número positivo mayor o igual a 1.");
				
			} else {
				
				LimpiarMensajesDelSistema ();
			}
						
		} while (rProducto.fCostoProducto <= 0 || eResultado == 0);
		
		//ID del producto	
		if (ListaVacia((*rLista).pPrimero)) {
			
			rProducto.eIdProducto = 1;
			
		} else {
			
			rProducto.eIdProducto = IdProducto((*rLista).pPrimero);
			
		}
			
		CentrarTextoEnCuadroChicoDerecho ("El ID del producto registrado es", 14);
		gotoxy (82, 14);
		printf ("%d", rProducto.eIdProducto);
		
		//Agregar o no otro producto
		CentrarTextoEnCuadroChicoIzquierdo("¿Desea agregar otro producto?", 19);
		CentrarTextoEnCuadroChicoIzquierdo("[S-s/N-n]: ", 20);
		fflush (stdin);
		cOpcion = toupper(getchar());
				
		if (cOpcion == 'S') {
					
			gotoxy (4, 24);
			printf ("Regresando al formulario...");
			
			RegistrarProducto(&(*rLista), &rProducto);
					
		} else {
			
			RegistrarProducto(&(*rLista), &rProducto);
			
		}
			
		LimpiarMensajesDelSistema ();		
		gotoxy (4, 24);
		printf ("Regresando al menú de productos...");
		
		sleep (1);
		
	} while (cOpcion == 'S');	
	
	return rProducto;
}

int LeerIDProducto () {
	
	int eIdProducto;
	char cOpcion;
	TcCadena sIdProducto;
		
		do {
			
			//Leer ID del producto
			fflush(stdin);
			gotoxy(52, 5);
			gets(sIdProducto);
				
			eIdProducto = atoi(sIdProducto);
					
			if (strlen(sIdProducto) > 0) {
						
				
				if (eIdProducto > 0) {
							
					LimpiarMensajesDelSistema ();	
					
				} else {
					
					gotoxy(4, 24);
					printf ("El ID del producto debe ser un número positivo mayor o igual a 1.");
					
				}
				
				LimpiarMensajesDelSistema ();
						
			} 
			
		} while (strlen(sIdProducto) > 0 && eIdProducto == 0);
	
	return eIdProducto;
}

TrProducto ModificarProducto (TrLista rLista, int eIdProducto) {
	
	int eOpcion;
	char cOpcion;
	TpProducto pModificar;
	TrProducto rProducto;
	
	if (ListaVacia(rLista.pPrimero)) {
		
		SinElementos ();
		
	} else {
		
		pModificar = BuscarProductoId(rLista.pPrimero, eIdProducto);
		
		rProducto.eIdArticulo[0] = pModificar->eIdArticulo[0];
		strcpy(rProducto.sNombreProducto, pModificar->sNombreProducto);
		rProducto.fPrecioProducto = pModificar->fPrecioProducto;
		rProducto.eIdCategoria = pModificar->eIdCategoria;
		rProducto.fCostoProducto = pModificar->fCostoProducto;
		rProducto.eIdProducto = pModificar->eIdProducto;
		
		if (pModificar == NULL) {
			
			gotoxy (4, 24);
			printf("El producto con ID %d no existe", eIdProducto);
			
		} else {
			
			MostrarConsultaDelProducto(pModificar, 2, 0);
			CentrarTextoEnCuadroChicoDerecho ("¿Desea modificar los datos", 13);
			CentrarTextoEnCuadroChicoDerecho ("de este producto? [S/N]", 14);
			fflush (stdin);
			gotoxy (78, 14);
			cOpcion = toupper(getchar());
			
			if (cOpcion == 'S') {
				
				do {
					
					InterfazModificarProductoDos ();
					gotoxy (57, 5);
					scanf("%d", &eOpcion);
					
					switch (eOpcion) {
						case 1: 
								fflush(stdin);
								gotoxy (65 ,16);
								gets(rProducto.sNombreProducto);
								BorrarProducto(&rLista, rProducto.eIdProducto, 2);
								RegistrarProducto(&rLista, &rProducto);
								gotoxy (45, 16);
								printf ("%s", rProducto.sNombreProducto);
								break;
							
						case 2: gotoxy (65 ,16);
								scanf("%d", &rProducto.eIdCategoria);
								BorrarProducto(&rLista, rProducto.eIdProducto, 2);
								RegistrarProducto(&rLista, &rProducto);
								gotoxy (45, 16);
								printf ("%d", rProducto.eIdCategoria);
								break;
							
						case 3: gotoxy (65 ,16);
								scanf("%f", &rProducto.fPrecioProducto);
								BorrarProducto(&rLista, rProducto.eIdProducto, 2);
								RegistrarProducto(&rLista, &rProducto);
								gotoxy (45, 16);
								printf ("%f", rProducto.fPrecioProducto);
								break;
							
						case 4: gotoxy (65, 16);
								scanf("%f", &rProducto.fCostoProducto);
								BorrarProducto(&rLista, rProducto.eIdProducto, 2);
								RegistrarProducto(&rLista, &rProducto);
								gotoxy (45, 16);
								printf ("%f", rProducto.fCostoProducto);
								break;
							
						case 5: gotoxy (65 ,16);
								scanf("%d", &rProducto.eIdArticulo[0]);	
								BorrarProducto(&rLista, rProducto.eIdProducto, 2);
								RegistrarProducto(&rLista, &rProducto);
								gotoxy (45, 16);
								printf ("%d", rProducto.eIdArticulo[0]);									
								break;
							
						case 6: LimpiarMensajesDelSistema ();
								gotoxy (4, 24);
								printf("Adiós.");
								break;
							
						default: gotoxy (4, 24);
								 printf("Ingrese una opción válida.");
								 break;
					}
					
				} while (eOpcion != 6);
				
			}
															
		}
				
	}
	
	return rProducto;
	
}

void BorrarProducto (TrLista *rLista, int eIdProducto, int eOpcion) {

	char cOpcion;
	TpProducto pBorrar;
	
	if (ListaVacia((*rLista).pPrimero)) {
		
		SinElementos ();
		
	} else {
		
		pBorrar = BuscarProductoId((*rLista).pPrimero, eIdProducto);
		
		if (pBorrar == NULL) {
			
			gotoxy (4, 24);
			printf("El producto con ID %d no existe", eIdProducto);
			
		} else {
			
			switch (eOpcion) {
				
				case 1: MostrarConsultaDelProducto(pBorrar, 2, 0);
			
						CentrarTextoEnCuadroChicoDerecho ("¿Desea borrar este producto? [S/N]: ", 14);
						fflush (stdin);
						gotoxy (82, 14);
						cOpcion = toupper(getchar());
			
						if (cOpcion == 'S') {
							Borrar (rLista, pBorrar);
							free (pBorrar);
						}
						break;
				case 2: Borrar (rLista, pBorrar);
						free (pBorrar);
						break;
			}
			
		}
		
	}
	
}

void Borrar (TrLista *rLista, TpProducto pBorrar) {
	
	if ((*rLista).pPrimero == (*rLista).pUltimo ) {
				
		(*rLista).pPrimero = NULL;
		(*rLista).pUltimo = NULL;
				
	} else {
				
		if (pBorrar == (*rLista).pUltimo) {
						
			(*rLista).pUltimo = (*rLista).pUltimo->pAnterior;
			(*rLista).pUltimo->pSiguiente = NULL;
						
		} else {
						
			if (pBorrar == (*rLista).pPrimero) {
							
				(*rLista).pPrimero = (*rLista).pPrimero->pSiguiente;
				(*rLista).pPrimero->pAnterior = NULL;
							
			} else {
						
				pBorrar->pSiguiente->pAnterior = pBorrar->pAnterior;
				pBorrar->pAnterior->pSiguiente = pBorrar->pSiguiente;
							
			}	
				
		}
					
	}
	
}

TpProducto BuscarProductoId (TpProducto pPrimero, int eIdProducto) {
	
	if (ListaVacia(pPrimero)) {
		
		return NULL;
		
	} else {
		
		if (eIdProducto == pPrimero->eIdProducto) {
			
			return pPrimero;
			
		} else {
			
			return BuscarProductoId (pPrimero->pSiguiente, eIdProducto);
			
		}
			
	}
	
}

void MostrarConsultaDelProducto (TpProducto pConsulta, int eOpcionListar, int ePosY) {
	
	switch (eOpcionListar) {
		
		case 0: gotoxy (60, 9);
				printf ("%d", pConsulta->eIdProducto);
		
				gotoxy (65, 11);
				printf ("%s", pConsulta->sNombreProducto);
				
				gotoxy (65, 13);
				printf ("%f", pConsulta->fPrecioProducto);
			
				gotoxy (65, 15);
				printf ("%f", pConsulta->fCostoProducto);
			
				gotoxy (65, 17);
				printf ("%d", pConsulta->eIdCategoria);
				
				gotoxy (65, 20);
				printf("%d", pConsulta->eIdArticulo[0]);
				break;
		case 1: gotoxy (2, ePosY + 9);
				printf ("%d", pConsulta->eIdProducto);
		
				gotoxy (15, ePosY + 9);
				printf ("%s", pConsulta->sNombreProducto);
				
				gotoxy (35, ePosY + 9);
				printf ("%.1f", pConsulta->fPrecioProducto);
			
				gotoxy (48, ePosY + 9);
				printf ("%.1f", pConsulta->fCostoProducto);
			
				gotoxy (65, ePosY + 9);
				printf ("%d", pConsulta->eIdCategoria);
				
				gotoxy (80, ePosY + 9);
				printf("%d", pConsulta->eIdArticulo[0]);
				break;
		case 2: gotoxy (38, 10);
				printf ("%d", pConsulta->eIdProducto);
		
				gotoxy (38, 12);
				printf ("%s", pConsulta->sNombreProducto);
				
				gotoxy (38, 14);
				printf ("%.1f", pConsulta->fPrecioProducto);
			
				gotoxy (38, 16);
				printf ("%.1f", pConsulta->fCostoProducto);
			
				gotoxy (38, 18);
				printf ("%d", pConsulta->eIdCategoria);
				
				gotoxy (38, 21);
				printf("%d", pConsulta->eIdArticulo[0]);
				break;
		case 3: CentrarTextoEnCuadroChicoDerecho ("Los nuevos datos son:", 16);
				gotoxy (45, 16);
				printf ("%d", pConsulta->eIdProducto);
		
				gotoxy (47, 11);
				printf ("%s,", pConsulta->sNombreProducto);
				
				gotoxy (60, 12);
				printf ("%.1f", pConsulta->fPrecioProducto);
			
				gotoxy (62, 13);
				printf ("%.1f", pConsulta->fCostoProducto);
			
				gotoxy (64, 14);
				printf ("%d", pConsulta->eIdCategoria);
				
				gotoxy (66, 16);
				printf("%d", pConsulta->eIdArticulo[0]);
	}
	
}

void ConsultarProducto (TrLista rLista, int eIdProducto) {
	
	TpProducto pConsulta;
	
	if (ListaVacia(rLista.pPrimero)) {
		
		SinElementos ();
		
	} else {
		
		pConsulta = BuscarProductoId(rLista.pPrimero, eIdProducto);
		
		if (pConsulta == NULL) {
			
			gotoxy (4, 24);
			printf("El producto con ID %d no existe", eIdProducto);
			
		} else {
			
			MostrarConsultaDelProducto(pConsulta, 0, 0);
			
		}		
		
	}
	
}

void ListarProductosPorCategoria (TrLista rLista) {

	int eIdCategoria;
	int ePosY = 0;
	TpProducto pPos = rLista.pPrimero;
	
	system("cls");
	MargenPantalla ();
	InterfazProductosPorCategoria ();
	
	if (ListaVacia(rLista.pPrimero)) {
		
		SinElementos ();
		
	} else {
		
		gotoxy (53, 5);
		scanf("%d", &eIdCategoria);
		
		while (!ListaVacia(pPos)) {
			
			if (pPos->eIdCategoria == eIdCategoria) {
				
				MostrarConsultaDelProducto(pPos, 1, ePosY);
				pPos = pPos->pSiguiente;
				
			} else {
				
				pPos = pPos->pSiguiente;
				
			}
			
			ePosY ++;
			
		}
		
	}
		
	getchar();
}

void ListarTodosLosProductos (TpProducto pPrimero, int ePosY) {

	if (!ListaVacia(pPrimero)) {
	
		MostrarConsultaDelProducto(pPrimero, 1, ePosY);
		
		ePosY ++;
		
		ListarTodosLosProductos(pPrimero->pSiguiente, ePosY);
		
	} else {
		
		SinElementos ();
	}
		
}
