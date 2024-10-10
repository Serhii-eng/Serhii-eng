#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define mapWidth 80
#define mapHeigh 25

typedef struct SObject  //структура для зберігання параметрів об'єкту
{
    float x, y;  //позиція об'єкту в просторі
    float width, height; //ширина, висота об'єкту

    float vertSpeed; //вертикальна швидкість об'єкту, чим вище об'єкт, тим менше значення змінної
    float horizSpeed; //горизонтальне переміщення (в основному стосується переміщення ворогів)

    char directionObject; // напрямок руху об'єкту задається символами 'R' або 'L'

    BOOL IsFly; //об'єкт в повітрі
    char cType; //символ, або символи з яких утворюється об'єкт
}TObject;

char map[mapHeigh][mapWidth+1];

TObject mario;

TObject *brick = NULL; //нерухомий об'єкт
int brickLength;

TObject *moving = NULL; //рухомий об'єкт
int movingLength;

//////////////////////////////////////
TObject *moving_fire = NULL; //рухомий об'єкт
int movingFireLength;
//////////////////////////////////////

//////////////////////////////////////
TObject *moving_rocket = NULL; //рухомий об'єкт
int movingRocketLength;
//////////////////////////////////////

int level = 1;
int score;
int maxLvl;


void ClearMap() //функція для очищення карти
{
    for(int i = 0; i < mapWidth; i++)
    {
       map[0][i] = ' ';
    }
    map[0][mapWidth] = '\0';
    for(int j = 1; j < mapHeigh; j++)
    {
        sprintf(map[j], map[0]);
    }
}


void SetObjectPos(TObject *obj, float xPos, float yPos) //Процедура задає позицію об'єкту
{
    (*obj).x = xPos;
    (*obj).y = yPos;
}


void PlayerDead()
{
    system("color 4F");
    Sleep(500);
    CreateLevel(level);
}


void InitObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight, float hSpeed, char inType)//процедура ініціалізує об'єкт ціляком
{
    SetObjectPos(obj, xPos, yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
    (*obj).vertSpeed = 0;
    (*obj).cType = inType;
    (*obj).horizSpeed = hSpeed;
}


void InitObjectRocket(TObject *obj, float xPos, float yPos, float oWidth, float oHeight, float hSpeed, char inType)//процедура ініціалізує ракету
{
    SetObjectPos(obj, xPos, yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
    (*obj).vertSpeed = 0;
    (*obj).cType = inType;
    (*obj).horizSpeed = hSpeed;
}



BOOL IsCollision(TObject o1, TObject o2);
BOOL IsCollisionWithSymbol(TObject o1, TObject o2);
void CreateLevel(int lvl);
TObject *GetNewMoving();


void VertMoveObject(TObject *obj) //Процедура обчислення вертикальної швидкості об'єкту, та перевірка зіштовху з іншими об'єктами
{
    (*obj).IsFly = TRUE;
    (*obj).vertSpeed += 0.05;
    SetObjectPos(obj, (*obj).x, (*obj).y + (*obj).vertSpeed);

    for(int i = 0; i < brickLength; i++)
    if(IsCollision(*obj, brick[i])) // якщо об'єкт зіштовхнувся з перешкодою
    {
        if(obj[0].vertSpeed > 0) //якщо об'єкт летить вниз
            obj[0].IsFly = FALSE;

            if( (brick[i].cType == '?') && (obj[0].vertSpeed < 0) && (obj == &mario) )//якщо маріо зіштовхнувся з цеглою типу питання '?'
            {                                                                         //і рухались знизу вгору і це був маріо
                brick[i].cType = '-';                                                 //то міняємо тип цегли на '-'
                InitObject(GetNewMoving(), brick[i].x, brick[i].y-3, 3, 2, 0.2, '$');      //додаємо рухомий об'єкт зверху кирпича
                moving[movingLength-1].vertSpeed = -0.7; // після вибивання грошей вони підлітають вгору (об'єкт летить в гору, значення негативне, в низ позитивне)
            }

        (*obj).y -= (*obj).vertSpeed;
        (*obj).vertSpeed = 0;

        if(brick[i].cType == '+') //перевірка на проходження рівня
        {
            level++;
            if(level > maxLvl) level = 1;

            system("color 2F");//залити консоль зеленим кольором
            Sleep(500);
            CreateLevel(level);
        }
        break;
    }
}


void DeleteMoving(int i) //процедура видалення рухомого об'єкту(коли маріо перемагає напригуючи зверху на ворога)
{
    movingLength--;
    moving[i] = moving[movingLength]; //розміщуємо останній елемент масиву на місце видаленого
    moving = realloc( moving, sizeof(*moving) * movingLength ); //зменшуємо масив на один елемент

}


void MarioCollision()//процедура для перевірки зіткнення маріо з рухомими об'єктами
{
    for(int i = 0; i < movingLength; i++)
        if(IsCollision(mario, moving[i]))
        {
            if(moving[i].cType == 'o') //взаємодія маріо з ворогом
            {
                if(     (mario.IsFly == TRUE) //приземляємося зверху на ворога якщо знаходимося в повітрі
                   &&   (mario.vertSpeed > 0) // при цьому летимо в низ
                   &&   (mario.y + mario.height < moving[i].y + moving[i].height * 0.5) //маріо повинен знаходитись вище половини зросту ворога
                  )
                {
                    score += 50; //очки за вбитого ворога
                    DeleteMoving(i); //видалення переможеного ворога
                    i--;
                    continue;
                }
                else
                {
                    PlayerDead(); //якщо маріо не пригнув зверху то ворог вбиває його і рівень починається з початку
                }
            }

            if(moving[i].cType == '$') //при зіштовхненні маріо з об'єктом типу гроші, знищуємо цей об'єкти '$'
            {
                score += 100; //очки за  зібрані гроші
                DeleteMoving(i);
                i--;
                continue;
            }
        }
}

///////////////////////////////////////
void MarioCollisionWithFire()//процедура для перевірки зіткнення маріо з рухомими об'єктами
{
        for(int i = 0; i < movingFireLength; i++)
        if(IsCollisionWithSymbol(mario, moving_fire[i]))
        {
            PlayerDead(); //якщо маріо не пригнув зверху то ворог вбиває його і рівень починається з початку
        }
}
////////////////////////////////////////

void HorizonMoveObject(TObject *obj) //процедура горизонтального переміщення об'єктів (в основному стосується ворогів)
{
    obj[0].x += obj[0].horizSpeed; //можна звертатись до полів структури як до нульового елементу масиву
    for(int i = 0; i < brickLength; i++)
        if(IsCollision(obj[0], brick[i]))
        {
            obj[0].x -= obj[0].horizSpeed;
            obj[0].horizSpeed = -obj[0].horizSpeed;
            return;
        }

    if(obj[0].cType == 'o')
    {
        //коли ворог доходе до прірви, то не падає, а йде в зворотньому напрямку
        TObject tmp = *obj; //створена копія об'єкту (відбувається розіменування)
        VertMoveObject(&tmp); //прикладаємо до нього силу тяжіння
        if(tmp.IsFly == TRUE) //якщо об'єкт опинився в польоті
        {
            obj[0].x -= obj[0].horizSpeed; //відміняємо поточне переміщення
            obj[0].horizSpeed = -obj[0].horizSpeed; //і йдемо в зворотню сторону
        }
    }
}


BOOL IsPosInMap(int x, int y) //функція відповідає чи об'єкт в межах мапи
{
    return( (x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeigh) );
}


void PutObjectOnMap(TObject obj)//Процедура створює об'єкт на карті
{
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);
    for(int i = ix; i < (iWidth + ix); i++)
        for(int j = iy; j < (iHeight + iy); j++)
            if(IsPosInMap(i, j))//перевірка потрібна щоб не вийти за межі масиву карти
                map[j][i] = obj.cType;
}

/////////////////////
void RotateFireObjectOnMap(TObject *obj)//Процедура створює об'єкт на карті
{
    int ix = (int)round(obj->x);
    int iy = (int)round(obj->y);
    int iWidth = (int)round(obj->width);
    int iHeight = (int)round(obj->height);
    int firePos = (int)round(obj->vertSpeed);
    if(obj->vertSpeed > 7.5) obj->vertSpeed = -0.5; //7.5 та -0,5 потрібні для встановлення меж замкнутого кола

    if(firePos == 0)
    {
        int j = iy;
        for(int i = ix; i < (iWidth + ix); i++)
            if(IsPosInMap(i, j))//перевірка потрібна щоб не вийти за межі масиву карти
                map[j][i] = obj->cType;
    }
    else if(firePos == 1)
    {
        for(int i = ix, j = iy; i < (iWidth + ix-2) || j < (iHeight + iy-2); i++, j++)
            if(IsPosInMap(i, j))
                map[j][i] = obj->cType;
    }
    else if(firePos == 2)
    {
        int i = ix;
        for(int j = iy; j < (iWidth + iy-1); j++)
            if(IsPosInMap(i, j))
                map[j][i] = obj->cType;
    }
    else if(firePos == 3)
    {
        for(int i = ix, j = iy; i > (ix - iWidth+2) || j < (iHeight + iy-2); i--, j++)
            if(IsPosInMap(i, j))
                map[j][i] = obj->cType;
    }
    else if(firePos == 4)
    {
        int j = iy;
        for(int i = ix; i > (ix - iWidth); i--)
            if(IsPosInMap(i, j))//перевірка потрібна щоб не вийти за межі масиву карти
                map[j][i] = obj->cType;
    }
    else if(firePos == 5)
    {
        for(int i = ix, j = iy; i > (ix - iWidth+2) || j > (iy - iHeight+2); i--, j--)
            if(IsPosInMap(i, j))
                map[j][i] = obj->cType;
    }
    else if(firePos == 6)
    {
        int i = ix;
        for(int j = iy; j > (iy - iWidth+1); j--)
            if(IsPosInMap(i, j))
                map[j][i] = obj->cType;
    }
    else if(firePos == 7)
    {
        for(int i = ix, j = iy; i < (iWidth + ix-2) || j > (iy - iHeight+2); i++, j--)
            if(IsPosInMap(i, j))
                map[j][i] = obj->cType;
    }

    obj->vertSpeed += 0.15;
}
//////////////////////


void showMap() //функція для відображення мапи та її вмісту
{
    map[mapHeigh-1][mapWidth-1] = '\0';
    for(int j = 0; j < mapHeigh; j++)
    {
        printf( "%s", map[j]);
    }
}


void setCur(int x, int y)//процедура переміщення курсора в консолі
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    //функція GetStdHandle(STD_OUTPUT_HANDLE) повертає адресу нашої консолі
    //функція   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)
    //встановлює координати які ми задаємо (coord), по адресі яку приймає в аргумент.
}


void HorizonMoveMap(float dx) //процедура для горизонтального переміщення карти
{
    mario.x -= dx;
    for(int i = 0; i < brickLength; i++) //перевірка на зіткнення маріо зі всими об'єктими
        if(IsCollision(mario, brick[i])) //якщо маріо зіштовхнувся, то повернути персонажа з камерою на вихідну позицію
        {
            mario.x += dx;
            return;
        }
    mario.x += dx;

    for(int i = 0; i < brickLength; i++)
        brick[i].x += dx;
    for(int i = 0; i < movingLength; i++)
        moving[i].x += dx;
    for(int i = 0; i < movingFireLength; i++)
        moving_fire[i].x += dx;
}


BOOL IsCollision(TObject o1, TObject o2) //відповідає чи відбулося зіткнення об'єктів
{
    return ((o1.x + o1.width) > o2.x) && (o1.x < (o2.x + o2.width)) &&
            ((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height));
}


BOOL IsCollisionWithSymbol(TObject o1, TObject o2)////////////////////////////////////////
{
    char c;
    int ix = (int)round(o1.x);
    int iy = (int)round(o1.y);
    int iWidth = (int)round(o1.width);
    int iHeight = (int)round(o1.height);
    for(int i = ix; i < (iWidth + ix); i++)
        for(int j = iy; j < (iHeight + iy); j++)
        {
            c = map[j][i];
            if(map[j][i] == o2.cType) return 1;
        }
    return 0;


}

TObject *GetNewBrick() //функция додає новий (нерухомий) елемент в масив і повертає його адресу
{
    brickLength++;
    brick = realloc(brick, sizeof(*brick) * brickLength);
    return brick + brickLength - 1;
}


TObject *GetNewMoving() //функция додає новий (рухомий) елемент в масив і повертає його адресу
{
    movingLength++;
    moving = realloc(moving, sizeof(*moving) * movingLength);
    return moving + movingLength - 1;
}


////////////////////////////////////
//для ініціалізації вогняного стовпа що крутиться, також необхідно додати невеликий блок до якого буде прив'язаний вогняний стовб
TObject *GetNewMovingFire() //функция додає новий (рухомий) елемент в масив і повертає його адресу
{
    movingFireLength++;
    moving_fire = realloc(moving_fire, sizeof(*moving_fire) * movingFireLength);
    return moving_fire + movingFireLength - 1;
}
////////////////////////////////////
//cтворити таку функцію для іншого об'єкту TObject *GetNewMoving()
//щоб на цей об'єкт не діяли стандартні процедури, а діяли спеціальні процедури зроблені для нього
//і додавати цей об'єкт в інші процедури тільки за потребою


////////////////////////////////////
//для ініціалізації рухомого об'єкту ракета
TObject *GetNewMovingRocket() //функция додає новий (рухомий) елемент в масив і повертає його адресу
{
    movingRocketLength++;
    moving_rocket = realloc(moving_rocket, sizeof(*moving_rocket) * movingRocketLength);
    return moving_rocket + movingRocketLength - 1;
}
////////////////////////////////////


void PutScoreOnMap()
{
    char c[30];
    sprintf(c, "Score: %d", score); //зберігаємо наш рахунок у вигляді рядку
    int len = strlen(c);
    for(int i = 0; i < len; i++)
    {
        map[1][i+5] = c[i]; //міняємо симсоли на карті на символи рядку
    }
}


void CreateLevel(int lvl) //в функції створюються рівні гри
{
    system("color 9F");

    brickLength = 0;
    brick = realloc(brick, 0);
    movingLength = 0;
    moving = realloc(moving, 0);

    ////////////////
    movingFireLength = 0;
    moving_fire = realloc(moving_fire, 0);
    ////////////////
    InitObject(&mario, 39, 10, 3, 3, 0, '@');
    score = 0;

    if(lvl == 1)
    {
        InitObject(GetNewBrick(), 20, 20, 40, 5, 0, '#');
            InitObject(GetNewBrick(), 30, 10, 5, 3, 0, '?');
            InitObject(GetNewBrick(), 50, 10, 5, 3, 0, '?');
        InitObject(GetNewBrick(), 60, 15, 40, 10, 0, '#');
            InitObject(GetNewBrick(), 60, 5, 10, 3, 0, '-');
            InitObject(GetNewBrick(), 70, 5, 5, 3, 0, '?');
            InitObject(GetNewBrick(), 75, 5, 5, 3, 0, '-');
            InitObject(GetNewBrick(), 80, 5, 5, 3, 0, '?');
            InitObject(GetNewBrick(), 85, 5, 10, 3, 0, '-');
        InitObject(GetNewBrick(), 100, 20, 20, 5, 0, '#');
        InitObject(GetNewBrick(), 120, 15, 10, 10, 0, '#');
        InitObject(GetNewBrick(), 140, 15, 10, 5, 0, '#');
        InitObject(GetNewBrick(), 180, 15, 10, 10, 0, '+');

        InitObject(GetNewMoving(), 25, 10, 3, 2, 0.1, 'o');
        InitObject(GetNewMoving(), 80, 10, 3, 2, 0.1, 'o');

        InitObject(GetNewMovingFire(), 20, 15, 5, 2, 0, 'f'); //вогняний об'єкт
    }

    if(lvl == 2)
    {
        InitObject(GetNewBrick(), 20, 20, 40, 5, 0, '#');
        InitObject(GetNewBrick(), 60, 15, 10, 10, 0, '#');
        InitObject(GetNewBrick(), 80, 20, 20, 5, 0, '#');
        InitObject(GetNewBrick(), 120, 15, 10, 10, 0, '#');
        InitObject(GetNewBrick(), 150, 20, 40, 5, 0, '#');
        InitObject(GetNewBrick(), 210, 15, 10, 10, 0, '+');

        InitObject(GetNewMoving(), 25, 10, 3, 2, 1, 'o');
        InitObject(GetNewMoving(), 80, 10, 3, 2, 1, 'o');
        InitObject(GetNewMoving(), 65, 10, 3, 2, 0.3, 'o');
        InitObject(GetNewMoving(), 120, 10, 3, 2, 0.4, 'o');
        InitObject(GetNewMoving(), 160, 10, 3, 2, 0.5, 'o');
        InitObject(GetNewMoving(), 175, 10, 3, 2, 0.6, 'o');
    }

    if(lvl == 3)
    {
        InitObject(GetNewBrick(), 20, 20, 40, 5, 0, '#');
        InitObject(GetNewBrick(), 80, 20, 15, 5, 0, '#');
        InitObject(GetNewBrick(), 120, 15, 15, 10, 0, '#');
        InitObject(GetNewBrick(), 160, 10, 15, 15, 0, '+');

        InitObject(GetNewMoving(), 25, 10, 3, 2, 0, 'o');
        InitObject(GetNewMoving(), 50, 10, 3, 2, 0, 'o');
        InitObject(GetNewMoving(), 80, 10, 3, 2, 0, 'o');
        InitObject(GetNewMoving(), 90, 10, 3, 2, 0, 'o');
        InitObject(GetNewMoving(), 120, 10, 3, 2, 0, 'o');
        InitObject(GetNewMoving(), 130, 10, 3, 2, 0, 'o');
    }

    maxLvl = 3;
}


int main()
{
    CreateLevel(level);

    do
    {
        ClearMap();

        if( (mario.IsFly == FALSE) && (GetKeyState(VK_SPACE) < 0) ) mario.vertSpeed -= 1;
        if(GetKeyState('A') < 0) HorizonMoveMap(1); //в право
        if(GetKeyState('D') < 0) HorizonMoveMap(-1); //в ліво

        if(mario.y > mapHeigh) PlayerDead(); //коли персонаж падає у прірву значення поля структури збільшується mario.y (бо заповнення консолі відбувається знизу в гору)

        VertMoveObject(&mario);
        MarioCollision();

        for(int i = 0; i < brickLength; i++) //для перемальвування нерухомих об'єктів на карті
            PutObjectOnMap(brick[i]);
        /////////////////
        for(int i = 0; i < movingFireLength; i++)
            RotateFireObjectOnMap(&moving_fire[i]);
            MarioCollisionWithFire();
        /////////////////


        for(int i = 0; i < movingLength; i++) //для перемальвування рухомих об'єктів на карті
        {
            VertMoveObject(moving + i);
            HorizonMoveObject(moving + i);
            if(moving[i].y > mapHeigh) //знищити ворога якщо він знаходиться нижче екрану (заповнення карти починається з верхноьго лівого кута)
            {
                DeleteMoving(i);
                i--;
                continue;
            }
            PutObjectOnMap(moving[i]);
        }
        PutObjectOnMap(mario);
        PutScoreOnMap();

        setCur(0, 0);
        showMap();////////////////   //////////
        Sleep(10);
    }
    while(GetKeyState(VK_ESCAPE) >= 0); //для виходу з гри, натиснути escape
    return 0;
}
