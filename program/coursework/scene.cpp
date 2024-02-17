#include "scene.h"

Scene::Scene()
{
    set_camera(Camera(Point(0, -120, 170), Vector(45, 0, 0)));
    set_light(LightSource(Point(0, 0, 1000), 500));
    add_object(new Surface(0, 0));

    double delta_x[3] = {0, 13, -13};
    double delta_y[3] = {8, -7, -7};
    char *petal_colors[3] = {"#FF9999", "#E9E9E9", "#BA0032"};

    for (int i = 0; i < 3; ++i)
    {
        add_object(new Receptacle(delta_x[i], delta_y[i]));
        add_object(new Stem(delta_x[i], delta_y[i]));
        add_object(new Center(delta_x[i], delta_y[i]));
        add_object(new Leaf(delta_x[i], delta_y[i]));

        int petalCnt = 9;
        for (int j = 0; j < petalCnt; ++j)
        {
            shared_ptr<Petal> p = std::make_shared<Petal>(petal_colors[i], j, delta_x[i], delta_y[i]);
            add_object(p);
            _petal_arr.push_back(p);
        }
    }
}

Scene::~Scene() {}


size_t Scene::get_size()
{
    return _arr.size();
}

shared_ptr<Camera> Scene::get_camera()
{
    return _camera;
}

void Scene::set_camera(const Camera& camera)
{
    _camera = shared_ptr<Camera>(new Camera(camera));
}


shared_ptr<LightSource> Scene::get_light()
{
    return _light;
}

void Scene::set_light(const LightSource& light)
{
    _light = shared_ptr<LightSource>(new LightSource(light));
}


shared_ptr<Drawer> Scene::get_drawer()
{
    return _draw;
}

void Scene::set_drawer(const Drawer &drawer)
{
    _draw = shared_ptr<Drawer>(new Drawer(drawer));
}

void Scene::set_drawer(shared_ptr<Drawer> &drawer)
{
    _draw = drawer;
}

double Scene::get_border()
{
    return _border_y;
}

void Scene::add_object(shared_ptr<SceneObject> object)
{
    _arr.push_back(object);
}

void Scene::add_object(SceneObject *object)
{
    _arr.push_back(shared_ptr<SceneObject>(object));
}

void Scene::remove_object(scene_iter &iter)
{
    _arr.erase(iter);
}

Point Scene::get_center()
{
    Point c(0, 0, 0);
    int k = 0;
    for (size_t i = 0; i < _arr.size(); ++i)
    {
        if (_arr[i]->is_drawable())
        {
            k++;
            Point t = dynamic_cast<VisibleObject*>(&(*_arr[i]))->get_model()->get_center();
            c.x += t.x;
            c.y += t.y;
            c.z += t.z;
        }
    }
    c.x /= k;
    c.y /= k;
    c.z /= k;

    return c;
}

