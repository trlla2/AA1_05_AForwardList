#include "ForwardList.h"

int main() {
    // Test constructor and IsEmpty
    ForwardList list1;

    // Test PushBack
    list1.PushBack(10);
    list1.PushBack(20);
    list1.PushBack(30);
    std::cout << std::endl << "Pushed 10,20,30 to back of list1: " << list1 << " Size: " << list1.Size() << std::endl;

    // Test Front/Back
    std::cout << "Front: " << list1.Front() << ", Back: " << list1.Back() << std::endl;

    // Test PushFront
    list1.PushFront(5);
    list1.PushFront(2);
    list1.PushFront(25);
    std::cout << std::endl << "Push front: " << list1 << " Size: " << list1.Size() << std::endl;

    // Test PopFront
    list1.PopFront();
    std::cout << std::endl << "After PopFront: " << list1 << std::endl;

    // Test PopBack
    list1.PopBack();
    std::cout << std::endl << "After PopBack: " << list1 << std::endl;

    // Test Insert
    list1.Insert(15, 1);
    std::cout << std::endl << "Inserted 15 at position 1: " << list1 << std::endl;

    // Test Erase
    list1.PushBack(10);
    list1.PushBack(10);
    std::cout << std::endl << "List: " << list1 << std::endl;
    list1.Erase(10);
    std::cout << "After erase(10): " << list1 << std::endl;

    // Test PushBackAverageNode
    list1.PushBackAverageNode();
    std::cout << "New average: " << list1.Back() << std::endl;

    // Test operator
    ForwardList list2;
    list2.PushBack(25);
    list2.PushBack(15);
    list2.PushBack(5);

    std::cout << std::endl << "list1: " << list1 << std::endl << "list2: " << list2 << std::endl;
    std::cout << "list1 == list2? " << (list1 == list2) << std::endl;

    // Test concatenation operator
    ForwardList list3 = list1 + list2;
    std::cout << std::endl << "Concatenated list (list1 + list2): " << list3 << std::endl;

}