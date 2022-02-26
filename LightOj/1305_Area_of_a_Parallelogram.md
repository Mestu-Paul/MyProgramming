**<a href="https://lightoj.com/problem/area-of-a-parallelogram">Problem</a></br>
Tag Geometry**</br></br>


Here given three point (A<sub>X</sub>,A<sub>Y</sub>) , (B<sub>X</sub>,B<sub>Y</sub>) and (C<sub>X</sub>,C<sub>Y</sub>). Let 4<sup>th</sup> point is (Dx,Dy) and intersection point of two diagonal (O<sub>X</sub>,O<sub>Y</sub>). 

<img src="https://github.com/Mestu-Paul/myOwnCode/blob/main/LightOj/parellelogram.png" alt="parallal image">

**Find out the 4<sup>th</sup> point :**</br><hr>
We know that mid point of a straigt line (between (A<sub>X</sub>,A<sub>Y</sub>) and (B<sub>X</sub>,B<sub>Y</sub>)) =  ( (A<sub>X</sub>+B<sub>X</sub>)/2 , (A<sub>y</sub>+B<sub>y</sub>)/2)

So for O<sub>X</sub> = (A<sub>X</sub>+C<sub>X</sub>)/2 </br>
**here A<sub>X</sub> and C<sub>X</sub> are given in problem**

Again 
> => O<sub>X</sub> = (A<sub>X</sub>+C<sub>X</sub>)/2 = (B<sub>X</sub>+D<sub>X</sub>)/2 </br>
> => A<sub>X</sub>+C<sub>X</sub> = B<sub>X</sub>+D<sub>X</sub></br>
> => D<sub>X</sub> =  A<sub>X</sub>+C<sub>X</sub> - B<sub>X</sub>

For O<sub>Y</sub> = (A<sub>Y</sub>+C<sub>Y</sub>)/2 </br>
**here A<sub>Y</sub> and C<sub>Y</sub> are given in problem**
> => O<sub>Y</sub> = (B<sub>Y</sub>+D<sub>Y</sub>)/2 </br>
> => 2 x O<sub>Y</sub> = B<sub>Y</sub>+D<sub>Y</sub></br>
> => D<sub>Y</sub> =  2 x O<sub>Y</sub> - B<sub>Y</sub>

So we get point (D<sub>X</sub>,D<sub>Y</sub>).

**Find out the area :**</br><hr>

We can find out area in different ways.Here I show a easy way-</br>
Here we will use regular polygon laws. 
So area = </br>

<img src="https://github.com/Mestu-Paul/myOwnCode/blob/main/LightOj/law.png" alt="parallal image" align="right">
(1/2) X </br>
|A<sub>X</sub> B<sub>X</sub> C<sub>X</sub> D<sub>X</sub> A<sub>X</sub>|</br>
|A<sub>Y</sub> B<sub>Y</sub> C<sub>Y</sub> D<sub>Y</sub> A<sub>Y</sub>|</br>

=  A<sub>X</sub> X B<sub>Y</sub> + B<sub>X</sub> X C<sub>Y</sub> + C<sub>X</sub> X D<sub>Y</sub> + 
D<sub>X</sub> X A<sub>y</sub> - B<sub>X</sub> X A<sub>Y</sub> - C<sub>X</sub> X B<sub>Y</sub> - D<sub>X</sub> X C<sub>Y</sub> - A<sub>X</sub> X D<sub>Y</sub>


**Here source code**</br><hr>
``` c++

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int test,Case=1;
    cin>>test;
    while(test--){
        double Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
        cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;
        Dx = Ax + Cx - Bx;
        Dy = Ay + Cy - By;
        long double ab,bc,ac;
        double area = abs(Ax*By + Bx*Cy + Cx*Dy + Dx*Ay - Bx*Ay - Cx*By - Dx*Cy - Ax*Dy);
        cout<<"Case "<<Case++<<": "<<Dx<<" "<<Dy<<" "<<(ll)round(area/2)<<endl;
    }
}

```
