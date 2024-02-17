#ifndef VERTEX_H
#define VERTEX_H

#include "point.h"
#include "vector.h"

class Vertex : public Point
{
public:
    Vector n;

    Vertex();
    Vertex(double data_x, double data_y, double data_z);
    Vertex(const Point& other);
    Vertex(const Vertex& other);

    virtual ~Vertex();

    Vertex operator =(Vertex& other);
    bool operator==(const Vertex& other);
    void normalize();
};

#endif // VERTEX_H
