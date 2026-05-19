#include "../include/FileScanner.h"

 fs::path Path;

fs::path getDirectoryInput()
{
    string input;

    while (true)
    {
        cout << "Enter path to organize files: ";
        getline(cin, input);

        Path = input;

        // Converts relative path to absolute using HOME/USERPROFILE
        if (!Path.is_absolute())
        {
            const char *homeDir = getenv("HOME");

            if (homeDir == nullptr)
            {
                homeDir = getenv("USERPROFILE");
            }

            if (homeDir != nullptr)
            {
                Path = fs::path(homeDir) / Path;
            }
            else
            {
                 cout << "\033[31mCannot detect home directory!\033[0m" << endl;
                continue;
            }
        }

        // Validates path
        if (!fs::exists(Path))
        {
            cout << "\033[31mPath does not exist!\033[0m" << endl;
            continue;
        }

        if (!fs::is_directory(Path))
        {
             cout << "\033[31mPath is not a directory!\033[0m" << endl;
            continue;
        }

        // cout << "Valid Path: " << Path << endl; just for debug
        return Path;
    }
}
queue<fs::path> files;

void scanFiles()
{
    fs::path Path = getDirectoryInput();

    bool hasFiles = false;

    for (const auto &entry : fs::directory_iterator(Path))
    {
        if (entry.is_regular_file())
        {
            hasFiles = true;
            files.push(entry.path());
        }
    }

    if (!hasFiles)
    {
        cout << "\033[33mNo files found in this folder or everything is already organized!\033[0m" << endl;
        return;
    }

}