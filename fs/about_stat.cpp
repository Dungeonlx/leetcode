#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void AboutStat(const char* FilePath) 
{
    struct stat Buf;

    if (stat(FilePath, &Buf) != 0) 
    {
        std::cout << "fail to stat " << FilePath << std::endl;
        std::cout << strerror(errno) << std::endl;
        return;
    }

    std::cout << "file: " << FilePath << std::endl;
    std::cout << "inode: " << Buf.st_ino << std::endl;
}

int main(int argc, char* argv[]) 
{
    AboutStat(argv[1] ? argv[1] : __FILE__);

    return 0;
}
