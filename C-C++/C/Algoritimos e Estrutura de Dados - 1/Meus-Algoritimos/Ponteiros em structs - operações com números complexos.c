#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    float real, img, mod;

} complexo;

void atualizar_complexo(complexo *px, float real, float img)
{
    px->mod = sqrt(pow(real, 2) + pow(img, 2));
}

int main()
{
    complexo x, *px = &x;
    scanf("%f %f", &x.real, &x.img);

    atualizar_complexo(px, x.real, x.img);

    if (x.img >= 0)
    {
        printf("%.1f+%.1f", x.real, x.img);
    }
    else if (x.img < 0)
    {
        printf("%.1f%.1f", x.real, x.img);
    }
    printf("i\n%.1f", x.mod);

    return 0;
}
