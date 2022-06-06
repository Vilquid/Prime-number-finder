#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define e_aigu 130
#define a_circonflexe 131
#define a_grave 133
#define c_cedille 135
#define e_circonflexe 136
#define e_grave 138
#define E_aigu 144
#define u_grave 151

bool is_prime(int);
void titre();
void test(int max_number);
void affichage_des_nombres_premiers(int);

int main()
{

	titre();

	printf("Time taken by the code for the number 10 : 0.000000 sec\n");
	printf("Time taken by the code for the number 100 : 0.015000 sec\n");
	printf("Time taken by the code for the number 1 000 : 0.000000 sec\n");
	printf("Time taken by the code for the number 10 000 : 0.090000 sec\n");
	printf("Time taken by the code for the number 100 000 : 0.719000 sec\n");
	printf("Time taken by the code for the number 100 000 : 94.990000 sec\n");
	printf("\n");
	printf("\n");
	printf("\n");

	printf("Jusqu'%c o%c voulez-vous avoir la liste des nombres premiers ?\n", a_grave, u_grave);
	int max_number = 0;
	scanf("%d", &max_number);
	printf("\n");

//


	// Nettoyage de l'écran
//	#ifdef _WIN32
//		system("cls");
//	#endif
//	#ifdef __linux__
//		system("clear");
//	#endif

	// Fermeture des instructions pré-processées
//	test(max_number);
	affichage_des_nombres_premiers(max_number);


	return 0;
}

bool is_prime(int tested_number)
{
	double square_root = (int) sqrt(tested_number) + 1;

	for (int i = 2; i < square_root; i++)
	{
		if (tested_number % i == 0)
		{
			return false;
		}
	}

	return true;
}

void titre()
{
//	printf(" ____  ____  _  _      _____   _      _     _      ____  _____ ____    _____ _  _      ____  _____ ____\n");
//	printf("/  __\\/  __\\/ \\/ \\__/|/  __/  / \\  /|/ \\ /\\/ \\__/|/  _ \\/  __//  __\\  /    // \\/ \\  /|/  _ \\/  __//  __\\\n");
//	printf("|  \\/||  \\/|| || |\\/|||  \\    | |\\ ||| | ||| |\\/||| | //|  \\  |  \\/|  |  __\\| || |\\ ||| | \\||  \\  |  \\/|\n");
//	printf("|  __/|    /| || |  |||  /_   | | \\||| \\_/|| |  ||| |_\\\\|  /_ |    /  | |   | || | \\||| |_/||  /_ |    /\n");
//	printf("\\_/   \\_/\\_\\\\_/\\_/  \\|\\____\\  \\_/  \\|\\____/\\_/  \\|\\____/\\____\\\\_/\\_\\  \\_/   \\_/\\_/  \\|\\____/\\____\\\\_/\\_\\\n");
//	printf("\n");
//	printf("\n");
}

void test(int max_number)
{
	while (max_number <= 100000)
	{
		int tested_number = 2;
		printf("Liste des nombres premiers jusqu'%c %d :\n",a_grave, max_number);

		// Début du chronométrage
		clock_t time = clock();
		while (tested_number <= max_number)
		{
			if (is_prime(tested_number))
			{
				printf(".", tested_number);
			}

			tested_number++;
		}
		time = clock() - time;
		printf("Time taken by the code for the number %d : %f sec\n", max_number, ((double)time)/CLOCKS_PER_SEC);
		printf("\n");

		max_number *= 10;
	}
}

void affichage_des_nombres_premiers(int max_number)
{
	unsigned long int tested_number = 2;
	unsigned long int tableau[max_number];
	unsigned long int indice_tableau = 0;
	memset(tableau, 0, sizeof(tableau));
	printf("Liste des nombres premiers jusqu'%c %d :\n",a_grave, max_number);

	// Début du chronométrage
//	clock_t time = clock();
	printf("\n");
	while (tested_number <= max_number)
	{
		if (is_prime(tested_number))
		{
			tableau[indice_tableau] = tested_number;
			indice_tableau++;
		}

		tested_number++;
	}
//	time = clock() - time;

//	printf("  -  %d\n", tested_number);

	for (unsigned long long i = 0; i < indice_tableau || tableau[i] < 0; i++)
	{
		printf("  -  %llu\n", tableau[i]);
	}
//	printf("Time taken by the code %f sec.\n", ((double)time)/CLOCKS_PER_SEC);
}