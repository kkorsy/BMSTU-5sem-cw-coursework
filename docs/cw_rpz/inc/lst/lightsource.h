class LightSource : public InvisibleObject
{
public:
    LightSource();
    LightSource(const Point& position);
    LightSource(const Point& position, double itensity);
    explicit LightSource(const LightSource& other);

    virtual ~LightSource();

    Point& get_position();
    double get_itensity();
    void set_itensity(double itensity);

    const Point& get_position() const;

    void operator =(const LightSource& other);

    virtual void accept(ObjectVisitor&);
    virtual SceneObject* clone();

private:
    Point _pos;
    double _i;
};

//constructors and destructor
LightSource::LightSource() {}

LightSource::LightSource(const Point& position) :
    _pos(position) {}

LightSource::LightSource(const Point& position, double itensity) :
    _pos(position), _i(itensity) {}

LightSource::LightSource(const LightSource& other) :
    _pos(other._pos), _i(other._i) {}

LightSource::~LightSource() {}


//methonds
Point& LightSource::get_position() {    return _pos;    }

double LightSource::get_itensity() {    return _i;  }

void LightSource::set_itensity(double itensity) {   _i = itensity;  }

const Point& LightSource::get_position() const {    return _pos;    }

void LightSource::operator =(const LightSource& other)
{
    this->_pos = other._pos;
    this->_i = other._i;
}

void LightSource::accept(ObjectVisitor& visitor)
{
    visitor.visit(*this);
}

SceneObject *LightSource::clone()
{
    return new LightSource(*this);
}

