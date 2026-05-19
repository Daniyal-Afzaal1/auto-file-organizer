#pragma once

//headers
#include <queue>
#include <iostream>
#include <algorithm>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

extern queue<fs::path> files;
extern fs::path Path;


//function declarations
fs::path getDirectoryInput();
void scanFiles();