/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondel <rblondel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:36:25 by rblondel          #+#    #+#             */
/*   Updated: 2021/05/12 16:27:38 by rblondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

// char *ft_concat(char *str)
// {
//     int i;
//     int y;
//     int len;
//     char *result;

//     len = 0;
//     i = 0;
//     y = 0;
//     while (str[len] != '\n' && str[len])
//         len++;
//     if (!str[len])
//     {
//         if (!(result = malloc(sizeof(char) * (len + 1))))
//             return (NULL);
//         while (str[y])
//         {
//             result[y] = str[y];
//             y++;
//         }
//         result[y] = 0;
//         return (result);
//     }
//     len++;
//     while (str[i])
//         i++;
//     if (!(result = malloc(sizeof(char) * (i - len + 1))))
//         return (NULL);
//     while (str[len])
//     {
//         result[y] = str[len];
//         y++;
//         len++;
//     }
//     result[y] = 0;
//     return (result);
// }



// void ft_realloc(char *str)
// {
//     free(str);
// }

char *ft_concat(char *str, char *buff)
{
    char *str2;
    int buff_len;
    int str_len;
    int i;
    int y;

    i           = 0;
    y           = 0;
    str_len     = 0;
    buff_len    = 0;
    if (!buff)
        return (str);
    while (buff[buff_len])
        buff_len++;
    while (str && str[str_len])
        str_len++;
    printf("%i %i", str_len, buff_len);
    if (!(str2 = malloc(sizeof(char) * (buff_len + str_len + 1))))
        return (0);
    while (str && str[i])
    {
        str2[i] = str[i];
        i++;
    }
    while (buff[y])
    {
        str2[i] = buff[y];
        i++;
        y++;
    }
    str2[i] = '\0';
    free(str);
    return (str2);
}

int ft_str_chr(char *buff)
{
    int i;

    i = 0;
    while (buff[i])
    {
        if (buff[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

int     gnl_read(int fd, char **str_line)
{
    char    buff[BUFFER_SIZE + 1];
    int     rret;
    int     i;
    
    i = 0;
    rret = read(fd, buff, BUFFER_SIZE);
    if (rret <= 0)
        return (rret);
    if (!(*str_line))
    {
        *str_line = malloc(sizeof(char) * 1);
        (*str_line)[0] = '\0';
    }
    buff[rret] = 0;
    *str_line = ft_concat(*str_line, buff);
    while (!ft_str_chr(buff))
    {
        rret = read(fd, buff, BUFFER_SIZE);
        if (rret < 0)
            buff[0] = 0;
        else
            buff[rret] = 0;
        *str_line = ft_concat(*str_line, buff);
    }
    return (rret);
}

int        get_next_line(int fd, char **line)
{
    static char *str;
    //str = malloc(sizeof(char) * 1);
    //str[0] = '\0';

    (void)line;
/*     if (!str_line)
    {
        *str_line = malloc(sizeof(char) * 1);
        (*str_line)[0] = '\0';
    }  */
    gnl_read(fd, &str);
    printf("%s\n", str);
    //*line = str;
    //printf("%s\n", *line);
    //system("leaks a.out");
    return (0);
}

// int get_next_line(int fd, char **line)
// {
//     char    buff[BUFFER_SIZE];
//     int     rret;
//     int     len;
//     int     i;
//     char    *stock;

//     (void) line;
//     i = 0;
//     len = 0;
//     rret = read(fd, buff, BUFFER_SIZE);
//     ft_lstnew(fd, buff);
//     while (buff[len] != '\n' && buff[len])
//         len++;
//     if (!(stock = malloc(sizeof(char) * (len + 1))))
//         return (0);
//     while (i < len)
//     {
//         stock[i] = buff[i];
//         i++;
//     }
//     stock[i] = 0;
//     printf("stock : %s", stock);
//     free(stock);
//     return (1);
// }


#include <fcntl.h>

int main(int ac, char **av)
{
    (void)ac;
    (void) av;
    char *line = NULL;

    int fd;
    fd = open("test2", O_RDONLY);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    get_next_line(fd, &line);
    get_next_line(fd, &line);

    //printf("%s", gnl_read(fd));
    return (0);
}