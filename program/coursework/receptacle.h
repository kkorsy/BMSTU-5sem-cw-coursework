#ifndef RECEPTACLE_H
#define RECEPTACLE_H

#include "simple_object.h"


class Receptacle : public VisibleObject
{
public:
    Receptacle(double delta_x, double delta_y);
    explicit Receptacle(const Receptacle& other);

    virtual ~Receptacle();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
};

#endif // RECEPTACLE_H
