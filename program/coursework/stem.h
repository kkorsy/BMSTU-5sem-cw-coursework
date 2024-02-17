#ifndef STEM_H
#define STEM_H

#include "simple_object.h"


class Stem : public VisibleObject
{
public:
    Stem(double delta_x, double delta_y);
    explicit Stem(const Stem& other);

    virtual ~Stem();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
};

#endif // STEM_H
