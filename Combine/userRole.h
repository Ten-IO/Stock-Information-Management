#ifndef USERROLE_H
#define USERROLE_H
#include <string>
using namespace std;

enum Role { USER, ADMIN };

struct User {
    Role role;
    string username;
    int item_id;
    string action_type;
    string date;
};

struct Log {
    User user;
    Log* next;
};

struct Loglist {
    int n;
    Log* head;
    Log* tail;
};

inline Loglist* initLogList() {
    Loglist* log = new Loglist;
    log->head = nullptr;
    log->tail = nullptr;
    log->n = 0;
    return log;
}

#endif

