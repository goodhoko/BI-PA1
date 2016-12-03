#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int max(int a, int b)
{
	return (a < b) ? b : a;
}

void arraynuller(int *array, int count)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		array[i] = 0;
	}
}

int sumArray(int *array, int count)
{
	int max=0, i;
	for (i = 0; i < count; ++i)
	{
		max += array[i];
	}
	return max;
}
void copyArray(char *from, char *to, int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		to[i] = from[i];
	}
}

int dieselgate(int *valves, int *maxsum, int count, char *exhaust, char *tmpExhaust, int depth, int a, int b, int c, char option)
{
	if (option == 'a')
		tmpExhaust[depth-1] = 'a';
	if (option == 'b')
		tmpExhaust[depth-1] = 'b';
	if (option == 'c')
		tmpExhaust[depth-1] = 'c';

	if (depth == count)
	{
		if (*maxsum > max(a, max(b, c)))
		{
			*maxsum = max(a, max(b, c));
			copyArray(tmpExhaust, exhaust, count);
		}
		return max(a, max(b, c));
	}
	return min(dieselgate(valves, maxsum, count, exhaust, tmpExhaust, depth+1, a + valves[depth], b, c, 'a'), min(dieselgate(valves, maxsum, count, exhaust, tmpExhaust, depth+1, a, b + valves[depth], c, 'b'), dieselgate(valves, maxsum, count, exhaust, tmpExhaust, depth+1, a, b, c + valves[depth], 'c')));
}

void printdata(int *valves, int count, char *exhaust)
{
	int i, j;

	j = 0;
	printf("A: ");
	for (i = 0; i < count; ++i)
	{
		if(exhaust[i] == 'a')
			{
				if (j)
					printf(", ");
				printf("%d", valves[i]);
				j = 1;
			}
	}
	printf("\n");

	j = 0;
	printf("B: ");
	for (i = 0; i < count; ++i)
	{
		if(exhaust[i] == 'b')
			{
				if (j)
					printf(", ");
				printf("%d", valves[i]);
				j = 1;
			}
	}
	printf("\n");

	j = 0;
	printf("C: ");
	for (i = 0; i < count; ++i)
	{
		if(exhaust[i] == 'c')
			{
				if (j)
					printf(", ");
				printf("%d", valves[i]);
				j = 1;
			}
	}
	printf("\n");
}

int minMax(int *valves, int count, int a, int b, int c )
 {
   if (! count)
    return (max(a, max(b, c)));
   return (min(minMax ( valves + 1, count - 1, a + *valves, b, c ), min(minMax ( valves + 1, count - 1, a, b + *valves, c ), minMax ( valves + 1, count - 1, a, b, c + *valves ))));
 }

/*reads values from stdin, alocates int array for them a returns pointer to it. returns NULL if input was invalid. Count of valves is saved to count.*/
int *getdata(int *count)
{
	int tmp, checker;
	int *tmpValves = NULL;
	while((checker = scanf("%d", &tmp)) != EOF)
	{
		if (checker != 1 || tmp <= 0)
		{
			free(tmpValves);
			return NULL;
		}
		else
		{
			++*count;
			tmpValves = (int*)realloc(tmpValves, (*count)*sizeof(int));
			tmpValves[*count - 1] = tmp;
		}
	}
	return tmpValves;
}

int main(){
	int *valves, count = 0, tmp = 0, *maxsum = &tmp;
	char *exhaust, *tmpExhaust;

	printf("Emise ventilu:\n");

	if ((valves = getdata(&count)) == NULL || count == 0)
	{
		printf("Nespravny vstup.\n");
		free(valves);
		return 1;
	}
	if (count == 1)
	{
		printf("Nejvyssi emise: %d\n", *valves);
		printf("A: %d\nB:\nC:\n", *valves);
		return 0;
	}

	exhaust = (char*)malloc(count*sizeof(char));
	tmpExhaust = (char*)malloc(count*sizeof(char));
	*maxsum = sumArray(valves, count);

	/*printf("minmax vraci: %d\n", minMax(valves, count, 0, 0, 0));*/
	printf("Nejvyssi emise: %d\n", dieselgate(valves, maxsum, count, exhaust, tmpExhaust, 0, 0, 0, 0, 'x'));
	printdata(valves, count, exhaust);

	free(valves);
	free(exhaust);
	free(tmpExhaust);
	return 0;
}
