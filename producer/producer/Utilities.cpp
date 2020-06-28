#include "Utilities.h"
#include <cstdio>
#include <cerrno>

bool Utilities::FileExists(char* fileName)
{
    FILE* fp;
    errno_t err;

    if ((err = fopen_s(&fp, fileName, "r")) != 0) {
    
        return err != ENOENT;
    }

    if (fp) {
        fclose(fp);
        return true;
    }    

    return false;
}