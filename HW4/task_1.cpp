// TASK IS DONE

#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

void island(vector<vector<int>> &island_map, int& x, int& y){ 
    if (island_map[x][y] == 1){
        island_map[x][y]++;
        return;
    }
}

int main()
{
    bool same_island = 0;
    int cnt = 0;

    int x,y;

    int W;
    int H;

    cout << "Weigh: " << endl;
    cin >> W;
    W += 2;
    cout << "Height: " << endl;
    cin >> H;
    H += 2;

    string s;

    vector<vector<int>> island_map;
    vector<int> island_raw;

    // Заполнение матрицы значениями и добавление нулей по краям
    for (int i = 0; i < H; i++){
        if (i == 0 || i == H-1){
            for(int j = 0; j < W; j++){
                island_raw.push_back(0);
            }
        island_map.push_back(island_raw);
        island_raw.clear();
        } else{
            island_raw.push_back(0);
            cin >> s;
            for(int j = 0; j < W-2; j++){
                island_raw.push_back(s[j] - 48);
            }
            island_raw.push_back(0);
            island_map.push_back(island_raw);
            island_raw.clear();
        }
    }

    for (int i = 1; i < H - 1; i++){
        for(int j = 1; j < W - 1; j++){
            if (((island_map[i-1][j] == 1 || island_map[i+1][j] == 1) ||
                (island_map[i][j-1] == 1 || island_map[i][j+1] == 1)) &&
                (island_map[i][j] == 1)){
                    // same_island = 1;
                    island(island_map, i ,j);
            } else if (island_map[i][j] == 1) {
                cnt++;
                island(island_map, i, j);
            }
        }
    }

    cout << cnt << endl;

    // for (int i = 0; i < H; i++){
    //     for(int j = 0; j < W; j++){
    //         cout << island_map[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
}