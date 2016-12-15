#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include "Classes.h"

bool RadiusSize(Elips1D &refElips);

int main(void)
{
    Elips1D E1D_1(1.0, 0.0, 3.0);
    Elips1D E1D_2(4.0, 0.0, 0.0);
    Elips2D E2D_1(0.0, 3.0, 3.0, 4.0, 2.0);
    Elips2D E2D_2(6.0, 0.0, 3.0, 0.0, 4.0);
    bool bCheck;

    bCheck = RadiusSize(E1D_1);
    bCheck = RadiusSize(E1D_2);
    bCheck = RadiusSize(E2D_1);
    bCheck = RadiusSize(E2D_2);

    return 0;
}

bool RadiusSize(Elips1D &refElips)
{
    return ((refElips.CenterDistance() * 2) < refElips.GetRadius());
}