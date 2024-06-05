#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class SnapshotArray {
private:
    unordered_map<int , vector<pair<int , int>>> photos;
    int snaps = 0;
public:
    SnapshotArray(int length) {
        // for (int i = 0; i < length; i++) {
        //     photos[i].emplace_back(0,0);
        // }
    }

    void set(int index , int val) {
        photos[index].emplace_back(snaps , val);
    }

    int snap() {
        return snaps++;
    }

    int get(int index , int snap_id) {
        vector<pair<int,int>>& photo = photos[index];
        int end = photo.size();
        // for (int i = len; i >= 0; i--) {
        //     if (photo[i].first <= snap_id)
        //         return photo[i].second;
        // }
        int begin = 0 , mid = (begin + end) / 2;
        while (begin<=end) {
            mid = (begin + end) / 2;
            if (photo[mid].first < snap_id) {
                begin = mid+1;
            }
            else
                end = mid-1;
        }
        while (mid+1<photo.size()&&photo[mid].first == photo[mid + 1].first)
            mid++;
        return photo[mid].second;
    }
};
//["SnapshotArray","set","snap","set","get"]
//[[3],[0,5],[],[0,6],[0,0]]
//[null,null,0,null,5]
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
int main() {
    // SnapshotArray *snapshotArr=new SnapshotArray(3);
    // snapshotArr->set(0 , 5);
    // cout<<snapshotArr->snap();
    // snapshotArr->set(0 , 6);
    // cout<<snapshotArr->get(0 , 0);
    SnapshotArray* snapshotARR = new SnapshotArray(1);
    snapshotARR->set(0 , 15);
    cout << snapshotARR->snap();
    cout << snapshotARR->snap();
    cout << snapshotARR->snap();
    cout << snapshotARR->get(0 , 2);
    cout << snapshotARR->snap();
    cout << snapshotARR->snap();
    cout << snapshotARR->get(0 , 0);

    // vector<vector<int>> Test;
    // Test.emplace_back(vector<int>{1 , 2 , 3});
    // Test.push_back({ 4,5,6 });
    // vector<int> a = { 7,8,9 };
    // vector<int> b = { 9,10,11 };
    // Test.emplace_back(a);
    // Test.push_back(b);
}