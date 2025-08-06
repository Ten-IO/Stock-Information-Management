#pragma once
#include <string>
#include "DisplayManager.h"

// system emblem for utf-8 v1
std::string start();

// system emblem for utf-8 mini
std::string smallStart();

// system emblem for ascii
std::string simpleStart();

// future implementation - for long/big data progress wait
void loadScreen();