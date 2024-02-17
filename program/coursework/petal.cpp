#include "petal.h"
#include "object_visitor.h"
#include "transform_command.h"

Petal::Petal(const char* color, int i, double delta_x, double delta_y)
{
    _color = QColor(color).rgba();
    char filename[FILENAME_MAX] = "C:/Users/Honor/Desktop/cw/program/petal_grid_";
    filename[strlen(filename)] = (char) i + '0';
    strncat(filename, ".txt", 4);
    _model = make_shared<Model>(filename, _color, delta_x, delta_y);
}

Petal::Petal(const Petal& other) : VisibleObject(other)
{
    _color = other._color;
}

Petal::~Petal() {}


//methods
void Petal::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* Petal::clone()
{
    return new Petal(*this);
}

void Petal::rotate(Point &cent, Vector &dir, Point fl_cent, double angle)
{
    Rotate(dir, cent).execute(*(this->get_model()));
    Rotate(Vector(0, 0, angle), fl_cent).execute(cent);
}
