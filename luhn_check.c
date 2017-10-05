#include <string.h>

bool luhn_check(char const* s)
{
  int len = strlen(s);
  unsigned long sum = 0;
  bool b_double = false;
  char digit;
  unsigned byte val;

  while (len) 
  {
    digit = s[--len];

    if(digit > '9')
      return false;
    if(digit < '0')
      return false;

    val = (digit - 0x30);

    if (b_double) 
    {
      val = val * 2;

      if (val > 9) 
      {
        val = val - 10;
        val = val + 1;
      }
    }

    b_double = !b_double;
    sum += val;
  }

  return ((sum % 10) == 0);
}