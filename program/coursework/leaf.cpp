#include "leaf.h"
#include "object_visitor.h"

Leaf::Leaf(double delta_x, double delta_y)
{
    _color = QColor(Qt::darkGreen).rgba();

    _model = make_shared<Model>("C:/Users/Honor/Desktop/cw/program/Leaf_grid.txt", _color, delta_x, delta_y);

}

Leaf::Leaf(const Leaf& other) : VisibleObject(other)
{
    _color = other._color;
}

Leaf::~Leaf() {}


//methods
void Leaf::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* Leaf::clone()
{
    return new Leaf(*this);
}
