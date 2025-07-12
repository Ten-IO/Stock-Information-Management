#include <iostream>
#include <ctime>
std::string TimeCall(){
    time_t now = time(nullptr);
    struct tm rec = *localtime(&now);
    char buff[80]={};
    strftime(buff, 80, "%a %b %Y-%T %Z:", &rec);
    return std::string(buff);

}

int main() {
    // char *ctime(const time_t *timer);
    time_t now=time(nullptr);
    char *record= ctime(&now);

    // struct tm info = *localtime(&now);
    // char buff[70]; // current 52
    // strftime(buff, 70, "Now: %a %e %b %Y-%T %Z", &info);

    std::string buff= TimeCall();
    std::cout<<"Time: " << record<<"\n"<<buff<<'\n';

}