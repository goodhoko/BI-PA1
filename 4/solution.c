#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	/*the office dimensions, day counter, infected people counter, temporary iCounter for use in cycle*/
	int rows, cols, dCounter=0, iCounter=0, iCounterTMP = 0, i, j, c;
	int office[502][502];
	int tmp[502][502];

	/*office initilization => all places will be empty by default*/
	for (i = 0; i < 502; ++i)
	{
		for (j = 0; j < 502; ++j)
		{
			office[i][j] = 0;
			tmp[i][j] = 0;
		}
	}

	printf("Velikost kancelare:\n");

	/*reading input*/
	if (scanf("%d%d", &rows, &cols)!=2 || rows > 500 || cols > 500 || rows < 1 || cols < 1)
	{
		printf("Nespravny vstup.\n");
		return 1;
	}
	else 
	{
		/*checks if there is \n after office dimensions*/
		if (getchar()!='\n')
		{
			printf("Nespravny vstup.\n");
			return 1;
		}
		else
		{
			/*reads the map of the office and stores it into array*/
			i=1;
			j=1;
			while((c=fgetc(stdin))!=EOF)
			{
				/*checks validity of input characters*/
				if (c!='o' && c!='.' && c!='!' && c!='\n')
				{
					printf("Nespravny vstup.\n");
					return 1;
				}
				/*if there is \n, checks if number of characters in line fits declared number of columns, then go to the next line*/
				else if (c=='\n')
					{
						if(j!=cols+1)
						{
							printf("Nespravny vstup.\n");
							return 1;
						}
						i++;
						j=1;
					}
					/*writes the input to the array and counts infected people*/
					else
					{
						if (c=='o') office[i][j]=1;
						if (c=='!')
							{
								office[i][j]=2;
								iCounter++;
							}
						j++;
					}
			}
			/*checks if office has declared number of rows*/
			if (i!=rows+1)
			{
				printf("Nespravny vstup.\n");
				return 1;
			}
			/*checks if the there is atleast one infected person*/
			if (iCounter==0)
			{
				printf("Nikdo neonemocnel.\n");
				return 1;
			}
			else
			{
				/*cycle, that checks if number of infected increased.*/
				do
				{
					iCounterTMP=iCounter;
					/*switch between writing office > tmp and tmp > office*/
					if ((dCounter%2)==0)
					{
						for (i = 1; i <= rows; ++i)
						{
							for (j = 1; j <= cols; ++j)
							{
								if (office[i][j]==1)
								{
									if (office[i-1][j]==2 || office[i][j+1]==2 || office[i+1][j]==2 || office[i][j-1]==2)
									{
										tmp[i][j]=2;
										iCounter++;									
									}
									else
									{
										tmp[i][j]=1;
									}
								}
								if (office[i][j]==2)
								{
									tmp[i][j]=2;
								}
							}
						}
					}
					else
					{
						for (i = 1; i <= rows; ++i)
						{
							for (j = 1; j <= cols; ++j)
							{
								if (tmp[i][j]==1)
								{
									if (tmp[i-1][j]==2 || tmp[i][j+1]==2 || tmp[i+1][j]==2 || tmp[i][j-1]==2)
									{
										office[i][j]=2;
										iCounter++;
									}
									else
									{
										office[i][j]=1;
									}
								}
								if (tmp[i][j]==2)
								{
									office[i][j]=2;
								}
							}
						}
					}
					dCounter++;
				} while(iCounter!=iCounterTMP);
				
				printf("Nakazenych: %d, doba sireni nakazy: %d\n", iCounter, dCounter-1);
			}

		}		
	}
	return 0;
}
