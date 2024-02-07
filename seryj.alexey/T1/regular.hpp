#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "shape.hpp"
namespace seryj {
  class Regular : public Shape
  {
  public:
    Regular(point_t a, point_t b, point_t c);
    virtual double getArea()const;
    virtual rectangle_t getFrameRect()const;
    virtual void move(const point_t&);
    virtual void move(const double& x,const double& y);
    virtual void scale(double k);
  private:
    int amount_of_sides_ = 0;
    double hypotenuse_ = 0;
    point_t pos_ = { 0,0 };
    point_t point_b_ = { 0,0 };
    point_t point_c_ = { 0,0 };
  };
}
#endif
