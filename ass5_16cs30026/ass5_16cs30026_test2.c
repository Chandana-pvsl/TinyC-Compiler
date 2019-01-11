// test for loops
void main()
{
   int n,l1,l2,l3,l4,g,z,cou=1;
   printf("Enter n:");
   scanf("%d",&n);
   z=(n*2)-1;
   g=(n-1);
   int r;
   while(r%2==0)
    {
        scanf("%d",&r);
    }
   /* ned pyramid */
   for(l1=1;l1<=z;l1=l1+2)
   {
       for(l2=1;l2<=g;l2++)
       {
           printf(" ");
       }
       g--;
       for(l3=1;l3<=l1;l3++)
       {
           printf("%d",cou);
           if(l3!=1)
           {
                if(l3>=(l1+1)/2)
                {
                    for(l4=1;l4<((l1+1)/2);l4++)
                    {
                        cou--;
                        printf("%d",cou);

                    }
                    cou++;
                    if(l4==(l1+1)/2)
                    {
                      l4++;
                    }
                }
           }
           cou++;
       }
       do{
        if(j>10)
        i++;
       }while(i<10);
       // printf("\n");
   }
}