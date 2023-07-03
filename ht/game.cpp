#include "includes&&headers.h"
int main(){
    string nick;
    int num = rand_num();
    cout << "Input your name "<< endl << ">>> ";
    cin >> nick;
    int ur_num;
    int attempts = 0;
    bool resume;
    string answ;
    while(true){
        if (resume){
        attempts = 0;
        num = rand_num(); 
        resume = 0;
        }
        cout << "Input number" << endl << ">>>";
        cin >> ur_num;
        if (ur_num > num){
            cout << "Your number is higher than guessed" << endl;
            attempts+=1;
        }
        else if(ur_num < num){
            cout << "Your number is lower than guessed" << endl;
            attempts+=1;
        }
        else{
            cout << "Congratulations, you won, you have spent" << attempts+1 << "attempts, do u want to play more?\n>>>";
            cin >> answ;
            if(answ == "y" || answ == "yes" || answ =="Y" || answ =="Yes"){
                file_write(nick, attempts);
                resume = 1;
                continue;
            }
            else{
                file_write(nick, attempts);
                break;
                return 0;
        }
    }
}
}
