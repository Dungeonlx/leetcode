#include <iostream>
#include <fstream>
#include <algorithm>

std::string m_preProcess(std::string s) 
{
    int n = s.length();
    if (n == 0) return "^$";
    std::string ret = "^";
    for (int i = 0; i < n; i++)
        ret += "#" + s.substr(i, 1);
 
    ret += "#$";
    return ret;
}
 
std::string Manacher(std::string s) 
{
    std::string T = m_preProcess(s);
    std::cout << "PreProcessed: " << T << std::endl;
    int n = T.length();
    int* P = new int[n];
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) 
    {
        int i_mirror = 2 * C - i; // equals to i' = C - (i - C)
    
        P[i] = (R > i) ? std::min(R-i, P[i_mirror]) : 0;
    
        // Attempt to expand palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;
 
        // If palindrome centered at i expand past R,
        // adjust center based on expanded palindrome.
        if (i + P[i] > R) 
        {
            C = i;
            R = i + P[i];
        }
    }
 
    // Find the maximum element in P.
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) 
    {
        if (P[i] > maxLen) 
        {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    delete[] P;
  
    return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}

int main(int argc, char* argv[]) 
{
    std::ifstream file("gettysburg.txt");
    std::string ori_str;
    std::string longest_parlin_str;
    std::string color_str;
    int find_pos = 0;

    file >> ori_str;
    longest_parlin_str = Manacher(ori_str);
    find_pos = ori_str.find(longest_parlin_str);

    color_str = ori_str.substr(0, find_pos) + "\033[33m" + longest_parlin_str 
        + "\033[0m" + ori_str.substr(find_pos + longest_parlin_str.size(), 
                ori_str.size() - find_pos - longest_parlin_str.size());

    std::cout << color_str << std::endl;

    return 0;
}
