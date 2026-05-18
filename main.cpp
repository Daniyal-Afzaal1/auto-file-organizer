// deals with user input and overall flow
// #include <iostream>
// #include <filesystem>
// #include <algorithm>
// #include <cctype>
// using namespace std;
// namespace fs = std::filesystem; // creates an alias

// void organizer(fs::path Path)
// {
//   int totalFiles = 0;

//   for (const auto &entry : fs::directory_iterator(Path)) //calculates total files
//   {
//     if (entry.is_regular_file())
//       totalFiles++;
//   }

//    if (totalFiles == 0)
//     {
//         cout << "\033[33mNo files found in this folder or everything is already organized!\033[0m" << endl;
//         return; // Exit the function
//     }

//   int current = 0;
//   for (const auto &entry : fs::directory_iterator(Path))
//   {
//     fs::path filePath = entry.path();                          // file's path
//     string ext = filePath.extension().string();                // gives path so converted in string
//     transform(ext.begin(), ext.end(), ext.begin(), ::tolower); // to lowercase

//     fs::path destination; // where the file will go

//     if (ext == ".pdf" || ext == ".doc" || ext == ".docx" || ext == ".txt" ||
//         ext == ".rtf" || ext == ".odt" || ext == ".xls" || ext == ".xlsx" ||
//         ext == ".csv" || ext == ".ppt" || ext == ".pptx" || ext == ".epub" ||
//         ext == ".md" || ext == ".tex")
//     {
//       destination = Path / "Documents";
//     }
//     else if (ext == ".jpg" || ext == ".jpeg" || ext == ".png" || ext == ".gif" ||
//              ext == ".bmp" || ext == ".webp" || ext == ".tiff" || ext == ".svg" ||
//              ext == ".ico" || ext == ".heic" || ext == ".raw")
//     {
//       destination = Path / "Images";
//     }
//     else if (ext == ".mp4" || ext == ".mkv" || ext == ".avi" || ext == ".mov" ||
//              ext == ".wmv" || ext == ".flv" || ext == ".webm" || ext == ".m4v" ||
//              ext == ".3gp" || ext == ".mpeg" || ext == ".mpg")
//     {
//       destination = Path / "Videos";
//     }
//     else if (ext == ".mp3" || ext == ".wav" || ext == ".aac" || ext == ".flac" ||
//              ext == ".ogg" || ext == ".m4a" || ext == ".wma" || ext == ".opus" ||
//              ext == ".mid" || ext == ".midi")
//     {
//       destination = Path / "Audio";
//     }
//     else if (ext == ".zip" || ext == ".rar" || ext == ".7z" || ext == ".tar" ||
//              ext == ".gz" || ext == ".bz2" || ext == ".xz" || ext == ".iso")
//     {
//       destination = Path / "Archives";
//     }
//     else if (ext == ".cpp" || ext == ".c" || ext == ".h" || ext == ".hpp" ||
//              ext == ".py" || ext == ".java" || ext == ".js" || ext == ".ts" ||
//              ext == ".html" || ext == ".css" || ext == ".json" || ext == ".xml" ||
//              ext == ".yaml" || ext == ".yml" || ext == ".php" || ext == ".go" ||
//              ext == ".rs" || ext == ".swift" || ext == ".kt" || ext == ".sh" ||
//              ext == ".bat" || ext == ".ps1")
//     {
//       destination = Path / "Code";
//     }
//     else if (ext == ".appimage" || ext == ".deb" || ext == ".rpm" ||
//              ext == ".bin" || ext == ".run" || ext == ".exe" ||
//              ext == ".msi" || ext == ".dll")
//     {
//       destination = Path / "Executables";
//     }
//     else if (ext == ".ttf" || ext == ".otf" || ext == ".woff" || ext == ".woff2")
//     {
//       destination = Path / "Fonts";
//     }
//     else
//     {
//       continue;
//     }

//     if (!fs::exists(destination))
//     {
//       fs::create_directory(destination);
//     }

//     fs::path newLocation = destination / filePath.filename();

//     current++;
//     if (!fs::exists(newLocation))
//     {
//       fs::rename(filePath, newLocation);
//     }

//     cout << "\033[32m" << "[" << current << "/" << totalFiles << "] "
//          << "Moved " << filePath.filename() << " into " << newLocation.parent_path().filename() << "\033[0m" << endl; //these ANSI code work for linux
//   }
// }

// int main()
// {
//   int choice;
//   do
//   {
//     cout << R"(     _   _   _ _____ ___        _____ ___ _     _____       ___  ____   ____    _    _   _ ___ __________ ____  
//     / \ | | | |_   _/ _ \      |  ___|_ _| |   | ____|     / _ \|  _ \ / ___|  / \  | \ | |_ _|__  / ____|  _ \ 
//    / _ \| | | | | || | | |_____| |_   | || |   |  _| _____| | | | |_) | |  _  / _ \ |  \| || |  / /|  _| | |_) |
//   / ___ \ |_| | | || |_| |_____|  _|  | || |___| |__|_____| |_| |  _ <| |_| |/ ___ \| |\  || | / /_| |___|  _ < 
//  /_/   \_\___/  |_| \___/      |_|   |___|_____|_____|     \___/|_| \_\\____/_/   \_\_| \_|___/____|_____|_| \_\
//                                                                                                                 )";

//     cout << endl;
//     cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
//     cout << "          MENU" << endl;
//     cout << "1. Organize the Files" << endl;
//     cout << "2. Exit" << endl;
//     cout << "Enter your choice: " << endl;
//     cin >> choice;
//     cin.ignore();
//     if (choice == 1)
//     {
//       string Spath;
//       fs::path Path;

//       while (true)
//       {
//         cout << "Copy or Enter the Path where you want to oraganize files" << endl;
//         getline(cin, Spath); // in string as path can have space
//         Path = Spath;

//         if (Path.is_absolute())
//         {
//           if (!fs::exists(Path) || !fs::is_directory(Path))
//           {
//             cout << "Path does not exists or is not a folder!" << endl;
//             continue;
//           }
//           // logic
//           organizer(Path);
//           break;
//         }
//         else
//         {
//           char *homeDir = getenv("HOME");
//           Path = fs::path(homeDir) / Path;

//           if (homeDir == nullptr)
//           {
//             homeDir = getenv("USERPROFILE");

//             Path = fs::path(homeDir) / Path;
//           }

//           cout << "DEBUG: Path = " << Path << endl;
//           if (!fs::exists(Path) || !fs::is_directory(Path))
//           {
//             cout << "Path does not exits or is not a folder!" << endl;
//             continue;
//           }

//           // logic
//           organizer(Path);

//           break;
//         }

//       } // while loop end
//     }
//     else if (choice == 2)
//     {
//       cout << "Quitting...." << endl;
//     }
//     else
//     {
//       cout << "- Enter correct number from the menu !" << endl;
//       continue;
//     }

//   } while (choice != 2);
// }

#include "include/ConfigManager.h"

int main(){
  parseFolders();
  parseRules();
  return 0;
}