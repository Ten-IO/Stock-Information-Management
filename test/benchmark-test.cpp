#include <benchmark.h>
#include <iostream>
#include <vector>
#include "Search.h"

int main()
{
    Timer time;
    std::string pattern;
    std::vector<std::string> data
    {R"(
The chart illustrates the amount of money spent on five consumer goods (cars, computers, books, perfume and cameras) in France and the UK in 2010. Units are measured in pounds sterling.
Overall, the UK spent more money on consumer goods than France in the period given. Both the British and the French spent most of their money on cars whereas the least amount of money was spent on perfume in the UK compared to cameras in France. Furthermore, the most significant difference in expenditure between the two countries was on cameras.
In terms of cars, people in the UK spent about £450,000 on this as opposed to the French at £400,000. Similarly, the British expenditure was higher on books than the French (around £400,000 and £300,000 respectively). In the UK, expenditure on cameras (just over £350,000) was over double that of France, which was only £150,000.
On the other hand, the amount of money paid out on the remaining goods was higher in France. Above £350,000 was spent by the French on computers which was slightly more than the British who spent exactly £350,000. Neither of the countries spent much on perfume which accounted for £200,000 of expenditure in France but under £150,000 in the
UK.
EXAMINER COMMENTS: The report has been organised into logical paragraphs with flexible use of linking. The overview is very clear with key features well highlighted. Accurate data is used to support sentences in the body paragraphs. There is a range of complex structures and vocabulary which are all flexibly used. This is an estimated band score 9 writing task 1 report for the academic paper. As you can see, the structure and information are presented in a way that is easy to understand, while the language offers complexity.)"};    

    std::cout<< "Search: "<< pattern;
        std::cin >> pattern;
        NativeStringMatch(data.at(0), pattern);
        
    }