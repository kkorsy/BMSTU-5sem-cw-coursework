#ifndef MANAGERS_H
#define MANAGERS_H

#include "scene.h"
#include "visualizer.h"
#include "transformator.h"
#include "draw_visitor.h"


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

#endif // MANAGERS_H
