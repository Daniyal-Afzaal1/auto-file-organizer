#include "../include/FileProcessor.h"

string getExtension(const fs::path &file)
{
    if (!file.has_extension())
        return "";

    return file.extension().string();
}

string getDestinationFolder(const string &extension)
{
    auto it = rules.find(extension); //points to that key/value pair
    return (it != rules.end()) ? it->second : "Others";
}

fs::path moveFile(const fs::path &file, const string &folder)
{
    fs::path destinationDir = Path / folder;

    // ensure directory exists
    if (!fs::exists(destinationDir))
    {
        fs::create_directories(destinationDir);
    }

    string name = file.stem().string();
    string ext  = file.extension().string();

    fs::path newPath = destinationDir / (name + ext);

    int counter = 1;

    // if file already exists, generate new name
    while (fs::exists(newPath))
    {
        newPath = destinationDir / (name + " (" + to_string(counter) + ")" + ext);
        counter++;
    }

    // move file
    fs::rename(file, newPath);

    return newPath;
}

stack<MoveAction> undoStack; 

void processFiles(){
    int totalFiles = files.size();
    int current = 1;

    while(!files.empty()){
        fs::path Filepath = files.front();
        files.pop();

        string extension = getExtension(Filepath);
        string DestinationFolder = getDestinationFolder(extension);
        fs::path newPath = moveFile(Filepath,DestinationFolder);

        // log
        writeLog("Moved " + Filepath.string() + " -> " + newPath.string(), "MOVE");
        // store for undo
        undoStack.push({Filepath, newPath});

        cout << "\033[32m"
             << "[" << current << "/" << totalFiles << "] "
             << "Moved " << Filepath.filename()
             << " into " << newPath.parent_path().filename()
             << "\033[0m" << endl;

        current++;
    }
}


