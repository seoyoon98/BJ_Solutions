#include <iostream>

using namespace std;

int dstChan; // destination channel
int brokBtnN; // number of broken button
int* xBtn; // broken button

int main(int argc, const char * argv[]) {
    // insert code here...
    
    do {
        cin >> dstChan;
    } while (dstChan < 0 || dstChan > 500000);
    cout << "destination Channel: " << dstChan << "\n";
    
    do {
        cin >> brokBtnN;
    } while (brokBtnN < 0 || brokBtnN > 10);
    cout << "number of broken button: " << brokBtnN << "\n";
    
    if (dstChan == 100)
        cout << 0;
    
    return 0;
}
