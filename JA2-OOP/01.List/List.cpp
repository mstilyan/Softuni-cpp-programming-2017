//
// Created by stiliele on 23.4.2017 г..
//

#include <assert.h>
#include <string>
#include "List.h"

/*List::Node implementation */
List::Node::Node(T value, Node* prev, Node* next) :
    value(value),
    prev(prev),
    next(next){

}

T List::Node::getValue() const {
    return value;
}

void List::Node::setValue(T value) {
    this->value = value;
}

List::Node* List::Node::getNext() const {
    return next;
}

void List::Node::setNext(Node *next) {
    this->next = next;
}

List::Node* List::Node::getPrev() const {
    return prev;
}

void List::Node::setPrev(Node *prev) {
    this->prev = prev;
}
/*------------------------------------*/

/*List implementation*/
List::List() :
    head(nullptr),
    tail(nullptr),
    size(0){

}

List::List(const List& other) :
    head(nullptr),
    tail(nullptr),
    size(0){
    if(this != &other){
        Node* currNode = other.head;
        while(currNode != nullptr){
            add(currNode->getValue());
            currNode = currNode->getNext();
        }
    }
}

T List::first() const {
    assert(head != nullptr);
    return head->getValue();
}

void List::add(T value) {
    Node* newNode = new Node(value, nullptr, nullptr);
    if (isEmpty()){
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
    size++;
}

void List::addAll(const List& other){
    Node* currNode = other.head;
    while(currNode != nullptr){
        add(currNode->getValue());
        currNode = currNode->getNext();
    }
}

void List::removeFirst() {
    assert(head != nullptr);
    Node* second = head->getNext();
    delete head;

    if (second != nullptr){
        second->setPrev(nullptr);
        head = second;
    } else {
        head = nullptr;
        tail = nullptr;
    }

    size--;
}

void List::removeAll(){
    Node* temp = nullptr;
    while(head != nullptr){
        temp = head->getNext();
        delete head;
        head = temp;
    }

    tail = nullptr;
    size = 0;
}

size_t List::getSize() const {
    return this->size;
}

bool List::isEmpty() const {
    return this->size == 0;
}

List List::getReversed(List l) {
    assert(!l.isEmpty());
    List result;
    Node* currNode = l.tail;
    while(currNode != nullptr){
        result.add(currNode->getValue());
        currNode = currNode->getPrev();
    }

    return result;
}

std::string List::toString() const {
    std::string result;
    Node* currNode = head;
    while(currNode != nullptr){
        result += std::to_string(currNode->getValue());
        if(currNode != tail)
            result += " ";
        currNode = currNode->getNext();
    }

    return result;
}

List& List::operator=(const List &other) {
    if (this != &other){
        removeAll();
        Node* currNode = other.head;
        while(currNode != nullptr){
            add(currNode->getValue());
            currNode = currNode->getNext();
        }
    }

    return *this;
}

List& List::operator<<(const T& value){
    add(value);
}

List& List::operator<<(const List& other){
    Node* currNode = other.head;
    while(currNode != nullptr){
        add(currNode->getValue());
        currNode = currNode->getNext();
    }

    return *this;
}

List::~List() {
    removeAll();
}