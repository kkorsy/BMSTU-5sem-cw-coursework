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

//constructors and destructor
Model::Model() {}

Model::Model(const vector<Point>& p_arr)
{
    this->add_vertices(p_arr);

    _center.x = 0;
    _center.y = 0;
    _center.z = 0;

    for (Point pnt : p_arr)
    {
        _center.x += pnt.x;
        _center.y += pnt.y;
        _center.z += pnt.z;
    }

    _center.x /= p_arr.size();
    _center.y /= p_arr.size();
    _center.z /= p_arr.size();
}

Model::Model(const Model& other)
{
    this->_center = other._center;
    this->v_arr.clear();
    this->s_arr.clear();
    for (auto &vertex : other.v_arr)
        v_arr.push_back(make_shared<Vertex>(*vertex));
    for (auto &side : other.s_arr)
        s_arr.push_back(make_shared<Side>(*side));
}

Model::Model(const char *filename, QRgb color, double delta_x, double delta_y)
{
    FILE *f = fopen(filename, "r");

    shared_ptr<Side> s;
    while ((s = _makeSide(f, color, delta_x, delta_y)) != nullptr)
    {
        _add_side(s->vertex_arr, s->color);
    }

    fclose(f);

    _center.x = 0;
    _center.y = 0;
    _center.z = 0;

    for (shared_ptr<Vertex> pnt : v_arr)
    {
        _center.x += pnt->x;
        _center.y += pnt->y;
        _center.z += pnt->z;
    }

    _center.x /= v_arr.size();
    _center.y /= v_arr.size();
    _center.z /= v_arr.size();
}

Model::~Model() {}


//methods
shared_ptr<Point> Model::_readPoint(FILE *f, double delta_x, double delta_y)
{
    double x, y, z;
    shared_ptr<Point> p = nullptr;
    if (fscanf(f, "%lf %lf %lf", &x, &y, &z) == 3)
        p = make_shared<Point>(x * 5 + delta_x * 5, y * 5 + delta_y * 5, z * 5);

    return p;
}


shared_ptr<Side> Model::_makeSide(FILE *f, QRgb color, double delta_x, double delta_y)
{
    shared_ptr<Side> s = nullptr;

    shared_ptr<Point> p1 = _readPoint(f, delta_x, delta_y), p2 = _readPoint(f, delta_x, delta_y), p3 = _readPoint(f, delta_x, delta_y);
    if (p1 && p2 && p3)
    {
        vector<shared_ptr<Vertex>> v;
        shared_ptr<Vertex> v1(new Vertex(*p1));
        v.push_back(v1);
        shared_ptr<Vertex> v2(new Vertex(*p2));
        v.push_back(v2);
        shared_ptr<Vertex> v3(new Vertex(*p3));
        v.push_back(v3);

        add_vertex(*p1);
        add_vertex(*p2);
        add_vertex(*p3);
        s = make_shared<Side>(v, *p1, color);
    }

    return s;
}

void Model::normalize_n_vrt()
{
    for (auto vertex : v_arr)
        vertex->n.normalize();
}

void Model::correct_n()
{
    for (auto vertex : v_arr)
    {
        vertex->n.x = 0;
        vertex->n.y = 0;
        vertex->n.z = 0;
    }

    for (auto side : s_arr)
        side->set_vert_normal(_center);

    normalize_n_vrt();
}

void Model::_add_side(vector<shared_ptr<Vertex>> vertex_arr, QRgb color)
{
    shared_ptr<Side> new_side(new Side(vertex_arr, _center, color));
    s_arr.push_back(new_side);
}

void Model::add_vertex(const Point &pnt)
{
    shared_ptr<Vertex> new_vertex(new Vertex(pnt));
    v_arr.push_back(new_vertex);
}

void Model::add_vertices(const vector<Point> &p_arr)
{
    for (Point point : p_arr)
        add_vertex(point);
}

void Model::add_side(std::initializer_list<size_t> ind_arr, QRgb color)
{
    vector<shared_ptr<Vertex>> new_side;

    for (size_t i : ind_arr)
    {
        if (i >= v_arr.size())
            throw error::WrongIndex(__FILE__, typeid (*this).name(), __LINE__ - 1);

        new_side.push_back(v_arr[i]);
    }

    _add_side(new_side, color);
}

void Model::add_side(vector<size_t> ind_arr, QRgb color)
{
    vector<shared_ptr<Vertex>> new_side;

    for (auto i : ind_arr)
    {
        if (i >= v_arr.size())
            throw error::WrongIndex(__FILE__, typeid (*this).name(), __LINE__ - 1);

        new_side.push_back(v_arr[i]);
    }

    _add_side(new_side, color);
}

Point& Model::get_center()
{
    return _center;
}

void Model::operator=(const Model &other)
{
    this->_center = other._center;
    this->v_arr.clear();
    this->s_arr.clear();
    for (auto &vertex : other.v_arr)
        v_arr.push_back(make_shared<Vertex>(*vertex));
    for (auto &side : other.s_arr)
        s_arr.push_back(make_shared<Side>(*side));
}

