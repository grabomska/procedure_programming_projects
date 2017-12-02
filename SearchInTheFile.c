#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int file(const char * fName, const char * exp)
{
	int line = 1;
	int position = 1;
	int found = 0;

	char arr[512];
	char *splt;
	char *string;

	FILE * file;
	file = fopen(fName,"r");

	/*Checking successful opening*/
	if (file != NULL)
	{
		/**/
		while(fgets(arr,512,file) != NULL)
		{
			/*splitting the line into words*/
			splt = strtok(arr," ");
			int wI = 0; /*word index*/

			/*searching needed expression in the line */
			while (splt != NULL)
			{
				string = strstr(splt,exp);


				if(string != NULL)
				{
					position = (strlen(arr) - strlen(string)) + (wI * (strlen(string)) + 1);
					printf("%d:%d %s\n", line, position, exp);
					found++;
				}

				splt = strtok(NULL, " ");
				wI++;
			}

			line++;
		}
	}
	else
	{
		printf("File is not opened successfully");
		return 1;
	}

	if (found == 0)
	{
		printf("No matches\n");
	}
	else
		printf("quantity of matches: %d", found);

	fclose(file);
	return 0;
}



int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		/*checking file extension*/
		if (strstr(argv[1], ".txt") == NULL)
		{
		    printf("File is not txt\n");
		    exit (1);
		}
		else
			file(argv[1],argv[2]);

	}
	else
	{
		printf("Correct form: %s file.txt expression\n", argv[0]);
		exit (1);
	}

	return 0;
}

