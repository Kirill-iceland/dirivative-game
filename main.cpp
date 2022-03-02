const int window_w = 150;
const int window_h = 40;
const int speed_mult =  2;
const int tps = 5;
int creation_speed = 7 * speed_mult;
// int arr_pointer = 0;
// const int arr_len = 30;

#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <time.h>
// const int _O_U16TEXT = 0x20000;

auto timestart = std::chrono::system_clock::now();
auto timenow = std::chrono::system_clock::now();

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

std::wstring wrepeat(std::wstring str, int n){
    std::wstring res = L"";
    for (int i = 0; i < n; i++)
    {
        res = res + str;
    }
    return res;
}

#include "math_function.hpp"
// f_of_x f_arr [arr_len] = {};





void print_grid(){
    std::wcout << L"┌";
    std::wcout << wrepeat(L"─", window_w);
    std::wcout << L"┐\n";


    std::wstring middle = L"│";
    middle = middle + wrepeat(L" ", window_w);
    middle = middle + L"│\n";
    for (int i = 0; i < window_h; i++)
    {
        std::wcout << middle;
    }

    
    std::wcout << L"└";
    std::wcout << wrepeat(L"─", window_w);
    std::wcout << L"┘\n";
    
}


start_f start = start_f();
einar EINAR = einar(int(window_w / 2) - 2, window_h - 1);

bool loop(int tick){
            // int ch = std::cin.get();
    // std::wcout << ch;
    if(GetKeyState(VK_RIGHT) & 0x8000){
        EINAR.move(1);
        // std::wcout << "test";
    }else if(GetKeyState(VK_LEFT) & 0x8000){
        EINAR.move(-1);
    }
    if(tick % creation_speed == 0){
        // if(arr_pointer == arr_len){
        //     arr_pointer = 0;
        // }
        // f_arr[arr_pointer] = f_of_x();
        // f_arr[arr_pointer].print();
        // arr_pointer++;
        // gotoxy(0,0);
        // std::wcout << arr_pointer << " " << tick;
        start.add_next(f_of_x());
        // gotoxy(0,0);
        // created++;
        // std::wcout << created << " " << tick;

    }

    if(!start.check(tick)){
        return 0;
    }
    return 1;
}

int main(){
    // Setup
	HWND consoleWindow = GetConsoleWindow();
	// SetWindowPos( consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = 0;
    cursor.dwSize = 1;
    SetConsoleCursorInfo(hStdout, &cursor);
    _setmode(_fileno(stdout), 0x20000);

    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);
    srand(time(0));
    
    // SetConsoleTextAttribute(hStdout, 0x02);
    SetConsoleTitle(TEXT("Dirivative Game"));
    // system("mode 650");
    system("cls");
    
    // f_of_x f = f_of_x();

    print_grid();
    // f.print();
    
    // std::wcout << f.size << std::endl;
    // for (int i = 0; i < f.size; i++)
    // {
    //     std::wcout << f.structure[i].pow;
    //     std::wcout << " " << f.structure[i].mult << " " << std::endl;
    // }
    //     std::wcout << f.to_String() << std::endl;

    //     while(f.size > 0){
    //         f.dirivative();
    //         std::wcout << f.to_String() << std::endl;
    //     }

    EINAR.print();

    int tick = 0;
    int created = 0;
    while(1){

        timenow = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = timenow - timestart;
        if(elapsed_seconds.count() >= 1 / tps){
            timestart = timenow;
            if(!loop(tick)){
                SetConsoleMode(hStdin, mode);
                return 0;
            }
            tick++;
        }
    }
    SetConsoleMode(hStdin, mode);

    
    return 0;
}