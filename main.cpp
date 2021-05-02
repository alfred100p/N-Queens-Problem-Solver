#include <iostream>
#include<vector>

using namespace std;
int qcount=0;
int printq(int n,vector<int>V,int p) {
    qcount+=1;
    if(p==1) {
        cout << '\n';

        for (int i = 0; i < n; i++) {
            cout << string(V[i], '0') << 'Q' << string(n - V[i] - 1, '0') << "\n";
        }
    }

    return 0;

}

int nqp2(int ix, int n,vector<int>V,vector<int>N,int p){
    if(ix==n)
        printq(n,V,p);
    else{
        for(int i=0;i<n;i++){
            if(N[i]==n)//here this prevents queens being in same column
                continue;
            else{
                int j=0;
                for(;j<ix;j++) {
                    if (abs(j - ix) == abs(V[j] - i))//prevents queens in same diagonal
                        break;
                }
                        if(j==ix) {
                            N[i] = n;
                            V[ix] = i;
                            nqp2(ix + 1, n, V, N,p);
                            N[i] = i;
                        }

                }
            }
        }


    return 0;
}

int main(){
    int n;//no of queens
    cout<<"Enter the Number of Queens:\n";
    cin>>n;
    int p;//whether to show all arrangements
    cout<<"Enter 1 if you want to print all arrangements else enter 0:\n";
    cin>>p;
    vector<int> V(n,-1);//Vector storing all assigned column values in an iteration
    //if V[i]=j means ith row queen is at jth column if unassigned value is -1 by default
    vector<int> N(n);//Vector showing all unassigned column values
    //N[i] can either be i or n, if N[i]=i means ith column has no queen, if N[i]=n means a queen has occupied the column
    for(int i=0;i<n;i++)
        N[i]=i;
    for(int i=0;i<n;i++){//assigning all possible values to first value
        V[0]=i;
        N[i]=n;
        nqp2(1,n,V,N,p);
        N[i]=i;
    }

    cout<<"\n"<<qcount<<" possible arrangement(s)";
    qcount=0;
    char c;
    cout<<"\nType Enter to quit";
    cin>>c;



    return 0;
}

