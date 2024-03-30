#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_BINS 100

int main() {
    int items[MAX_ITEMS];
    int num_items, bin_capacity;
    int bins[MAX_BINS] = {0};
    int num_bins = 0;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    printf("Enter the capacity of each bin: ");
    scanf("%d", &bin_capacity);
    printf("Enter the sizes of %d items:\n", num_items);
    for (int i = 0; i < num_items; i++) {
        scanf("%d", &items[i]);
    }
    for (int i = 0; i < num_items; i++) {
        int item_size = items[i];
        int bin_found = 0;
        for (int j = 0; j < num_bins; j++) {
            if (bins[j] >= item_size && bins[j] + item_size <= bin_capacity) {
                bins[j] += item_size;
                bin_found = 1;
                break;
            }
        }
        if (!bin_found) 
		{
            bins[num_bins++] = item_size;
        }
    }
    printf("Number of bins used: %d\n", num_bins);
    for (int i = 0; i < num_bins; i++) 
	{
        printf("Bin %d: %d\n", i + 1, bins[i]);
    }
    return 0;
}
