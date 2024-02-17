#include "surface.h"
#include "object_visitor.h"

Surface::Surface(double delta_x, double delta_y)
{
    _color = QColor("#B6845D").rgba();

    _model = make_shared<Model>("C:/Users/Honor/Desktop/cw/program/surface_grid.txt", _color, delta_x, delta_y);

}

Surface::Surface(const Surface& other) : VisibleObject(other)
{
    _color = other._color;
}

Surface::~Surface() {}


//methods
void Surface::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* Surface::clone()
{
    return new Surface(*this);
}
