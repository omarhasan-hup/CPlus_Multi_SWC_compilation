// #include <iostream>
// #include "calc.hpp"
// #include "printing.hpp"
// int main ()
// {
//     int x1=0;
//     int x3=10;
//     int x4=8;
//     auto x2=calc(x3,x4);

//     std::cout << "X1= "<< x1 <<"\n";
//     std::cout << "X2= "<< x2 <<"\n";
//     std::cout << "X3= "<< x3 <<"\n";
//     std::cout << "X4= "<< x4 <<"\n";
    
//     std::cout << "Using the Print_swc Below \n";

//     printing();

//     return 0;
// }


/*
 * FreeRTOS C++ Demo
 * This is a simple C++ program to demonstrate the creation of multiple tasks in FreeRTOS.
 */

#include <iostream>
#include <unistd.h> // Required for usleep()

// FreeRTOS kernel includes
#include "FreeRTOS.h"
#include "task.h"


/**
 * @brief This hook is called by the idle task when it is scheduled.
 *
 * In the POSIX port, the FreeRTOS scheduler can starve other pthreads on the system,
 * including the thread that simulates the tick interrupt. To prevent this, we
 * introduce a small sleep in the idle hook. This yields the CPU back to the OS,
 * allowing the tick thread to run.
 *
 * This function's implementation is required because configUSE_IDLE_HOOK is set to 1
 * in FreeRTOSConfig.h.
 */
extern "C" void vApplicationIdleHook(void)
{
    // Sleep for a short period to allow other threads to run.
    // 100 microseconds is a reasonable value.
    usleep(100);
}
/**
 * @brief The function that will be executed by each task.
 *
 * @param pvParameters A pointer to the parameters passed to the task. In this case, it's a string.
 */
void vSimplePrintTask(void *pvParameters)
{
    // The parameter is cast to a char pointer to be used as the task's identifying message.
    char *pcTaskMessage = (char *)pvParameters;

    // Each task runs in an infinite loop.
    for (;;)
    {
        /*
         * Print out the message.
         * Note: In a real-world multi-threaded application, access to shared resources
         * like std::cout should be protected by a mutex to prevent interleaved output.
         * For this simple example, it's generally okay.
         */
        std::cout << pcTaskMessage << " is executing." << std::endl;

        /*
         * Delay for a period. This is a cooperative way to yield the CPU to other tasks.
         * The delay is specified in ticks. The pdMS_TO_TICKS() macro converts milliseconds
         * to the equivalent number of ticks.
         */
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

// Define the messages that will be passed to each task.
// Using static const char* ensures they have a permanent storage location.
static const char *pcTextForTask1 = "Task 1";
static const char *pcTextForTask2 = "Task 2";
static const char *pcTextForTask3 = "Task 3";
static const char *pcTextForTask4 = "Task 4";

/**
 * @brief The main entry point of the application.
 */
int main()
{
    std::cout << "--- FreeRTOS Task Creation Demo ---" << std::endl;

    // Create four tasks.
    // For the POSIX port, the stack size is specified in words, and a larger stack is often needed.
    xTaskCreate(vSimplePrintTask, "Task 1", configMINIMAL_STACK_SIZE * 2, (void *)pcTextForTask1, 1, NULL);
    xTaskCreate(vSimplePrintTask, "Task 2", configMINIMAL_STACK_SIZE * 2, (void *)pcTextForTask2, 1, NULL);
    xTaskCreate(vSimplePrintTask, "Task 3", configMINIMAL_STACK_SIZE * 2, (void *)pcTextForTask3, 1, NULL);
    xTaskCreate(vSimplePrintTask, "Task 4", configMINIMAL_STACK_SIZE * 2, (void *)pcTextForTask4, 1, NULL);

    /*
     * Start the scheduler.
     * This will begin multitasking and will not return. The tasks that were created will start executing.
     */
    vTaskStartScheduler();

    /*
     * The following code will only be reached if there is insufficient FreeRTOS heap
     * memory available for the idle and/or timer tasks to be created.
     * See http://www.freertos.org/a00111.html
     */
    return 0; // Should not be reached.
}
