#include "MyOwnPQ.h"
#include <iostream>

int main() {
    MyOwnPriorityQueue<int> q;
    int num;
    int num2;
    char abc[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

    cout << "PRIMERA PRUEBA: " << endl;
    for (int x = 0; x < 15; x++)
    {
        num = rand() % 51;
        num2 = rand() % 51;
        q.insert(num, num2);
        q.Print();
    }
    cout << "VALOR MINIMO: " << q.front() << endl;
    q.pop();
    q.Print();
    cout << "VALOR MINIMO: " << q.front() << endl;
    q.pop();
    q.Print();
    cout << "VALOR MINIMO: " << q.front() << endl;
    q.pop();
    q.Print();
    cout << "VALOR MINIMO: " << q.front() << endl;
    cout << "SEGUNDA PRUEBA " << endl;

    MyOwnPriorityQueue<int> q1;
    for (int x = 0; x < 1000; x++)
    {
        num = rand() % 1001;
        num2 = rand() % 1001;
        q1.insert(num, num2);
    }
    cout << "VALOR MINIMO: " << q1.front() << endl;
    q1.pop();
    q1.Print();
    cout << "VALOR MINIMO: " << q1.front() << endl;
    q1.pop();
    q1.Print();
    cout << "VALOR MINIMO: " << q1.front() << endl;
    q1.pop();
    q1.Print();
    cout << "VALOR MINIMO: " << q1.front() << endl;

    cout << "TERCERA PRUEBA " << endl;
    MyOwnPriorityQueue<char> q2;
    for (int x = 0; x < 15; x++)
    {
        num = rand() % 51;
        num2 = rand() % 27;
        q2.insert(num, abc[num2]);
        q2.Print();
    }
    cout << "VALOR MINIMO: " << q2.front() << endl;
    q2.pop();
    q2.Print();
    cout << "VALOR MINIMO: " << q2.front() << endl;
    q2.pop();
    q2.Print();
    cout << "VALOR MINIMO: " << q2.front() << endl;
    q2.pop();
    q2.Print();
    cout << "VALOR MINIMO: " << q2.front() << endl;
}