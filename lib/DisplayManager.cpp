#include "DisplayManager.h"

void setEnableAnsi()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(console, &mode);
    SetConsoleMode(console, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
void setCharCode()
{
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, ".UTF8");
}

void preCursor()
{
    std::cout << "\033[s";
}
void postCursor()
{
    std::cout << "\033[u";
}

int readInt(const std::string &prompt)
{
    int tmp;
    std::cout << "\033[2C";
    while (1)
    {
        std::cout << prompt;
        std::cin >> tmp;
        if (!std::cin.fail())
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return tmp;
        }
        else
            std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[A";
        std::cout << "\033[2K";
        preCursor();
        midBox(1);
        postCursor();
        std::cout << "\033[D\033[8C";
    }
}
double readDouble(const std::string &prompt)
{
    double tmp;
    std::cout << "\033[2C";
    while (1)
    {
        std::cout << prompt;
        std::cin >> tmp;
        if (!std::cin.fail())
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return tmp;
        }
        else
            std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[A";
        std::cout << "\033[2K";
        preCursor();
        midBox(1);
        postCursor();
        std::cout << "\033[D\033[8C";
    }
}
std::string readStr(const std::string &prompt)
{
    std::string tmp;
    bool hasPunc = false;
    std::cout << "\033[2C";
    while (1)
    {
        hasPunc = false;
        std::cout << prompt;
        std::getline(std::cin, tmp);
        for (char c : tmp)
        {
            if (ispunct(c))
            {
                hasPunc = true;
                break;
            }
        }

        if (!hasPunc)
            return tmp;

        std::cout << "\033[A";
        std::cout << "\033[2K";
        preCursor();
        midBox(1);
        postCursor();
        std::cout << "\033[D\033[8C";
    }
}
void readChar(const std::string &prompt, std::string &input, bool &isEnter)
{
    char clck;
    inputBox(1);
    std::cout << "\033[2C";

    std::cout << prompt << input;
    clck = _getch();
    std::cout << '\n';
    if (clck == 13)
        isEnter = true;
    else if (clck == 8)
    {
        if (!input.empty())
            input.pop_back();
    }
    else if (isprint(clck))
        input += clck;
}
std::string readPasswd(const std::string &prompt)
{
    std::string passwd;
    inputBox(1);
    char ch;
    std::cout << "\033[6C" << prompt;
    while (true)
    {
        ch = _getch();
        if (ch == 13)
            break;
        else if (ch == 8)
        {
            if (!passwd.empty())
            {
                passwd.pop_back();
                std::cout << "\b \b";
            }
        }
        else
        {
            passwd.push_back(ch);
            std::cout << '*';
        }
    }
    std::cout << '\n';
    return passwd;
}

void setFRGB(int r, int g, int b)
{
    printf("\033[38;2;%d;%d;%dm", r, g, b);
}
void setBRGB(int r, int g, int b)
{
    printf("\033[48;2;%d;%d;%dm", r, g, b);
}
void resetTerm()
{
    std::cout << "\033[0m";
    // std::cout << "\033[39m";
    // std::cout << "\033[49m";
}

void topBox(int state)
{
    if (state == 1)
        std::cout << "  ╭----------------------------------------------------------------------------╮\n";
    else
        std::cout << "   ________________________________________________________\n";
}
void midBox(int state)
{
    if (state == 1)
        std::cout << "  |  →                                                                         |\n";
    else
        std::cout << "  | >                                                      |\n";
}
void botBox(int state)
{
    if (state == 1)
        std::cout << "  ╰----------------------------------------------------------------------------╯\n";
    else
        std::cout << "  |________________________________________________________|\n";
}

void inputBox(const int &state)
{
    if (state == 1)
    {
        std::cout << "  ╭----------------------------------------------------------------------------╮\n";
        std::cout << "  |  →                                                                         |\n";
        std::cout << "  ╰----------------------------------------------------------------------------╯\n";
    }
    else
    {
        std::cout << "   ________________________________________________________\n";
        std::cout << "  | >                                                      |\n";
        std::cout << "  |________________________________________________________|\n";
    }
    std::cout << "\033[2A\033[6C";
}

void max(int &a, int b)
{
    if (a < b)
        a = b;
}
void topCover(std::string sc, char mc, int count)
{
    std::cout << sc;
    for (int i = 0; i < count; i++)
        std::cout << mc;
}
void botCover(char c, int idL, int nameL, int catgL, int unitL, int priceL)
{
    topCover("| ", c, idL);
    topCover(" | ", c, nameL);
    topCover(" | ", c, catgL);
    topCover(" | ", c, unitL);
    topCover(" | ", c, priceL);
    std::cout << " |\n";
}

void tableList(List *ls)
{
    int idL = 3, nameL = 10, catgL = 8, unitL = 5, priceL = 8;
    Stock *s = ls->head;
    while (s != nullptr)
    {
        max(idL, static_cast<int>(std::to_string(s->item.id).length()));
        max(nameL, static_cast<int>(s->item.name.length()));
        max(catgL, static_cast<int>(s->item.category.length()));
        max(unitL, static_cast<int>(std::to_string(s->item.units).length()));
        max(priceL, static_cast<int>(std::to_string(s->item.unitPrice).length()));

        s = s->next;
    }
    s = ls->head;

    std::cout << std::endl;
    topCover(" ", '_', idL + nameL + catgL + unitL + priceL + 14);
    std::cout << std::endl;
    std::cout << "| " << std::setw(idL) << "ID"
              << " | " << std::setw(nameL) << "Name"
              << " | " << std::setw(catgL) << "Category"
              << " | " << std::setw(unitL) << "Units"
              << " | " << std::setw(priceL) << "Price" << " |\n";
    botCover('_', idL, nameL, catgL, unitL, priceL);

    while (s != nullptr)
    {
        std::cout << "| " << std::setw(idL) << s->item.id
                  << " | " << std::setw(nameL) << s->item.name
                  << " | " << std::setw(catgL) << s->item.category
                  << " | " << std::setw(unitL) << s->item.units
                  << " | $" << std::setw(priceL - 1) << s->item.unitPrice << " |\n";
        s = s->next;
    }
    botCover('_', idL, nameL, catgL, unitL, priceL);
    delete s;
}

int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csBuff;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csBuff))
        return csBuff.srWindow.Right - csBuff.srWindow.Left + 1;
    return -1;
}

void clearScreen()
{
    system("cls");
}

void showItem(Item item)
{
    std::cout << "   ID: " << item.id << " - " << item.name << '\n'
              << "Category: " << item.category << '\n'
              << "unit: " << item.units << '\n'
              << "Price/unit: " << item.unitPrice << '\n';
}

ColumnLength maxCoLen(List *ls)
{
    ColumnLength len;
    Stock *s = ls->head;
    while (s != nullptr)
    {
        max(len.idL, static_cast<int>(std::to_string(s->item.id).length()));
        max(len.nameL, s->item.name.length());
        max(len.catgL, s->item.category.length());
        max(len.unitL, static_cast<int>(std::to_string(s->item.units).length()));
        max(len.priceL, static_cast<int>(std::to_string(s->item.unitPrice).length()));
        s=s->next;
    }
    return len;
}