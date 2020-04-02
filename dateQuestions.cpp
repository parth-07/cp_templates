#include <bits/stdc++.h>
#define show(x) cout << #x " = " << x << endl;
#define show2(x, y) cout << #x " = " << x << " " << #y << " = " << y << endl;
#define all(x) x.begin(), x.end()
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> iipair;
typedef pair<unsigned, unsigned> uupair;
typedef vector<int> vec;
typedef vector<unsigned> uvec;

const unsigned MONTH_LIMIT = 12;
const unsigned DAYS_IN_A_YEAR = 365;
const unsigned CYCLE = 400;
const uvec MONTH = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
enum Day
{
    MON,
    TUES,
    WED,
    THURS,
    FRI,
    SAT,
    SUN,
    DAY_MAX
};

bool isLeapYear(ull year)
{
    return ((year % 100 && year % 4 == 0) || (year % 400 == 0));
}
ull leapYearCount(ull ly, ull ry)
{
    ull res = 0;
    for (ull i = ly; i <= ry; ++i)
    {
        if ((i % 100 && i % 4 == 0) || (i % 400 == 0))
        {
            ++res;
            cout << i << " ";
        }
    }
    cout << endl;
    return res;
}
ull leapYearCount(ull year)
{
    ull res = year / 4;
    res -= year / 100;
    res += year / 400;
    return res;
}

unsigned getFirstDay(ull month, ull year)
{
    ull days = (year - 1) + leapYearCount(year - 1) + MON;
    if (isLeapYear(year) && month > 2)
        ++days;
    for (unsigned i = 1; i < month; ++i)
        days += MONTH[i];
    return days % DAY_MAX;
}

uupair getContestDates(ull month, ull year)
{
    unsigned startDay = getFirstDay(month, year);
    unsigned lastSun = (SUN - startDay + DAY_MAX) % DAY_MAX + 1;
    // show(lastSun);
    lastSun += DAY_MAX * ((MONTH[month] - lastSun) / DAY_MAX);
    // show(lastSun);
    return uupair((FRI - startDay + DAY_MAX) % DAY_MAX + 1, lastSun - DAY_MAX);
}

ll collisionCount(ll ly, ll ry)
{
    if(ry<ly) return 0;
    ull res = 0;
    for (ull i = ly; i <= ry; ++i)
    {
        for (unsigned j = 1; j <= 12; ++j)
        {
            uupair dates = getContestDates(j, i);
            res += (dates.second >= dates.first && dates.second < (dates.first + 10));
        }
    }
    return res;
}

ll collisionCount(ll year,ll lm,ll rm)
{
    ll res=0;
    for(ll i=lm;i<=rm;++i)
    {
        uupair dates = getContestDates(i, year);
        res += (dates.second >= dates.first && dates.second < (dates.first + 10));
    }
    return res;
}

ll collisionCount(ll ly,ll lm,ll ry,ll rm)
{
    if(ry<ly) return 0;
    ll res=0;
    if(ly == ry)
    {
        res+=collisionCount(ly,lm,rm);
    }
    else
    {
        res+=collisionCount(ly,lm,12);
        res+=collisionCount(ry,1,rm);
    }
    if(ry-ly > 1)   res+=collisionCount(ly+1,ry-1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ull month, year;
    /* cin>>month>>year;
    uupair dates=getContestDates(month,year);
    cout<<"Long Challenge = "<<dates.first<<endl;
    cout<<"Cook Off = "<<dates.second; */
    ull res_cycle = collisionCount(1, CYCLE);
    ull ly, ry, lm, rm;
    unsigned t;
    cin >> t;
    ull res;
    while (t--)
    {
        res=0;
        cin >> lm >> ly;
        cin >> rm >> ry;
        ll l_cycle,r_cycle;
        l_cycle=r_cycle=-1;
        if(ry - ly > 500)
        {
            l_cycle=ceil((ly+1)*1.0/CYCLE)*CYCLE,r_cycle=((ry-1)/CYCLE)*CYCLE;
            res+=collisionCount(ly,lm,l_cycle-1,12);
            res+=collisionCount(r_cycle+1,1,ry,rm);
            res+=((r_cycle-l_cycle)/CYCLE) * res_cycle;
        }
        else res+=collisionCount(ly,lm,ry,rm);
        cout<<res<<"\n"; 
    }
}
