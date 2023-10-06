#include "main.h"
#include <stdio.h>

/**
 * struct Task - Structure for a single task
 * @description: Description of the task
 * @completed: Whether the task is completed or not
 * Return: 0
 */

void print_menu(void)
{
	printf("\nTo-Do List Menu:\n");
	printf("1. Add Task\n");
	printf("2. View Tasks\n");
	printf("3. Mark Task as Completed\n");
	printf("4. Quit\n");
	printf("Enter your choice: ");
}

int main(void)
{
	struct Task tasks[MAX_TASKS];
	int task_count = 0;

	int choice;
	while (1)

	{
		print_menu();
		scanf("%d", &choice);

		switch (choice)

		{
		case 1: /* Add Task */
			if (task_count < MAX_TASKS)

			{
				printf("Enter task description: ");
				scanf(" %[^\n]", tasks[task_count].description);
				tasks[task_count].completed = false;
				task_count++;
				printf("Task added!\n");
			}

			else
			{
				printf("Task list is full!\n");
			}

			break;

		case 2: /* View Tasks */
			printf("\nTasks:\n");
			for (int i = 0; i < task_count; i++)
			{
				printf("%d. %s [%s]\n", i + 1, tasks[i].description,
					   tasks[i].completed ? "Completed" : "Not Completed");
			}

			break;

		case 3: /* Mark Task as Completed */
			printf("Enter the task number to mark as completed: ");
			int task_number;
			scanf("%d", &task_number);

			if (task_number >= 1 && task_number <= task_count)
			{
				tasks[task_number - 1].completed = true;
				printf("Task marked as completed!\n");
			}

			else
			{
				printf("Invalid task number!\n");
			}

			break;

		case 4: /* Quit */
			printf("Goodbye!\n");
			return 0;

		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}
	}

	return 0;
}
