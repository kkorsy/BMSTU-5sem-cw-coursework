#ifndef PETAL_H
#define PETAL_H

#include "simple_object.h"

class Scene;


class Petal : public VisibleObject
{
public:
    Petal(const char *color, int i, double delta_x, double delta_y);
    explicit Petal(const Petal& other);

    virtual ~Petal();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

    void rotate(Point &cent, Vector &dir, Point fl_cent, double angle);

private:
    QRgb _color;
};

#endif // PETAL_H
