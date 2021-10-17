
#ifndef L1V2CL_TEXTCONTROL_H
#define L1V2CL_TEXTCONTROL_H

#include <iostream>
#include <fstream>
#include <utility>
#include "stack.h"
#include "textOperation.h"
using namespace std;

class TextControl {

public:
    TextControl() {
        text = "";
    }

    bool undo() {
        if (undoStack.empty())
            return true;
        TextOperation thisOp = undoStack.top();
        redoStack.push(TextOperation(thisOp.getNewData(), thisOp.getData(), thisOp.getPos()));
        undoStack.pop();
        text.replace(thisOp.getPos(), thisOp.getNewData().length(), thisOp.getData());
        return false;
    }

    bool redo() {
        if (redoStack.empty())
            return true;
        TextOperation thisOp = redoStack.top();
        undoStack.push(TextOperation(thisOp.getNewData(), thisOp.getData(), thisOp.getPos()));
        redoStack.pop();
        text.replace(thisOp.getPos(), thisOp.getNewData().length(), thisOp.getData());
        return false;
    }

    bool canUndo() {
        return !undoStack.empty();
    }

    bool canRedo() {
        return !redoStack.empty();
    }

    bool insert(string &value, unsigned int pos) {
        return replace(value, pos, 0);
    }

    bool remove(unsigned int pos, unsigned int len) {
        return replace("", pos, len);
    }

    bool replace(const string &value, unsigned int pos, unsigned int len) {
        if (pos + len > text.length())
            return true;
        undoStack.push(TextOperation(text.substr(pos, len), value, pos));
        text.replace(pos, len, value);
        redoStack.clear();
        return false;
    }

    bool save(const string &filename) {
        undoStack.push(TextOperation(text, "", 0));
        if (redoStack.saveData(filename + ".redo"))
            return true;
        if (undoStack.saveData(filename + ".undo"))
            return true;
        undoStack.pop();
        return false;
    }

    bool load(const string &filename) {
        if (redoStack.loadData(filename + ".redo"))
            return true;
        if (undoStack.loadData(filename + ".undo"))
            return true;
        text = undoStack.top().getData();
        undoStack.pop();
        return false;
    }

    string getUndoStack() {
        return undoStack.printStack();
    }

    string getRedoStack() {
        return redoStack.printStack();
    }

    string getText() const {
        return text;
    }

private:
    Stack redoStack;
    Stack undoStack;
    string text;
};

#endif //L1V2CL_TEXTCONTROL_H
