#include <bits/stdc++.h>
using namespace std;

// this function will store tasks that the user will add.this can also be done by using an array.
void add_task(vector<string> &tasks, const string &task, int &task_number)
{
    tasks[task_number] = task;
    task_number++;
}

// this function will show the tasks that the user will add.
void view_tasks(const vector<string> &tasks, int task_number, int completed_number)
{
    if (task_number == 0 && completed_number == 10)
    {
        cout << "No tasks!" << endl;
    }
    else
    {
        cout << endl
             << "Pending Tasks" << endl;
        for (int i = 0; i < task_number; i++)
        {
            cout << i + 1 << '.' << tasks[i] << endl;
        }
        cout << endl;

        cout << endl
             << "Completed Taks" << endl;
        for (int i = 10; i < completed_number; i++)
        {
            cout << i - 9 << '.' << tasks[i] << endl;
        }
        cout << endl;
    }
}

// this function will check whether the tasks are completed or pending.
void Task_completion(vector<string> &tasks, int &completed_number, int comp_no, int &task_number)
{
    swap(tasks[completed_number++], tasks[comp_no - 1]);
    for (int i = comp_no - 1; i <= task_number; i++)
    {
        swap(tasks[i], tasks[i + 1]);
    }
    task_number--;
}

// this function will ask the user whether the user wants to remove any task. 
void remove_task(vector<string> &tasks, int &task_number, int &completed_number)
{
    int choice;
    cout << endl
         << "Enter 1. if you want to remove a pending task \nEnter 2. if you want to remove a completed task \nEnter your choice : ";
    cin >> choice;
    if (choice == 1)
    {
        view_tasks(tasks, task_number, completed_number);
        int choice_task;
        cout << "enter the task number you want to remove :";
        cin >> choice_task;
        for (int i = choice_task - 1; i <= task_number; i++)
        {
            swap(tasks[i], tasks[i + 1]);
        }
        task_number--;
    }
    else if (choice == 2)
    {
        view_tasks(tasks, task_number, completed_number);
        int choice_task;
        cout << "enter the task number you want to remove :";
        cin >> choice_task;
        for (int i = choice_task + 9; i <= completed_number; i++)
        {
            swap(tasks[i], tasks[i + 1]);
        }
        completed_number--;
    }
    else
    {
        cout << endl
             << "Please enter valid choice" << endl;
    }
}

int main()
{
    int task_number = 0;
    int completed_number = 10;

    vector<string> tasks(20, "task");
    while (true)
    {
        int flag = 0;
        int choice;
        cout << "1. Add tasks" << endl;
        cout << "2. View task" << endl;
        cout << "3. Remove task" << endl;
        cout << "4. To Mark Task as Completed" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string task;
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, task);
            add_task(tasks, task, task_number);
            break;
        }
        case 2:
        {
            view_tasks(tasks, task_number, completed_number);
            break;
        }
        case 3:
        {
            remove_task(tasks, task_number, completed_number);
            break;
        }

        case 4:
            int comp_no;
            cout << "Enter The Task Number You Want To Mark Completed : ";
            cin >> comp_no;

            Task_completion(tasks, completed_number, comp_no, task_number);

            cout << "Task Marked As Completed !!!!" << endl;
            break;

        case 5:
            cout << "Exit:";
            flag = 1;
            break;
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
        if (flag == 1)
        {
            break;
        }
    }

    return 0;
}