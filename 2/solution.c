#include <stdio.h>
#include <math.h>

void funkce1(int d1, int d2, int dv)            
{
	int p1, p2, k = 0, i;
	for(i = 0; i <= dv/d2; ++i)
	{
		if((dv-(i*d2))%d1 == 0)
		{
			p2 = i;
			p1 = (dv-(i*d2))/d1;
			printf("= %d * %d + %d * %d\n", d1, p1, d2, p2);
			k++;
		}
	}
	if (k == 0)
		printf("Reseni neexistuje.\n");
	else
		printf("Celkem variant: %d\n", k);
}

void funkce2(int d1, int d2, int dv)
{
	int k =0, i;
	for(i = 0; i <= dv/d2 ; ++i)
	{
		if((dv-(i*d2))%d1 == 0)
		{
			k++;
		}
	}
	if(k == 0)
		printf("Reseni neexistuje.\n");
	else
		printf("Celkem variant: %d\n", k);
}


int main(){
	int d1, d2, dv;					/*d1, d2 = delky segmentu, dv = vysledna delka trati, p1, p2 = vysledne pocty segmentu, k = pocet moznych kombinaci*/
	char o;							/*ovladac "+" nebo "-" pro ovladani vystupu*/
	printf("Delky koleji:\n");
	if(scanf("%d%d", &d1, &d2) != 2 || d1 == d2 || d1 <= 0 || d2 <= 0) printf("Nespravny vstup.\n");
	else
	{
		printf("Vzdalenost:\n");
		if(scanf(" %c %d", &o, &dv)!=2 || dv < 0 || !(o == '+' || o == '-'))  printf("Nespravny vstup.\n");
		else
		{
			if(o == '+')
				funkce1(d1, d2, dv);
			else
				funkce2(d1, d2, dv);
		}
	}
	
	return 0;
}
