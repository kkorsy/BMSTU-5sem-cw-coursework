#include "drawer.h"

#include <iostream>
using namespace std;


QRgb get_color(QRgb color, double itensity)
{
    QColor new_color(color);
    int r, g, b;

    new_color.getRgb(&r, &g, &b);

    if (itensity <= 1)
    {
        r *= itensity;
        g *= itensity;
        b *= itensity;
    }
    else
    {
        r = min<double>(r * itensity, 255);
        g = min<double>(g * itensity, 255);
        b = min<double>(b * itensity, 255);
    }

    new_color.setRgb(r, g, b);

    return new_color.rgba();
}

Drawer::Drawer(weak_ptr<QImage> image)
{
    if (image.expired())
        throw error::ImageExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    QSize size = image.lock()->size();

    _image = image;
    height = size.height();
    width = size.width();

    half_height = height / 2;
    half_width = width / 2;

    _init_map();
}

Drawer::Drawer(const Drawer& other)
{
    _image = other._image;
    height = other.height;
    width = other.width;
    half_height = other.half_height;
    half_width = other.half_width;

    _init_map();
}

Drawer::~Drawer() {   _free_map();    }

void Drawer::_init_map()
{
    _colormap = new QRgb*[this->height];
    _zmap = new double*[this->height];
    _itenmap = new double*[this->height];

    for (int i = 0; i < this->height; i++)
    {
        _zmap[i] = new double[this->width];
        _colormap[i] = new QRgb[this->width];
        _itenmap[i] = new double[this->width];
    }
}

void Drawer::_free_map()
{
    for (int i = 0; i < this->height; i++)
    {
        delete _colormap[i];
        delete _zmap[i];
        delete  _itenmap[i];
    }

    delete _colormap;
    delete _zmap;
    delete  _itenmap;
}

void Drawer::draw_point(const Point &pnt, QRgb color)
{
    int x = static_cast<int>(pnt.x) + half_width;
    if (x < 0 || x >= width)
        return;

    int y = -static_cast<int>(pnt.y) + half_height;
    if (y < 0 || y >= height)
        return;

    if (pnt.z > _zmap[y][x])
    {
        _zmap[y][x] = pnt.z;
        _colormap[y][x] = color;
    }
}

void Drawer::draw_point_shd(const Point &pnt)
{
    int x = static_cast<int>(pnt.x) + half_width;
    if (x < 0 || x >= width)
        return;

    int y = -static_cast<int>(pnt.y) + half_height;
    if (y < 0 || y >= height)
        return;
}


void Drawer::draw_point(const Point &pnt, QRgb color, double itensity)//, const Point &pnt_shd)
{
    int x = static_cast<int>(pnt.x) + half_width;
    if (x < 0 || x >= width)
        return;

    int y = -static_cast<int>(pnt.y) + half_height;
    if (y < 0 || y >= height)
        return;

    if (pnt.z > _zmap[y][x])
    {
        _zmap[y][x] = pnt.z;
        _colormap[y][x] = color;
        _itenmap[y][x] = itensity;
    }
}

void Drawer::correct_intensity(const Point& pnt, double i, double tr)
{
    int x = static_cast<int>(pnt.x) + half_width;
    if (x < 0 || x >= width)
        return;

    int y = -static_cast<int>(pnt.y) + half_height;
    if (y < 0 || y >= height)
        return;
}

void Drawer::make_map_plain()
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            _colormap[i][j] = background;
}

void Drawer::make_itenmap_plain(double iten)
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            _itenmap[i][j] = iten;
}

void Drawer::fill_zmap_onedepth(double depth)
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
        {
            _zmap[i][j] = depth;
        }
}

void Drawer::move_to_qimage()
{
    if (_image.expired())
        throw error::ImageExpired(__FILE__, typeid (*this).name(), __LINE__ - 1);

    QImage& img = *_image.lock();
    size_t row_size = static_cast<size_t>(width) * sizeof (QRgb);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            _colormap[i][j] = get_color(_colormap[i][j], _itenmap[i][j]);
        }
        memcpy(img.scanLine(i), &_colormap[i][0], row_size);
    }
}

int Drawer::get_max_y()
{
    return half_height;
}

int Drawer::get_min_y()
{
    return -half_height;
}

int Drawer::get_min_x()
{
    return -half_width;
}

int Drawer::get_max_x()
{
    return half_width;
}
