class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int sma = stoi(arriveAlice.substr(0, 2)),
            lma = stoi(leaveAlice.substr(0, 2)),
            sda = stoi(arriveAlice.substr(3, 2)),
            lda = stoi(leaveAlice.substr(3, 2));
        int smb = stoi(arriveBob.substr(0, 2)),
            lmb = stoi(leaveBob.substr(0, 2)),
            sdb = stoi(arriveBob.substr(3, 2)),
            ldb = stoi(leaveBob.substr(3, 2));
        cout << sma << " " << sda << " " << lma << " " << lda << " " << smb
             << " " << sdb << " " << lmb << " " << ldb << " ";
        int sm, sd, em, ed;
        if (sma == smb)
            sm = sma, sd = max(sda, sdb);
        else if (sma < smb)
            sm = smb, sd = sdb;
        else
            sm = sma, sd = sda;
        if (lma == lmb)
            em = lma, ed = min(lda, ldb);
        else if (lma < lmb)
            em = lma, ed = lda;
        else
            em = lmb, ed = ldb;
        if (sm > em)
            return 0;
        if (sm == em)
            return max(0, ed - sd + 1);
        int ans = ed;
        if (sm == 1 || sm == 3 || sm == 5 || sm == 7 || sm == 8 || sm == 10 ||
            sm == 12)
            ans += 32 - sd;
        else if (sm == 4 || sm == 6 || sm == 9 || sm == 11)
            ans += 31 - sd;
        else
            ans += 29 - sd;
        for (int i = sm + 1; i < em; i++)
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 ||
                i == 12)
                ans += 31;
            else if (i == 4 || i == 6 || i == 9 || i == 11)
                ans += 30;
            else
                ans += 28;
        return ans;
    }
};