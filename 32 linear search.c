#include <stdio.h>
int main() 
{
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int array[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
	{
        scanf("%d", &array[i]);
    }
    printf("Enter the key to search for: ");
    scanf("%d", &key);
    int found = 0; 
    for (int i = 0; i < size; i++) 
	{
        if (array[i] == key) 
		{
            found = 1; 
            printf("Element found at index %d\n", i);
            break;
        }
    }
    if (!found) 
	{
        printf("Element not found in the array\n");
    }
    return 0;
}
