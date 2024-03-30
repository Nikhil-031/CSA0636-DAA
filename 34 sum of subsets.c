#include <stdio.h>
void printSubset(int subset[], int subsetSize) 
{
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) 
	{
        printf("%d ", subset[i]);
    }
    printf("}\n");
}
void findSubsets(int numbers[], int size, int targetSum, int subset[], int subsetSize, int currentIndex, int currentSum) 
{
    if (currentSum == targetSum) 
	{
        printSubset(subset, subsetSize);
        return;
    }
    if (currentIndex == size) 
	{
        return;
    }
    subset[subsetSize] = numbers[currentIndex];
    findSubsets(numbers, size, targetSum, subset, subsetSize + 1, currentIndex + 1, currentSum + numbers[currentIndex]);
    findSubsets(numbers, size, targetSum, subset, subsetSize, currentIndex + 1, currentSum);
}
int main() 
{
    int size, targetSum;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int numbers[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) 
	{
        scanf("%d", &numbers[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    int subset[size];
    findSubsets(numbers, size, targetSum, subset, 0, 0, 0);
    return 0;
}
