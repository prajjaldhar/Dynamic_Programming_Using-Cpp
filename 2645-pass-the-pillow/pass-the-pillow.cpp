class Solution {
public:
    int passThePillow(int n, int time) {
    int me = 1;
    int dir = 1;
    while(time--)
    {
        me = me + dir;

        if(me == n)
            dir = -1;

        else if(me == 1)
            dir = 1;
    }

    return me;
        }
};