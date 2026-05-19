#include "../include/SearchManager.h"

void searchFile()
{
    string fileName;
    bool found = false;

    cout << "Enter file name to search: ";
    getline(cin, fileName);

    for (const auto &entry : fs::recursive_directory_iterator(Path))
    {
        if (entry.is_regular_file())
        {
            if (entry.path().filename() == fileName)
            {
                cout << "\033[32mFound: " << entry.path() << "\033[0m" << endl;
                found = true;
            }
        }
    }

    if (!found)
    {
        cout << "\033[33mFile not found!\033[0m\n";
    }
}