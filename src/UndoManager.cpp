#include "../include/UndoManager.h"

void undoLastAction()
{
    if (undoStack.empty())
    {
        cout << "\033[33mNothing to undo!\033[0m\n";
        return;
    }

    MoveAction last = undoStack.top();

    try
    {
        fs::rename(last.to, last.from);
        undoStack.pop();

        writeLog("Undo: " + last.to.string() + " -> " + last.from.string(), "UNDO");

        cout << "\033[32mUndo successful: " << last.to.filename() << "\033[0m" << endl;
    }
    catch (const exception &e)
    {
        writeLog(string("Undo failed: ") + e.what(), "ERROR");
        cout << "\033[31mUndo failed!\033[0m\n";
    }
}