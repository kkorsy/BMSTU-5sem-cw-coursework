#ifndef DAYNIGHTCOMMANDS_H
#define DAYNIGHTCOMMANDS_H

#include "base_command.h"
#include "managers.h"

class NightCommand : public BaseCommand
{
public:
    NightCommand();
    virtual ~NightCommand();

    virtual void execute(weak_ptr<Scene> scene);
};

class DayCommand : public BaseCommand
{
public:
    DayCommand();
    virtual ~DayCommand();

    virtual void execute(weak_ptr<Scene> scene);
};

#endif // DAYNIGHTCOMMANDS_H
