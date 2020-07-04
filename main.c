int main(int argc, char *argv[])
{
    int fd;

    if (argc != 2)
    {
        write(2, "usage: ./fdf [target_file.fdf]\n", 31);//сообщение
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0 || read_file(fd, &(env.map)) != 0) //(read(fd, stack[0], 0) < 0)
    {
        write(2, "An error occurred reading the file... Is it valid?\n", 51);
        return (1);
    }
    return(0);
}