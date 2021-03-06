#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

uint32_t reverseSelectedBits(uint32_t v, uint8_t lo, uint8_t hi) {
  uint32_t revBits = 0;
  uint32_t mask = 0;
  
  // 1101|0101 --> 1101|1010
  for (int i=lo; i<=hi; ++i) {
    int shift = hi - (i-lo);
    bool set = v & (1 << i);
    revBits |= ((uint32_t)set) << shift;
    mask |= 1 << i;
  }

  revBits |= v & ~mask;

  return revBits;
}

int main(int argc, char *argv[]) {
  uint32_t val;

  // 1101|0101 --> 1101|1010
  val = reverseSelectedBits(0xd5, 0, 3);
  printf("Input: 0xd5 Output: 0x%02x Expected: 0xda\n", val);

  // 1101|0101 --> 1011|0101
  val = reverseSelectedBits(0xd5, 4, 7);
  printf("Input: 0xd5 Output: 0x%02x Expected: 0xb5\n", val);
  
  // 1|101010|1 --> 1|010101|1
  val = reverseSelectedBits(0xd5, 1, 6);
  printf("Input: 0xd5 Output: 0x%02x Expected: 0xab\n", val);
}
