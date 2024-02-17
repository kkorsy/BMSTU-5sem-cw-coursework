/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *hot_keys;
    QAction *about_prog;
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_9;
    QFrame *line;
    QFrame *line_2;
    QPushButton *PushUp;
    QPushButton *PushRight;
    QPushButton *PushLeft;
    QPushButton *PushDown;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QPushButton *PushCloser;
    QPushButton *PushFurther;
    QLabel *label_10;
    QPushButton *PushLightCloser;
    QPushButton *PushLightFurther;
    QPushButton *PushLightUp;
    QPushButton *PushLightRight;
    QPushButton *PushLightLeft;
    QPushButton *PushLightDown;
    QLabel *label_11;
    QPushButton *RotateLeft;
    QPushButton *RotateRight;
    QPushButton *RotateDown;
    QPushButton *RotateUp;
    QFrame *line_9;
    QRadioButton *rb_day;
    QRadioButton *rb_night;
    QLabel *label_12;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(910, 650);
        hot_keys = new QAction(MainWindow);
        hot_keys->setObjectName("hot_keys");
        about_prog = new QAction(MainWindow);
        about_prog->setObjectName("about_prog");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 10, 611, 581));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(630, 10, 71, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label_3->setFont(font);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(630, 280, 131, 21));
        label_8->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(650, 30, 91, 21));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        label_9->setFont(font1);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(700, 10, 201, 16));
        QFont font2;
        font2.setPointSize(9);
        line->setFont(font2);
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(620, 30, 20, 231));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::VLine);
        PushUp = new QPushButton(centralwidget);
        PushUp->setObjectName("PushUp");
        PushUp->setGeometry(QRect(730, 50, 61, 23));
        PushUp->setFont(font1);
        PushRight = new QPushButton(centralwidget);
        PushRight->setObjectName("PushRight");
        PushRight->setGeometry(QRect(800, 90, 61, 23));
        PushRight->setFont(font1);
        PushLeft = new QPushButton(centralwidget);
        PushLeft->setObjectName("PushLeft");
        PushLeft->setGeometry(QRect(660, 90, 61, 23));
        PushLeft->setFont(font1);
        PushDown = new QPushButton(centralwidget);
        PushDown->setObjectName("PushDown");
        PushDown->setGeometry(QRect(730, 130, 61, 23));
        PushDown->setFont(font1);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(630, 250, 271, 16));
        line_3->setFont(font2);
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setLineWidth(1);
        line_3->setFrameShape(QFrame::HLine);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(890, 20, 20, 241));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setFrameShape(QFrame::VLine);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(760, 280, 141, 20));
        line_5->setFont(font2);
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setLineWidth(1);
        line_5->setFrameShape(QFrame::HLine);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(630, 450, 271, 16));
        line_6->setFont(font2);
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setLineWidth(1);
        line_6->setFrameShape(QFrame::HLine);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(620, 300, 20, 161));
        line_7->setFrameShadow(QFrame::Plain);
        line_7->setFrameShape(QFrame::VLine);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(890, 290, 20, 171));
        line_8->setFrameShadow(QFrame::Plain);
        line_8->setFrameShape(QFrame::VLine);
        PushCloser = new QPushButton(centralwidget);
        PushCloser->setObjectName("PushCloser");
        PushCloser->setGeometry(QRect(730, 80, 61, 23));
        PushCloser->setFont(font1);
        PushFurther = new QPushButton(centralwidget);
        PushFurther->setObjectName("PushFurther");
        PushFurther->setGeometry(QRect(730, 100, 61, 23));
        PushFurther->setFont(font1);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(650, 310, 91, 21));
        label_10->setFont(font1);
        PushLightCloser = new QPushButton(centralwidget);
        PushLightCloser->setObjectName("PushLightCloser");
        PushLightCloser->setGeometry(QRect(730, 360, 61, 23));
        PushLightCloser->setFont(font1);
        PushLightFurther = new QPushButton(centralwidget);
        PushLightFurther->setObjectName("PushLightFurther");
        PushLightFurther->setGeometry(QRect(730, 380, 61, 23));
        PushLightFurther->setFont(font1);
        PushLightUp = new QPushButton(centralwidget);
        PushLightUp->setObjectName("PushLightUp");
        PushLightUp->setGeometry(QRect(730, 330, 61, 23));
        PushLightUp->setFont(font1);
        PushLightRight = new QPushButton(centralwidget);
        PushLightRight->setObjectName("PushLightRight");
        PushLightRight->setGeometry(QRect(800, 370, 61, 23));
        PushLightRight->setFont(font1);
        PushLightLeft = new QPushButton(centralwidget);
        PushLightLeft->setObjectName("PushLightLeft");
        PushLightLeft->setGeometry(QRect(660, 370, 61, 23));
        PushLightLeft->setFont(font1);
        PushLightDown = new QPushButton(centralwidget);
        PushLightDown->setObjectName("PushLightDown");
        PushLightDown->setGeometry(QRect(730, 410, 61, 23));
        PushLightDown->setFont(font1);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(650, 160, 91, 21));
        label_11->setFont(font1);
        RotateLeft = new QPushButton(centralwidget);
        RotateLeft->setObjectName("RotateLeft");
        RotateLeft->setGeometry(QRect(660, 200, 61, 23));
        RotateLeft->setFont(font1);
        RotateRight = new QPushButton(centralwidget);
        RotateRight->setObjectName("RotateRight");
        RotateRight->setGeometry(QRect(800, 200, 61, 23));
        RotateRight->setFont(font1);
        RotateDown = new QPushButton(centralwidget);
        RotateDown->setObjectName("RotateDown");
        RotateDown->setGeometry(QRect(730, 220, 61, 23));
        RotateDown->setFont(font1);
        RotateUp = new QPushButton(centralwidget);
        RotateUp->setObjectName("RotateUp");
        RotateUp->setGeometry(QRect(730, 180, 61, 23));
        RotateUp->setFont(font1);
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName("line_9");
        line_9->setGeometry(QRect(630, 150, 271, 16));
        line_9->setFont(font2);
        line_9->setFrameShadow(QFrame::Plain);
        line_9->setLineWidth(1);
        line_9->setFrameShape(QFrame::HLine);
        rb_day = new QRadioButton(centralwidget);
        rb_day->setObjectName("rb_day");
        rb_day->setGeometry(QRect(650, 510, 91, 22));
        QFont font3;
        font3.setPointSize(10);
        rb_day->setFont(font3);
        rb_day->setChecked(true);
        rb_night = new QRadioButton(centralwidget);
        rb_night->setObjectName("rb_night");
        rb_night->setGeometry(QRect(650, 550, 91, 22));
        rb_night->setFont(font3);
        rb_night->setTabletTracking(false);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(630, 480, 141, 21));
        label_12->setFont(font);
        line_10 = new QFrame(centralwidget);
        line_10->setObjectName("line_10");
        line_10->setGeometry(QRect(770, 480, 131, 20));
        line_10->setFont(font2);
        line_10->setFrameShadow(QFrame::Plain);
        line_10->setLineWidth(1);
        line_10->setFrameShape(QFrame::HLine);
        line_11 = new QFrame(centralwidget);
        line_11->setObjectName("line_11");
        line_11->setGeometry(QRect(890, 490, 20, 101));
        line_11->setFrameShadow(QFrame::Plain);
        line_11->setFrameShape(QFrame::VLine);
        line_12 = new QFrame(centralwidget);
        line_12->setObjectName("line_12");
        line_12->setGeometry(QRect(620, 500, 20, 91));
        line_12->setFrameShadow(QFrame::Plain);
        line_12->setFrameShape(QFrame::VLine);
        line_13 = new QFrame(centralwidget);
        line_13->setObjectName("line_13");
        line_13->setGeometry(QRect(630, 580, 271, 16));
        line_13->setFont(font2);
        line_13->setFrameShadow(QFrame::Plain);
        line_13->setLineWidth(1);
        line_13->setFrameShape(QFrame::HLine);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 910, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(hot_keys);
        menu->addSeparator();
        menu->addAction(about_prog);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214 \321\206\320\262\320\265\321\202\320\272\320\260", nullptr));
        hot_keys->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\200\321\217\321\207\320\270\320\265 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", nullptr));
        about_prog->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214:", nullptr));
#if QT_CONFIG(whatsthis)
        PushUp->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        PushUp->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        PushRight->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        PushLeft->setText(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        PushDown->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
        PushCloser->setText(QCoreApplication::translate("MainWindow", "\320\221\320\273\320\270\320\266\320\265", nullptr));
        PushFurther->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\273\321\214\321\210\320\265", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214:", nullptr));
        PushLightCloser->setText(QCoreApplication::translate("MainWindow", "\320\221\320\273\320\270\320\266\320\265", nullptr));
        PushLightFurther->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\320\273\321\214\321\210\320\265", nullptr));
        PushLightUp->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        PushLightRight->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        PushLightLeft->setText(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        PushLightDown->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214:", nullptr));
        RotateLeft->setText(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        RotateRight->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        RotateDown->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
        RotateUp->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        rb_day->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\275\321\214", nullptr));
        rb_night->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\321\207\321\214", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\320\275\320\260 \320\264\320\275\321\217 \320\270 \320\275\320\276\321\207\320\270:", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
