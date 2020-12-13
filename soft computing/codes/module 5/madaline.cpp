#include<bits/stdc++.h>
using namespace std;

int main(){
    int x1[4] = {1,1,-1,-1}; //input 1
    int x2[4] = {1,-1,1,-1}; // input 2
    int t[4] = {-1,1,1,-1}; // output
    int z1[4] = {0,0,0,0}; //z1 input
    int z2[4] = {0,0,0,0}; //z2 input
    double w[4] = {0.05,0.1,0.2,0.2}; // w11 w12 w21 w22
    double b[2] = {0.3,0.15}; // bz1 bz2
    double v[2] = {0.5,0.5}; // vz1 vz2
    double learn_rate = 0.5;
    int fo[4] = {0,0,0,0}; //final output
    cout << "Epochs ->";
    int epoch;
    cin >> epoch;
    int count = 1;
    while(epoch--){
        cout << "Epoch "<< count<<" -->\n";
        count++;
        cout <<" X1 \t X2 \t t \t|| Zin1 \t Zin 2 \t Z1 \t Z2 \tYin \t Y ||\t W11 \t W12 \t b1 \t W21 \t W22 \t b2 \t\n";
        for(int i=0;i<4;i++){
            
            cout <<fixed << setprecision(3) << x1[i] << " \t " << setprecision(3) << x2[i] <<" \t "<< setprecision(3) << t[i] <<" \t||";
            
            double zin1 = b[0] + x1[i]*w[0] + x2[i]*w[2];
            double zin2 = b[1] + x1[i]*w[1] + x2[i]*w[3];
            if(zin1 >= 0)
                z1[i] = 1;
            else
                z1[i] = -1;
            if(zin2 >= 0)
                z2[i] = 1;
            else
                z2[i] = -1;
            double yin = 0.5;  //b0
            yin += z1[i]*v[0] + z2[i]*v[1];
            if(yin >= 0)
                fo[i] = 1;
            else
                fo[i] = -1;
            
            cout <<fixed << setprecision(3) <<zin1<<" \t "<< setprecision(3) <<zin2<<"    " << setprecision(3) <<z1[i]<<" \t " << setprecision(3) <<z2[i]<<" \t "<< setprecision(3) <<yin<<"  "<<fo[i]<<" ||\t";

            if(t[i]!=fo[i] & t[i]==1){
                if(zin1<zin2){
                    b[0]+=learn_rate*(1-zin1);
                    w[0]+=learn_rate*(1-zin1)*x1[i];
                    w[2]+=learn_rate*(1-zin1)*x2[i];
                }
                else if(zin1>zin2){
                    b[1]+=learn_rate*(1-zin2);
                    w[1]+=learn_rate*(1-zin2)*x1[i];
                    w[3]+=learn_rate*(1-zin2)*x2[i];
                }
                else{
                    b[0]+=learn_rate*(1-zin1);
                    w[0]+=learn_rate*(1-zin1)*x1[i];
                    w[2]+=learn_rate*(1-zin1)*x2[i];
                    b[1]+=learn_rate*(1-zin2);
                    w[1]+=learn_rate*(1-zin2)*x1[i];
                    w[3]+=learn_rate*(1-zin2)*x2[i];
                }
            }
            else if(t[i]!=fo[i] & t[i]==-1){
                if(zin1>=0){
                    b[0]+=learn_rate*(-1-zin1);
                    w[0]+=learn_rate*(-1-zin1)*x1[i];
                    w[2]+=learn_rate*(-1-zin1)*x2[i];
                }
                if(zin2>=0){
                    b[1]+=learn_rate*(-1-zin2);
                    w[1]+=learn_rate*(-1-zin2)*x1[i];
                    w[3]+=learn_rate*(-1-zin2)*x2[i];
                }
            }

            cout <<fixed << setprecision(3) << w[0] <<"\t" << setprecision(3) << w[1] << "\t" << setprecision(3) << b[0] <<"\t" << setprecision(3) << w[2] <<"\t" << setprecision(3) << w[3] <<"\t" << setprecision(3) << b[1]<< "\t\n";

        }
    }
}