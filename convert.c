#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void convert (float temp, char type) 
{
    switch (type) 
    {
        case 'C':
        case 'c':
            if (temp < -273.15){
                printf("Temperature is below absolute zero");
                break;
            }
            else{
                float k = temp + 273.15;
                float f = (temp * 9 / 5) + 32; 
                printf ("%.2f C:\n", temp);
                printf ("%.2f K:\n",  k);
                printf ("%.2f F:\n", f);
                break;
            }
        
        case 'K':
        case 'k':
            if (temp < 0){
                printf("Temperature is below absolute zero");
                break;
            }
            else {
                float c = temp - 273.15;
                float f = (temp / 5 * 9) - 459.67;
                printf ("%.2f K: \n", temp);
                printf ("%.2f C: \n",  c);
                printf ("%.2f F: \n", f); 
            break;
            }
        
        case 'F':
        case 'f':
            if (temp < -459.67) {
                printf("Temperature is below absolute zero");
                break;
            }
            else {  
                float c = (temp - 32) * 5 / 9;
                float k = (temp + 459.67) * 5 / 9;
                printf ("%.2f F: \n", temp);
                printf ("%.2f C: \n",  c);
                printf ("%.2f K: \n", k); 
                break;
            }
       
        default: 
            if (temp < -273.15) {
                printf("Temperature is below absolute zero");
                break;
            }
            else {
                float k = temp + 273.15;
                float f = (temp * 9 / 5) + 32; 
                printf ("%.2f C: \n", temp);
                printf ("%.2f K: \n",  k);
                printf ("%.2f F: \n", f);
                break;
            }
    } 
      
}

int main()
{
    float value;
    char s;
    printf("Please type temperature and scale\n");    
    scanf("%f%c",&value,&s);
    convert(value,s);
    getch();
    return 0;
}
