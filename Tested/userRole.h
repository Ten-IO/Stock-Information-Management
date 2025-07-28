#ifndef USERROLE_H
#define USERROLE_H

#include <iostream>

enum Role {USER, ADMIN};

struct User {
    Role role;
    std::string username;
    int item_id;
    std::string action_type; 
    std::string date;
};
struct Log{
    User user;
    Log *next;
};
struct Loglist{
    int n;
    Log *head;
    Log *tail;
};
Loglist *initLogList() {
    Loglist *log = new Loglist;
    log->head=nullptr;
    log->tail=nullptr;
    log->n=0;
    return log;
};

#endif