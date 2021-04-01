//dynamically allocating 2d arrays
#include "matrix.h"
#include <iostream>

using namespace std;

Dimension::Dimension(){
    cout << "Enter number of rows and columns:\n";
    cin >> r >> c;
    a = new int *[r];
    for (int i = 0; i < r;i++){
        a[i] = new int[c];//size of row is equivalent to number of columns
    }
    for (int i = 0; i < r;i++){
        for (int j = 0; j < c;j++){
            cout << "Enter element at row"<<" "<< i+1 <<" "<<" and column"<<" " <<j+1<< ":\n";
            cin >> a[i][j];
        }
    }
}
void Dimension::product(){
    int x;
    cout << "Your matrix:"<<"\n";
    for (int e = 0; e < r;e++){
        for (int f = 0; f < c;f++){
            cout<< a[e][f]<<" ";
            if(f==(c-1)){
                cout<<endl;//indicates a row is finished
            }

        }
    }

    cout << "Enter the scalar you wish to multiply with the matrix:\n";
    cin >> x;
    cout << "After multiplication:"<<"\n";
    for (int m = 0; m < r;m++){
        for (int k = 0; k < c;k++){
            cout << (x * (a[m][k]))<<" ";
               if(k==(c-1)){
                cout<<endl;//a row is finished
            }
        }
    }
    int  choice;
    cout<<"Do you wish to multiply with another matrix?\n"<<"If you do input 1 and 2 if you don't\n";
    cin>>choice;

        switch(choice){
            case 1:
            int r1,c1;
            int **b;
            int **e;
            cout << "Enter number of rows and columns:\n";
            cin >> r1 >> c1;//second matrix b
            try{
                if(c!=r1){
                    throw(r1);
                }
            }
            catch(int v){
                cout<<"Sorry,for multiplication to be succesfull no. of columns in intial matrix should match no. of rows in second matrix\n";
                cout << "Enter number of rows and columns:\n";
                cin >> r1 >> c1;
            }
            b = new int *[r1];
                for (int i = 0; i < r1;i++){
                  b[i] = new int[c1];//size of row is equivalent to number of columns
                }
                for (int i = 0; i < r1;i++){
                    for (int j = 0; j < c1;j++){
                        cout << "Enter element at row"<<" "<< i+1 <<" "<<" and column"<<" " <<j+1<< ":\n";
                        cin >> b[i][j];
                    }
                }

            e = new int *[r];
               for (int i = 0; i < r;i++){
                  e[i] = new int[c1];//size of row is equivalent to number of columns
                }
                for (int t=0;t<r;t++){
                    for(int q=0;q<c1;q++){
                       e[t][q]=0;//intializing elements of resultant matrix to zero
                    }
                }
                for(int i=0;i<r;i++){//no. of rows of resultant matrix equal that of first matrix
                    for(int j=0;j<c1;j++){//no. of columns of resultant matrix equal that of second matrix
                        for(int k=0;k<c;k++){//product is (r*c1)
                            e[i][j]+=(a[i][k]*b[k][j]);
                        }
                    }
                }
                cout << "After multiplication:"<<"\n";
                  for (int m = 0; m < r;m++){
                    for(int k=0;k<c1;k++){
                        cout<< e[m][k]<<" ";
                           if(k==(c1-1)){
                            cout<<endl;//indicates a row is finished
                          }
                    }
                }


               for (int y = 0; y < r1;y++){
               delete[] b[y];//deallocate the rows
               }
               delete[] b;

               for (int z=0;z<r;z++){
                   delete[] e[z];
               }
               delete[] e;

               break;

                case 2:
                cout<<"No operation will be performed\n";
                break;
                default:
                cout<<"Unrecognized input!!\n";
                break;
            }

}

Dimension::~Dimension(){
    for (int y = 0; y < r;y++){
        delete[] a[y];//deallocate the rows
    }
    delete[] a;
}

