#ifndef BASE_TYPE_HPP
#define BASE_TYPE_HPP
#include <iostream>

namespace nikiforov
{
  struct point_t
  {
    double x = 0.0;
    double y = 0.0;
  };

  struct rectangle_t
  {
    double width = 0.0;
    double height = 0.0;
    point_t pos = { 0,0 };
  };
}

#endif
