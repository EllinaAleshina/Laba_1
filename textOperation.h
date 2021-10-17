#ifndef TEXTOPERATION_H
#define TEXTOPERATION_H

#include <iostream>
#include <utility>
#include <memory>
#include <ostream>
#include "stackElementParent.h"

using namespace std;

enum Operations{
    DELETE = 0,
    EDIT
};

class TextOperation : StackElementParent {
public:
    TextOperation() {
        operation = Operations::DELETE;
        data = "";
        newData = "";
        pos = 0;
    }

    TextOperation(Operations operation, string data, unsigned int pos) {
        className = "TextOperation";
        this->operation = operation;
        this->data = std::move(data);
        newData = "";
        this->pos = pos;
    }

    explicit TextOperation(string data, string newData, unsigned int pos) {
        className = "TextOperation";
        this->operation = Operations::EDIT;
        this->data = std::move(data);
        this->newData = std::move(newData);
        this->pos = pos;
    }

    explicit TextOperation(Operations operation, string data, string newData, unsigned int pos) {
        className = "TextOperation";
        this->operation = operation;
        this->data = std::move(data);
        this->newData = std::move(newData);
        this->pos = pos;
    }

    TextOperation(const TextOperation &src) = default;

    ~TextOperation() = default;

    Operations getOperation() const {
        return operation;
    }
    void setOperation(const Operations &value){
        operation = value;
    }

    bool operator==(TextOperation &other) {
        return other.getPos()==pos && other.getOperation()==operation && other.getData()==data;
    }

    string getData() const {
        return data;
    }

    string getNewData() const {
        return newData;
    }

    void setData(const string &value) {
        data = value;
    }

    unsigned int getPos() const {
        return pos;
    }
    void setPos(unsigned int value){
        pos = value;
    }

    string save () override {
        return whoami() + "\n" + (data.empty() ? "<none>" : data) + "\n" +
        (newData.empty() ? "<none>" : newData) + "\n" +
        (operation == Operations::DELETE ? "0" : "1") + "\n" + to_string(pos) + "\n";
    }

    void load (std::istream &s) override {
        s >> data;
        s >> newData;
        s >> pos;
        operation = pos ? Operations::EDIT : Operations::DELETE;
        s >> pos;
        data = data == "<none>" ? "" : data;
        newData = newData == "<none>" ? "" : newData;
    }

    string print () override {
        return "StackElement:\n" + to_string(pos) + "\n" + data + "\n" + newData + "\n" +
        (operation == Operations::DELETE ? "DELETE" : "EDIT") + "\n";
    }

private:
    Operations operation;
    string data;
    string newData;
    unsigned int pos{};
};

#endif // TEXTOPERATION_H
