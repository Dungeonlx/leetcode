#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <algorithm>
#include <time.h>

namespace String 
{
    // string tolower
    std::string ToLower(std::string str)                                      
    {                                                                           
        std::string ret = "";                                                   
        std::locale loc;                                                        
                                                                                
        for (std::string::size_type i = 0; i < str.size(); ++i)                 
            ret += std::tolower(str[i], loc);                                   
                                                                                
        return ret;                                                             
    }

    bool CompareByLength(const std::string & l, const std::string & r) 
    {
        if (l.size() < r.size()) 
            return true;

        return false;
    }
};

namespace Time 
{
    void ToElapse(unsigned elapsed) 
    {
        int sec = elapsed / CLOCKS_PER_SEC;

        std::cout << "elapsed: " << sec << "." << elapsed - sec * CLOCKS_PER_SEC << std::endl;
    }
};

class Dict 
{
public:
    Dict(const char* DictFileName, bool isToLower = true, bool SortByLength = true) 
    {
        std::ifstream DictFile(DictFileName);
        std::string strLine;

        while (std::getline(DictFile, strLine)) 
        {
            if (isToLower) 
                m_WordList.push_back(String::ToLower(strLine));
            else
                m_WordList.push_back(strLine);
        }

        if (SortByLength) 
        { 
            std::sort(m_WordList.begin(), m_WordList.end(), String::CompareByLength);
            std::reverse(m_WordList.begin(), m_WordList.end());
        }

        std::cout << m_WordList.size() << " words" << std::endl;
    }
    virtual ~Dict() 
    {
    
    }

public:
    // 4 DEBUG
    void printWordList() 
    {
        for (int i = 0; i < m_WordList.size(); i++) 
            std::cout << m_WordList[i] << std::endl;
    }

private:
    std::vector<std::string> m_WordList;
};

int main(int argc, char* argv[]) 
{
    unsigned t0 = clock();
    // START
    //=========================================================================
    
    Dict objDict("dict.txt");

    //objDict.printWordList();

    // END
    //=========================================================================
    unsigned elapsed = clock() - t0;
    Time::ToElapse(elapsed);

    return 0;
}
