#include <string>
#include <vector>
#include <map>
#include <stack>
#include <iostream>
#define MP make_pair
using namespace std;

string e_msg(string nickname)
{
    return (nickname + "님이 들어왔습니다.");
}
string l_msg(string nickname)
{
    return (nickname += "님이 나갔습니다.");
}
string ret_id(string str, int start)
{
    int i = start;
    int end = str.size();
    string id;
    while (i < end)
    {
        if (str[i] == ' ')
            break;
        id += str[i];
        i++;
    }
    return id;
}

string ret_nick(string str)
{
    stack<char> st;
    int i = str.size() - 1;
    while (str[i] != ' ')
    {
        st.push(str[i]);
        i--;
    }
    string nick;
    while (!st.empty())
    {
        nick += st.top();
        st.pop();
    }
    return nick;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> mp;
    int N = record.size();
    vector<pair<string, int> > content; //id, (0,1) -> enter, leave
    for (int i = 0; i < N; i++)
    {
        string rec = record[i];
        if (rec.substr(0, 5) == "Enter")
        {
            string id = ret_id(rec, 6);
            string nick = ret_nick(rec);
            if (mp.find(id) == mp.end())
                mp.insert(MP(id, nick));
            else
                mp[id] = nick;
            content.push_back(MP(id, 0));
        }
        else if (rec.substr(0, 5) == "Leave")
        {
            string id = ret_id(rec, 6);
            content.push_back(MP(id, 1));
        }
        else if (rec.substr(0, 6) == "Change")
        {
            
            string id = ret_id(rec, 7);
            string nick = ret_nick(rec);
            mp[id] = nick;
        }
    }
    N = content.size();
    for (int i = 0; i < N; i++)
    {
        string id = content[i].first;
        int act = content[i].second;
        if (act == 0)
        {
            answer.push_back(e_msg(mp[id]));
        }
        else
            answer.push_back(l_msg(mp[id]));
    }
    return answer;
}