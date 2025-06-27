#include <iostream>
#include <stock.h>
#include <creator.h>
#include <sorter.h>
#include <displayManager.h>
#include <reader.h>

using namespace std;

int main()
{
    List *s = initList();
    Item i1 = Item{101, 20, "GoPro", "Camera", 400};
    Item i2 = Item{103, 10, "VXE R1", "Mouse", 18};
    Item i3 = Item{102, 110, "Window AK", "License Box", 5};
    Item i4 = Item{104, 50, "", "Keyboard", 400};
    Item i5 = Item{105, 220, "ESP32", "Micro-Controller", 400};

    addEnd(s, i1);
    addEnd(s, i2);
    addEnd(s, i3);
    addEnd(s, i4);
    addEnd(s, i5);
    addEnd(s, i3);
    addEnd(s, i2);
    addEnd(s, i4);
    addEnd(s, i1);
    addEnd(s, i3);
    addEnd(s, i2);
    addEnd(s, i3);
    addEnd(s, i5);
    addEnd(s, i2);
    addEnd(s, i1);
    addEnd(s, i3);
    addEnd(s, i4);
    addEnd(s, i1);
    addEnd(s, i5);
    addEnd(s, i4);
    addEnd(s, i2);
    addEnd(s, i1);
    addEnd(s, i3);
    addEnd(s, i4);
    addEnd(s, i2);
    addEnd(s, i3);
    addEnd(s, i2);
    addEnd(s, i2);

    std::cout << "+ Initial State:\n";
    display(s);
    std::cout << "\n%list: " << s->n << std::endl;

    mergeSortList(&s, 8, s->n - 1); // Check not to be outbound - If we put "n" but in sort put [size+1] work, but arr[0] empty
    std::cout << "+ Sort State:\n";

    display(s);
}