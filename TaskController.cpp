#include <iostream>
#include "TaskController.h"

TaskController::TaskController(TaskManager& manager, TaskView& view)
    : model(manager), view(view) {
}

void TaskController::addTask() {
    std::string title = view.getInput("Enter task title: ");
    std::string description = view.getInput("Enter task description: ");
    int priority = view.getIntegerInput("Enter task priority (1-5): ");
    auto deadline = std::chrono::system_clock::now() + std::chrono::hours(24); // Пример: дедлайн через 24 часа

    model.addTask(Task(title, description, priority, deadline));
}

void TaskController::showTasks() {
    view.displayTasks(model.getTasks());
}

void TaskController::sortTasks() {
    model.sortTasks([](const Task& a, const Task& b) {
        return a.getPriority() > b.getPriority();
        });
    view.displayTasks(model.getTasks());
}

void TaskController::filterTasks() {
    auto filtered = model.filterTasks([](const Task& task) {
        return !task.isDone(); // Показывать только невыполненные задачи
        });
    view.displayTasks(filtered);
}

void TaskController::editTask() {
    size_t index = view.getIntegerInput("Enter task index to edit: ") - 1;
    model.editTask(index, [this](Task& task) {
        std::cout << "\nWhat do you want to edit?\n";
        std::cout << "1. Title\n";
        std::cout << "2. Description\n";
        std::cout << "3. Priority\n";
        std::cout << "4. Deadline\n";
        int choice = view.getIntegerInput("Choose an option: ");
        switch (choice) {
        case 1:
            task.setTitle(view.getInput("Enter new title: "));
            break;
        case 2:
            task.setDescription(view.getInput("Enter new description: "));
            break;
        case 3:
            task.setPriority(view.getIntegerInput("Enter new priority (1-5): "));
            break;
        case 4: {
            // Пример изменения дедлайна
            int hours = view.getIntegerInput("Enter new deadline in hours from now: ");
            auto new_deadline = std::chrono::system_clock::now() + std::chrono::hours(hours);
            task.setDeadline(new_deadline);
            break;
        }
        default:
            std::cout << "Invalid option. No changes made.\n";
        }
        });
}

void TaskController::deleteTask() {
    size_t index = view.getIntegerInput("Enter task index to delete: ") - 1;

    // Добавляем подтверждение перед удалением
    std::string confirmation = view.getInput("Are you sure you want to delete this task? (yes/no): ");
    if (confirmation == "yes") {
        model.deleteTask(index);
        std::cout << "Task deleted successfully.\n";
    }
    else {
        std::cout << "Task deletion cancelled.\n";
    }
}

void TaskController::markTaskAsDone() {
    size_t index = view.getIntegerInput("Enter task index to mark as done: ") - 1;

    if (index >= model.getTasks().size()) {
        std::cout << "Invalid task index. No changes made.\n";
        return;
    }

    model.editTask(index, [](Task& task) {
        task.markAsDone();
        });

    std::cout << "Task #" << index + 1 << " marked as done.\n";
}