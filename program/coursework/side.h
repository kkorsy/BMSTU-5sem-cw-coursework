#ifndef SIDE_H
#define SIDE_H

#include <QColor>
#include <memory>
#include <vector>

#include "vertex.h"
#include "vector.h"
#include "side_errors.h"


class Side
{
public:
    vector<shared_ptr<Vertex>> vertex_arr;
    Vector n;
    QRgb color;

    Side();
    Side(const Side& other);
    Side(vector<shared_ptr<Vertex>> vertex_arr, const Point& control_p, QRgb color);

    virtual ~Side();

    void n_correction(const Point& control_p);
    void set_vert_normal(const Point& control_p);

private:
    void _find_normal();
};

#endif // SIDE_H
