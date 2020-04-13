#include <bits/stdc++.h>
using namespace std;

struct POINT{
    int x;
    int y;
    int z;

    // POINT(int x, int y, int z):x(x),y(y),z(z){};
};

void printBulk(vector<vector<POINT>> bulk){
    for(auto face : bulk){
        for(auto point : face){
            cout<<point.x<<" "<<point.y<<"  ";
        }
        cout<<endl;
    }
}

auto handleInput(){
    int n_of_bulks;
    cin>>n_of_bulks;

    vector<vector<vector<POINT>>> bulks(n_of_bulks);

    for(int i = 0 ; i < n_of_bulks ; i++){
        int n_of_faces;
        cin>>n_of_faces;
        vector<vector<POINT>> bulk(n_of_faces);

        for(int j = 0 ; j < n_of_faces ; j++){
            int n_of_points;
            cin>>n_of_points;
            vector<POINT> face(n_of_points);

            for(int k = 0 ; k < n_of_points ; k++){
                int x,y,z;
                cin>>x>>y>>z;
                POINT point = {x,y,z};
                face[k] = point;
            }
            bulk[j] = face;
        }

        bulks[i] = bulk;
    }

    return bulks;
}

bool sortByZ(vector<POINT> one, vector <POINT> two){
    return one[0].z<two[0].z?true:false;
}

bool isParallel(vector < POINT> face){
    POINT prev = face[0];

    for(auto point : face){
        if(prev.z==point.z){
            prev = point;
            continue;
        }
        return true;
    }

    return false;
}

vector<POINT> removeColinear(vector<POINT> face){
    vector<POINT> trimmedFaceX;
    trimmedFaceX.reserve(face.size());
    // cout<<"**"<<trimmedFace.size()<<"**"<<endl;
    for(int i = 0 ; i < face.size() ; i++){
        int j = i;
        for(; j < face.size() ; j++){
            if(face[j].x!=face[i].x)break;
        }
        trimmedFaceX.push_back(face[i]);
        if(i<j-1) trimmedFaceX.push_back(face[j-1]);
        i = j-1;
    }

    vector<POINT> trimmedFaceY;
    trimmedFaceY.reserve(trimmedFaceX.size());
    // cout<<"**"<<trimmedFace.size()<<"**"<<endl;
    for(int i = 0 ; i < trimmedFaceX.size() ; i++){
        int j = i;
        for(; j < trimmedFaceX.size() ; j++){
            if(trimmedFaceX[j].y!=trimmedFaceX[i].y)break;
        }
        trimmedFaceY.push_back(trimmedFaceX[i]);
        if(i<j-1) trimmedFaceY.push_back(trimmedFaceX[j-1]);
        i = j-1;
    }
    // cout<<"**"<<trimmedFace.size()<<"**"<<endl;
    // return face;
    return trimmedFaceY;
}

bool isEmpty(vector<POINT> vec){
    return vec.empty();
}

int area(vector<POINT> face){
    int sum = 0;
    face.push_back(face[0]);
    for(auto i = face.begin() ; i != face.end() - 1 ; i++){
        sum = sum + (*i).x*(*(i+1)).y-(*i).y*(*(i+1)).x;
    }

    return sum/2;
}

void solve(vector <vector < POINT>> bulk){
    int n_of_units = 0 ;

    //remove all faces which are non perpendicular to z
    bulk.erase(remove_if(bulk.begin(),bulk.end(),isParallel),bulk.end());

    // Remove all unessasary points (colinear)
    transform(bulk.begin(),bulk.end(),bulk.begin(),removeColinear);
    bulk.erase(remove_if(bulk.begin(),bulk.end(),isEmpty),bulk.end());

    //sort all faces by height
    if(!bulk.empty()){
        sort(bulk.begin(),bulk.end(),sortByZ);
    } else cout<<"Empty";

    printBulk(bulk);
    //assign positive/negetive volume sign to each face

    cout<<"The bulk is composed of "<<n_of_units<<" units."<<endl;
}

int main(int argc, char const *argv[])
{
    vector<vector<vector<POINT>>> bulks;

    bulks = handleInput();
    
    for(auto bulk : bulks){
        solve(bulk);
    }

    // printBulk(bulks);

    return 0;
}