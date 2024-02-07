#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace doroshenko
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& destination) = 0;
    virtual void move(double moveX, double moveY) = 0;
    virtual void scale(double coefficient) = 0;
  };
}

#endif
