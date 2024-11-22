/* 
    File: Multi Purpose Utility Program
    Purpose: 
        Removing extra spaces between words in input texts.
        Printing all prime numbers up to a certain number entered by the user.
        Checking whether it is possible to arrange domino pieces so that the right side of each piece matches the left side of the next one.
        Modifying text messages to make them socially acceptable by replacing inappropriate words or phrases, 
        especially those related to social media, with polite alternatives.       

    Author: Mariam Badr Yehia Abd El-naby
    Date: 11 Oct 2024
    Detailed explanation of the file :

        The program solves several problems. It can remove extra spaces between words, 
        print the prime numbers of a given number entered by the user, 
        determine if it is possible to arrange domino pieces such that the right side of each piece matches the left side of the next piece, 
        and also modify a message to make it socially acceptable by filtering out inappropriate words, particularly related to social media.
        
*/
#include <bits/stdc++.h>
using namespace std;

void problem1() ;
void problem4(long long n);
void problem7(int n) ;
void problem10(string nameFile, string wordsFile) ;
void clear_Input() ;

int main() {
    cout << "==========================  Welcome to this program  ==========================" ;

    while (true){
        int choice1, choice2 ;
        
        // User menu
        cout << endl ;
        cout << "1) Programs" << endl;
        cout << "2) End" << endl;
        cout << endl ;
        cout << "Please, choose a valid  what do you want: ";
        cin  >> choice1;
        // Invalidate user input
        while (cin.fail() || (choice1 != 1 && choice1 != 2)) {

            clear_Input();
            cout << endl <<"Invalid input.\nPlease enter a valid choice: ";
            cin >> choice1;
        }

        if (choice1 == 2 ) {
            cout << "*****Thank you for using This  program*****" ;
            break;                         // Exit the program for choice 2

        }else {
            cout << endl ;
            cout << "1) Problem 1 (Modify a sentence) "     << endl;
            cout << "2) Problem 4 (Find prime numbers up to a given number)"  << endl;
            cout << "3) Problem 7 (Solve a domino chain problem)"     << endl;
            cout << "4) Problem 10 (Edit a text file based on a dictionary of word replacements)"    << endl;
            cout << "5) Return (Go back to the main menu)"        << endl;
            cout << endl ;
            cout << "Which problem do you want to choose:  " ;
            cin >>  choice2;

            while (choice2 < 1 || choice2 > 5 || cin.fail()) {

                 clear_Input();
                cout << "Invalid input.\n Please, enter a valid choice: ";
                cin >> choice2;
            }

            if (choice2 == 5) {
                continue; // Return to the main menu

            }else if(choice2 == 1){
                cout << "Please, enter your sentence: " ;
                problem1();

            }else if(choice2 == 2){
                cout << "Please, enter your number: "  ;
                long long n ; cin >> n ;
                 while (n < 0 || cin.fail()) {
                      cout << endl ;
                      clear_Input();
                    cout << "Invalid input.\n Please, enter a valid number: ";
                    cin >> n;
                }
                problem4(n);
            }

            else if(choice2 == 3){
                cout << "Please, enter your number of domino : " ; 
                long long n ; cin >> n ;
                 while (n < 0 || cin.fail()) {
                    clear_Input();
                    cout << "Invalid input.\n Please, enter a valid number: ";
                    cin >> n;
                }
                problem7(n);

            }else if (choice2 = 4){

               string nameFile , words ;int chooseFile , choosewords; 

               cout << "Are you want to enter your file(1) or file by default(2) ? "<< endl ;
               cout << "enter what do you want 1 or 2: " ;
               cin >> chooseFile ;
               cout << endl ;
                while (chooseFile != 1 && chooseFile != 2 ) {
                      clear_Input();
                    cout << "Invalid input.\n Please, enter a valid choice: ";
                    cin >> chooseFile;
                    cout << endl ;
                }
               if(chooseFile == 1) {
                        cout << endl << "please, enter name of your file: "  ;
                        cin >> nameFile ;
               }else{
                nameFile = "input.txt";
               }

               cout << endl ;
               cout << "Are you want to enter your words file(1) or words file by default(2) ? " << endl;
               cout << "enter what do you want 1 or 2: " ;
               cin >> choosewords ;

                while (choosewords != 1 && choosewords != 2 ) {
                      clear_Input();
                    cout << "Invalid input.\n Please, enter a valid choice: ";
                    cin >> choosewords;
                }
               if(choosewords == 1) {
                        cout << endl<< "please, enter name of your words file: "  ;
                        cin >> words ;
               }else{
                words = "words.txt";
               }

              problem10(nameFile , words);
              cout << "Edit file Saved successfully as output." << endl ;
            }
 
        } 
    }
    
    return 0;
}


void problem1(){
    char sequence[101] , ch; cin >> sequence[0] ; int index = 1 ; bool word = false ;
    while(cin.get(ch)  && ch  != '.' && index < 101){
      sequence[index++] = ch ;
   }
    string edit_seq ;
    edit_seq += toupper(sequence[0]) ;
    
    for(int i = 1 ; i < index ; i++){
        
       if(isalpha(sequence[i])){
           
           edit_seq += tolower(sequence[i]);
           word = true ;
           
       }else if(isspace(sequence[i])) {
           if(word){
              edit_seq += ' ';
              word = false ;
           }
           
       }else{
           edit_seq += sequence[i];
           word = true ;
       }
    }
    edit_seq += '.';
    cout << "Modified sentence: " << edit_seq << endl ;

}


void problem4( long long n ){
   vector<bool> numbers(n + 1, true);

   for(long long i = 2 ; i * i <= n ; i++){
     
     if(numbers[i]){

        for(long long j = i * i; j <= n ; j += i){
          numbers[j] = false ;
     }
     }
   }
   cout << "Primes number are: { ";
   for(int i = 2 ; i <= n; i++){
    if(numbers[i]){
       if(i != 2) cout << ", " ;
       cout << i  ;
     } 
   }
   cout << " }"  << endl ;

}

struct dominoT {
    int leftDots;
    int rightDots;
};

bool Chain(int right, int index, vector<dominoT>& dominos, vector<dominoT>& res, vector<bool>& done) {
    if (index == dominos.size()) {
        cout << "The order domain is: ";
        for (int i = 0; i < res.size(); i++) {
            if (i > 0) cout << " - ";
            cout << res[i].leftDots << "|" << res[i].rightDots;
        }
        cout << endl;
        return true;
    }
    for (int i = 0; i < dominos.size(); i++) {
        if (!done[i] && dominos[i].leftDots == right) {
            done[i] = true;
            res.push_back(dominos[i]);
            if (Chain(dominos[i].rightDots, index + 1, dominos, res, done)) {
                return true;
            }
            res.pop_back();
            done[i] = false;
        }
    }
    return false;
}

bool FormsDominoChain(vector<dominoT>& dominos) {
    vector<dominoT> res;
    vector<bool> done(dominos.size(), false);
    for (int i = 0; i < dominos.size(); i++) {
        done[i] = true;
        res.push_back(dominos[i]);
        if (Chain(dominos[i].rightDots, 1, dominos, res, done)) {
            return true;
        }
        res.pop_back();
        done[i] = false;
    }
    return false;
}

void problem7(int n) {
    vector<dominoT> dominos(n);
    cout << "Please, enter your dominos: ";
    for (int i = 0; i < n; i++) {
        cin >> dominos[i].leftDots >> dominos[i].rightDots;
    }
    if (!FormsDominoChain(dominos)) cout << "No way to form a domino chain." << endl;
}


void problem10(string nameFile, string wordsFile) {
    
    wifstream file, Words;
    wofstream newFile("output.txt") ;

    Words.imbue(locale(Words.getloc(), new codecvt_utf8<wchar_t>()));
    file.imbue(locale(file.getloc(), new codecvt_utf8<wchar_t>()));
    
    Words.open(wordsFile);
    while(!Words.is_open()){

         cerr << "error, opening words file." << endl ;
         cerr << "Please, enter a correct file: " ;
         cin >> wordsFile ;
         Words.imbue(locale(Words.getloc(), new codecvt_utf8<wchar_t>()));
         Words.open(wordsFile);
         cerr << endl ;  cerr << endl ;
    }
   
    map<wstring, wstring> list;
    wstring line;

    
    while (getline(Words, line)) {

        wstring wrong, correct;
        wstringstream iss(line);
        iss >> wrong >> correct;
        list[wrong] = correct; 
    }
    Words.close();


    file.open(nameFile);
    while(!file.is_open()){
         cerr << "error, opening input file." << endl ;
         cerr << "Please, enter a correct file: " ;
         cin >> nameFile ;
         file.imbue(locale(file.getloc(), new codecvt_utf8<wchar_t>()));
         file.open(nameFile);
         cerr << endl ; cerr << endl ;
    }
  

    wstring word;
    newFile.imbue(locale(newFile.getloc(), new codecvt_utf8<wchar_t>()));
    while (file >> word) {
        if (list.count(word)) {
            newFile << list[word]; 
        } else {
            newFile << word; 
        }
        newFile << " ";
    }

    file.close();  
    newFile.close(); 
}


void clear_Input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
