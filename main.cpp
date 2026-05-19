#include "include/ConfigManager.h"
#include "include/FileScanner.h"
#include "include/FileProcessor.h"
#include "include/SearchManager.h"
#include "include/UndoManager.h"
#include "include/Logger.h"
#include "include/helper.h"
#include "include/TreeManager.h"

#include <iostream>
using namespace std;

int main()
{
    loadConfig();
    parseFolders();
    parseRules();

    int choice;

    while (true)
    {
        MainMenu();
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\033[31mInvalid input! Enter a number.\033[0m\n";
            continue;
        }

        cin.ignore(1000, '\n');

        switch (choice)
        {
        case 1:
        {
            scanFiles();
            processFiles();
            displaySuccessMessage();
            break;
        }

        case 2:
        {
            searchFile();
            break;
        }

        case 3:
        {
            undoLastAction();
            break;
        }

        case 4:
        {
            viewLog();
            break;
        }

        case 5:
        {
            buildTree();
            displayTree(root,0);
            break;
        }

        case 6:
        {
            cout << "\033[32mExiting program...\033[0m\n";
            return 0;
        }

        default:
        {
            cout << "\033[31mInvalid choice! Try again.\033[0m\n";
            break;
        }
        }
    }

    return 0;
}


