#include <stdio.h>

int main(void) {
    int counter[10] = { 0 };

    int number;
    while (scanf("%d", &number) && number != 0)
        counter[number % 10]++;

    for (int i = 0; i < 10; i++)
        printf("%d: %d개\n", i, counter[i]);

    return 0;
}
