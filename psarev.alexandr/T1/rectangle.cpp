#include "rectangle.hpp"
#include <cmath>

using namespace psarev;

Rectangle::Rectangle(point_t firPoint, point_t secPoint) :
  llCorner(firPoint), urCorner(secPoint)
{
  center = { (llCorner.x + urCorner.x) / 2, (llCorner.y + urCorner.y) / 2 };
}

rectangle_t Rectangle::getFrameRect() const
{
  return { fabs(llCorner.x - urCorner.x), fabs(llCorner.y - urCorner.y), center };
}

double Rectangle::getArea() const
{
  return ((urCorner.x - llCorner.x) * (urCorner.y - llCorner.y));
}

void Rectangle::move(const point_t newCenter)
{
  double centerXCh = newCenter.x - center.x;
  double centerYCh = newCenter.y - center.y;
  llCorner.x += centerXCh;
  llCorner.y += centerYCh;
  urCorner.x += centerXCh;
  urCorner.y += centerYCh;
  center = newCenter;
}

void Rectangle::move(double xCh, double yCh)
{
  llCorner.x += xCh;
  llCorner.y += yCh;
  urCorner.x += xCh;
  urCorner.y += yCh;
  center = { center.x + xCh, center.y + yCh };
}

void Rectangle::scale(double coef)
{
  llCorner.x = llCorner.x * coef + (1 - coef) * center.x;
  llCorner.y = llCorner.y * coef + (1 - coef) * center.y;
  urCorner.x = urCorner.x * coef + (1 - coef) * center.x;
  urCorner.y = urCorner.y * coef + (1 - coef) * center.y;
}
