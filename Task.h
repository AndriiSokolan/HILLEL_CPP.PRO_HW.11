#ifndef TASK_H
#define TASK_H

#include <string>
#include <chrono>

class Task {
private:
    std::string title; // Название задачи
    std::string description; // Описание задачи
    int priority; // Приоритет (1-5)
    std::chrono::system_clock::time_point deadline; // Дедлайн задачи
    bool is_done; // Состояние выполнения
    std::chrono::system_clock::time_point created_at; // Дата создания

public:
    Task(const std::string& title, const std::string& description, int priority,
        const std::chrono::system_clock::time_point& deadline);

    // Геттеры
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    int getPriority() const;
    std::chrono::system_clock::time_point getDeadline() const;
    bool isDone() const;
    std::chrono::system_clock::time_point getCreatedAt() const;

    // Сеттеры
    void setTitle(const std::string& new_title);
    void setDescription(const std::string& new_description);
    void setPriority(int new_priority);
    void setDeadline(const std::chrono::system_clock::time_point& new_deadline);
    void markAsDone();
};

#endif // TASK_H