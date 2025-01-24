#include "TaskView.h"
#include <iostream>
#include <iomanip> // Для форматирования времени

void TaskView::displayTasks(const std::vector<Task>& tasks) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        const auto& task = tasks[i];
        std::cout << "Task #" << i + 1 << ":\n";
        std::cout << "Title: " << task.getTitle() << "\n";
        std::cout << "Description: " << task.getDescription() << "\n";
        std::cout << "Priority: " << task.getPriority() << "\n";

        auto created_time = std::chrono::system_clock::to_time_t(task.getCreatedAt());
        auto deadline_time = std::chrono::system_clock::to_time_t(task.getDeadline());

        char created_buf[26];
        char deadline_buf[26];
        ctime_s(created_buf, sizeof(created_buf), &created_time);
        ctime_s(deadline_buf, sizeof(deadline_buf), &deadline_time);

        std::cout << "Created At: " << created_buf;
        std::cout << "Deadline: " << deadline_buf;
        std::cout << "Status: " << (task.isDone() ? "Done" : "Not Done") << "\n\n";
    }
}

std::string TaskView::getInput(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int TaskView::getIntegerInput(const std::string& prompt) {
    std::cout << prompt;
    int input;
    std::cin >> input;
    std::cin.ignore(); // Удаление символа новой строки
    return input;
}