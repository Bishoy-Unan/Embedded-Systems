#include<stdarg.h>
#include<stdio.h>

//variadic functions to add numbers
int addNumbers(int n,...)
{
    
    int sum = 0;
    //declaring pointer to the argument list
    va_list ptr;
    //intializing argument to the list pointer
    va_start(ptr,n);
    for(int i=0; i < n ;i++)
    {
        // accessing current variable and pointing to next one 
        sum+= va_arg(ptr, int);
    }
    //ending argument list traversal
    va_end(ptr);

    return sum;

}/* AddNumbers function */


// variadic function to find the largest number
int LargestNumber(int n,...)
{
    // declaring pointer to argument list
    va_list ptr;
    //intializing argument to the list pointer 
    va_start (ptr, n);
    int max = va_arg(ptr ,int);

    for(int i=0 ;i< n-1;i++)
    {
        //accessing current variable and pointing to the next
        int temp = va_arg(ptr, int);
        max = temp > max ? temp : max ;
    }

    //end of argument traversal
    va_end(ptr);

return max ;
}/* LargestNumber function */

int mian(void)
{
    printf("\n\n variadic functions: \n");
    //variable number of argument
    printf("\n 1 +  2 = %d",addNumbers(2,1,2));
    printf("\n 1 +  2  + 3 = %d",addNumbers(3,1,2,3));
    printf("\n 1 +  2  + 3 + 4 = %d",addNumbers(4,1,2,3,4));
    printf("\n\n\n");

    printf("\n %d",LargestNumber(2,1,3));
    printf("\n %d",LargestNumber(3,1,3,4));
    printf("\n %d",LargestNumber(4,1,7,8,9));
    printf("\n\n\n");
    


    return 0;
}