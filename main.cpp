const int window_w = 150;                   // in chars
const int window_h = 40;                    // in chars
const int speed_mult =  3;                  // more -> slower 
const int bullet_speed = 1;                 // more -> slower (bullets per tick)
const double tps = 10;                      // ticks per second 
const double einar_speed = 50;              // ticks per second (of click input)
int creation_speed = 7 * speed_mult;        // more -> slower (cretions per tick)
int score = 0;                              // -
int single_click_delay = einar_speed / 10;   // more -> longer
int click_delay = 0;                        // -
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

const std::wstring einar_string = L"EINAR";
const int einar_width = einar_string.length();

auto timestart = std::chrono::system_clock::now();
auto einarstart = std::chrono::system_clock::now();
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

    gotoxy(0,0);
    std::wcout << L"score: ";
    
}


start_f start = start_f();
einar EINAR = einar(int(window_w / 2) - 2, window_h - 1);

bool loop(int tick){
            // int ch = std::cin.get();
    // std::wcout << ch;
    if(tick % creation_speed == 0){
        // if(arr_pointer == arr_len){
        //     arr_pointer = 0;
        // }
        // f_arr[arr_pointer] = f_of_x();
        // f_arr[arr_pointer].print();
        // arr_pointer++;
        // gotoxy(0,0);
        // std::wcout << arr_pointer << " " << tick;
        f_of_x * new_ = new f_of_x();
        start.add_next(new_);

    }
    if(tick % bullet_speed == 0){
        bullet_move_(start);
        if(GetKeyState(VK_SPACE) & 0x8000){
            bullet * new__ = new bullet(EINAR.x + int(einar_width / 2) - 1);
            start.add_bullet(new__);
        }
    }

    if(!start.check(tick)){
        return 0;
    }
    // gotoxy(30,0);
    // std::wcout << tick;
    return 1;
}

int main(){
    // Setup
	HWND consoleWindow = GetConsoleWindow();  
    RECT r;
    GetWindowRect(consoleWindow, &r);
    MoveWindow(consoleWindow, r.left, r.top, 1150, 720, TRUE);
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
        std::chrono::duration<double> e_elapsed_seconds = timenow - einarstart;
        if(elapsed_seconds.count() >= double(1 / tps)){
            timestart = timenow;
            if(!loop(tick)){
                SetConsoleMode(hStdin, mode);
                start._remove();
                int a;
                std::wcin >> a;
                return 0;
            }
            tick++;
        }
        if(e_elapsed_seconds.count() >= double(1 / einar_speed)){
            einarstart = timenow;
            if((EINAR.x < window_w - 5) && GetKeyState(VK_RIGHT) & 0x8000){
                if(click_delay == 0 || click_delay >= single_click_delay){
                    EINAR.move(1);
                }
                click_delay++;
            }else if((EINAR.x > 0) && GetKeyState(VK_LEFT) & 0x8000){
                if(click_delay == 0 || click_delay >= single_click_delay){
                    EINAR.move(-1);
                }
                click_delay++;
            }else if(click_delay != 0){
                click_delay = 0;
            }
        }

        gotoxy(7,0);
        SetConsoleTextAttribute(hStdout, 0x0e);
        std::wcout << score;
        SetConsoleTextAttribute(hStdout, 0x07);
        // created++;
        // std::wcout << created << " " << tick << " " << elapsed_seconds.count();
    }
    SetConsoleMode(hStdin, mode);
    start._remove();
    
    return 0;
}