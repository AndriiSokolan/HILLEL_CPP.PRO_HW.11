#include "Task.h"

Task::Task(const std::string& title, const std::string& description, int priority,
    const std::chrono::system_clock::time_point& deadline)
    : title(title), description(description), priority(priority),
    deadline(deadline), is_done(false), created_at(std::chrono::system_clock::now()) {
}

// Геттеры
const std::string& Task::getTitle() const { return title; }
const std::string& Task::getDescription() const { return description; }
int Task::getPriority() const { return priority; }
std::chrono::system_clock::time_point Task::getDeadline() const { return deadline; }
bool Task::isDone() const { return is_done; }
std::chrono::system_clock::time_point Task::getCreatedAt() const { return created_at; }

// Сеттеры
void Task::setTitle(const std::string& new_title) { title = new_title; }
void Task::setDescription(const std::string& new_description) { description = new_description; }
void Task::setPriority(int new_priority) { priority = new_priority; }
void Task::setDeadline(const std::chrono::system_clock::time_point& new_deadline) { deadline = new_deadline; }
void Task::markAsDone() { is_done = true; }