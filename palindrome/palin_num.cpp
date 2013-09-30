#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int m_pos(const char* nptr, int c) 
{
    int pos = 0;

    while (*nptr) 
    {
        if (*nptr == c) 
            return pos;
        nptr++;
        pos++;
    }

    return pos;
}

int m_atoi(const char* nptr) 
{
    bool isNegative = false;
    int i = 0;
    int mul = strlen(nptr) - 1;

    if (index(nptr, '.')) 
        mul = m_pos(nptr, '.') - 1;

    if (*nptr == '-') 
        isNegative = true;
    else 
        i += (*nptr - 48) * pow(10, mul);

    nptr++;
    mul--;

    while (*nptr) 
    {
        if (*nptr == '.')
            break;
        i += (*nptr - 48) * pow(10, mul);
        nptr++;
        mul--;
    } 
   
    if (isNegative)
        return 0 - i;

    return i;
}

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

    printf("%d\n", argv[1] ? m_atoi(argv[1]) : num);
    printf("%d\n", argv[1] ? atoi(argv[1]) : num);

    printf("%d\n", argv[1] ? reverse(atoi(argv[1])) : reverse(num));
    
    printf("%d\n", argv[1] ? isPalindrome(atoi(argv[1])) : isPalindrome(num));

    return 0;
}
