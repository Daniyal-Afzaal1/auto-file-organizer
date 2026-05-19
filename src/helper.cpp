//helper functions
#include "../include/helper.h"

//display functions
void MainMenu(){
     cout << R"(     _   _   _ _____ ___        _____ ___ _     _____       ___  ____   ____    _    _   _ ___ __________ ____  
    / \ | | | |_   _/ _ \      |  ___|_ _| |   | ____|     / _ \|  _ \ / ___|  / \  | \ | |_ _|__  / ____|  _ \ 
   / _ \| | | | | || | | |_____| |_   | || |   |  _| _____| | | | |_) | |  _  / _ \ |  \| || |  / /|  _| | |_) |
  / ___ \ |_| | | || |_| |_____|  _|  | || |___| |__|_____| |_| |  _ <| |_| |/ ___ \| |\  || | / /_| |___|  _ < 
 /_/   \_\___/  |_| \___/      |_|   |___|_____|_____|     \___/|_| \_\\____/_/   \_\_| \_|___/____|_____|_| \_\
                                                                                                                )";
    cout << "\n";
    cout << "-----------------------------------------------------------------------------------------------------------------\n";
    cout << "          MENU\n";
    cout << "1. Organize the Files\n";
    cout << "2. Search File\n";
    cout << "3. Undo Last Action\n";
    cout << "4. View Activity Log\n";
    cout << "5. Display Folder Structure\n";
    cout << "6. Exit\n";
    cout << "-----------------------------------------------------------------------------------------------------------------\n";
    cout << "Enter your choice: ";
}

void displaySuccessMessage()
{
    cout << "\033[32m\nOperation completed successfully.\033[0m\n";
}

string getCurrentTime()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    string timeStr = dt;

    // remove trailing newline
    timeStr.pop_back();

    return timeStr;
}