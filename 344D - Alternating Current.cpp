#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    char input[100010];

    scanf("%s", input);

    vector<char> st;

    int len = strlen(input);
    for(int i=0; i<len; i++)
    {
        if(st.size() == 0)
            st.push_back(input[i]);
        else
        {
            if(st[st.size()-1] == input[i])
                st.pop_back();
            else
                st.push_back(input[i]);
        }
    }

    if(st.size() == 0)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
