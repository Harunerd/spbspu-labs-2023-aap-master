#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp" 

class Rectangle : public Shape
{
public:
    Rectangle(const malanin::point_t& pos, double width, double height);

    double getArea() const override; // ���������� �������
    malanin::rectangle_t  getFrameRect() const; // ��������� ��������������� ��������������
    void move(const malanin::point_t& newPos); // ����������� � ���������� �����
    void move(double dx, double dy) override; // ����������� ���������� �� ����
    void scale(double scaleFactor) override; // ��������������� ������������ ������

private:
    malanin::point_t pos_; // ������� ������ ��������������
    double width_; // ������ ��������������
    double height_; // ������ ��������������
};

#endif // RECTANGLE_HPP