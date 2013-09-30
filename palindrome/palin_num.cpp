#include <stdio.h>
#include <stdlib.h>

unsigned int reverse(unsigned int num) 
{
    unsigned int rev = 0;

    while (num) 
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }

    return rev;
}

bool isPalindrome(int x) 
{
  if (x < 0) return false;
  int div = 1;
  while (x / div >= 10) {
    div *= 10;
  }        
  while (x != 0) {
    int l = x / div;
    int r = x % 10;
    if (l != r) return false;
    // remove l and r
    // l -------------- r
    x = (x % div) / 10;
    // remove l and r 2 digits
    div /= 100;
  }
  return true;
}

int main(int argc, char* argv[]) 
{
    unsigned int num = 616;

    printf("%d\n", argv[1] ? reverse(atoi(argv[1])) : reverse(num));
    
    printf("%d\n", argv[1] ? isPalindrome(atoi(argv[1])) : isPalindrome(num));

    return 0;
}
