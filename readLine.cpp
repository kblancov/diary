#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    string description;
    cout<<"Enter a text: "<<endl<<flush;
    getline(cin,description);
    cout<<"You entered: "<<description<<endl;
    return 0;
}
