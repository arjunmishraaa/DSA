class Solution {
public:
    void sortColors(vector<int>& v) {
        int a=0,b=0,c=0;
         
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0) a++;
            else if (v[i] == 1) b++;
            else if (v[i] == 2) c++;
        }

        for (int i = 0; i < a; i++) {
            v[i] = 0;
        }

        for (int i = a; i < a + b; i++) {
            v[i] = 1;
        }

        for (int i = a + b; i < a + b + c; i++) {
            v[i] = 2;
        }

    }
};