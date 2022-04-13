const int window_w = 150;                           // in chars
const int window_h = 40;                            // in chars
int speed_mult =  3;                                // more -> slower 
const double tps = 10;                              // ticks per second
const int bullet_speed = 1;                         // more -> slower (bullets per tick)
const int bullet_creation_delay = tps / 2;          // more -> slower (bullets per tick) 
int bullet_creation_delay_count = 0;                // more -> slower (bullets per tick) 
const double einar_speed = 50;                      // ticks per second (of click input)
int difficulty = 3;                                 // more -> esear
int creation_speed = difficulty * 7 * speed_mult;   // more -> slower (cretions per tick)
int score = 0;                                      // -
int single_click_delay = einar_speed / 10;          // more -> longer
int click_delay = 0;                                // -
// int arr_pointer = 0;
// const int arr_len = 30;

#include <iostream>
#include <fstream>
#include <cstdio>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include "sha1.h"
// const int _O_U16TEXT = 0x20000;

const std::wstring end_string = L"YOU LOST";
const std::wstring einar_string = L"EINAR";
const std::string secret_hash = "the best text.#$%^@#$";
std::string errrrrrrrrr = "main";
const int einar_width = einar_string.length();

auto timestart = std::chrono::system_clock::now();
auto einarstart = std::chrono::system_clock::now();
auto timenow = std::chrono::system_clock::now();

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

DWORD mode;

std::ifstream highscore_file("dirivative-game.txt");
int highscore;
std::string highscore_hash;

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


const int MR_legth  = 59;
const int MR_height = 13;
const std::wstring MR [MR_height] = {
    L"                             |                             ",
    L"                             |                             ",
    L"                             |                             ",
    L"  _____________________------|------_____________________  ",
    L" /###################/ _     _     _ \\###################\\ ",
    L"/###################| |_|   |_|   |_| |###################\\",
    L".----_-----_-----_--+  _     _     _  +--_-----_-----_----.",
    L"|   | |   | |   | |   | |   | |   | |   | |   | |   | |   |",
    L"|   |_|   |_|   |_|   |_|   |_|   |_|   |_|   |_|   |_|   |",
    L"|    _     _     _     _    ___    _     _     _     _    |",
    L"|   | |   | |   | |   | |  |   |  | |   | |   | |   | |   |",
    L"|   |_|   |_|   |_|   |_|  |   |  |_|   |_|   |_|   |_|   |",
    L"+--------------------------|___|--------------------------+"
};



void print_grid(){
    std::wcout << L"┌";
    std::wcout << wrepeat(L"─", window_w);
    std::wcout << L"┐\n";


    std::wstring middle = L"│";
    middle = middle + wrepeat(L" ", window_w);
    middle = middle + L"│\n";
    std::wstring middle_l = L"│" + wrepeat(L" ", (window_w - MR_legth) / 2);
    std::wstring middle_r = wrepeat(L" ", window_w - MR_legth - (window_w - MR_legth) / 2) + L"│\n";
    const int padding_top = (window_h - MR_height) / 2;
    const int padding_botttum = window_h - MR_height - (window_h - MR_height) / 2;

    for (int i = 0; i < padding_top; i++){
        std::wcout << middle;
    }
    for (int i = 0; i < MR_height; i++){
        std::wcout <<  middle_l + MR[i] + middle_r;
    }
    for (int i = 0; i < padding_botttum; i++){
        std::wcout << middle;
    }
    
    std::wcout << L"└";
    std::wcout << wrepeat(L"─", window_w);
    std::wcout << L"┘\n";

    gotoxy(1,0);
    std::wcout << L"score: ";    
    if(highscore == 0){
        gotoxy(window_w - 11, 0);
    }else{
        gotoxy(window_w - int(log10(highscore)) - 11, 0);
    }
    std::wcout << L"highscore: ";
    SetConsoleTextAttribute(hStdout, 0x0e);
    std::wcout << highscore;
    SetConsoleTextAttribute(hStdout, 0x07);

    gotoxy(0, padding_top +1);
    for (int i = 0; i < MR_height; i++){
        std::wcout <<  middle;
    }
    
}


start_f start = start_f();
einar EINAR = einar(int(window_w / 2) - 2, window_h - 1);

bool loop(int tick){
            // int ch = std::cin.get();
    // std::wcout << ch;
    if(tick % creation_speed == 0){
        errrrrrrrrr = "creation of next";
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
        errrrrrrrrr = "bullet move";
        bullet_move_(start);
        if(GetKeyState(VK_SPACE) & 0x8000){
            if(bullet_creation_delay_count % bullet_creation_delay == 0){
                errrrrrrrrr = "creation of bullet";
                bullet * new__ = new bullet(EINAR.x + int(einar_width / 2) - 1);
                start.add_bullet(new__);
            }
            bullet_creation_delay_count++;
        }else{
            bullet_creation_delay_count = 0;
        }
    }
    
    errrrrrrrrr = "check";
    if(!start.check(tick)){
        return 0;
    }
    // gotoxy(30,0);
    // std::wcout << tick;
    return 1;
}

void end(DWORD mode){
    if(highscore < score){
        std::ofstream highscore_file1("dirivative-game.txt");
        highscore_file1 << sha1(secret_hash + std::to_string(score));
        highscore_file1.close();
    }
    start._remove();
    gotoxy(window_w / 2 - end_string.length() / 2, window_h / 2);
    SetConsoleTextAttribute(hStdout, 0x0c);
    std::wcout << end_string;
    gotoxy(window_w / 2 - end_string.length() / 2, window_h / 2 + 2);
    SetConsoleTextAttribute(hStdout, 0x07);
    system("pause");
    SetConsoleMode(hStdin, mode);
}

int main(){
try{
    // Setup
    freopen("error.txt", "w", stderr);

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

    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT);
    srand(time(0));
    
    // SetConsoleTextAttribute(hStdout, 0x02);
    SetConsoleTitle(TEXT("Dirivative Game"));
    // system("mode 650");
    system("cls");

    
    // f_of_x f = f_of_x();
  
    std::getline(highscore_file, highscore_hash);
    if(highscore_hash == ""){
        highscore = 0;
    }else{
        bool done = false;
        int i = 0;
        while(!done){
            if(sha1(secret_hash + std::to_string(i)) == highscore_hash){
                highscore = i;
                done = true;
            }
            i++;
        }
    }
    highscore_file.close();

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
            errrrrrrrrr = "loop";
            timestart = timenow;
            if(!loop(tick)){
                end(mode);
                return 0;
            }
            tick++;
        }
        if(e_elapsed_seconds.count() >= double(1 / einar_speed)){
            errrrrrrrrr = "einar";
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

        gotoxy(8,0);
        SetConsoleTextAttribute(hStdout, 0x0e);
        std::wcout << score;
        SetConsoleTextAttribute(hStdout, 0x07);
        // created++;
        // std::wcout << created << " " << tick << " " << elapsed_seconds.count();
    }
    end(mode);
    return 0;
}
catch(int err){
    end(mode);
    std::wcout << err;
}
catch(char * err){
    end(mode);
    std::wcout << err;
}
catch(...){
    std::cerr << errrrrrrrrr;
    end(mode);
}
}