#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <functional>

class TaskManager {
private:
    std::vector<Task> tasks; // Контейнер для задач

public:
    void addTask(const Task& task);
    std::vector<Task> getTasks() const;
    std::vector<Task> filterTasks(std::function<bool(const Task&)> filter) const;
    void sortTasks(std::function<bool(const Task&, const Task&)> comparator);
    void editTask(size_t index, std::function<void(Task&)> editor);
    void deleteTask(size_t index);
};

#endif // TASKMANAGER_H