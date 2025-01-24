#include "TaskController.h"
#include "TaskManager.h"
#include "TaskView.h"
#include <iostream>

int main() {
    TaskManager manager;
    TaskView view;
    TaskController controller(manager, view);

    bool running = true;
    while (running) {
        std::cout << "\nTask Manager:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Show Tasks\n";
        std::cout << "3. Sort Tasks\n";
        std::cout << "4. Filter Tasks\n";
        std::cout << "5. Edit Task\n";
        std::cout << "6. Delete Task\n";
        std::cout << "7. Mark Task as Done\n";
        std::cout << "8. Exit\n";

        int choice = view.getIntegerInput("Choose an option: ");
        switch (choice) {
        case 1: controller.addTask(); break;
        case 2: controller.showTasks(); break;
        case 3: controller.sortTasks(); break;
        case 4: controller.filterTasks(); break;
        case 5: controller.editTask(); break;
        case 6: controller.deleteTask(); break;
        case 7: controller.markTaskAsDone(); break;
        case 8: running = false; break;
        default: std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}