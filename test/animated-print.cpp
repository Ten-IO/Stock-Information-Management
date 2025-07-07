#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

// 137 = 2.51s -> 2.53s - no flush - no cleared buffer
// no delay : 7262ms -> 7874ms
// 137 = 2.4s -> 2.74s - flush - cleared buffer
// no delay : 7509ms -> 8747ms
int main()
{
    // string = 137
    string toPrint = "Hello, Mr Potato. I was once a sad fruit, but now I'm classified as a vegetable. It reminded me of how we now starting to divide genders.";

    int i, sz = static_cast<int>(toPrint.size());
    cout << "== Compare ==\n";
    chrono::time_point<chrono::high_resolution_clock> init = chrono::high_resolution_clock::now();

    for (i = 0; i < sz; i++)
    {

        cout << toPrint[i];
        // 1 bottom
        // cout << "\033[B\033[D";

        // cout << toPrint[i] << flush;
        // // 1 up, 1 back
        // cout << "\033[A";

        // this_thread::sleep_for(chrono::milliseconds(10));
        // cout << "\033[u";
    }
    chrono::time_point<chrono::high_resolution_clock> stop = chrono::high_resolution_clock::now();
    auto timeMS = chrono::duration_cast<chrono::microseconds>(stop - init);
    auto timeNS = chrono::duration_cast<chrono::nanoseconds>(stop - init);

    cout << endl << endl;
    cout << timeNS.count() << " ns" << endl;
    cout << timeMS.count() << " ms" << endl;
    cout << fixed << setprecision(2) << timeMS.count() / 1e6 << " s" << endl;

    system("pause");
}