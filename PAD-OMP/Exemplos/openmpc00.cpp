// Windows
/*
#include <windows.h>  
#include <assert.h>  
#include <stdio.h>  
#include <omp.h>  
*/

// Linux
#include <omp.h>
#include <cstdio>

int main(int argc, char *argv[]){
	printf("\nOla 1 - Regiao Serial ... \n\n");
	#pragma omp parallel
	{
		printf("\nOla 2 - Regiao Paralela... \n\n");
	}
	printf("\nOla 3 - Regiao Serial... \n\n");
	return 0;
}