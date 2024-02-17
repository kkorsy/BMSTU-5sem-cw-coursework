#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <memory>

#include "vertex.h"
#include "side.h"

using std::make_shared;


class Model
{
public:
    vector<shared_ptr<Vertex>> v_arr;
    vector<shared_ptr<Side>> s_arr;

    Model();
    Model(const char *filename, QRgb color, double delta_x, double delta_y);
    Model(const vector<Point>& p_arr);
    explicit Model(const Model& other);

    virtual ~Model();

    void normalize_n_vrt();
    void add_vertex(const Point& pnt);
    void add_vertices(const vector<Point> &p_arr);
    void add_side(std::initializer_list<size_t> ind_arr, QRgb color);
    void add_side(vector<size_t> ind_arr, QRgb color);

    void correct_n();
    Point &get_center();

    void operator=(const Model& other);

protected:
    Point _center;

private:
    void _add_side(vector<shared_ptr<Vertex>> vertex_arr, QRgb color);
    shared_ptr<Side> _makeSide(FILE *f, QRgb color, double delta_x, double delta_y);
    shared_ptr<Point> _readPoint(FILE *f, double delta_x, double delta_y);
};

#endif // MODEL_H
