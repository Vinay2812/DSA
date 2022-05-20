/*
link ->https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=0
Ninja is planing this ‘N’ days-long training schedule.
Each day, he can perform any one of these three activities.
(Running, Fighting Practice or Learning New Moves).
Each activity has some merit points on each day. As Ninja has to improve all his skills,
he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity.
Your task is to calculate the maximum number of merit points that Ninja can earn.

i/p->
3
1 2 5
3 1 1
3 3 3

o/p->
11

Recursion -> tc-> O(2^n) sc->O(n)
Memoization -> tc-> O(n*3*3) sc-> O(n) + O(3n)
Tabulation -> tc -> O(n*3*3) sc-> O(3n)
Space optimization -> tc -> O(n*3*3) sc-> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int f(int day, int prev_task, vector<vector<int>> &points, vector<vector<int>>& dp)
{
    if(day == 0){
        int maxi = -1e9;
        for (int task = 0; task < 3; task++){
            if (task != prev_task){
                int store = points[day][task];
                maxi = max(maxi, store);
            }
        }
        return maxi;
    }
    
    if(dp[day][prev_task] != -1)
        return dp[day][prev_task];

    int maxi = -1e9;
    for(int task=0;task<3;task++){
        if(task != prev_task){
            int store = points[day][task] + f(day-1, task, points, dp);
            maxi = max(maxi, store);
        }
    }

    return dp[day][prev_task] = maxi;

}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    //memoization
    // int maxi = -1e9;
    // vector<vector<int>> dp(n, vector<int>(3, -1));
    // for(int task=0;task<3;task++){
    //     int point = f(n-1, task, points, dp);
    //     maxi = max(point, maxi);
    // }
    // return maxi;

    //tabulation
    // vector<vector<int>> dp(n, vector<int>(3, 0));

    // for(int prev_task=0;prev_task<3;prev_task++){
    //     int maxi = -1e9;
    //     for (int task = 0; task < 3; task++){
    //         if (task != prev_task){
    //             int store = points[0][task];
    //             maxi = max(maxi, store);
    //         }
    //     } 
    //     dp[0][prev_task] = maxi;
    // }
    

    // for(int day=1;day<n;day++){
    //     for(int prev_task=0;prev_task<3;prev_task++){
    //         int maxi = -1e9;
    //         for (int task = 0; task < 3; task++)
    //         {
    //             if (task != prev_task)
    //             {
    //                 int store = points[day][task] + dp[day-1][task];
    //                 maxi = max(store, maxi);
    //             }
    //         }
    //         dp[day][prev_task] = maxi;
    //     }
    // }

    // int maxi = -1e9;
    // for (int task = 0; task < 3; task++)
    // {
    //     int point = dp[n-1][task];
    //     maxi = max(point, maxi);
    // }
    // return maxi;

    //space optimization
    vector<int> prev(3, 0), curr(3, 0);

    for(int prev_task=0;prev_task<3;prev_task++){
        int maxi = -1e9;
        for (int task = 0; task < 3; task++){
            if (task != prev_task){
                int store = points[0][task];
                maxi = max(maxi, store);
            }
        }
        prev[prev_task] = maxi;
    }

    for(int day=1;day<n;day++){
        for(int prev_task=0;prev_task<3;prev_task++){
            int maxi = -1e9;
            for (int task = 0; task < 3; task++)
            {
                if (task != prev_task)
                {
                    int store = points[day][task] + prev[task];
                    maxi = max(store, maxi);
                }
            }
            curr[prev_task] = maxi;
        }
        prev = curr;
    }

    int maxi = -1e9;
    for (int task = 0; task < 3; task++)
    {
        int point = prev[task];
        maxi = max(point, maxi);
    }
    return maxi;
}

int main()
{
    int n;cin>>n;
    vector<vector<int>> points(n,vector<int>(3));

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>points[i][j];
        }
    }

    cout<<ninjaTraining(n, points);
    return 0;
}
