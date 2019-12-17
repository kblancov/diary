#include <iostream>
#include <fstream>
using namespace std;

void read(ifstream &myfile){
    int id;
    string myStr;
    myfile >> myStr;
    cout << myStr<< endl;
    myfile >> myStr;
    cout << myStr<< endl;
    myfile >> id;
    cout << id << endl;;
}

int main()
{

    ifstream myfile;
    myfile.open("diary.txt");
    read(myfile);
    myfile.close();
    return 0;
}