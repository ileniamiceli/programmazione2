#include <iostream>
#include "nodo.hpp"
#include "lista.hpp"
#include "studente.hpp"

int main(){
    Nodo<int> n0(10);
    Nodo<int> n1(11); //, &n0);
    Nodo<int> n2;

    cout << &n0 << endl;
    cout << &n1 << endl;
    cout << &n2 << endl;

    cout << n0.getValue() << endl;
    cout << n0.getNext() << endl;


    Studente s1("a", "a", "a", 20);
    Studente s2("b", "a", "a", 20);
    Studente s3("a", "b", "a", 20);
    Studente s4("a", "a", "a", 21);
    
    cout << "Confronti:" <<endl;

    cout << (s1 < s2) << endl; //true
    cout << (s1 > s2) << endl; //false
    cout << (s1 > s3) << endl; //false
    cout << (s3 > s2) << endl; //false?
    cout << (s1 > s4) << endl; //false
    cout << (s1 == s1) << endl; //true

    //n1.setValue(100);
    //n1.setNext(&n0);

    cout << n1.toString() << endl;

    cout << "Nodi:" << endl;

    Lista<int> list;
    //list.insert(&n0);
    //list.insert(&n1);
    //list.insert(&n2);
    //list.insert(14);
    list.insertInOrder(9);
    cout << list << endl;
    list.insertInOrder(3);
    cout << list << endl;
    list.insertInOrder(5);
    cout << list << endl;
    list.insertInOrder(19);
    cout << list << endl;
    list.insertInOrder(7);
    cout << list << endl;
    list.insertInOrder(42);
    cout << list << endl;

    Nodo<int> * d1 = list.deleteNode(5);
    cout << list << endl;
    Nodo<int> * d2 = list.deleteNode(3);
    cout << list << endl;
    Nodo<int> * d3 = list.deleteNode(42);
    cout << list << endl;

    cout << "Studenti:" << endl;
    
    Lista<Studente> lista2;
    lista2.insertInOrder(s1);
    cout << lista2 << endl;
    lista2.insertInOrder(s2);
    cout << lista2 << endl;
    lista2.insertInOrder(s3);
    cout << lista2 << endl;
    lista2.insertInOrder(s4);
    cout << lista2 << endl;
}