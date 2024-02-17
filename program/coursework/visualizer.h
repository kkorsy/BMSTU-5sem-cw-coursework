#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "drawer.h"
#include "projecting.h"
#include "camera.h"
#include "light_source.h"
#include "model.h"
#include "scene_errors.h"

#define PI      3.1415


class Visualizer
{
public:
    Visualizer();
    Visualizer(shared_ptr<Drawer>& drawer);

    ~Visualizer();

    void set_draw(const shared_ptr<Drawer>& drawer);
    void set_camera(const Camera& camera);
    void set_light(const LightSource& light);

    void draw_model(const Model& model);
    void draw_shadows(const Model &model);
    void draw_intensity(const Model &model, double tr);

    void show_scene();
    void clear(int night);

private:
    shared_ptr<Drawer> _draw;
    Camera _camera;
    LightSource _light;
    Vector _light_dir;

    Point _project_point(const Point& pnt);
    Point _project_point_shd(const Point& pnt);
    Point _invert_project_point(const Point &pnt);
    void _project_side(ProjectedSide &side, const vector<shared_ptr<Vertex>>& vertex_arr);
    void _project_side_shd(ProjectedSide &side, const vector<shared_ptr<Vertex>>& vertex_arr);
    double _calculate_intensity(const Vertex &v);
    double _glare_i(const Point& pnt, const Vector &n);
};

#endif // VISUALIZER_H
