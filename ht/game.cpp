#include "includes.h"
int main(){
    string nick, answ;
    uint64_t num = rand_num();
    cout << "Input your nickname "<< endl << ">>> "; cin >> nick;
    int ur_num =0; 
    uint64_t attempts = 1;
    bool resume = 0;
    do{
        if (resume){
        attempts = 0;
        num = rand_num(); 
        resume = 0;
        }
        vector<player> data;
        data.reserve(15);
        file_read(data);
        cout << "Input number" << endl << ">>>";
        cin >> ur_num;
        if (ur_num > num){
            cout << "Your number is greater than guessed" << endl;
            attempts++;
        }
        else if(ur_num < num){
            cout << "Your number is lower than guessed" << endl;
            attempts++;
        }
        else{
            cout << "Congratulations, you won, you have spent" << attempts << "attempts, do u want to play more?\n>>>";
            cin >> answ;
            if(answ == "y" || answ == "yes" || answ =="Y" || answ =="Yes"){
                file_write(data);
                data[1].show(data);
                resume = true;
            }
            else{
                file_write(data);
                data[1].show(data);
                break;
                
            }
        }
    }while(resume);
return 0;
}
