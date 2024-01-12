#include "parallelogram.hpp"
#include "base-types.hpp"
#include <iostream>
#include <cmath>
#include "equalityOfPoints.hpp"

sukacheva::Parallelogram::Parallelogram(const point_t& A, const point_t& B, const point_t& C):
  A_(A),
  B_(B),
  C_(C)
{

  if ((sukacheva::arePointsEqual(A_, B_) && sukacheva::arePointsEqual(C_, B_))
    || !(A_.y == B_.y || B_.y == C_.y))
  {
    throw std::logic_error("wrong parameters\n");
  }
}

double sukacheva::Parallelogram::getArea() const
{
  double height = std::abs(std::max(std::max(A_.y, B_.y), C_.y) -
    std::min(std::min(A_.y, B_.y), C_.y));
  double lenght = A_.y == B_.y ? std::abs(A_.x - B_.x) : B_.y == C_.y ?
    std::abs(C_.x - B_.x) : std::abs(A_.x - C_.x);
  return height * lenght;
}

sukacheva::rectangle_t sukacheva::Parallelogram::getFrameRect() const
{
  double height = std::abs(std::max(std::max(A_.y, B_.y), C_.y)
    - std::min(std::min(A_.y, B_.y), C_.y));
  double width = std::abs(std::max(std::max(A_.x, B_.x), C_.x) -
    std::min(std::min(A_.x, B_.x), C_.x));
  point_t cos = { ((std::max(std::max(A_.x, B_.x), C_.x) + std::min(std::min(A_.x, B_.x), C_.x)) * 0.5),
    ((std::max(std::max(A_.y, B_.y), C_.y) + std::min(std::min(A_.y, B_.y), C_.y)) * 0.5) };
  rectangle_t frameRect = { width, height, cos };
  return frameRect;
}

void sukacheva::Parallelogram::move(const double& x, const double& y) {
  point_t A_ = { A_.x + x, A_.y + y };
  point_t B_ = { B_.x + x, B_.y + y };
  point_t C_ = { C_.x + x, C_.y + y };
}

void sukacheva::Parallelogram::move(const point_t& center) {
  double newX = center.x;
  double newY = center.y;
  double oldX = (A_.x + B_.x) / 2;
  double oldY = (A_.y + C_.y) / 2;
  double dX = newX - oldX;
  double dY = newY - oldY;
  move(dX, dY);
}

void sukacheva::Parallelogram::scale(const double& k)
{
  double centerX = (A_.x + B_.x) / 2;
  double centerY = (A_.y + C_.y) / 2;
  point_t A_ = { (centerX + (A_.x - centerX) * k), (centerY + (A_.y - centerY) * k) };
  point_t B_ = { (centerX + (B_.x - centerX) * k), (centerY + (B_.y - centerY) * k) };
  point_t C_ = { (centerX + (C_.x - centerX) * k), (centerY + (C_.y - centerY) * k) };
}

void sukacheva::Parallelogram::newScale(const point_t& center, const double& k)
{
  double xSideA = A_.x - center.x;
  double ySideA = A_.y - center.y;
  double xSideB = B_.x - center.x;
  double ySideB = B_.y - center.y;
  double xSideC = C_.x - center.x;
  double ySideC = C_.y - center.y;

  A_.x = center.x + xSideA * k;
  A_.y = center.y + ySideA * k;
  B_.x = center.x + xSideB * k;
  B_.y = center.y + ySideB * k;
  C_.x = center.x + xSideC * k;
  C_.y = center.y + ySideC * k;
}
