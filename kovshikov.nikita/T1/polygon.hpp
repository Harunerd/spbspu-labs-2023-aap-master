#ifndef POLYGON_HPP
#define POLYGON_HPP
#include "shape.hpp"
#include <cstddef>
#include <algorithm>
#include <stdexcept>

namespace kovshikov
{
  class Polygon: public Shape
  {
  public:
    Polygon(size_t num, point_t * points);
    virtual ~Polygon(); // нужны ли еще какие то специальные методы?
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &newPos);
    virtual void move(double xPlus, double yPlus);
    virtual void scale(double multiplier);
    point_t getPos();
  private:
    size_t num_;
    point_t * points_ = nullptr;
  };
}

#endif
