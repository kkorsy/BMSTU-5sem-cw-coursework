#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <memory>
#include <vector>
#include <random>

#include "scene_object.h"
#include "camera.h"
#include "light_source.h"
#include "receptacle.h"
#include "stem.h"
#include "petal.h"
#include "center.h"
#include "leaf.h"
#include "surface.h"

#include "drawer.h"


using scene_iter = vector<shared_ptr<SceneObject>>::iterator;
using scene_const_iter = vector<shared_ptr<SceneObject>>::const_iterator;

using namespace std;


class Scene
{
public:
    Scene();

    ~Scene();

    scene_iter begin() {    return _arr.begin();    }
    scene_iter end() {  return _arr.end();  }

    scene_const_iter begin() const {    return _arr.cbegin();    }
    scene_const_iter end() const {  return _arr.cend();  }

    scene_const_iter cbegin() {    return _arr.cbegin();    }
    scene_const_iter cend() {  return _arr.cend();  }

    size_t get_size();

    shared_ptr<Camera> get_camera();
    void set_camera(const Camera& camera);

    shared_ptr<LightSource> get_light();
    void set_light(const LightSource& light);

    shared_ptr<Drawer> get_drawer();
    void set_drawer(const Drawer& drawer);
    void set_drawer(shared_ptr<Drawer>& drawer);

    void add_object(shared_ptr<SceneObject> object);
    void add_object(SceneObject* object);
    void remove_object(scene_iter& iter);

    double get_border();

    void add_items(int num);

    Point get_center();
    vector<shared_ptr<Petal>> _petal_arr;
    vector<shared_ptr<SceneObject>> _arr;

private:

    shared_ptr<Camera> _camera;
    shared_ptr<LightSource> _light;

    shared_ptr<Drawer> _draw;

    double _border_y = -190;
};

#endif // SCENE_H
