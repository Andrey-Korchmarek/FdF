void    read_map(char *file)
{
    int     n;
    int     fd;
    char    **line;

    fd = open(file, O_RDONLY);
    n = get_next_line(fd, line);
    close(fd);
    return ;
}