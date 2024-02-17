#ifndef OBJECT_VISITOR_H
#define OBJECT_VISITOR_H

#include "camera.h"
#include "light_source.h"
#include "receptacle.h"
#include "stem.h"
#include "petal.h"
#include "center.h"
#include "leaf.h"
#include "surface.h"


class ObjectVisitor
{
public:
    ObjectVisitor();
    virtual ~ObjectVisitor() = 0;

    virtual void visit(Camera& camera) = 0;
    virtual void visit(LightSource& light) = 0;

    virtual void visit(Receptacle& recept) = 0;
    virtual void visit(Stem& recept) = 0;
    virtual void visit(Petal& pet) = 0;
    virtual void visit(Center& cent) = 0;
    virtual void visit(Leaf& lf) = 0;
    virtual void visit(Surface& sur) = 0;
};

#endif // OBJECT_VISITOR_H
