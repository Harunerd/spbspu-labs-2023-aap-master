#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace sukacheva
{
  struct point_t
  {
    public:
    point_t(double x, double y);
    double x_;
    double y_;
  };

  struct rectangle_t
  {
    public:
    rectangle_t(double width, double height, point_t pos);
    double width_;
    double height_;
    point_t pos_;
  };
}
#endif
