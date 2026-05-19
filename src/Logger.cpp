#include "../include/Logger.h"

void writeLog(const string &message, const string &type)
{
    ofstream file("logs/activity_log.txt", ios::app);

    if (!file)
    {
        cout << "\033[31mError opening log file\033[0m\n";
        return;
    }

    file << "[" << type << "] "
         << "[" << getCurrentTime() << "] "
         << message << endl;

    file.close();
}

void viewLog()
{
    ifstream file("logs/activity_log.txt");

    if (!file)
    {
        cout << "\033[33mNo logs found\033[0m\n";
        return;
    }

    string line;

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}