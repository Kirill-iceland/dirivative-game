
int randomnum = 10000000;
const int max_size = 6;
int margin = 3;
int ccccccc = 0;
// int created_ = 0;
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


class bullet
{
    public:
        int x, y;
        bool is_next = false;
        bullet * next;
        bullet(int x_ = 0){
            x = x_;
            y = window_h - 3;

        }

        
        void print(){
            SetConsoleTextAttribute(hStdout, 0x06);
            gotoxy(x + 1, y + 1);
            std::wcout << L"dy";
            gotoxy(x + 1, y + 2);
            std::wcout << L"dx";
            SetConsoleTextAttribute(hStdout, 0x07);
        }



        void add_next(bullet * _next){
            if(is_next){
                (*next).add_next(_next);
            }else{
                is_next = true;
                next = _next;
                (*next).print();
            }
        }

        void remove_bullet(){
            if((*next).is_next){
                bullet * temp =  next;
                next = (*next).next;
                delete temp;
            }else{
                delete next;
                is_next = false;
            }
        }

        void remove(){
            gotoxy(x + 1, y + 1);
            std::wcout << L"  ";
            gotoxy(x + 1, y + 2);
            std::wcout << L"  ";
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
            // gotoxy(23,0);
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
            x = (rand() % (window_w - len - margin * 2)) + margin;
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

        void add_next(f_of_x * _next){
            if(is_next){
                (*next).add_next(_next);
            }else{
                is_next = true;
                next = _next;
                (*next).print();
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

        template <typename par>
        bool bullet_check(bullet & bullet_, par & parrent){ 
            if(y == bullet_.y - 1 || y == bullet_.y){
                if(x <= bullet_.x + 1 && x + len > bullet_.x){
                    bullet_.remove();
                    parrent.remove_bullet();
                    score++;
                    remove();
                    dirivative();
                    print();
                    return true;
                }
            }
            if(is_next){
                return (*next).bullet_check(bullet_, parrent);
            }else{
                return false;
            }
        }

        void _remove(){
            if(is_next){
                if((*next).is_next){
                    (*next)._remove();
                }
                delete next;
            }
        }
};



class start_f
{
    public:
        f_of_x * next;
        bullet * Bullet;
        bool is_next = false;
        bool is_bullet = false;
        start_f(){

        }
        void add_next(f_of_x * _next){
            if(is_next){
                (*next).add_next(_next);
            }else{
                is_next = true;
                next = _next;
            }
        }

        void add_bullet(bullet * _next){
            if(is_bullet){
                (*Bullet).add_next(_next);
            }else{
                is_bullet = true;
                Bullet = _next;
            }
        }

        bool check(int tick){
            if(is_next){
                return (*next).check(tick);
            }
            return true;
        }
        
        bool bullet_check(bullet & bullet_, bullet & parrent){
            if(is_next){
                return (*next).bullet_check(bullet_, parrent);
            }
            return false;
        }

        bool bullet_check(bullet & bullet_, start_f & parrent){
            if(is_next){
                return (*next).bullet_check(bullet_, parrent);
            }
            return false;
        }

        void remove_next(){
            if((*next).is_next){
                f_of_x * temp =  next;
                next = (*next).next;
                delete temp;
            }else{
                is_next = false;
                delete next;
            }
        }
        
        void remove_bullet(){
            if((*Bullet).is_next){
                bullet * temp =  Bullet;
                Bullet = (*Bullet).next;
                delete temp;
            }else{
                delete Bullet;
                is_bullet = false;
            }
        }

        void _remove(){
            if(is_next){
                (*next)._remove();
            }
            delete next;
            return;
        }
};


void bullet_move(start_f & s, bullet & main, bullet & parrent){
    if(s.bullet_check(main, parrent)){
        if(parrent.is_next){
            bullet_move(s, *(parrent.next), parrent);
        }
        return;
    }
    if(main.y > 0){
        gotoxy(main.x + 1, main.y + 2);
        std::wcout << L"  ";
        main.y--;
        main.print();
    }
    if(main.is_next){ 
        bullet_move(s, (*(main.next)), main);
    }
        
}
void bullet_move(start_f & s, bullet & main, start_f & parrent){
    if(s.bullet_check(main, parrent)){
        if(parrent.is_bullet){
            bullet_move(s, *(parrent.Bullet), parrent);
        }
        return;
    }
    if(main.y > 0){
        gotoxy(main.x + 1, main.y + 2);
        std::wcout << L"  ";
        main.y--;
        main.print();
        if(main.is_next){
            bullet_move(s, *(main.next), main);
        }
    }else{
        main.remove();
        parrent.remove_bullet();
        if(parrent.is_bullet){
            bullet_move(s, *(parrent.Bullet), main);
        }
    }
}

void bullet_move_(start_f & main){
    if(main.is_bullet){
        return bullet_move(main, *(main.Bullet), main);
    }
    return;
}






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
            std::wcout << einar_string;
            SetConsoleTextAttribute(hStdout, 0x07);
        }

        void move(int x_){
            SetConsoleTextAttribute(hStdout, 0x0e);
            if(x_ > 0){
                gotoxy(x + 1, y + 1);
                std::wcout << wrepeat(L" ", x_);
                std::wcout << einar_string;
            }else{
                gotoxy(x + 1 + x_, y + 1);
                std::wcout << einar_string;
                std::wcout << wrepeat(L" ", 0 - x_);
            }
            SetConsoleTextAttribute(hStdout, 0x07);
            x += x_;
        }
};
