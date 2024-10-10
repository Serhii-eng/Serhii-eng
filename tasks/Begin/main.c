#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI		3.14159265358979323846

void begin40();

int main()
{
    begin40();
    return 0;
}

void begin40()
{
    double A1, B1, C1, A2, B2, C2;
    printf(" A1 = "); scanf("%lf", &A1);
    printf(" B1 = "); scanf("%lf", &B1);
    printf(" C1 = "); scanf("%lf", &C1);
    printf(" A2 = "); scanf("%lf", &A2);
    printf(" B2 = "); scanf("%lf", &B2);
    printf(" C2 = "); scanf("%lf", &C2);

    double D = A1 * B2 - A2 * B1;
    double x = (C1 * B1 - C2 * B1) / D;
    double y = (A1 * C2 - A2 * C1) / D;

    printf(" x = %lf\n", x);
    printf(" y = %lf\n", y);
}


void begin39()
{
    double A, B, C;
    printf(" A = "); scanf("%lf", &A);
    printf(" B = "); scanf("%lf", &B);
    printf(" C = "); scanf("%lf", &C);

    double D = B * B - 4 *A * C;
    double x1 = ((-1) * B + sqrt(D)) / (2 * A);
    double x2 = ((-1) * B - sqrt(D)) / (2 * A);

    printf(" x1 = %lf\n", x1);
    printf(" x2 = %lf\n", x2);
}


void begin38()
{
    double A, B;
    printf(" A = "); scanf("%lf", &A);
    printf(" B = "); scanf("%lf", &B);

    double x = -1 * B / A;

    printf(" x = %lf\n", x);
}

void begin37()
{
    double V1km_ch, V2km_ch, s_km, T_ch;
    printf(" V1km_ch = "); scanf("%lf", &V1km_ch);
    printf(" V2km_ch = "); scanf("%lf", &V2km_ch);
    printf(" s_km = "); scanf("%lf", &s_km);
    printf(" T_ch = "); scanf("%lf", &T_ch);

    double S_km = fabs(s_km - (V1km_ch * T_ch + V2km_ch * T_ch));

    printf(" S_km = %lf\n", S_km);
}

void begin36()
{
    double V1km_ch, V2km_ch, s_km, T_ch;
    printf(" V1km_ch = "); scanf("%lf", &V1km_ch);
    printf(" V2km_ch = "); scanf("%lf", &V2km_ch);
    printf(" s_km = "); scanf("%lf", &s_km);
    printf(" T_ch = "); scanf("%lf", &T_ch);

    double S_km = s_km + T_ch * (V1km_ch + V2km_ch);

    printf(" S_km = %lf\n", S_km);
}


void begin35()
{
    double Vkm_ch, Ukm_ch, T1_ch, T2_ch;
    printf(" Vkm_ch = "); scanf("%lf", & Vkm_ch);
    printf(" Ukm_ch = "); scanf("%lf", &Ukm_ch);
    printf(" T1_ch = "); scanf("%lf", &T1_ch);
    printf(" T2_ch = "); scanf("%lf", &T2_ch);

    double s = Vkm_ch * T1_ch;
    double S = (s * 2) - (Ukm_ch * T2_ch);

    printf(" S = %lf\n", S);
}

void begin34()
{
    double X_kg, A_price, Y_kg, B_price;
    printf(" X = "); scanf("%lf", &X_kg);
    printf(" A_price = "); scanf("%lf", &A_price);
    printf(" Y_kg = "); scanf("%lf", &Y_kg);
    printf(" B_price = "); scanf("%lf", &B_price);

    double price_A_1_kg = A_price / X_kg;
    double price_B_1_kg = B_price / Y_kg;
    double Difference_of_price = price_A_1_kg / price_B_1_kg;

    printf(" price_A_1_kg = %lf\n", price_A_1_kg);
    printf(" price_B_1_kg = %lf\n", price_B_1_kg);
    printf(" Difference_of_price = %lf\n", Difference_of_price);
}

void begin33()
{
    double X_kg, A_price, Y_kg;
    printf(" X = "); scanf("%lf", &X_kg);
    printf(" A_price = "); scanf("%lf", &A_price);
    printf(" Y_kg = "); scanf("%lf", &Y_kg);

    double price_1_kg =  A_price / X_kg;
    double Price_Y = price_1_kg * Y_kg;

    printf(" price/1_kg = %lf\n", price_1_kg);
    printf(" Price/Y = %lf\n", Price_Y);
}
void begin32()
{
    double Tc;
    printf(" Tc = ");
    scanf("%lf", &Tc);
    printf("Tc = %lf\n", Tc);

    double Tf  = Tc * 9 / 5 + 32;

    printf(" Tf = %lf\n", Tf);
}

void begin31()
{
    double Tf;
    printf(" Tf = ");
    scanf("%lf", &Tf);
    printf("Tf = %lf\n", Tf);

    double Tc  = (Tf - 32) * 5 / 9;
    printf(" Tc = %lf\n", Tc);
}

void begin30()
{
    double a;
    printf(" Enter the radian 'a', that can be (0 < a < 2 * PI) = ");
    scanf("%lf", &a);
    printf("a = %lf\n", a);

    int p_c = 180;
    double degree = p_c * a / PI;
    printf("degree = %lf\n", degree);
}

void begin29()
{
    double deg;
    printf(" Enter the angle 'a', that can be (0 < a < 360) = ");
    scanf("%lf", &deg);
    printf("a = %lf\n", deg);

    double rad = deg * PI / 180.0;
    printf("rad = %lf\n", rad);
}

void begin28()
{
    double A;
    printf(" A = ");
    scanf("%lf", &A);
    printf("A = %lf\n", A);



    double a, b;
    a = A * A;
    printf(" A^2 = %lf\n", a);
    b = a * A;
    printf(" A^3 = %lf\n", b);
    A = a * b;
    printf(" A^5 = %lf\n", A);
    a = A * A;
    printf(" A^10 = %lf\n", a);
    b = a * A;
    printf(" A^15 = %lf\n", b);
}

void begin27()
{
    double A;
    printf(" A = ");
    scanf("%lf", &A);
    printf("A = %lf\n", A);



    double a;
    a = A * A;
    printf(" A^2 = %lf\n", a);
    a = a * a;
    printf(" A^4 = %lf\n", a);
    a = a * a;
    printf(" A^8 = %lf\n", a);
}

void begin26()
{
    double x;
    printf(" x = ");
    scanf("%lf", &x);
    printf("x = %lf\n", x);



    double y = 4 * pow(x - 3, 6) - 7 * pow(x - 3, 3) + 2;

    printf(" y = %lf\n", y);
}

void begin25()
{
    double x;
    printf(" x = ");
    scanf("%lf", &x);
    printf("x = %lf\n", x);



    double y = 3 * pow(x, 6) - 6 * pow(x, 2) - 7;

    printf(" y = %lf\n", y);
}

void begin24()
{
    double A;
    printf(" A = ");
    scanf("%lf", &A);
    printf("A = %lf\n", A);

    double B;
    printf(" B = ");
    scanf("%lf", &B);
    printf("B = %lf\n", B);

    double C;
    printf(" C = ");
    scanf("%lf", &C);
    printf("C = %lf\n", C);

    double a, b;
    a = A;
    b = B;
    A = B;
    B = C;
    C = a;

    printf(" A = %lf\n", A);
    printf(" B = %lf\n", B);
    printf(" C = %lf\n", C);
}

void begin23()
{
    double A;
    printf(" A = ");
    scanf("%lf", &A);
    printf("A = %lf\n", A);

    double B;
    printf(" B = ");
    scanf("%lf", &B);
    printf("B = %lf\n", B);

    double C;
    printf(" C = ");
    scanf("%lf", &C);
    printf("C = %lf\n", C);

    double a, b;
    a = A;
    b = B;
    A = C;
    C = B;
    B = a;

    printf(" A = %lf\n", A);
    printf(" B = %lf\n", B);
    printf(" C = %lf\n", C);
}

void begin22()
{
    double A;
    printf(" A = ");
    scanf("%lf", &A);
    printf("A = %lf\n", A);

    double B;
    printf(" B = ");
    scanf("%lf", &B);
    printf("B = %lf\n", B);

    double temp = A;
    A = B;
    B = temp;

    printf(" A = %lf\n", A);
    printf(" B = %lf\n", B);
}

void begin21()
{
    double x1;
    printf(" x1 = ");
    scanf("%lf", &x1);
    printf("x1 = %lf\n", x1);

    double y1;
    printf(" y1 = ");
    scanf("%lf", &y1);
    printf("y1 = %lf\n", y1);

    double x2;
    printf(" x2 = ");
    scanf("%lf", &x2);
    printf("x2 = %lf\n", x2);

    double y2;
    printf(" y2 = ");
    scanf("%lf", &y2);
    printf("y2 = %lf\n", y2);

    double x3;
    printf(" x3 = ");
    scanf("%lf", &x3);
    printf("x3 = %lf\n", x3);

    double y3;
    printf(" y3 = ");
    scanf("%lf", &y3);
    printf("y3 = %lf\n", y3);

    int degree_2 = 2;
    double a = sqrt(pow(x2 - x1, degree_2) + pow(y2 - y1, degree_2));
    double b = sqrt(pow(x2 - x3, degree_2) + pow(y2 - y3, degree_2));
    double c = sqrt(pow(x1 - x3, degree_2) + pow(y1 - y3, degree_2));

    double P = a + b + c;
    printf(" P = %lf\n", P);

    double p = (a + b +c) / 2.0;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf(" S = %lf\n", S);
}

void begin20()
{
    double x1;
    printf(" x1 = ");
    scanf("%lf", &x1);
    printf("x1 = %lf\n", x1);

    double y1;
    printf(" y1 = ");
    scanf("%lf", &y1);
    printf("y1 = %lf\n", y1);

    double x2;
    printf(" x2 = ");
    scanf("%lf", &x2);
    printf("x2 = %lf\n", x2);

    double y2;
    printf(" y2 = ");
    scanf("%lf", &y2);
    printf("y2 = %lf\n", y2);

    int degree_2 = 2;
    double L = sqrt(pow(x2 - x1, degree_2) + pow(y2 - y1, degree_2));
    printf(" L = %lf\n", L);
}

void begin19()
{
    double x1, y1, x2, y2;
    printf(" x1 = ");    scanf("%lf", &x1);
    printf(" y1 = ");    scanf("%lf", &y1);
    printf(" x2 = ");    scanf("%lf", &x2);
    printf(" y2 = ");    scanf("%lf", &y2);

    double a = fabs(x1 - x2);
    double b = fabs(y1 - y2);

    double P = a + b + a + b;
    double S = a * b;

    printf(" P = %lf\n", P);
    printf(" S = %lf\n", S);
}

void begin18()
{
    double A;
    printf(" A = ");
    scanf("%lf", &A);
    printf("A = %lf\n", A);

    double B;
    printf(" B = ");
    scanf("%lf", &B);
    printf("B = %lf\n", B);

    double C;
    printf(" C = ");
    scanf("%lf", &C);
    printf("C = %lf\n", C);

    double AC =  abs(A - C);
    printf(" AC = %lf\n", AC);

    double BC =  abs(C - B);
    printf(" BC = %lf\n", BC);

    double mul =  AC * BC;
    printf(" mul = %lf\n", mul);
}


void begin17()
{
    double A;
    printf(" A = ");
    scanf("%lf", &A);
    printf("A = %lf\n", A);

    double B;
    printf(" B = ");
    scanf("%lf", &B);
    printf("B = %lf\n", B);

     double C;
    printf(" C = ");
    scanf("%lf", &C);
    printf("C = %lf\n", C);

    double AC =  abs(A - C);
    printf(" AC = %lf\n", AC);

    double BC =  abs(B - C);
    printf(" BC = %lf\n", BC);

    double sum =  AC + BC;
    printf(" sum = %lf\n", sum);
}

void begin16()
{
    double x1;
    printf(" x1 = ");
    scanf("%lf", &x1);
    printf("x1 = %lf\n", x1);

    double x2;
    printf(" x2 = ");
    scanf("%lf", &x2);
    printf("x2 = %lf\n", x2);

    double L =  abs(x1 - x2);
    printf(" L = %lf\n", L);


}

void begin15()
{
    double S;
    printf(" S = ");
    scanf("%lf", &S);
    printf("S = %lf\n", S);

    double R =  sqrt(S / PI);

    int two = 2;
    double D =  R * two;
    printf(" D = %lf\n", D);

    int degree_2 = 2;
    double L = two * PI * R;
    printf(" L = %lf\n", L);
}

void begin14()
{
    double L;
    printf(" L = ");
    scanf("%lf", &L);
    printf("L = %lf\n", L);

    double R = L / (PI * 2);
    printf(" R = %lf\n", R);

    double S = PI * R * R;
    printf(" S = %lf\n", S);
}

void begin13()
{
    double R1;
    printf(" R1 (Must be more than R2) = ");
    scanf("%lf", &R1);
    printf("R1 = %lf\n", R1);

    double R2;
    printf(" R2 (Must be less than R1)  = ");
    scanf("%lf", &R2);
    printf("R2 = %lf\n", R2);

    int degree_2 = 2;

    double S1 = PI * pow(R1, degree_2);
    printf(" Outer circle area S1 = %lf\n", S1);

    double S2 = PI * pow(R2, degree_2);
    printf(" Inner circle area = %lf\n", S2);

    double S3 = S1 - S2;
    printf(" Ring area S3 = %lf\n", S3);
}

void begin12()
{
    double a;
    printf(" a = ");
    scanf("%lf", &a);
    printf("Katet a = %lf\n", a);

    double b;
    printf(" b = ");
    scanf("%lf", &b);
    printf("Katet b = %lf\n", b);

    double c = sqrt(a * a + b * b);
    printf(" Gipotenuza c = %lf\n", c);

    double P = a + b + c;
    printf(" Perimetr = %lf\n", P);


}

void begin11()
{
    double a;
    printf(" a = ");
    scanf("%lf", &a);
    printf(" a = %lf\n", a);

    double b;
    printf(" b = ");
    scanf("%lf", &b);
    printf(" b = %lf\n", b);

    double A = abs(a);
    double B = abs(b);

    double Sum = A + B;
    printf(" Sum = %lf\n", Sum);

    double Difference = abs(a) - abs(b);
    printf(" Difference = %lf\n",Difference);

    double Multiplication = abs(a) * abs(b);
    printf(" Multiplication = %lf\n", Multiplication);


    double Devision = abs(a) / abs(b);
    printf(" Devision = %lf\n", Devision);
}





void begin10()
{
    double a, b;
    printf(" a = "); scanf("%lf", &a);
    printf(" b = "); scanf("%lf", &b);

    double A = a * a;
    double B = b * b;

    double Sum_of_squares = A + B;
    double Difference_of_squeres = A - B;
    double Product_of_squares = A * B;
    double Quotient_of_squares = A / B;

    printf(" Sum_of_squares = %lf\n", Sum_of_squares);
    printf(" Difference_of_squeres = %lf\n", Difference_of_squeres);
    printf(" Product_of_squares = %lf\n", Product_of_squares);
    printf(" Quotient_of_squares = %lf\n", Quotient_of_squares);
}

void begin9()
{
    double a;
    printf(" a = ");
    scanf("%lf", &a);
    printf(" a = %lf\n", a);

    double b;
    printf(" b = ");
    scanf("%lf", &b);
    printf(" b = %lf\n", b);

    double Geometric_mean = sqrt(abs(a * b));
    printf(" Geometric_mean = %lf\n", Geometric_mean);
}

void begin8()
{
    double a;
    printf(" a = ");
    scanf("%lf", &a);
    printf(" a = %lf\n", a);

    double b;
    printf(" b = ");
    scanf("%lf", &b);
    printf(" b = %lf\n", b);

    int two = 2;
    double Average = (a + b) / two;
    printf(" Average = %lf\n", Average);
}

void begin7()
{
    double R;
    printf(" R = ");
    scanf("%lf", &R);
    printf(" R = %lf\n", R);

    int two = 2;
    double L = two * PI * R;
    printf(" L = %lf\n", L);



    int degree_2 = 2;
    double S = PI * pow(R, degree_2);
    printf(" S = %lf\n", S);
}

void begin6()
{
    double a;
    printf(" a = ");
    scanf("%lf", &a);
    printf(" a = %lf\n", a);

    double b;
    printf(" b = ");
    scanf("%lf", &b);
    printf(" b = %lf\n", b);

    double c;
    printf(" c = ");
    scanf("%lf", &c);
    printf(" c = %lf\n", c);


    double V = a * b * c;
    printf(" V = %lf\n", V);



    int two = 2;
    double S = two * (a * b + b * c + a * c);
    printf(" S = %lf\n", S);
}

void begin5()
{
    double a;
    printf(" a = ");
    scanf("%lf", &a);
    printf(" a = %lf\n", a);

    double V = a * a * a;
    printf(" V = %lf\n", V);

    double S = 6 * a * a;
    printf(" S = %lf\n", S);
}

void begin4()
{
    double d;
    printf(" d = ");
    scanf("%lf", &d);
    printf(" d = %lf\n", d);

    double L = d * PI;

    printf(" L = %lf\n", L);
}
