#include <cstdio>
#include <stack>

#define NMAX 100005

using namespace std;

FILE *in, *out;

int n, v[NMAX], left[NMAX], right[NMAX], frecv[NMAX];
long long rez;
stack<int> st;

int main() {
    in = fopen("leftmax.in", "r");
    fscanf(in, "%d", &n);
    v[0] = n+1;
    v[n+1] = n+1;

    for(int i = 1; i <= n; ++i) {
        fscanf(in, "%d", &v[i]);
        ++frecv[v[i]];
    }
    fclose(in);

    st.push(0);
    for(int i = 1; i <= n; ++i) {
        while(v[st.top()] < v[i])
            st.pop();

        left[i] = i - st.top() - 1;
        st.push(i);
    }

    while(!st.empty())
        st.pop();

    st.push(n+1);
    for(int i = n; i >= 1; --i) {
        while(v[st.top()] < v[i])
            st.pop();
        
        right[i] = st.top() - i - 1;
        st.push(i);
    }

    for(int i = 1; i <= n; ++i) {
        if(right[i] <= left[i]) {
            rez += (right[i]+1) * (right[i]+2) / 2;
            continue;
        }
        rez += ((right[i]+1) * (right[i]+2) / 2) - ((right[i]-left[i]) * (right[i]-left[i]+1) / 2);
    }

    out = fopen("leftmax.out", "w");
    rez %= 1000000007;
    fprintf(out, "%lld", rez);
    fclose(out);
    return 0;
}