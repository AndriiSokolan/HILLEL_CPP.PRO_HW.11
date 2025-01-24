#ifndef TASKCONTROLLER_H
#define TASKCONTROLLER_H

#include "TaskManager.h"
#include "TaskView.h"

class TaskController {
private:
    TaskManager& model;
    TaskView& view;

public:
    TaskController(TaskManager& manager, TaskView& view);

    void addTask();
    void showTasks();
    void sortTasks();
    void filterTasks();
    void editTask();
    void deleteTask();
    void markTaskAsDone();
};

#endif