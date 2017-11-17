#include <stdio.h>
#include <stdlib.h>


int numberOfAge(int y)
{
	int n;
	int fY = y/100;
	n = 5 * (fY % 4);
	if (n >= 7)
	{
		n = n - 7;
	}
	return n;
}

int calculateDay(int d, int m, int y)
{
	int res = 0;
	int noa = numberOfAge(y);
	int fS; /*result of first step*/
	int sS; /*result of second step*/
	int sY = y % 100; /*the second two digits of year */
	/*////////////////FIRST STEP/////////////////////*/
	fS = (d + m) % 7;
	/*////////////////SECOND STEP//////////////////////*/
	sS=(sY % 28) + (sY / 4) + noa;
	if ((m == 1 || m == 2) && ((y%4 == 0 && y%100 != 0) || y%400 == 0))
	{
		sS = sS - 1;
	}
	/*////////////////THIRD STEP/////////////////////////*/
	res = fS + sS - 1;
	if (res > 6)
	{
		res = res % 7;
	}

	return res;
}

int main ()
{
	int d, m, y;
	/*char c;*/
	int dow = 0; /*day of week*/
	printf("Please type date: DD MM YYYY (example: 1 1 2017 = 01.01.2017) \n");
	scanf("%d%d%d", &d, &m, &y);
	printf("Your date is %d.%d.%d\n", d, m, y);
	dow = calculateDay(d,m,y);
	switch (dow)
	{
		case 0:
		case 7: printf("Day of week is Saturday"); break;
		case 1: printf("Day of week is Sunday"); break;
		case 2: printf("Day of week is Monday"); break;
		case 3: printf("Day of week is Tuesday"); break;
		case 4: printf("Day of week is Wednesday"); break;
		case 5: printf("Day of week is Thursday"); break;
		case 6: printf("Day of week is Friday"); break;
	}

	return 0;
}
