#include<stdio.h>


int main(void)
{
    int i , n=3;
    char str[50];
    //open file logging.txt in write mode 
    FILE * fptr = fopen("logging.txt","w");
    if(fptr == NULL)
    {
        printf("coud not open file");
        return 0;
    } 
    for(i=0;i<n;i++)
    {
        puts("Enter a name ");
        scanf(" %[^\n]%*c ",str);
        fprintf( fptr, "%d.%s\n",i,str);
    }
    fclose(fptr);


    return 0;
}


