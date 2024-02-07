#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace miheev
{
  class Triangle: public Shape
  {
  public:
    Triangle(point_t p1, point_t p2, point_t p3);
    ~Triangle() override;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t) override;
    void move(double dx, double dy) override;
    void scale(double) override;

  private:
    point_t* points_;
    point_t center_;
  };
};

#endif
