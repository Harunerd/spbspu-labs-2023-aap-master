#ifndef T1_SHAPE_H
#define T1_SHAPE_H
#include "base-types.hpp"

namespace tellez
{
  class Shape
  {
    public:
      virtual double getArea() const = 0;
      virtual rectangle_t getFrameRect() const = 0;
      virtual void move(double dx, double dy) = 0;
      virtual void move(point_t position) = 0;
      virtual void scale(double ds) = 0;
      virtual Shape * clone() const = 0;
      virtual ~Shape() = default;
  };
}
#endif
