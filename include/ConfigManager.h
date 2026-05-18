#pragma once

#include <fstream>
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

extern unordered_map <string,string> rules; //not create it here
extern unordered_map <string,vector<string>> folders;

string loadConfig();
void parseFolders();
void parseRules();