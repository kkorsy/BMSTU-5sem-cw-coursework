QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base_command.cpp \
    base_error.cpp \
    camera.cpp \
    center.cpp \
    day_night_commands.cpp \
    draw_command.cpp \
    draw_visitor.cpp \
    drawer.cpp \
    leaf.cpp \
    light_source.cpp \
    main.cpp \
    mainwindow.cpp \
    managers.cpp \
    model.cpp \
    object_visitor.cpp \
    petal.cpp \
    point.cpp \
    projecting.cpp \
    receptacle.cpp \
    scene.cpp \
    scene_errors.cpp \
    scene_object.cpp \
    side.cpp \
    side_errors.cpp \
    simple_object.cpp \
    stem.cpp \
    surface.cpp \
    transform_command.cpp \
    transformation.cpp \
    vector.cpp \
    vector_errors.cpp \
    vertex.cpp \
    visualizer.cpp

HEADERS += \
    all_commands.h \
    base_command.h \
    base_error.h \
    camera.h \
    center.h \
    day_night_commands.h \
    draw_command.h \
    draw_visitor.h \
    drawer.h \
    facade.h \
    leaf.h \
    light_source.h \
    mainwindow.h \
    managers.h \
    model.h \
    object_visitor.h \
    petal.h \
    point.h \
    projecting.h \
    receptacle.h \
    scene.h \
    scene_errors.h \
    scene_object.h \
    side.h \
    side_errors.h \
    simple_object.h \
    stem.h \
    surface.h \
    transform_command.h \
    transformation.h \
    transformator.h \
    vector.h \
    vector_errors.h \
    vertex.h \
    visualizer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
