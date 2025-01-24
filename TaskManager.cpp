#include "TaskManager.h"
#include <algorithm> // Äëÿ std::sort

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

std::vector<Task> TaskManager::getTasks() const {
    return tasks;
}

std::vector<Task> TaskManager::filterTasks(std::function<bool(const Task&)> filter) const {
    std::vector<Task> filtered_tasks;
    for (const auto& task : tasks) {
        if (filter(task)) {
            filtered_tasks.push_back(task);
        }
    }
    return filtered_tasks;
}

void TaskManager::sortTasks(std::function<bool(const Task&, const Task&)> comparator) {
    std::sort(tasks.begin(), tasks.end(), comparator);
}

void TaskManager::editTask(size_t index, std::function<void(Task&)> editor) {
    if (index < tasks.size()) {
        editor(tasks[index]);
    }
}

void TaskManager::deleteTask(size_t index) {
    if (index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}