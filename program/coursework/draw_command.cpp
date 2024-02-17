#include "draw_command.h"


InitDrawCommand::InitDrawCommand(const weak_ptr<QImage>& image) :
    _image(image) {}

InitDrawCommand::~InitDrawCommand() {}

void InitDrawCommand::execute(weak_ptr<Scene> scene)
{
    shared_ptr<Drawer> image(new Drawer(_image));

    InitDrawManager(scene, image).execute();
}


DrawCommand::DrawCommand() {}

DrawCommand::~DrawCommand() {}

void DrawCommand::execute(weak_ptr<Scene> scene)
{
    DrawManager(scene).execute();
}

DrawNightCommand::DrawNightCommand() {}

DrawNightCommand::~DrawNightCommand() {}

void DrawNightCommand::execute(weak_ptr<Scene> scene)
{
    DrawNightManager(scene).execute();
}

DrawDayCommand::DrawDayCommand() {}

DrawDayCommand::~DrawDayCommand() {}

void DrawDayCommand::execute(weak_ptr<Scene> scene)
{
    DrawDayManager(scene).execute();
}

