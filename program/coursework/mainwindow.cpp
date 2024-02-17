#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDoubleValidator>
#include <QMessageBox>
#include <QGraphicsView>

RgbMap create_rgb_map(int width, int height)
{
    RgbMap rgb_map = new QRgb*[height];

    for (int i = 0; i < height; i++)
        rgb_map[i] = new QRgb[width];

    return rgb_map;
}

RgbMap create_itensity_map(int width, int height)
{
    RgbMap iten_map = new QRgb*[height];

    for (int i = 0; i < height; i++)
        iten_map[i] = new QRgb[width];

    return iten_map;
}

void free_rgb_map(RgbMap &rgb_map, int height)
{
    for (int i = 0; i < height; i++)
        delete rgb_map[i];

    delete rgb_map;
}

void free_itensity_map(RgbMap &iten_map, int height)
{
    for (int i = 0; i < height; i++)
        delete iten_map[i];

    delete iten_map;
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _qscene(new QGraphicsScene(-10, -10, 10, 10)), _scene(new Scene())
{
    ui->setupUi(this);

    _size_scene = ui->graphicsView->size();

    _set_binds_input();

    _rgb_map = create_rgb_map(_size_scene.width(), _size_scene.height());

    ui->graphicsView->setSceneRect(0, 0, _size_scene.width(), _size_scene.height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(&(*_qscene));

    _image = shared_ptr<QImage>(new QImage(_size_scene.width(), _size_scene.height(), QImage::Format_RGB32));

    q_pmap = _qscene->addPixmap(QPixmap::fromImage(*_image));

    InitDrawCommand cmd(_image);
    _scene.execute(cmd);
    _draw_scene();
}

MainWindow::~MainWindow()
{
    delete ui;
    free_rgb_map(_rgb_map, _size_scene.height());
}

void MainWindow::_set_binds_input(void)
{
    QDoubleValidator *vld = new QDoubleValidator;

    vld->setLocale(QLocale(QLocale::English));
}

void MainWindow::_show_error(const char *error)
{
    QMessageBox error_message(QMessageBox::Critical, "Error", error);
    error_message.exec();
}

void MainWindow::_draw_night_scene()
{
    DrawNightCommand command;

    _scene.execute(command);
    q_pmap->setPixmap(QPixmap::fromImage(*_image));
    QCoreApplication::processEvents();
}

void MainWindow::_draw_day_scene()
{
    DrawDayCommand command;

    _scene.execute(command);
    q_pmap->setPixmap(QPixmap::fromImage(*_image));
    QCoreApplication::processEvents();
}

void MainWindow::_draw_scene()
{
    DrawCommand command;

    _scene.execute(command);
    q_pmap->setPixmap(QPixmap::fromImage(*_image));
    QCoreApplication::processEvents();
}

void MainWindow::on_PushUp_clicked()
{
    _move_camera(0, 1, 0);
}

void MainWindow::on_PushDown_clicked()
{
    _move_camera(0, -1, 0);
}

void MainWindow::on_PushRight_clicked()
{
    _move_camera(1, 0, 0);
}

void MainWindow::on_PushLeft_clicked()
{
    _move_camera(-1, 0, 0);
}

void MainWindow::on_PushCloser_clicked()
{
    _move_camera(0, 0, -1);
}

void MainWindow::on_PushFurther_clicked()
{
    _move_camera(0, 0, 1);
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
    case Qt::Key_Q:
        _move_camera(0, 1, 0);
        break;
    case Qt::Key_Z:
        _move_camera(0, -1, 0);
        break;
    case Qt::Key_D:
        _move_camera(1, 0, 0);
        break;
    case Qt::Key_A:
        _move_camera(-1, 0, 0);
        break;
    case Qt::Key_W:
        _move_camera(0, 0, -3);
        break;
    case Qt::Key_S:
        _move_camera(0, 0, 3);
        break;

    case Qt::Key_F:
        _rotate_camera(-1, 0, 0);
        break;
    case Qt::Key_V:
        _rotate_camera(1, 0, 0);
        break;
    case Qt::Key_B:
        _rotate_camera(0, -1, 0);
        break;
    case Qt::Key_C:
        _rotate_camera(0, 1, 0);
        break;

    case Qt::Key_Y:
        _move_light(0, 8, 0);
        break;
    case Qt::Key_N:
        _move_light(0, -8, 0);
        break;
    case Qt::Key_K:
        _move_light(8, 0, 0);
        break;
    case Qt::Key_H:
        _move_light(-8, 0, 0);
        break;
    case Qt::Key_U:
        _move_light(0, 0, -8);
        break;
    case Qt::Key_J:
        _move_light(0, 0, 8);
        break;

    default:
        break;
    }
}

void MainWindow::_move_camera(double x, double y, double z)
{
    shared_ptr<BaseCommand> ptr;
    ptr = shared_ptr<BaseCommand>(new MoveCamera(Vector(x, y, z)));
    _prev_cmd = shared_ptr<BaseCommand>(new MoveCamera(Vector(-x, -y, -z)));

    _scene.execute(*ptr);

    if (!is_running)
    {
        try {
            _draw_scene();
        }  catch (error::BehindScene &err) {
            cout << err.what() << endl;
            _scene.execute(*_prev_cmd);
        }
    }
}

void MainWindow::_move_light(double x, double y, double z)
{
    shared_ptr<BaseCommand> ptr;
    ptr = shared_ptr<BaseCommand>(new MoveLightSource(Vector(x, y, z)));

    _scene.execute(*ptr);

    if (!is_running)
    {
        try {
            _draw_scene();
        }  catch (error::BehindScene &err) {
            cout << err.what() << endl;
            _scene.execute(*_prev_cmd);
        }
    }
}

void MainWindow::_rotate_camera(double x, double y, double z)
{
    Point cent = _scene.get_center();

    shared_ptr<BaseCommand> ptr;
    ptr = shared_ptr<BaseCommand>(new RotateCamera(cent, Vector(x, y, z)));
    _prev_cmd = shared_ptr<BaseCommand>(new RotateCamera(cent, Vector(-x, -y, -z)));

    _scene.execute(*ptr);

    if (!is_running)
    {
        try {
            _draw_scene();
        }  catch (error::BehindScene &err) {
            cout << err.what() << endl;
            _scene.execute(*_prev_cmd);
        }
    }
}

void MainWindow::on_PushLightUp_clicked()
{
    _move_light(0, 8, 0);
}

void MainWindow::on_PushLightDown_clicked()
{
    _move_light(0, -8, 0);
}

void MainWindow::on_PushLightLeft_clicked()
{
    _move_light(-8, 0, 0);
}

void MainWindow::on_PushLightRight_clicked()
{
    _move_light(8, 0, 0);
}

void MainWindow::on_PushLightCloser_clicked()
{
    _move_light(0, 0, -8);
}

void MainWindow::on_PushLightFurther_clicked()
{
    _move_light(0, 0, 8);
}

void MainWindow::on_RotateUp_clicked()
{
    _rotate_camera(1, 0, 0);
}

void MainWindow::on_RotateDown_clicked()
{
    _rotate_camera(-1, 0, 0);
}

void MainWindow::on_RotateLeft_clicked()
{
    _rotate_camera(0, 1, 0);
}

void MainWindow::on_RotateRight_clicked()
{
    _rotate_camera(0, -1, 0);
}

void MainWindow::on_hot_keys_triggered()
{
    QMessageBox box;
    box.setWindowTitle("Горячие клавиши");
    box.setIconPixmap(QPixmap("C:/Users/Honor/Desktop/cw/program/hot_keys.png"));
    box.exec();
}


void MainWindow::on_about_prog_triggered()
{
    QMessageBox::information(this, "О программе", "Программное обеспечение для визуализации модели цветка космеи.\n\n"
                                                  "Есть возможность перемещения и вращения камеры, а также перемещения источника света с помощью как кнопок, так и горячих клавиш. "
                                                  "При смене времени суток (день / ночь) происходит движение лепестков цветка, а также меняется фон.");
}

void MainWindow::_swap_day_night(bool to_night)
{
    is_running = true;
    this->ui->rb_day->blockSignals(true);
    this->ui->rb_night->blockSignals(true);
    if (to_night)
    {
        std::clock_t t1, t2, sum = 0;
        shared_ptr<BaseCommand> cmd = std::make_shared<NightCommand>();
        for (int i = 0; i < 60; ++i)
        {
            // close petals
            // darker background
            t1 = std::clock();
            _scene.execute(*cmd);
            _draw_night_scene();
            t2 = std::clock();
            sum += t2 - t1;
        }
        sum /= 60;
        qDebug() << sum;
    }
    else
    {
        shared_ptr<BaseCommand> cmd = std::make_shared<DayCommand>();
        for (int i = 0; i < 60; ++i)
        {
            // open petals
            // lighter background
            _scene.execute(*cmd);
            _draw_day_scene();
        }
    }
    this->ui->rb_day->blockSignals(false);
    this->ui->rb_night->blockSignals(false);
    is_running = false;
}

void MainWindow::on_rb_night_clicked()
{
    if (!is_day)
    {
        this->ui->rb_night->setChecked(true);
        this->ui->rb_day->setChecked(false);
        return;
    }

    this->ui->rb_day->setChecked(false);
    _swap_day_night(true);
    is_day = false;
}


void MainWindow::on_rb_day_clicked()
{
    if (is_day)
    {
        this->ui->rb_night->setChecked(false);
        this->ui->rb_day->setChecked(true);
        return;
    }

    this->ui->rb_night->setChecked(false);
    _swap_day_night(false);
    is_day = true;
}

