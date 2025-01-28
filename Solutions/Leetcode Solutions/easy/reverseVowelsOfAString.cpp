#include "../../../helperFunctions.h"

using namespace std;

/******************************************
  Link: https://leetcode.com/problems/reverse-vowels-of-a-string/description/
  Runtime: 100.00%
  Memory: 82.35%
******************************************/

string reverseVowelsOfAString(string s)
{
  int i = 0;
  int j = s.size() - 1;

  while (i < j)
  {
    char firstLetter = s[i];
    char secondLetter = s[j];
    bool shouldSwap = true;
    if (!(firstLetter == 'a' || firstLetter == 'A' || firstLetter == 'e' || firstLetter == 'E' || firstLetter == 'i' || firstLetter == 'I' || firstLetter == 'o' || firstLetter == 'O' || firstLetter == 'u' || firstLetter == 'U'))
    {
      ++i;
      shouldSwap = false;
    }
    if (!(secondLetter == 'a' || secondLetter == 'A' || secondLetter == 'e' || secondLetter == 'E' || secondLetter == 'i' || secondLetter == 'I' || secondLetter == 'o' || secondLetter == 'O' || secondLetter == 'u' || secondLetter == 'U'))
    {
      --j;
      shouldSwap = false;
    }
    if (shouldSwap)
    {
      swap(s[i], s[j]);
      ++i;
      --j;
    }
  }

  return s;
}

int main()
{
  cout << reverseVowelsOfAString("IceCreAm") << endl;
  return 0;
}