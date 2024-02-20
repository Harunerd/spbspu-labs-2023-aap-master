#include "rectangle.hpp"

Rectangle::Rectangle(const malanin::point_t& pos, double width, double height) // ����������� ������
    : pos_(pos), width_(width), height_(height)
{
}

double Rectangle::getArea() const
{
    return width_ * height_; // ������� == ������������ ������ � ������
}

malanin::rectangle_t Rectangle::getFrameRect() const
{
    malanin::rectangle_t frameRect;
    frameRect.pos = pos_;
    frameRect.width = width_;
    frameRect.height = height_;
    return frameRect; // �������������� ������������� ����� ������ ��������������
}

void Rectangle::move(const malanin::point_t& newPos)
{
    pos_ = newPos; // ���������� ������������� � ����� ��������� �����
}

void Rectangle::move(double dx, double dy)
{
    pos_.x += dx; // ���������� ������������� �� �������� �� ��� �������(X)
    pos_.y += dy; // ���������� ������������� �� �������� �� ��� �������(Y)
}

void Rectangle::scale(double scaleFactor)
{
    width_ *= scaleFactor; // ������������ ������ ��������������
    height_ *= scaleFactor; // ������������ ������ ��������������
}