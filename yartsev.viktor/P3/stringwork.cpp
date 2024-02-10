#include "stringwork.hpp"
#include <iostream>

void yartsev::readstring(char * str)
{
  size_t read = 0;
  size_t size = 10000;
  std::cin >> std::noskipws;
  std::cin >> str[0];
  read++;
  if (str[0] == '\n') {
    throw std::logic_error("Wrong input: empty string");
  }
  char symbol = 0;
  while ((std::cin >> symbol) && (symbol != '\n')) {
    if (read == size) {
      try {
        size = yartsev::resizestring(str, read);
      } catch (std::bad_alloc) {
        throw;
      }
    }
    str[read++] = symbol;
  }
  std::cin >> std::skipws;
}

size_t yartsev::resizestring(char *& str, const size_t cursize, const size_t addsize)
{
  char * newstr = nullptr;
  try {
    newstr = new char [cursize + addsize];
  } catch (std::bad_alloc & e) {
    throw;
  }
  for (int i = 0; i < cursize; i++) {
    newstr[i] = str[i];
  }
  delete [] str;
  str = newstr;
  return cursize + addsize;
}
