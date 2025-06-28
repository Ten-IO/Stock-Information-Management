#include <iostream>
#include <stock.h>
#include <creator.h>
#include <displayManager.h>
using namespace std;
int main() {
    List *ls = initList();
    addEnd(ls, Item{101, 20, "GoPro", "Camera", 400});
    addEnd(ls,  Item{10213, 10, "VXE R1", "Mouse", 18});
    addEnd(ls,  Item{102, 110, "Window AK", "License Box", 5});
    addEnd(ls,  Item{104, 50, "", "Keyboard", 400});
    addEnd(ls,  Item{105, 220, "ESP32", "Micro-Controller", 400});

    tableList(ls);


}