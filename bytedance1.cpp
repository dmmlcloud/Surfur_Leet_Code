# include <iostream>
# include <cstdio>
# include <string>
# include <map>
using namespace std;
int main(void) 
{
    map<char , int> umap;
    int front = 0;
    int back = 0;
    string s;
    cin >> s;
    int max = 0;
    for(front = back;front<s.length();front++)
    {
        if(umap.find(s[front]) != umap.end() && umap[s[front]]!=-1)
        {
            int temp = umap[s[front]]+1;
            for(int i = back; i<umap[s[front]]+1; i++)
            {
                umap[s[i]] = -1;
            }
            if(front - back > max) max = front - back;
            back = temp;
            front--;
        }
        else
        {
            umap[s[front]] = front;
            if(front - back+1  > max) max = front - back+1;
        }
    }
    cout << max;
    return 0;
}