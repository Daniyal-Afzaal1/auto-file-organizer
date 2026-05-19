#include "../include/ConfigManager.h"

string loadConfig() // opens file and add the data in a string
{
    ifstream file("config/config.json");

    if (!file.is_open())
    {
         cout << "\033[31mError: Could not open config/config.json file!\033[0m" << endl;
        return "";
    }

    string data;
    getline(file, data, '\0');

    file.close();
    return data;
}

unordered_map<string, vector<string>> folders;
unordered_map<string, string> rules;

void parseFolders()
{
    string Data = loadConfig();
    if (Data.empty())
    {
         cout << "\033[31mError: Config file is empty or failed to load folders!\033[0m" << endl;
        return;
    }

    int start = Data.find("\"folders\"");
    int openBrace = Data.find('{', start);
    int closeBrace = Data.find('}', openBrace);

    string folderPart = Data.substr(openBrace + 1, closeBrace - openBrace - 1); // takes inside values of folders

    stringstream ss(folderPart); // it takes input line by line for string
    string line;

    while (getline(ss, line))
    {
        int firstQuote = line.find('"');
        if (firstQuote == string::npos) // npos: not found,holds very big integer
            continue;

        int secondQuote = line.find('"', firstQuote + 1);
        string key = line.substr(firstQuote + 1, secondQuote - firstQuote - 1); // extracts key

        folders[key] = {};

        int openBracket = line.find('[');
        int closeBracket = line.find(']');

        string inside = line.substr(openBracket + 1, closeBracket - openBracket - 1); // extract key array

        size_t pos = 0; // size_t: for positive positions

        while (true)
        {
            size_t first = inside.find('"', pos);
            if (first == string::npos)
                break; // if nothing everything breaks and empty vector

            size_t second = inside.find('"', first + 1);
            if (second == string::npos)
                break;

            string value = inside.substr(first + 1, second - first - 1);

            folders[key].push_back(value);

            pos = second + 1;
        }
    }
}

void parseRules() // fills Rules unordered_map
{
    string data = loadConfig();
    if (data.empty())
    {
         cout << "\033[31mError: Config file is empty or failed to load rules!\033[0m" << endl;
        return;
    }

    int start = data.find("\"rules\"");
    int openBrace = data.find('{', start);
    int closeBrace = data.find('}', openBrace);

    string rulesPart = data.substr(openBrace + 1, closeBrace - openBrace - 1);

    stringstream ss(rulesPart);
    string line;

    while (getline(ss, line))
    {
        int firstQuote = line.find('"');
        if (firstQuote == string::npos)
            continue;

        int secondQuote = line.find('"', firstQuote + 1);
        string key = line.substr(firstQuote + 1, secondQuote - firstQuote - 1);

        int colon = line.find(':');

        int valStart = line.find('"', colon);
        int valEnd = line.find('"', valStart + 1);

        string value = line.substr(valStart + 1, valEnd - valStart - 1);

        rules[key] = value;
    }
}

