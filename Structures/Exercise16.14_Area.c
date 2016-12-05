#include <stdio.h>

#define PI 3.1416
#define RECTANGLE 1
#define CIRCLE 0

struct point{
        int x,y;
        };

struct shape{
        int shape_kind;
        struct point center;
        union{
            struct{
                int height;
                int width;
                }rectangle;
            struct{
                int radius;
                }circle;
        }u;
}s;

double area(struct shape s);
double scale(struct shape d1, double c);
struct shape move(struct shape d1, int a , int b);

int main()
{
    s.center.x = 12;
    s.center.y = 20;
    s.shape_kind = RECTANGLE;
    s.u.rectangle.height = 3;
    s.u.rectangle.width = 5;

    /*  If it's a circle:

    s.shape_kind = CIRCLE;
    s.u.circle_radius = 3; */

    printf("%.2f\n", area(s));

    printf("Area: %.2f\n", area(s));
    printf("Scaled: %.2f\n",scale(s,2));

    return 0;
}

double area (struct shape s)
{
    if(s.shape_kind == RECTANGLE)
        return s.u.rectangle.height * s.u.rectangle.width;
    else
        return 2*PI*s.u.circle.radius;
}

struct shape move(struct shape d1, int a , int b)
{
    d1.center.x += a;
    d1.center.y += b;
    return d1;
}

double scale(struct shape d1, double c)
{
    return area(d1)*c;
}
