#ifndef L1V2CL_STACK_H
#define L1V2CL_STACK_H

#include <memory>
#include <istream>
#include <ostream>
#include "textOperation.h"

class Stack {
public:
    Stack() {
        m_top = nullptr;
        m_bottom = nullptr;
        m_size = 0;
    };

    Stack(const Stack& other) {
        m_top = nullptr;
        m_bottom = nullptr;
        m_size = 0;
        copy(other);
    };

    ~Stack() = default;

    void pop() {
        if (m_top != nullptr) {
            StackElement* tmpTop = m_top;
            m_top = m_top->prev;
            m_size--;
            delete tmpTop;
        }
        if (m_top == nullptr)
            m_bottom = nullptr;
    }

    void push(const TextOperation &value) {
        m_top = new StackElement(value, m_top);
        m_size++;
        if (m_size == 1)
            m_bottom = m_top;
    }

    void clear() {
        while (!empty())
            pop();
    }

    TextOperation& top() {
        if (m_top == nullptr)
            throw std::out_of_range("top() of empty stack");
        return m_top->obj;
    }

    TextOperation& bottom() {
        if (m_top == nullptr)
            throw std::out_of_range("top() of empty stack");
        return m_bottom->obj;
    }

    size_t size() const {
        return m_size;
    }

    bool empty() const {
        return m_top == nullptr;
    }

    string printStack(){
        Stack s = Stack(*this);
        string str;
        while (!s.empty()){
            str += s.top().print();
            s.pop();
        }
        return str;
    }

    bool operator==(Stack& stack) {
        if (stack.size() != size())
            return false;
        auto t = stack.m_top;
        auto t1 = m_top;
        while (t != nullptr) {
            if (!(t->obj == t1->obj))
                return false;
            t = t->prev;
            t1 = t1->prev;
        }
        return true;
    }

    bool saveData(const string &filename) const {
        std::fstream s(filename, std::fstream::binary | std::fstream::trunc | std::fstream::out);
        if (!s.is_open())
            return true;
        Stack tmp = Stack(*this);
        s << tmp.size() << "\n";
        while (!tmp.empty()) {
            s << tmp.top().save();
            tmp.pop();
        }
        s.close();
        return false;
    }

    bool loadData(const string &filename) {
        clear();
        std::fstream s(filename, std::fstream::binary | std::fstream::in);
        if (!s.is_open())
            return true;
        Stack stack = Stack();
        unsigned int size;
        s >> size;
        for (int i = 0; i < size; i++) {
            string className;
            s >> className;
            if (className == "TextOperation") {
                stack.push(TextOperation());
                stack.top().load(s);
            }
        }
        while (!stack.empty()) {
            push(stack.top());
            stack.pop();
        }
        s.close();
        return false;
    }

private:
    void copy(const Stack& other) {
        if (other.m_top == nullptr) {
            return;
        }
        Stack temp;
        auto t = other.m_top;
        do {
            temp.push(t->obj);
            t = t->prev;
        } while (t != nullptr);
        t = temp.m_top;
        do {
            push(t->obj);
            t = t->prev;
        } while (t != nullptr);
    }

    struct StackElement {
        TextOperation obj;
        StackElement *prev;
        StackElement() = default;
        StackElement(const TextOperation &operation, StackElement *prev) : obj(operation), prev(prev) {};
    };

    class Iterator {
    public:
        Iterator() = default;

        explicit Iterator(StackElement *element) : element(element) {};

        Iterator &operator++() {
            if (atEmpty()){
                throw std::out_of_range("++ on iterator pointing at empty element");
            }
            element = element->prev;
            return *this;
        }

        bool operator==(const Iterator &other) const {
            return this->element == other.element;
        }

        bool operator!=(const Iterator &other) const {
            return !(*this==other);
        }

        bool atEmpty() const {
            return (element == nullptr);
        }
    private:
        StackElement *element;
    };

    StackElement* m_top;
    StackElement* m_bottom;
    size_t m_size;
};

#endif //L1V2CL_STACK_H
