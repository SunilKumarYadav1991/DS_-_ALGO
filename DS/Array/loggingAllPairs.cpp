/******************************************************************************
Log all the pairs
*******************************************************************************/

#include <iostream>
void logAllPairOfArray(int array[], int size)
{
    for(int i=0; i<size;++i)
        for(int j=0; j<size; ++j)
        std::cout<<array[i]<<", "<<array[j] <<std::endl;
}
int main()
{
    int a[5]={1,2,3,4,5};
    
	logAllPairOfArray(a,5);

    return 0;
}
