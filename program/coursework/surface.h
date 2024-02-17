#ifndef SURFACE_H
#define SURFACE_H

#include "simple_object.h"


class Surface : public VisibleObject
{
public:
    Surface(double delta_x, double delta_y);
    explicit Surface(const Surface& other);

    virtual ~Surface();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
};

#endif // SURFACE_H
