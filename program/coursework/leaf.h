#ifndef LEAF_H
#define LEAF_H

#include "simple_object.h"


class Leaf : public VisibleObject
{
public:
    Leaf(double delta_x, double delta_y);
    explicit Leaf(const Leaf& other);

    virtual ~Leaf();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
};

#endif // LEAF_H
