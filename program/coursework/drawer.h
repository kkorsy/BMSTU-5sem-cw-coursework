#ifndef DRAWER_H
#define DRAWER_H

#include <QImage>
#include <memory>

#include "point.h"
#include "scene_errors.h"


using RgbMap = QRgb**;
using ZMap = double**;

using IMap = double**;

using namespace std;


class Drawer
{
public:
    Drawer(weak_ptr<QImage> image);
    explicit Drawer(const Drawer& other);
    virtual ~Drawer();

    void draw_point(const Point& pnt, QRgb color);
    void draw_point(const Point& pnt, QRgb color, double intensity);//, const Point &pnt_shd);
    void draw_point_shd(const Point &pnt);
    void make_map_plain();
    void fill_zmap_onedepth(double depth);
    void make_itenmap_plain(double iten); //hi

    void correct_intensity(const Point& pnt, double i, double tr); //hi

    void move_to_qimage();

    int get_max_y();
    int get_min_y();
    int get_max_x();
    int get_min_x();

    void set_background(QRgb other) { background = other; }
    QColor get_background() { return QColor(background); }

private:
    weak_ptr<QImage> _image;
    RgbMap _colormap;
    ZMap _zmap;
    IMap _itenmap;
    QRgb background = qRgb(88, 189, 255);

    int height, width;
    double half_height, half_width;

    void _init_map();
    void _free_map();
};

#endif // DRAWER_H
