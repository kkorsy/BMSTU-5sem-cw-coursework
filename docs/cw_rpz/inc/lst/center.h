class Center : public VisibleObject
{
public:
    Center(double delta_x, double delta_y);
    explicit Center(const Center& other);

    virtual ~Center();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
};

Center::Center(double delta_x, double delta_y)
{
    _color = QColor("#FFCC00").rgba();

    _model = make_shared<Model>("C:/Users/Honor/Desktop/cw/program/Center_grid.txt", _color, delta_x, delta_y);

}

Center::Center(const Center& other) : VisibleObject(other)
{
    _color = other._color;
}

Center::~Center() {}


//methods
void Center::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* Center::clone()
{
    return new Center(*this);
}

