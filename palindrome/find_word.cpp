#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <locale>
#include <algorithm>
#include <time.h>

namespace String 
{
    bool IsTheChar(std::string str, int c) 
    {
        str.erase(std::remove(str.begin(), str.end(), c), str.end());

        if (str.size() == 0)
            return true;

        return false;
    }

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

class Dict 
{
public:
    Dict(const char* DictFileName, bool isToLower = true, bool SortByLength = true) 
    {
        std::ifstream DictFile(DictFileName);
        std::string strLine;

        while (std::getline(DictFile, strLine)) 
        {
            if (String::IsTheChar(strLine, ' ')) 
                continue;
            
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
    virtual ~Dict() {}

public:
    std::vector<std::string> getWordList() { return m_WordList; }

    // 4 DEBUG
    void printWordList() 
    {
        for (int i = 0; i < m_WordList.size(); i++) 
            std::cout << m_WordList[i] << std::endl;
    }

private:
    std::vector<std::string> m_WordList;
};

bool isInRange(std::map<int, int> m, int p, int s) 
{
    std::map<int, int>::iterator iter;

    for (iter = m.begin(); iter != m.end(); iter++) 
    {
        if (iter->first <= p) 
        {
            if (p + s <= iter->first + iter->second) 
                return true;
        }

        if (p <= iter->first) 
        {
            if (iter->first <= p + s) 
                return true;
        }
    }

    return false;
}

void solution(std::string str, std::vector<std::string> WordList) 
{
    std::map<int, int> PosLengthMap;
    std::map<int, int>::iterator PosLengthIter;
    std::string NewStr = "";
    int FindPos;
    int i;

    for (i = 0; i < WordList.size(); i++) 
    {
        FindPos = String::ToLower(str).find(WordList[i]);
        
        if (FindPos != std::string::npos) 
        {
            //if (PosLengthMap.find(FindPos) != PosLengthMap.end()) 
            //    continue;
            
            if (isInRange(PosLengthMap, FindPos, WordList[i].size())) 
                continue;
            PosLengthMap[FindPos] = WordList[i].size();
        }
    }

    for (PosLengthIter = PosLengthMap.begin(); 
         PosLengthIter != PosLengthMap.end(); PosLengthIter++) 
    {
        //std::cout << PosLengthIter->first << " " << PosLengthIter->second << std::endl;
        NewStr += str.substr(PosLengthIter->first, PosLengthIter->second) + " ";
    }

    std::cout << NewStr << std::endl;
}

int main(int argc, char* argv[]) 
{
    unsigned t0 = clock();
    // START
    //=========================================================================
    
    Dict objDict("dict.txt");
    //objDict.printWordList();
    
    std::ifstream file("gettysburg.txt");
    std::string str;
    file >> str;
    std::cout << str << std::endl;
    solution(str, objDict.getWordList());

    // END
    //=========================================================================
    unsigned elapsed = clock() - t0;
    std::cout << "elapsed " << elapsed << std::endl;

    return 0;
}
