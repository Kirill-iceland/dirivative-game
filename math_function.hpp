
int randomnum = 10000000;
const int max_size = 6;
int added = 0;
int created_ = 0;
const std::wstring sup_int [10] = {L"⁰", L"", L"²", L"³", L"⁴", L"⁵", L"⁶", L"⁷", L"⁸", L"⁹"};

std::string int_to_str(int n){
    std::stringstream s;
    s << n;
    std::string res;
    s >> res;
    return res;
}
std::wstring int_to_wstr(int n){
    if(n > 1){
        return std::to_wstring(n);
    }else{
        return L"";
    }
}

class power_of_x
{
    public:
        int pow, mult;
        power_of_x(int p = 0, int m = 0){
            pow = p;
            mult = m;
        }
};

class f_of_x
{
    public:
        int x, y, speed, size, len;
        bool is_next = false;
        std::wstring text;
        power_of_x structure [max_size];
        power_of_x new_structure [max_size];
        f_of_x* next;
        f_of_x(){
            gotoxy(23,0);
            // created_++;
            // std::wcout << created_;
            // srand(time(0) + randomnum);
            structure[0] = power_of_x(0, (rand() % 9 + 1) * (1 - (rand() % 2) * 2));
            
            bool done = false;
            int i = 1;
            while (!done)
            {
                if((rand() % 3) && i < max_size){
                    structure[i] = power_of_x(i, rand() % 21 - 10);
                    i++;
                }else{
                    done = true;
                }
            }
            size = i;
            while(structure[size - 1].mult == 0){
                size--;
            }

            text = to_String();
            len = text.length();
            x = rand() % (window_w - len);
            y = 0;
            speed = size * speed_mult;
        }

        std::wstring to_String(){
            std::wstring res = L"";
            if(size > 1){
                if(structure[size - 1].mult > 0){
                    res = int_to_wstr(structure[size - 1].mult) + L"x" + sup_int[structure[size - 1].pow];
                }else if(structure[size - 1].mult < 0){
                    res = L"-" + int_to_wstr(0 - structure[size - 1].mult) + L"x" + sup_int[structure[size - 1].pow];
                }
            }
            for (int i = size - 2; i > 0; i--)
            {   
                if(structure[i].mult > 0){
                    res = res + L" + " + int_to_wstr(structure[i].mult) + L"x" + sup_int[i];
                }else if(structure[i].mult < 0){
                    res = res + L" - " + int_to_wstr(0 - structure[i].mult) + L"x" + sup_int[i];
                }
            }
            if(size > 1){
                if(structure[0].mult > 0){
                    res = res + L" + " + std::to_wstring(structure[0].mult);
                }else if(structure[0].mult < 0){
                    res = res + L" - " + std::to_wstring(0 - structure[0].mult);
                }
            }else{
                if(structure[0].mult > 0){
                    res = res + std::to_wstring(structure[0].mult);
                }else if(structure[0].mult < 0){
                    res = res + L"-" + std::to_wstring(0 - structure[0].mult);
                }
            }
            return res;
        }

        power_of_x * dirivative(){
            if(size < 2){
                size = 0;
                return {};
            }else{
                size--;
                for (int i = size; i > 0; i--)
                {   
                    new_structure[i - 1] = power_of_x(i - 1, structure[i].mult * i);
                    structure[i] = new_structure[i];
                }
                structure[0] = new_structure[0];
                text = to_String();
                len = text.length();
                return structure;
            }
        }

        void print(){
            gotoxy(x + 1, y + 1);
            std::wcout << text;
        }

        void remove(){
            gotoxy(x + 1, y + 1);
            std::wcout << wrepeat(L" ", len);
        }

        void add_next(f_of_x _next){
            if(is_next){
                (*next).add_next(_next);
            }else{
                is_next = true;
                next = &_next;
            }
        }

        bool check(int tick){
            if(tick % speed == 0){
                if(y == window_h - 1){
                    return false;
                }
                remove();
                y++;
                print();
            }
            if(is_next){
                return (*next).check(tick);
            }
            return true;
        }
};

class start_f
{
    public:
        f_of_x next;
        bool is_next = false;
        start_f(){

        }
        void add_next(f_of_x _next){
            gotoxy(20,0);
            added++;
            std::wcout << added;
            if(is_next){
                next.add_next(_next);
            }else{
                is_next = true;
                next = _next;
            }
        }

        bool check(int tick){
            if(is_next){
                return next.check(tick);
            }
            return true;
        }
};

class einar
{
    public:
        int x,y;
        einar(int x_, int y_){
            x = x_;
            y = y_;
        }

        void print(){
            SetConsoleTextAttribute(hStdout, 0x0e);
            gotoxy(x + 1, y + 1);
            std::wcout << L"EINAR";
            SetConsoleTextAttribute(hStdout, 0x07);
        }

        void move(int x_){
            SetConsoleTextAttribute(hStdout, 0x0e);
            if(x_ > 0){
                gotoxy(x + 1, y + 1);
                std::wcout << wrepeat(L" ", x_);
                std::wcout << L"EINAR";
            }else{
                gotoxy(x + 1 - x_, y + 1);
                std::wcout << L"EINAR";
                std::wcout << wrepeat(L" ", 0 - x_);
            }
            SetConsoleTextAttribute(hStdout, 0x07);
            x += x_;
        }
};