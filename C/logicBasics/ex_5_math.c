#include<stdio.h>
#include<math.h>

int main()
{
    printf("Hello world!");
    int d, vf, vg;
    float tf, hip, vgReq;
    scanf ("%d%d%d", &d, &vf, &vg);
    // tempo (horas) = 12/vel
    tf = 12/vf;
    // hipotenusa = sqrt (d^2 + 12^2)
    hip = sqrt((d*d) + (12*12));
    // vgRequerida = hipotenusa/tempo 
    vgReq = hip/tf;
    // If vgRequerida < vg
    if(vgReq < vg){
        printf("1");
    }else{
        printf("0");
    }
    
    return 0;
}