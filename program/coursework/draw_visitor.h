#ifndef DRAW_VISITOR_H
#define DRAW_VISITOR_H

#include "object_visitor.h"
#include "visualizer.h"


class DrawVisitor : public ObjectVisitor
{
public:
    DrawVisitor(shared_ptr<Visualizer>& visual);
    virtual ~DrawVisitor();

    virtual void visit(Camera& camera);
    virtual void visit(LightSource& light);

    virtual void visit(Receptacle& recept);
    virtual void visit(Stem& st);
    virtual void visit(Petal &pet);
    virtual void visit(Center &cent);
    virtual void visit(Leaf &lf);
    virtual void visit(Surface& sur);

private:
    shared_ptr<Visualizer> _visual;
};

#endif // DRAW_VISITOR_H
