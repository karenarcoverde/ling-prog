/*****************************************************************************/
/*************************** Arquivo fibonacci.cpp ***************************/

int resultadoFibonacci (int indice) {

	// Índice não positivos devem ser tratados na função principal

	if (indice == 0)	
		return 0;
	else if (indice == 1)
		return 1;
	else
		return resultadoFibonacci (indice - 1) + resultadoFibonacci (indice - 2);
}

