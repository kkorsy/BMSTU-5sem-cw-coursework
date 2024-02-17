#include "day_night_commands.h"

NightCommand::NightCommand() {}

NightCommand::~NightCommand() {}

void NightCommand::execute(weak_ptr<Scene> scene)
{
    NightManager(scene).execute();
}

DayCommand::DayCommand() {}

DayCommand::~DayCommand() {}

void DayCommand::execute(weak_ptr<Scene> scene)
{
    DayManager(scene).execute();
}
