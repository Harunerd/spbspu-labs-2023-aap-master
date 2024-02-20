#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
    virtual double getArea() const = 0; // ���������� �������
    virtual malanin::rectangle_t getFrameRect() const = 0; // ��������� ��������������� �������������� ��� ������
    virtual void move(const malanin::point_t & newPos) = 0; // �����������  � ���������� �����
    virtual void move(double dx, double dy) = 0; //  � ���� �������� �� ���� ������� � �������(���������)
    virtual void scale(double scaleFactor) = 0; // ���������� ��������������� ������������ ������ � ����.
};
#endif