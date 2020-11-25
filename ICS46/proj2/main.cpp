#include <iostream>
#include <string>
#include "LLQueue.hpp"
#include"proj2.hpp"

using namespace std;

int main()
{
 



    LLQueue<int> a;
   
    try{
              a.front();
    }
    catch (QueueEmptyException& e)
    {
        std::cerr << "Queue isEmpty, nothing to dequeue" << std::endl;
    }

     try{
              a.dequeue();
    }
    catch (QueueEmptyException& e)
    {
        std::cerr << "Queue isEmpty" << std::endl;
    }



   
  
    /*
    a.enqueue(5);
    a.enqueue(6);
    a.enqueue(7);
    a.enqueue(8);

    std::cout << "Elemenets Enqueued Sucessfully.\n";
    a.~LLQueue();
    std::cout << "Elemenets Dequeued Sucessfully.\n";


    LLQueue<int> c;
    c.enqueue(5);
    c.enqueue(6);
    c.enqueue(7);
    c.enqueue(8);
    std::cout << "Elemenets Enqueued Sucessfully.\n";
    std::cout << "\n";
    LLQueue<int> b(c);
    std::cout << "Elemenets Copied Sucessfully.\n";
    std::cout << "\n";
    c.~LLQueue();
    std::cout << "Elemenets Dequeued Sucessfully.\n";
    std::cout << "\n";
    b.~LLQueue();
    std::cout << "Elemenets Dequeued Sucessfully.\n";
    std::cout << "\n";

    LLQueue<std::string> d;
    d.enqueue("this");
    d.enqueue("is a");
    d.enqueue("string");

    LLQueue<std::string> e;
    e.enqueue("check");
    e.enqueue("me");


    d = e;

    std::cout << "Elemenets Assigned Sucessfully.\n";

    d.~LLQueue();
    std::cout << "Elemenets Dequeued Sucessfully.\n";
    e.~LLQueue();
    std::cout << "Elemenets Dequeued Sucessfully.\n";

*/
    return 0;
}