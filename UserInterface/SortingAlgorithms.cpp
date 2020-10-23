#include "SortingAlgorithms.hpp"

extern int swap_count(0);
extern int comp_count(0);

float * BubbleSort(float * numbers, int count)
{
    if (count >= 2)
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (numbers[j] > numbers[j + 1])
                {
                    Swap(&numbers[j], &numbers[j + 1]);
                }
                
                comp_count++;
            }
        }
    }
    
    return numbers;
}

float * SelectionSort(float * numbers, int count)
{
    if (count >= 2)
    {
        int max_index = 0;
        
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - i; j++)
            {
                if (numbers[j] > numbers[max_index])
                {
                    max_index = j;
                }
                
                comp_count++;
            }
            
            Swap(&numbers[max_index], &numbers[count - i - 1]);
            
            max_index = 0;
        }
    }
    
    return numbers;
}

void Swap(float * a, float * b)
{
    float change_val = *a;
    *a = *b;
    *b = change_val;
    
    swap_count++;
}
