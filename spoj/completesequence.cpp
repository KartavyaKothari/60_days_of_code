#include <bits/stdc++.h>
using namespace std;

class TestCase{
    public:
    int c;
    vector<int> series;

    TestCase(int n){
        series.reserve(100);
        c=n;
    }
};

vector<TestCase> handleInput(){
    int n;
    cin>>n;
    vector<TestCase> testcases;
    testcases.reserve(n);
    // TestCase testcase(n);

    for(int i = 0 ; i < n ; i++){
        int num;
        int s,c;
        cin>>s>>c;

        TestCase testcase(c);
        
        while(s--){
            cin>>num;
            testcase.series.push_back(num);
        }

        testcases.push_back(testcase);
    }

    return testcases;
}

void print(vector<int> vec){
    for(auto i : vec){
        cout<<i<<" ";
    }cout<<endl;
};

void printMatrix(vector<vector<int>> mat){
    cout<<"*****"<<endl;
    for(auto row: mat){
        print(row);
    }cout<<endl;
    cout<<"*****"<<endl;
}

bool isSeriesConstant(vector<int> series){
    int prev_ele = series[0];
    for(auto ele : series){
        if(prev_ele!=ele) return false;
    }
    return true;
}

vector<int> findDifference(vector<int> series){
    vector<int> diff;
    diff.reserve(series.size());

    for(int i = 1 ; i < series.size() ; i++){
        diff.push_back(series[i]-series[i-1]);
    }

    return diff;
}

vector< vector<int>> fillDifferenceMatrix(vector<int> series){
    vector< vector<int>> differenceMatrix;
    differenceMatrix.push_back(series);

    while(!isSeriesConstant(differenceMatrix.back())){
        differenceMatrix.push_back(findDifference(differenceMatrix.back()));
    }

    return differenceMatrix;
}

vector< vector<int>> predict_next(vector< vector<int>> diffMatrix){
    int prev = diffMatrix.back().back();
    for(auto row = diffMatrix.rbegin() ; row != diffMatrix.rend() - 1; row++){
        (*row).push_back(prev);
        prev = prev+(*(row+1)).back();
    }
    diffMatrix[0].push_back(prev);

    return diffMatrix;
}

void solve(TestCase testcase){
    int n_calc = testcase.c;
    vector<int> series = testcase.series;
    // print(series);

    vector< vector<int>> differenceMatrix = fillDifferenceMatrix(series);
    for(int i = 0 ; i < n_calc ; i++){
        differenceMatrix = predict_next(differenceMatrix);
        cout<<differenceMatrix[0].back()<<" ";
    }

    // printMatrix(differenceMatrix);
    // cout<<n_calc;

}

int main(int argc, char const *argv[])
{
    vector<TestCase> testcases;

    testcases = handleInput();

    for(auto testcase: testcases){
        solve(testcase);
        cout<<endl;
    }

    return 0;
}
