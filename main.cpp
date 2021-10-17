#include <iostream>
#include <cassert>
#include <QApplication>
#include "textOperation.h"
#include "textControl.h"
#include "MainWindow.h"

void printStack(Stack s){
    while (!s.empty()){
        cout << ">>entry<<" << endl;
        cout << s.top().getPos() << endl;
        cout << s.top().getData() << endl;
        cout << s.top().getOperation() << endl;
        s.pop();
    }
}

int main(int argc, char **argv) {
    //part 1
    TextOperation textOperation = TextOperation(Operations::DELETE, "text1", 5);
    TextOperation textOperation1 = TextOperation(textOperation);
    assert(textOperation1.getOperation() == Operations::DELETE);
    textOperation.setOperation(Operations::EDIT);
    textOperation.setData("text2");
    assert(textOperation.getData() == "text2");
    assert(textOperation.getOperation() == Operations::EDIT);
    textOperation.setPos(5);
    assert(textOperation.getPos()==5);

    //part 2

    Stack stack;
    TextOperation to = TextOperation(Operations::EDIT, "data", 3);
    stack.push(to);
    stack.saveData("tmpfile");
    Stack stack1 = Stack(stack);
    assert(stack == stack1);
    stack1.loadData("tmpfile");
    assert(stack == stack1);
    assert(!stack.empty());
    assert(stack.size()==1);
    assert(stack.top() == to);
    stack.pop();
    assert(stack.empty());
    stack1.clear();
    assert(stack1.empty());

    std::cout << "Tests completed successfully" << std::endl;
    //return 0;


    QApplication app(argc, argv);
    MainWindow win;
    win.show();
    return app.exec();
}
