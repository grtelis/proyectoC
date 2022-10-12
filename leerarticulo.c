TrProducto LeerProducto (TrLista rLista) {
	
	TrProducto rProducto;
	TcCadena sNombreProducto;
	int ePosIdArticulo, eResultado, eVerdadero = 1;
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
			gets(sNombreProducto);
			
			if (strlen(sNombreProducto) > 0 && !ValidarCadena(sNombreProducto)) {
				
				gotoxy (4, 24);
				printf ("El nombre del producto debe contener mínimo un caracter y sólo se aceptan letras.");
				
			} else {
				
				EspacioEnBlanco ();
			}
		
		} while (strlen(sNombreProducto) > 0 && !ValidarCadena(sNombreProducto));
		
		strcpy (sNombreProducto, rProducto.sNombreProducto);
		
		//Categorías			
		do {
			
			printf ("%d", eVerdadero);
	
			fflush(stdin);
			gotoxy(32, 10);
			eResultado = scanf("%d", &rProducto.eIdCategoria);
						
			if (rProducto.eIdCategoria <= 0 || eResultado == 0) {
							
				gotoxy (4, 24);
				printf ("El ID de la categoría debe ser un número positivo mayor o igual a 1.");
							
			} else {
				
				EspacioEnBlanco ();
				
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
				
				if (rProducto.eIdArticulo[0] == 0 || eResultado == 0) {
					
					gotoxy (4, 24);
					printf ("El ID del artículo debe ser un número positivo mayor o igual a 1.");
					
				} else {
					
					EspacioEnBlanco ();
					
					do {
						
						CentrarTextoEnCuadroChicoIzquierdo("¿Desea agregar otro? [S-s/N-n]: ", 13);
						fflush (stdin);
						cOpcionArticulo = toupper(getchar());
					
						if (cOpcionArticulo == 'S') {
						
							gotoxy (37, 12);
							printf ("   ");
						}
						
						if (cOpcionArticulo != 'S' && cOpcionArticulo != 'N') {
							
							gotoxy (37, 13);
							printf ("   ");
							
							gotoxy (4, 24);
							printf ("Sólo se aceptan los caracteres 'S', 's', 'N' o 'n'.");
							
						} else {
							
							EspacioEnBlanco ();
							
						}
						
					} while (cOpcionArticulo != 'S' && cOpcionArticulo != 'N');
					
				}
							
			} while (rProducto.eIdArticulo[0] == 0 || eResultado == 0 || cOpcionArticulo == 'S');
	
			ePosIdArticulo ++;
	
		} while (rProducto.eIdArticulo[ePosIdArticulo -1] == 0);
		
		//Precio del producto			
		do {
	
			fflush(stdin);
			gotoxy(27, 15);
			eResultado = scanf("%f", &rProducto.fPrecioProducto);
			
			if (rProducto.fPrecioProducto <= 0 || eResultado == 0) {
				
				gotoxy (4, 24);
				printf ("El precio del artículo debe ser un número positivo mayor o igual a 1.");
				
			} else {
				
				EspacioEnBlanco ();
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
				
				EspacioEnBlanco ();
			}
						
		} while (rProducto.fCostoProducto <= 0 || eResultado == 0);
		
		//ID del producto
			
		if (ListaVacia(rLista.pPrimero)) {
			
			rProducto.eIdProducto = 1;
			
		} else {
			
			rProducto.eIdProducto = IdProducto(rLista.pPrimero);
			
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
					
			} 
			
			EspacioEnBlanco ();		
			gotoxy (4, 24);
			printf ("Regresando al menú de productos...");
		
		sleep (1);
		
	} while (cOpcion == 'S');	
	
	return rProducto;
	
}

TrProducto LeerProducto (TrLista rLista) {
	
	TrProducto rProducto;
	TcCadena sNombreProducto;
	int ePosIdArticulo, eResultado, eVerdadero = 1;
	char cOpcionArticulo, cOpcion;
	
	do {
		
		system("cls");
		MargenPantalla ();
		MargenConDosCuadros ();
		InterfazDeRegistrarProducto ();
		MensajesDelSistema ();
		
		fflush(stdin);
		gotoxy(54, 5);
		gets(sNombreProducto);
			
		if (strcmp (sNombreProducto, rProducto.sNombreProducto) != 0 && ValidarCadena(sNombreProducto) && strlen(sNombreProducto) > 0) {
			
			eVerdadero = 1;
			fflush(stdin);
			gotoxy(32, 10);
			eResultado = scanf("%d", &rProducto.eIdCategoria);
			
		} 
		
		eVerdadero = 0;
		
			
	} while (eVerdadero == 1);
	
	return rProducto;
	
}

do {
		
		system("cls");
		MargenPantalla ();
		MargenConDosCuadros ();
		InterfazDeRegistrarProducto ();
		MensajesDelSistema ();
		
		gotoxy (24, 23);
		printf ("Para salir dé doble enter.");
		gotoxy (4, 24);
		printf ("El nombre del producto debe contener mínimo un caracter,");
		gotoxy (4, 25);
		printf ("no se debe repetir y sólo se aceptan letras.");
		
		fflush(stdin);
		gotoxy(54, 5);
		gets(sNombreProducto);
		
		if (strcmp (sNombreProducto, rProducto.sNombreProducto) != 0 && ValidarCadena(sNombreProducto) && strlen(sNombreProducto) > 0) {
			
			EspacioEnBlanco ();
			
			//Categorías
			do {
			
				printf ("%d", eVerdadero);
		
				fflush(stdin);
				gotoxy(32, 10);
				eResultado = scanf("%d", &rProducto.eIdCategoria);
							
				if (rProducto.eIdCategoria <= 0 || eResultado == 0) {
								
					gotoxy (4, 24);
					printf ("El ID de la categoría debe ser un número positivo mayor o igual a 1.");
								
				} else {
					
					EspacioEnBlanco ();
					
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
					
					if (rProducto.eIdArticulo[0] == 0 || eResultado == 0) {
						
						gotoxy (4, 24);
						printf ("El ID del artículo debe ser un número positivo mayor o igual a 1.");
						
					} else {
						
						EspacioEnBlanco ();
						
						do {
							
							CentrarTextoEnCuadroChicoIzquierdo("¿Desea agregar otro? [S-s/N-n]: ", 13);
							fflush (stdin);
							cOpcionArticulo = toupper(getchar());
						
							if (cOpcionArticulo == 'S') {
							
								gotoxy (37, 12);
								printf ("   ");
							}
							
							if (cOpcionArticulo != 'S' && cOpcionArticulo != 'N') {
								
								gotoxy (37, 13);
								printf ("   ");
								
								gotoxy (4, 24);
								printf ("Sólo se aceptan los caracteres 'S', 's', 'N' o 'n'.");
								
							} else {
								
								EspacioEnBlanco ();
								
							}
							
						} while (cOpcionArticulo != 'S' && cOpcionArticulo != 'N');
						
					}
								
				} while (rProducto.eIdArticulo[0] == 0 || eResultado == 0 || cOpcionArticulo == 'S');
		
				ePosIdArticulo ++;
		
			} while (rProducto.eIdArticulo[ePosIdArticulo -1] == 0);
			
			//Precio del producto			
			do {
		
				fflush(stdin);
				gotoxy(27, 15);
				eResultado = scanf("%f", &rProducto.fPrecioProducto);
				
				if (rProducto.fPrecioProducto <= 0 || eResultado == 0) {
					
					gotoxy (4, 24);
					printf ("El precio del artículo debe ser un número positivo mayor o igual a 1.");
					
				} else {
					
					EspacioEnBlanco ();
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
					
					EspacioEnBlanco ();
				}
							
			} while (rProducto.fCostoProducto <= 0 || eResultado == 0);
			
			//ID del producto
			
			if (ListaVacia(rLista.pPrimero)) {
				
				rProducto.eIdProducto = 1;
				
			} else {
				
				rProducto.eIdProducto = IdProducto(rLista.pPrimero);
				
			}
				
			CentrarTextoEnCuadroChicoDerecho ("El ID del producto registrado es", 14);
			gotoxy (82, 14);
			printf ("%d", rProducto.eIdProducto);
			
		} 
			
	} while (strcmp (sNombreProducto, rProducto.sNombreProducto) != 0 && ValidarCadena(sNombreProducto) && strlen(sNombreProducto) > 0);
	
	return rProducto;
