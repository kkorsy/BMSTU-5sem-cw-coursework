class Stem : public VisibleObject
{
public:
    Stem(double delta_x, double delta_y);
    explicit Stem(const Stem& other);

    virtual ~Stem();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

private:
    QRgb _color;
};

Stem::Stem(double delta_x, double delta_y)
{
    _color = QColor(Qt::darkGreen).rgba();
    _model = make_shared<Model>("C:/Users/Honor/Desktop/cw/program/Stem_grid.txt", _color, delta_x, delta_y);

}

Stem::Stem(const Stem& other) : VisibleObject(other)
{
    _color = other._color;
}

Stem::~Stem() {}


//methods
void Stem::accept(ObjectVisitor &visitor)
{
    visitor.visit(*this);
}

SceneObject* Stem::clone()
{
    return new Stem(*this);
}


