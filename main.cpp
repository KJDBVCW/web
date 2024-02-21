#include <iostream>
using namespace std;
#include <fcntl.h>


#include "mylib.h"
int main(){
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);

    /*
    wstring dstu[1000] = {L"hello", L"bye", L"one"};
    wstring dsnghia[1000] = {L"Xin chào", L"Tạm biệt", L"Một"};
    int N = 3;
    */

    wstring dstu[1000];
    wstring dsnghia[1000];
    int N;
    NapTuDien(dstu, dsnghia, N, "data.txt");
    int chon;
    do {
        chon = ThucDon();
        if (chon == 1){
            TraTu(dstu, dsnghia, N);
        }
        else if (chon == 0){
            wcout<<L"Cảm ơn bạn đã sử dụng chương trình\n";
        }
        wcout<<L"Nhấn phím bất kì và enter để trở về\n";
        wchar_t k;
        wcin>>k;
    } while (chon != 0);
    return 0;
}
