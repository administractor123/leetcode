#include "../head/leetCode.h"
#include <iostream>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.find(endWord) == wordSet.end())
            return 0;
        
        queue<pair<string, int>> roadQ;
        roadQ.push({beginWord, 1});

        unordered_set<string> wordVisited;
        wordVisited.insert(beginWord);

        while (!roadQ.empty())
        {
            auto [currentWord, level] = roadQ.front();
            roadQ.pop();

            for(int i = 0; i < currentWord.size(); ++i)
            {
                string wordTemp = currentWord;
                for(char c = 'a'; c <= 'z'; ++c)
                {
                    if(wordTemp[i] == c) continue;

                    wordTemp[i] = c;
                    if(wordTemp == endWord)
                        return level + 1;
                    
                    if(wordSet.find(wordTemp) != wordSet.end() 
                       && wordVisited.find(wordTemp) == wordVisited.end())
                    {
                        roadQ.push({wordTemp, level + 1});
                        wordVisited.insert(wordTemp);
                    }
                }
            }
        }
        
        return 0;
    }
};

int main(int argc, char* argv[])
{
    vector<string> wordList {"hot", "dog"};
    Solution s1;
    cout<< s1.ladderLength("hot", "dog", wordList) <<endl;

    return 0;
}