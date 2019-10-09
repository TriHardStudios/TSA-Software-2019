// Accept function pointer, elapse time, accept start time
// property struct generated by passed stuff
// Manage queue

// Actually run the functions with the function pointers
// Deploy threads

class TaskScheduler {
private:
    int taskNumber = 0;
public:
    // Gets the function pointer, elapse time and start time if applicable
    void addTask(int, int, void);
private:
    // Makes a structure from the passed information
    int createTask();
    // Runs the threads with an infinite loop checking the queue and executing threads
    void threadRun();
    // Checks queue to see if there is space for any threads
    int assesQueue();
    // Stops a thread

    void terminateThread();

};