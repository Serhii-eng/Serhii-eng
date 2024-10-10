#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define mapWidth 80
#define mapHeigh 25

typedef struct SObject  //��������� ��� ��������� ��������� ��'����
{
    float x, y;  //������� ��'���� � �������
    float width, height; //������, ������ ��'����

    float vertSpeed; //����������� �������� ��'����, ��� ���� ��'���, ��� ����� �������� �����
    float horizSpeed; //������������� ���������� (� ��������� ��������� ���������� ������)

    char directionObject; // �������� ���� ��'���� �������� ��������� 'R' ��� 'L'

    BOOL IsFly; //��'��� � �����
    char cType; //������, ��� ������� � ���� ����������� ��'���
}TObject;

char map[mapHeigh][mapWidth+1];

TObject mario;

TObject *brick = NULL; //��������� ��'���
int brickLength;

TObject *moving = NULL; //������� ��'���
int movingLength;

//////////////////////////////////////
TObject *moving_fire = NULL; //������� ��'���
int movingFireLength;
//////////////////////////////////////

//////////////////////////////////////
TObject *moving_rocket = NULL; //������� ��'���
int movingRocketLength;
//////////////////////////////////////

int level = 1;
int score;
int maxLvl;


void ClearMap() //������� ��� �������� �����
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


void SetObjectPos(TObject *obj, float xPos, float yPos) //��������� ���� ������� ��'����
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


void InitObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight, float hSpeed, char inType)//��������� �������� ��'��� �������
{
    SetObjectPos(obj, xPos, yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
    (*obj).vertSpeed = 0;
    (*obj).cType = inType;
    (*obj).horizSpeed = hSpeed;
}


void InitObjectRocket(TObject *obj, float xPos, float yPos, float oWidth, float oHeight, float hSpeed, char inType)//��������� �������� ������
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


void VertMoveObject(TObject *obj) //��������� ���������� ����������� �������� ��'����, �� �������� ������� � ������ ��'������
{
    (*obj).IsFly = TRUE;
    (*obj).vertSpeed += 0.05;
    SetObjectPos(obj, (*obj).x, (*obj).y + (*obj).vertSpeed);

    for(int i = 0; i < brickLength; i++)
    if(IsCollision(*obj, brick[i])) // ���� ��'��� ����������� � ����������
    {
        if(obj[0].vertSpeed > 0) //���� ��'��� ������ ����
            obj[0].IsFly = FALSE;

            if( (brick[i].cType == '?') && (obj[0].vertSpeed < 0) && (obj == &mario) )//���� ���� ����������� � ������ ���� ������� '?'
            {                                                                         //� �������� ����� ����� � �� ��� ����
                brick[i].cType = '-';                                                 //�� ������ ��� ����� �� '-'
                InitObject(GetNewMoving(), brick[i].x, brick[i].y-3, 3, 2, 0.2, '$');      //������ ������� ��'��� ������ �������
                moving[movingLength-1].vertSpeed = -0.7; // ���� ��������� ������ ���� �������� ����� (��'��� ������ � ����, �������� ���������, � ��� ���������)
            }

        (*obj).y -= (*obj).vertSpeed;
        (*obj).vertSpeed = 0;

        if(brick[i].cType == '+') //�������� �� ����������� ����
        {
            level++;
            if(level > maxLvl) level = 1;

            system("color 2F");//������ ������� ������� ��������
            Sleep(500);
            CreateLevel(level);
        }
        break;
    }
}


void DeleteMoving(int i) //��������� ��������� �������� ��'����(���� ���� �������� ���������� ������ �� ������)
{
    movingLength--;
    moving[i] = moving[movingLength]; //�������� ������� ������� ������ �� ���� ����������
    moving = realloc( moving, sizeof(*moving) * movingLength ); //�������� ����� �� ���� �������

}


void MarioCollision()//��������� ��� �������� �������� ���� � �������� ��'������
{
    for(int i = 0; i < movingLength; i++)
        if(IsCollision(mario, moving[i]))
        {
            if(moving[i].cType == 'o') //������� ���� � �������
            {
                if(     (mario.IsFly == TRUE) //������������� ������ �� ������ ���� ����������� � �����
                   &&   (mario.vertSpeed > 0) // ��� ����� ������ � ���
                   &&   (mario.y + mario.height < moving[i].y + moving[i].height * 0.5) //���� ������� ����������� ���� �������� ������ ������
                  )
                {
                    score += 50; //���� �� ������� ������
                    DeleteMoving(i); //��������� ������������ ������
                    i--;
                    continue;
                }
                else
                {
                    PlayerDead(); //���� ���� �� ������� ������ �� ����� ����� ���� � ����� ���������� � �������
                }
            }

            if(moving[i].cType == '$') //��� ���������� ���� � ��'����� ���� �����, ������� ��� ��'���� '$'
            {
                score += 100; //���� ��  ����� �����
                DeleteMoving(i);
                i--;
                continue;
            }
        }
}

///////////////////////////////////////
void MarioCollisionWithFire()//��������� ��� �������� �������� ���� � �������� ��'������
{
        for(int i = 0; i < movingFireLength; i++)
        if(IsCollisionWithSymbol(mario, moving_fire[i]))
        {
            PlayerDead(); //���� ���� �� ������� ������ �� ����� ����� ���� � ����� ���������� � �������
        }
}
////////////////////////////////////////

void HorizonMoveObject(TObject *obj) //��������� ��������������� ���������� ��'���� (� ��������� ��������� ������)
{
    obj[0].x += obj[0].horizSpeed; //����� ���������� �� ���� ��������� �� �� ��������� �������� ������
    for(int i = 0; i < brickLength; i++)
        if(IsCollision(obj[0], brick[i]))
        {
            obj[0].x -= obj[0].horizSpeed;
            obj[0].horizSpeed = -obj[0].horizSpeed;
            return;
        }

    if(obj[0].cType == 'o')
    {
        //���� ����� ������ �� �����, �� �� ����, � ��� � ����������� ��������
        TObject tmp = *obj; //�������� ���� ��'���� (���������� ������������)
        VertMoveObject(&tmp); //���������� �� ����� ���� ������
        if(tmp.IsFly == TRUE) //���� ��'��� �������� � ������
        {
            obj[0].x -= obj[0].horizSpeed; //�������� ������� ����������
            obj[0].horizSpeed = -obj[0].horizSpeed; //� ����� � �������� �������
        }
    }
}


BOOL IsPosInMap(int x, int y) //������� ������� �� ��'��� � ����� ����
{
    return( (x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeigh) );
}


void PutObjectOnMap(TObject obj)//��������� ������� ��'��� �� ����
{
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);
    for(int i = ix; i < (iWidth + ix); i++)
        for(int j = iy; j < (iHeight + iy); j++)
            if(IsPosInMap(i, j))//�������� ������� ��� �� ����� �� ��� ������ �����
                map[j][i] = obj.cType;
}

/////////////////////
void RotateFireObjectOnMap(TObject *obj)//��������� ������� ��'��� �� ����
{
    int ix = (int)round(obj->x);
    int iy = (int)round(obj->y);
    int iWidth = (int)round(obj->width);
    int iHeight = (int)round(obj->height);
    int firePos = (int)round(obj->vertSpeed);
    if(obj->vertSpeed > 7.5) obj->vertSpeed = -0.5; //7.5 �� -0,5 ������ ��� ������������ ��� ���������� ����

    if(firePos == 0)
    {
        int j = iy;
        for(int i = ix; i < (iWidth + ix); i++)
            if(IsPosInMap(i, j))//�������� ������� ��� �� ����� �� ��� ������ �����
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
            if(IsPosInMap(i, j))//�������� ������� ��� �� ����� �� ��� ������ �����
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


void showMap() //������� ��� ����������� ���� �� �� �����
{
    map[mapHeigh-1][mapWidth-1] = '\0';
    for(int j = 0; j < mapHeigh; j++)
    {
        printf( "%s", map[j]);
    }
}


void setCur(int x, int y)//��������� ���������� ������� � ������
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    //������� GetStdHandle(STD_OUTPUT_HANDLE) ������� ������ ���� ������
    //�������   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)
    //���������� ���������� �� �� ������ (coord), �� ����� ��� ������ � ��������.
}


void HorizonMoveMap(float dx) //��������� ��� ��������������� ���������� �����
{
    mario.x -= dx;
    for(int i = 0; i < brickLength; i++) //�������� �� �������� ���� � ����� ��'������
        if(IsCollision(mario, brick[i])) //���� ���� �����������, �� ��������� ��������� � ������� �� ������� �������
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


BOOL IsCollision(TObject o1, TObject o2) //������� �� �������� �������� ��'����
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

TObject *GetNewBrick() //������� ���� ����� (���������) ������� � ����� � ������� ���� ������
{
    brickLength++;
    brick = realloc(brick, sizeof(*brick) * brickLength);
    return brick + brickLength - 1;
}


TObject *GetNewMoving() //������� ���� ����� (�������) ������� � ����� � ������� ���� ������
{
    movingLength++;
    moving = realloc(moving, sizeof(*moving) * movingLength);
    return moving + movingLength - 1;
}


////////////////////////////////////
//��� ����������� ��������� ������ �� ���������, ����� ��������� ������ ��������� ���� �� ����� ���� ����'������ �������� �����
TObject *GetNewMovingFire() //������� ���� ����� (�������) ������� � ����� � ������� ���� ������
{
    movingFireLength++;
    moving_fire = realloc(moving_fire, sizeof(*moving_fire) * movingFireLength);
    return moving_fire + movingFireLength - 1;
}
////////////////////////////////////
//c������� ���� ������� ��� ������ ��'���� TObject *GetNewMoving()
//��� �� ��� ��'��� �� ���� ��������� ���������, � ���� ��������� ��������� ������� ��� �����
//� �������� ��� ��'��� � ���� ��������� ����� �� ��������


////////////////////////////////////
//��� ����������� �������� ��'���� ������
TObject *GetNewMovingRocket() //������� ���� ����� (�������) ������� � ����� � ������� ���� ������
{
    movingRocketLength++;
    moving_rocket = realloc(moving_rocket, sizeof(*moving_rocket) * movingRocketLength);
    return moving_rocket + movingRocketLength - 1;
}
////////////////////////////////////


void PutScoreOnMap()
{
    char c[30];
    sprintf(c, "Score: %d", score); //�������� ��� ������� � ������ �����
    int len = strlen(c);
    for(int i = 0; i < len; i++)
    {
        map[1][i+5] = c[i]; //������ ������� �� ���� �� ������� �����
    }
}


void CreateLevel(int lvl) //� ������� ����������� ��� ���
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

        InitObject(GetNewMovingFire(), 20, 15, 5, 2, 0, 'f'); //�������� ��'���
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
        if(GetKeyState('A') < 0) HorizonMoveMap(1); //� �����
        if(GetKeyState('D') < 0) HorizonMoveMap(-1); //� ���

        if(mario.y > mapHeigh) PlayerDead(); //���� �������� ���� � ����� �������� ���� ��������� ���������� mario.y (�� ���������� ������ ���������� ����� � ����)

        VertMoveObject(&mario);
        MarioCollision();

        for(int i = 0; i < brickLength; i++) //��� ��������������� ��������� ��'���� �� ����
            PutObjectOnMap(brick[i]);
        /////////////////
        for(int i = 0; i < movingFireLength; i++)
            RotateFireObjectOnMap(&moving_fire[i]);
            MarioCollisionWithFire();
        /////////////////


        for(int i = 0; i < movingLength; i++) //��� ��������������� ������� ��'���� �� ����
        {
            VertMoveObject(moving + i);
            HorizonMoveObject(moving + i);
            if(moving[i].y > mapHeigh) //������� ������ ���� �� ����������� ����� ������ (���������� ����� ���������� � ��������� ����� ����)
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
    while(GetKeyState(VK_ESCAPE) >= 0); //��� ������ � ���, ��������� escape
    return 0;
}
