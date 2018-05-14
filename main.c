#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,n,s,m,il,max=0;
    FILE *f = fopen("in.txt", "r");
    unsigned long long int a=0;
    fscanf(f,"%d",&n);
    int* tab = (int*) malloc (n*sizeof (int) );
    for(i = 0; i < n; i++)
    {
        fscanf(f, "%d %d", &s, &m);
        tab [i]=s*60+m;
        a++;
    }
    fclose(f);
    for(i=0; i<21599; i++)
    {
        il=0;
        for(j=0; j<n; j++)
        {
            a++;
            if (i<=16199)
            {
                if(i<= tab[j] && tab[j] <= (i+5400)) il++;
            }
            else
            {
                if(i<= tab[j] || tab[j] <= (i+5400)%21599) il++;
            }
            if(il >max)
                max=il;
        }
    }
    f = fopen("out.txt", "w");
    fprintf(f, "%d", max);
    fclose(f);
    free(tab);
    printf(" Ilosc danych %d \n Licznik operacji %u  \n", n, a);
    return 0;
}
