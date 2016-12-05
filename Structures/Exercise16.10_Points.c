#include <stdio.h>

struct point{
        int x,y;
        };
struct rectangle{
        struct point upper_left, lower_right;
        };

struct rectangle move(struct rectangle rect, int a, int b);
int height(struct rectangle r);
int width(struct rectangle r);
int area(struct rectangle r);

int main()
{
    struct point upper_left = {0,3};
    struct point lower_right = {5,3};
    struct rectangle rect = {upper_left, lower_right};

    printf("Area: %d\n", area(rect));

    rect= move(rect,3,3);   //moving the rectangle
    printf("%d %d %d %d", rect.upper_left.x, rect.upper_left.y,
                          rect.lower_right.x,rect.lower_right.y);
    return 0;
}

int width(struct rectangle r)
{
    return r.lower_right.x - r.upper_left.x;
}

int height(struct rectangle r)
{
    return r.upper_left.y - r.upper_left.x;
}

int area(struct rectangle r)
{
    return width(r)*height(r);
}

struct rectangle move(struct rectangle rect, int a, int b)
{
    rect.upper_left.x += a;
    rect.upper_left.y += a;
    rect.lower_right.x += b;
    rect.lower_right.y += b;

    return rect;
}
