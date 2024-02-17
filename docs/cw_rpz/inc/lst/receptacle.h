class Receptacle : public VisibleObject
{
public:
    Receptacle(double delta_x, double delta_y);
    explicit Receptacle(const Receptacle& other);

    virtual ~Receptacle();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
};

Receptacle::Receptacle(double delta_x, double delta_y)
{
    _color = QColor(Qt::darkGreen).rgba();

    _model = make_shared<Model>("C:/Users/Honor/Desktop/cw/program/receptacle_grid.txt", _color, delta_x, delta_y);

}

Receptacle::Receptacle(const Receptacle& other) : VisibleObject(other)
{
    _color = other._color;
}

Receptacle::~Receptacle() {}


//methods
void Receptacle::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* Receptacle::clone()
{
    return new Receptacle(*this);
}

