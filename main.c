#include <stdio.h>
#include <string.h>
#include "libft.h"
int main ()
{
//    const char	*str = "BBBB";
//    const char *str2 = "AAAA";
//
//    size_t sz;
    size_t sz2;
//    char	buff2[0xF00];
    char    buf[10] = "ty";
//



    sz2 = ft_strlcpy(buf, "qwertyuiop", 5);
    printf("%d\n", (int)sz2);

//    sz = strlcpy(NULL, NULL, 0);
//    printf("%d\n", (int)sz);

    return 0;
}