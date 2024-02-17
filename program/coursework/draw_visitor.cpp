#include "draw_visitor.h"


DrawVisitor::DrawVisitor(shared_ptr<Visualizer>& visual) :
    _visual(visual) {}

DrawVisitor::~DrawVisitor() {}

void DrawVisitor::visit(Camera&) {}

void DrawVisitor::visit(LightSource&) {}

void DrawVisitor::visit(Receptacle &recept)
{
    _visual->draw_model(*recept.get_model());
}

void DrawVisitor::visit(Stem &st)
{
    _visual->draw_model(*st.get_model());
}

void DrawVisitor::visit(Petal &pet)
{
    _visual->draw_model(*pet.get_model());
}

void DrawVisitor::visit(Center &cent)
{
    _visual->draw_model(*cent.get_model());
}

void DrawVisitor::visit(Leaf &lf)
{
    _visual->draw_model(*lf.get_model());
}

void DrawVisitor::visit(Surface &sur)
{
    _visual->draw_model(*sur.get_model());
}
