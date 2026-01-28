#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {
    
std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    Element* element = new Element(entry);
    element->next = head;
    head = element;
    ++current_size;
}

int List::pop() {
    if (head == nullptr) {
        throw std::runtime_error("List is empty");
    }

    Element* to_delete = head;
    int data = head->data;
    head = head->next;

    delete to_delete;
    --current_size;

    return data;
}

void List::reverse() {
    Element* prev = nullptr;
    Element* current = head;

    while (current != nullptr) {
        Element* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

List::~List() {
    while (head != nullptr) {
        Element* tmp = head;
        head = head->next;
        delete tmp;
    }
}

}  // namespace simple_linked_list
