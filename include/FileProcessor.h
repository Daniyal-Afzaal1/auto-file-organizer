#pragma once

#include "ConfigManager.h"
#include "FileScanner.h"
#include "Logger.h"
#include <stack>

struct MoveAction {
    fs::path from;//originalpath
    fs::path to;//newpath
};

extern stack<MoveAction> undoStack;  

string getExtension(const fs::path &file);
string getDestinationFolder(const string &extension);
fs::path moveFile(const fs::path &file, const string &folder);
void processFiles();