#ifndef TASKVIEW_H
#define TASKVIEW_H

#include "Task.h"
#include <vector>
#include <string>

class TaskView {
public:
    void displayTasks(const std::vector<Task>& tasks);
    std::string getInput(const std::string& prompt);
    int getIntegerInput(const std::string& prompt);
};

#endif // TASKVIEW_H