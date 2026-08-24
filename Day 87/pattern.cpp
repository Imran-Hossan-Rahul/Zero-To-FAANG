#include <iostream>
using namespace std;

/*

* * * * * 
  * * * * 
    * * * 
      * * 
        * 

int main(){
    
int n;
cin >> n;

for(int i = 0; i < n; i++){
    if(i > 0){
        for(int j = 0; j < i; j++){
            cout << "  ";
        }
    }
    
    for(int j = 0; j < n - i; j++){
        cout << "* ";
    }
    
    cout << endl;
}

return 0;
}


*****
 ****
  ***
   **
    *

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        if(i > 0){
            for(int j = 0; j < i; j++){
                cout << " ";
            }
        }

        for(int j = 0; j < n - i; j++){
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}


1 1 1 1 1 
2 2 2 2 
3 3 3 
4 4 
5 


int main(){
    
int count = 1;
int n;
cin >> n;

for(int i = 0; i < n; i++){
    
if(i > 0){
    for(int j = 0; j < i; j++){
        cout << "  ";
    }
}

for(int  j = 0; j < n - i; j++){
    cout << count << " ";
}

cout << endl;
count++;
}

return 0;
}



              1 
            1 2 3 
          1 2 3 4 5 
        1 2 3 4 5 6 7 
      1 2 3 4 5 6 7 8 9 
    1 2 3 4 5 6 7 8 9 10 11 
  1 2 3 4 5 6 7 8 9 10 11 12 13 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int count = 1;
        if(i <= n - 1){
            for(int j = 0; j < n - i - 1; j++){
                cout << "  ";
            }
        }

        for(int j = 0; j < (i * 2) + 1; j++){
            cout << count << " ";
            count++;
        }

        cout << endl;
    }

    return 0;
}


        1 
      1 2 1 
    1 2 3 1 2 
  1 2 3 4 1 2 3 
1 2 3 4 5 1 2 3 4 

int main (){
    
int n;
cin >> n;
int count = 1;

for(int i = 0; i < n; i++){
    
if(i < n - 1){
    for(int j = 0; j < n - i - 1 ; j++){
        cout << "  ";
    }
}

for(int j = 0; j <= i; j++){
    cout << j + 1 << " ";
}

for(int j = 0; j < i; j++){
    cout << j + 1 << " ";
}

cout << endl;
}

return 0;
}



        1 
      2 2 1 
    3 3 3 2 1 
  4 4 4 4 3 2 1 
5 5 5 5 5 4 3 2 1 


int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        if(i < n - 1){
            for(int j = 0; j < n - 1 - i; j++){
                cout << "  ";
            }
        }

        for(int j = 0; j <= i; j++){
            cout << i + 1 << " ";
        }

        for(int j = 0; j < i; j++){
            cout << i - j << " ";
        }

        cout << endl;
    }

    return 0;
}




*/

