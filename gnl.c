#include "get_next_line.h"

char *get_next_line(int fd)
{
    if(BUFFER_SIZE>0 && fd>=0 &&fd<1024)
    {
        char *nl = malloc(10000), *g = nl;
        while(read(fd,g,1)>0 && *g++ != '\0')
        return(g>nl) ? (g=0,nl) : (free(nl), NULL);
    }
    return (NULL);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

int main(int argc, char **argv)
{
	int fd;
	char *line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while ((line = get_next_line(fd)))
	{
		ft_putstr(line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
