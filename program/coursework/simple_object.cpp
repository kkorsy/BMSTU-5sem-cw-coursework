#include "simple_object.h"

SimpleObject::SimpleObject() {}

SimpleObject::~SimpleObject() {}


InvisibleObject::InvisibleObject() {}

InvisibleObject::~InvisibleObject() {}


VisibleObject::VisibleObject() {}

VisibleObject::VisibleObject(const VisibleObject& other)
{
    _model = make_shared<Model>(*(other._model));
}

shared_ptr<Model> VisibleObject::get_model()
{
    return _model;
}

VisibleObject::~VisibleObject() {}
