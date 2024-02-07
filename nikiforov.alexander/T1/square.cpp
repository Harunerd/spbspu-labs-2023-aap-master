#include "square.hpp"

using namespace nikiforov;

Square::Square(point_t firstPoint, double length) :
  lPoint(firstPoint),
  length(length)
{
  rPoint = { lPoint.x + length, lPoint.y + length };
  center = { ((rPoint.x + lPoint.x) / 2),((rPoint.y + lPoint.y) / 2) };
}

double Square::getArea() const
{
  return length * length;
}

rectangle_t Square::getFrameRect() const
{
  return rectangle_t{ length, length, center };
}

void Square::move(double x_m, double y_m)
{
  lPoint = { lPoint.x + x_m, lPoint.y + y_m };
  rPoint = { rPoint.x + x_m, rPoint.y + y_m };
  center = { center.x + x_m, center.y + y_m };
}

void Square::move(point_t newCenter)
{
  movePoint = { (newCenter.x - center.x), (newCenter.y - center.y) };
  lPoint = { lPoint.x + movePoint.x, lPoint.y + movePoint.y };
  rPoint = { rPoint.x + movePoint.x, rPoint.y + movePoint.y };
  center = newCenter;
}

void Square::scale(double ratio)
{
  length *= ratio;
  movePoint = { (length / 2), (length / 2) };
  lPoint = { center.x - movePoint.x, center.y - movePoint.y };
  rPoint = { center.x + movePoint.x, center.y + movePoint.y };
}
