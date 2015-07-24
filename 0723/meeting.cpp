#include<iostream>
using namespace std;
struct m_time {
    int start;
    int end;
};
int meeting[1001];
m_time data[1001];
int main() {
    int num;
    int max;
    cin>>num;

    for(int i=0; i<num; i++) {
        cin>>data[i].start>>data[i].end;
        meeting[i] = 1;
    }

    for(int i=0; i<num; i++) {
        for(int j = i; j<num; j++) {
            if(data[i].end <= data[j].start) {
                if(meeting[i]+1 > meeting[j]) {
                    meeting[j] = meeting[i]+1;
                }
            }
        }
    }

    max = meeting[0];
    for(int i=0; i<num; i++) {
        if(max < meeting[i])
            max = meeting[i];
    }
    
    cout<<max<<endl;

    return 0;
}
