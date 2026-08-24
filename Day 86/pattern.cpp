#include <iostream>
using namespace std;

/*

1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}



* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * *

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int i=0; i<n; i++){
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}


A B C D E 
A B C D E 
A B C D E 
A B C D E 
A B C D E

int main(){
    
int n;
cin >> n;
    
for(int i=0; i<n; i++){
    char c = 'A';
    for(int i=0; i<n; i++){
        cout << c << " ";
        c++;
    }

    cout << endl;
}

return 0;
}



1 2 3 
4 5 6 
7 8 9 

int main(){
    
int n;
cin >> n;
int count = 1;
for(int i=0; i<n; i++){
    
for(int j=0; j<n; j++){
    cout << count << " ";
    count++;
}

cout << endl;
}

return 0;
}



* 
* * 
* * * 
* * * * 
* * * * * 

int main(){

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}




1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 


int main(){

    int n;
    int count = 1;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << count << " ";
        }
        count++;
        cout << endl;
    }

    return 0;
}


1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 

int main(){
    
int n;
cin >> n;

for(int i=0; i<n; i++){
    int count = 1;
    for(int j=0; j<=i; j++){
        cout << count << " ";
        count++;
    }
    
    cout << endl;
}

return 0;
}


1 
2 1 
3 2 1 
4 3 2 1 
5 4 3 2 1 

int main(){
    
int n; int count = 1;
cin >> n;

for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
        cout << count - j << " ";
    }
    
    cout << endl;
    count++;
}

return 0;
}


*/