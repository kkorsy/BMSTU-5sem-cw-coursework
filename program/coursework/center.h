#ifndef CENTER_H
#define CENTER_H

#include "simple_object.h"


class Center : public VisibleObject
{
public:
    Center(double delta_x, double delta_y);
    explicit Center(const Center& other);

    virtual ~Center();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
};

#endif // CENTER_H
