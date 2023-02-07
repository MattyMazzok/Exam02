
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int i;
        int j;
        int a[9999];

        i = 0;
        while(i < 9999)
        {
            a[i] = 0;
            i++;
        }
        i = 1;
        while(i < 3)
        {
            j = 0;
            while(argv[i][j])
            {
                if (a[(unsigned int)argv[i][j]] == 0)
                {
                    write(1, &argv[i][j]);
                    a[(unsigned int)argv[i][j]] = 1;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
