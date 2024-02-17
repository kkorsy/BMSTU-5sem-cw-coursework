class SceneManager
{
public:
    SceneManager(weak_ptr<Scene> scene);
    virtual ~SceneManager() = 0;

    virtual void execute() = 0;

protected:
    weak_ptr<Scene> _scene;
};


class InitDrawManager : public SceneManager
{
public:
    InitDrawManager(weak_ptr<Scene> scene, shared_ptr<Drawer> draw);
    virtual ~InitDrawManager();

    virtual void execute();

private:
    shared_ptr<Drawer> _draw;
};


class DrawManager : public SceneManager
{
public:
    DrawManager(weak_ptr<Scene> scene);
    virtual ~DrawManager();

    virtual void execute();
};

class DrawNightManager : public SceneManager
{
public:
    DrawNightManager(weak_ptr<Scene> scene);
    virtual ~DrawNightManager();

    virtual void execute();
};

class DrawDayManager : public SceneManager
{
public:
    DrawDayManager(weak_ptr<Scene> scene);
    virtual ~DrawDayManager();

    virtual void execute();
};

class NightManager : public SceneManager
{
public:
    NightManager(weak_ptr<Scene> scene);
    virtual ~NightManager();

    virtual void execute();
};

class DayManager : public SceneManager
{
public:
    DayManager(weak_ptr<Scene> scene);
    virtual ~DayManager();

    virtual void execute();
};


class TransformManager : public SceneManager
{
public:
    TransformManager(weak_ptr<Scene> scene,
                     shared_ptr<Transformator> transf);
    TransformManager(weak_ptr<Scene> scene, weak_ptr<Petal> p,
                     shared_ptr<Transformator> transf);
    virtual ~TransformManager();

    virtual void execute();

    void camera_execute();
    void light_execute();
    void petal_execute();

private:
    shared_ptr<Transformator> _transf;
    shared_ptr<Petal> _p;
};

SceneManager::SceneManager(weak_ptr<Scene> scene) :
    _scene(scene) {}

SceneManager::~SceneManager() {}


InitDrawManager::InitDrawManager(weak_ptr<Scene> scene, shared_ptr<Drawer> draw) :
    SceneManager(scene), _draw(draw) {}

InitDrawManager::~InitDrawManager() {}

void InitDrawManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _scene.lock()->set_drawer(_draw);
}


DrawManager::DrawManager(weak_ptr<Scene> scene) :
    SceneManager(scene) {}

DrawManager::~DrawManager() {}

void DrawManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    shared_ptr<Scene> scene = _scene.lock();

    shared_ptr<Visualizer> visual(new Visualizer());

    visual->set_camera(*scene->get_camera());
    visual->set_light(*scene->get_light());
    visual->set_draw(scene->get_drawer());
    visual->clear(0);

    shared_ptr<ObjectVisitor> visitor(new DrawVisitor(visual));

    for (auto object : *_scene.lock())
        object->accept(*visitor);

    visual->show_scene();
}

DrawNightManager::DrawNightManager(weak_ptr<Scene> scene) :
    SceneManager(scene) {}

DrawNightManager::~DrawNightManager() {}

void DrawNightManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    shared_ptr<Scene> scene = _scene.lock();

    shared_ptr<Visualizer> visual(new Visualizer());

    visual->set_camera(*scene->get_camera());

    (scene->get_light())->set_itensity((scene->get_light())->get_itensity() - 3);
    visual->set_light(*scene->get_light());

    visual->set_draw(scene->get_drawer());
    visual->clear(1);

    shared_ptr<ObjectVisitor> visitor(new DrawVisitor(visual));

    for (auto object : *_scene.lock())
        object->accept(*visitor);

    visual->show_scene();
}

DrawDayManager::DrawDayManager(weak_ptr<Scene> scene) :
    SceneManager(scene) {}

DrawDayManager::~DrawDayManager() {}

void DrawDayManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    shared_ptr<Scene> scene = _scene.lock();

    shared_ptr<Visualizer> visual(new Visualizer());

    visual->set_camera(*scene->get_camera());

    (scene->get_light())->set_itensity((scene->get_light())->get_itensity() + 3);
    visual->set_light(*scene->get_light());

    visual->set_draw(scene->get_drawer());
    visual->clear(-1);

    shared_ptr<ObjectVisitor> visitor(new DrawVisitor(visual));

    for (auto object : *_scene.lock())
        object->accept(*visitor);

    visual->show_scene();
}

NightManager::NightManager(weak_ptr<Scene> scene) :
    SceneManager(scene) {}

NightManager::~NightManager() {}

void NightManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);
    shared_ptr<Scene> scene = _scene.lock();

    double delta_x[3] = {0, 13, -13};
    double delta_y[3] = {8, -7, -7};

    // rotate petals
    double delta = PI / 1500;

    for (int j = 0; j < 3; ++j)
    {
        Vector dir(-5.5 * delta, 0, 0);
        Point cent(0.122 * 5 + delta_x[j] * 5, 2.3 * 5 + delta_y[j] * 5, 21.184 * 5);
        Point fl_cent(1.25 + delta_x[j] * 5, -1 + delta_y[j] * 5, 101.167);
        for (int i = 0; i < 9; ++i)
        {
            if (i == 1)
            {
                dir.x = -4.5 * delta;
                dir.y = -3 * delta;
            }
            else if (i == 2)
            {
                dir.x = -1.5 * delta;
                dir.y = -4.8 * delta;
            }
            else if (i == 3)
            {
                dir.x = 2 * delta;
                dir.y = -4.5 * delta;
            }
            else if (i == 4)
            {
                dir.x = 4.5 * delta;
                dir.y = -1.8 * delta;
            }
            else if (i == 5)
            {
                dir.x = 4.5 * delta;
                dir.y = 1.8 * delta;
            }
            else if (i == 6)
            {
                dir.x = 2 * delta;
                dir.y = 4.5 * delta;
            }
            else if (i == 7)
            {
                dir.x = -1.5 * delta;
                dir.y = 4.8 * delta;
            }
            else if (i == 8)
            {
                dir.x = -4.5 * delta;
                dir.y = 3 * delta;
            }
            scene->_petal_arr[j * 9 + i]->rotate(cent, dir, fl_cent, -2 * PI / 9);
        }
    }
}

DayManager::DayManager(weak_ptr<Scene> scene) :
    SceneManager(scene) {}

DayManager::~DayManager() {}

void DayManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);
    shared_ptr<Scene> scene = _scene.lock();

    double delta_x[3] = {0, 13, -13};
    double delta_y[3] = {8, -7, -7};

    // rotate petals
    double delta = PI / 1500;

    for (int j = 0; j < 3; ++j)
    {
        Vector dir(5.5 * delta, 0, 0);
        Point cent(0.122 * 5 + delta_x[j] * 5, 2.3 * 5 + delta_y[j] * 5, 21.184 * 5);
        Point fl_cent(1.25 + delta_x[j] * 5, -1 + delta_y[j] * 5, 101.167);
        for (int i = 0; i < 9; ++i)
        {
            if (i == 1)
            {
                dir.x = 4.5 * delta;
                dir.y = 3 * delta;
            }
            else if (i == 2)
            {
                dir.x = 1.5 * delta;
                dir.y = 4.8 * delta;
            }
            else if (i == 3)
            {
                dir.x = -2 * delta;
                dir.y = 4.5 * delta;
            }
            else if (i == 4)
            {
                dir.x = -4.5 * delta;
                dir.y = 1.8 * delta;
            }
            else if (i == 5)
            {
                dir.x = -4.5 * delta;
                dir.y = -1.8 * delta;
            }
            else if (i == 6)
            {
                dir.x = -2 * delta;
                dir.y = -4.5 * delta;
            }
            else if (i == 7)
            {
                dir.x = 1.5 * delta;
                dir.y = -4.8 * delta;
            }
            else if (i == 8)
            {
                dir.x = 4.5 * delta;
                dir.y = -3 * delta;
            }
            scene->_petal_arr[j * 9 + i]->rotate(cent, dir, fl_cent, -2 * PI / 9);
        }
    }
}


TransformManager::TransformManager(weak_ptr<Scene> scene, shared_ptr<Transformator> transf) :
    SceneManager(scene), _transf(transf) {}

TransformManager::TransformManager(weak_ptr<Scene> scene, weak_ptr<Petal> p, shared_ptr<Transformator> transf) :
    SceneManager(scene), _p(p), _transf(transf) {}

TransformManager::~TransformManager() {}

void TransformManager::execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);
}

void TransformManager::camera_execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _transf->rotate(_scene.lock()->get_camera()->get_direction());
    _transf->transform(*_scene.lock()->get_camera());
}

void TransformManager::light_execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _transf->transform(_scene.lock()->get_light()->get_position());
}

void TransformManager::petal_execute()
{
    if (_scene.expired())
        throw error::SceneExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    _transf->transform(*(_p->get_model()));
}
