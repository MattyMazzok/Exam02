int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i;
        int j;
        int a[9999];

        i = 0;
        while (i<9999)
        {
            a[i] = 0;
            i++;
        }
        i=2;
        while(i>0)
        {
            j=0;
            while(argv[i][j])
            {
                if(i == 2 && a[(unsigned int)argv[i][j]] == 0)
                    a[(unsigned int)argv[i][j]] = 1;
                if(i == 1 && a[(unsigned int)argv[i][j]] == 1)
                {
                    write(1, &argv[i][j],1);
                    a[(unsigned int)argv[i][j]] = 2;
                }
                j++;
            }
            i--;
        }
    }
    write(1,"\n",1);
    return (0);
}
