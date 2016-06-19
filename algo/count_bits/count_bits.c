#include <stdio.h>
#include <stdint.h>

uint32_t count_bit_one(uint32_t target);

int main(int argc, char *argv[]) {
    printf("Count 0: %d\n", count_bit_one(0));
    printf("Count 1: %d\n", count_bit_one(1));
    printf("Count 0x952D: %d\n", count_bit_one(0x952D));

    return 0;
}

uint32_t count_bit_one(uint32_t target) {
    uint32_t count = 0;
    while (0 != target) {
        ++count;
        target &= target - 1;
    }

    return count;
}
