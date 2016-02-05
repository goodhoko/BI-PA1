#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double m1, m2, mv, k1, k2, kv, x, y, eps=1e-12;
	printf("Hmotnost a koncentrace #1:\n");
	if(scanf("%lf%lf", &m1, &k1)!=2 || m1 < eps || k1 < 0 || k1 > 1) printf("Nespravny vstup.\n");
	else
	{
		printf("Hmotnost a koncentrace #2:\n");
		if(scanf("%lf%lf", &m2, &k2)!=2 || m2 < 0 || k2 < 0 || k2 > 1) printf("Nespravny vstup.\n");
		else
		{
			printf("Hmotnost a koncentrace vysledku:\n");
			if(scanf("%lf%lf", &mv, &kv)!=2 || mv < 0 || kv < 0 || kv > 1) printf("Nespravny vstup.\n");
			else
			{
				if((mv-(m1+m2)) > eps) printf("Nelze dosahnout.\n");
				else
				{
					if(k1 == k2 && k2 == kv)
					{
						if (mv <= m1)
						{
							x=mv;
							y=0;
						}
						else
						{
							x=m1;
							y=mv-m1;
						}
						printf("%f x #1 + %f x #2\n", x, y);
					}
					else
					{
						x = (mv * (kv - k2)) / (k1 - k2);
						y = mv - x;
						if((x-m1) > eps || (y-m2) > eps || x < -eps || y < -eps)  printf("Nelze dosahnout.\n");
						else{
							printf("%f x #1 + %f x #2\n", x, y);
						}
					}
				}
			}	
		}
	}	
	return 0;
}
