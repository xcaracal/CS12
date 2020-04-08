#include "minFunc.h"
const int* min(const int arr[], int arrSize)
{
    const int* small;
    if(arrSize <= 1)
    {
        return arr;
    }
    else
    {
        small = min(arr, arrSize-1);
        if(*small < arr[arrSize-1])
        {
            return small;
        }
        else
        {
            return &arr[arrSize-1];
        }
    }
}