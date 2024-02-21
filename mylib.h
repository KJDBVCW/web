#include <iostream>
#include <sstream>
#include <fstream>
#include <codecvt>
using namespace std;

int ThucDon(){
    wcout<<L"TỪ ĐIỂN ANH VIỆT\n";
    wcout<<L"\t1. Tra từ\n";
    wcout<<L"\t0. Thoát\n";
    wcout<<L"Chọn chức năng: ";
    int c;
    //cin.ignore();
    wcin>>c;
    return c;
}

void TraTu(wstring dstu[], wstring dsnghia[], int N){
    wstring tu;
    wcout<<L"Nhập từ cần tra: ";
    wcin>>tu;
    bool tim = false;
    for(int i = 0; i < N; i++){
        if (dstu[i] == tu){
            wcout<<L"Nghĩa là: ";
            wcout<<dsnghia[i]<<endl;
            tim = true;
            break;
        }
    }
    if (tim == false){
        wcout<<L"Không thấy từ cần tra\n";
    }
}

void NapTuDien(wstring dstu[], wstring dsnghia[], int &N, const char * fileName){
    
    wifstream fin(fileName);
    locale loc(locale(), new codecvt_utf8<wchar_t>);
    fin.imbue(loc);
    N = 0;
    while (!fin.eof()){
        getline(fin, dstu[N]);
        getline(fin, dsnghia[N]);
        N++;
    }
    fin.close();
}