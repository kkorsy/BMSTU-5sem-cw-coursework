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

Side::Side() {}

Side::~Side() {}

Side::Side(const Side &other)
{
    vertex_arr.clear();
    for (auto& vertex : other.vertex_arr)
        vertex_arr.push_back(make_shared<Vertex>(*vertex));
    n = other.n;
    color = other.color;
}

Side::Side(vector<shared_ptr<Vertex>> v_arr, const Point& control_p, QRgb data_color)
{
    if (v_arr.size() < 2)
        throw error::DegenerateSide(__FILE__, typeid (*this).name(), __LINE__ - 1, v_arr.size());

    color = data_color;
    vertex_arr = v_arr;

    _find_normal();
    n_correction(control_p);

    for (auto vertex : vertex_arr)
        vertex->n += this->n;
}


void Side::n_correction(const Point &control_p)
{
    Vector temp(control_p, *vertex_arr[0]);

    if (this->n.scalar_mult(temp) < 0)
        n.invert();
}

void Side::set_vert_normal(const Point& control_p)
{
    _find_normal();
    n_correction(control_p);

    for (auto vertex : vertex_arr)
        vertex->n += this->n;
}


void Side::_find_normal()
{
    Vertex p1 = *vertex_arr[0];
    Vertex p2 = *vertex_arr[1];
    Vertex p3 = *vertex_arr[2];

    n.x = (p2.y - p1.y)*(p3.z - p1.z) - (p3.y - p1.y)*(p2.z - p1.z);
    n.y = (p3.x - p1.x)*(p2.z - p1.z) - (p2.x - p1.x)*(p3.z - p1.z);
    n.z = (p2.x - p1.x)*(p3.y - p1.y) - (p3.x - p1.x)*(p2.y - p1.y);

    n.normalize();
}

