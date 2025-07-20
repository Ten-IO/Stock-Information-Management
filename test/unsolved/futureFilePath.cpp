#include <iostream>
#include <filesystem>
std::string Check(const std::string &fileName)
{
    std::string tmp;
    std::filesystem::path path(fileName);
    std::string base = path.stem().string();
    for (char c : base)
    {
        if (c == '.' || c == '/')
        break;
        else if (!((c > 47 && c < 58) || (tolower(c) > 96 && tolower(c) < 123)) && c != '_' && c != '-')
            throw std::runtime_error("\nUnidentified sign located in file name. Please remove!\n");
            tmp += c;
    }
    return (path.empty()?"":path.string()+"/"+tmp+".csv");
    // return (base.empty()?base:base) + base + ".csv";
}
int main(){
        std::cout <<"1- " <<Check(".ds/NA.ptk")<<'\n';
        std::cout << "2- "<<Check("/ds/NA.ptk")<<'\n';
        std::cout << "3- "<<Check("NA.ptk")<<'\n';

}