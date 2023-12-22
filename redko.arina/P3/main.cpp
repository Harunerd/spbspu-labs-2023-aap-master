#include <iostream>
#include "getString.hpp"
#include "buildWithoutInt.hpp"

int main()
{
  const int add = 10;
  char * str = new char[add];
  int lenght = 0;
  str = redko::getString(str, lenght, add);
  if (!str)
  {
    std::cerr << "Error: can't allocate memory for input string\n";
    delete[] str;
    return 1;
  }
  if (!str[0])
  {
    std::cerr << "Error: empty string\n";
    delete[] str;
    return 1;
  }
  char * strResult = new char[lenght];
  if (!strResult)
  {
    std::cerr << "Error: can't allocate memory for result\n";
    delete[] str;
    return 1;
  }
  int lenResult = redko::buildWithoutInt(strResult, str, lenght);
  delete[] str;
  for (int i = 0; i < lenResult-1; i++)
  {
    std::cout << strResult[i];
  }
  std::cout << '\n';
  delete[] strResult;
  return 0;
}
