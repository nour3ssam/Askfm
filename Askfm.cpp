#include <iostream>
#include<string>
#include <vector>
#include <fstream>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int Mainn();
class User;
class Question;
class Answer; 
vector<User>Userslist;
vector<Question>Questionslist;
vector<Answer>Answerslist;

void Add_A_To_System(Answer ANew);
void Add_Q_To_System(Question QNew);

class Question {
private:
    string question;
    int from_id;
    int to_id;
    int idQ;
public:
    friend class System;
    Question() {
        question = "";
        from_id = 0;
        to_id = 0;
        idQ = 0;
    };
    Question(int idQ, string question, int from_id, int to_id ) {
        this->question = question;
        this->from_id = from_id;
        this->to_id = to_id;
        this->idQ = idQ;
    }
    void setquestion(string question) {
        this->question = question;
    }
    string getquestion() {
        return question;
    }
    void setidQ(int id) {
        this->idQ = id;
    }
    int getidQ() {
        return idQ;
    }
    void setfromid(int from_id) {
        this->from_id = from_id;
    }
    int  getfromid() {
        return from_id;
    }
    void settoid(int to_id) {
        this->to_id = to_id;
    }
    int  gettoid() {
        return  to_id;
    }
};

class Answer {
    string answer;
    int idA;
    int from_id;
    int to_id;
    int qid;
public:
    friend class System;
   
    Answer() {
        answer = "";
         from_id=0;
         to_id=0;
          idA = 0;
          qid = 0;
    };
    Answer( int idA,string answer, int from_id, int to_id ,int qid) {
        this->answer = answer;
        this->from_id = from_id;
        this->to_id = to_id;
        this->qid = qid;
        this->idA = idA;
    }
    void Setanswer(string answer) {
        this->answer = answer;
    }
    string getanswer() {
        return answer;
    }
    void setidA(int idA) {
        this->idA = idA;
    }
    int getidA() {
        return idA;
    }
    void setfromid() {
        this->from_id = from_id;
    }
    int  getfromid() {
        return from_id;
    }
    int  gettoid() {
        return  to_id;
    }
    void settoid(int to_id) {
        this->to_id = to_id;
    }
    int  getqid() {
        return  qid;
    }
    void setqid(int qid) {
        this->qid = qid;
    }
}; 
class User {
private:
    string Username;
    string Password;
    int id;
public:
    void friend Add_User_To_System(User New_User);
    friend class System;
    friend class Question;
    User() {
        Username = "";
        Password = "";
        id = 0;
    };
    User(int id, string username, string password) {
        this->Username = username;
        this->Password = password;
        this->id = id;
    }
    void Setusername(string username) {
        this->Username = username;
    }
    string getusername() {
        return Username;
    }
    int getid() {
        return id;
    }
    void SetPassword(string Password) {
        this->Password = Password;
    }
    string getpassword() {
        return Password;
    }
    User LogIn() {
        bool ck = 0;
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        for (int i = 0; i < Userslist.size(); i++) {
            if (Userslist[i].Username == username and Userslist[i].Password == password) {
                ck = 1;
                cout << "Your login is successfull. Thanks for logging in ! " << endl;
                return Userslist[i];
            }
        }
        if (!ck) {
            int x = 0;
            cout << "Invalid username or password " << endl;
            cout << "Enter 1: forget password " << endl;
            cout << "Enter 2: Try again " << endl;
            cin >> x;
            if (x == 1) {
                forgetuser();
            }
            if (x == 2) {
                return LogIn();
            }
        }
    }
    User registration() {
        bool ch = 0;
        string ruser, rpassword;
        cout << "Enter the username : ";
        cin >> ruser;
        cout << "Enter the password : ";
        cin >> rpassword;
        for (int i = 0; i < Userslist.size(); i++) {
            if (Userslist[i].Username == ruser) {
                ch = 1;
            }
        }
        if (ch) {
            cout << "Username already taken. Try another." << endl;
            return registration();
        }
        else {
            int New_userid;
            if (Userslist.empty()) {
                New_userid = 1;
            }
            else {
                New_userid = (Userslist.back().id) + 1;
            }
            User New_User(New_userid, ruser, rpassword);
            Userslist.push_back(New_User);
            Add_User_To_System(New_User);
            return New_User;
        }
    }
    void forgetuser() {
        bool fh = 0;
        string fusername;
        cout << "Enter your username please: ";
        cin >> fusername;
        int fid;
        cout << "Enter your ID please: ";
        cin >> fid;
        for (int i = 0; i < Userslist.size(); i++) {
            if (Userslist[i].Username == fusername and Userslist[i].id == fid) {
                fh = 1;
                cout << "Your password is " << Userslist[i].Password << endl;
            }
        }
        if (!fh) {
            cout << "Invalid username or ID. Try again." << endl;
            forgetuser();
        }
    }
    void users_list() {
        for (int i = 0; i < Userslist.size(); i++) {
            cout << Userslist[i].id << " " << Userslist[i].Username << " " << Userslist[i].Password << endl;
        }
    }
    void Ask_Question() {
        bool from = 0;
        bool to = 0;
        int touserid = 0;
        int fromuserid = 0;
        string fromuser;
        cout << "Enter your username: ";
        cin >> fromuser;
        string touser;
        cout << "Enter user name to ask him: ";
        cin >> touser;
        for (int i = 0; i < Userslist.size(); i++) {
            if (Userslist[i].Username == touser) {
                to = 1;
                touserid = Userslist[i].id;
            }
            if (Userslist[i].Username == fromuser) {
                from = 1;
                fromuserid = Userslist[i].id;
            }
        }
        if (!from) {
            cout << "your Username to send Q is incorrect Try again " << endl;
            return Ask_Question();
        }
        if (!to) {
            cout << "Username to receive Q is incorrect Try again " << endl;
            return Ask_Question();
        }
        cout << "Enter Question: ";
        string question;
        cin >> std::ws;
        getline(cin, question);
        int Qid ;
        if (Questionslist.empty()) {
            Qid = 1;
        }
        else {
            Qid = (Questionslist.back().getidQ()) + 1;
        }
        Question New_qus = { Qid, question, fromuserid, touserid };
        Questionslist.push_back(New_qus);
        Add_Q_To_System(New_qus);
    }
    void Answer_Question() {
        bool ca = 0;
        int queid = 0;
        int idfrom_user;
        cout << "Enter Question ID: ";
        cin >> queid;
        try {
            for (int i = 0; i < Questionslist.size(); i++) {
                if (Questionslist[i].getidQ() == queid) {
                    ca = 1;
                    if (Questionslist[i].gettoid() != id) {
                        string wrong = "This question is not to you: Try again ";
                        throw wrong;
                    }
                   string from_user = Userslist[Questionslist[i].getfromid() -1].Username;
                    idfrom_user = Userslist[Questionslist[i].getfromid() - 1].id;
                   cout << "Question From " << from_user << " to " << Username << " : ";;
                   cout << Questionslist[i].getquestion() << endl;
                   break;
                }
            }
        }
        catch (string x) {
            cout << x << endl;
            return Answer_Question();
        }
        if (!ca) {
            cout << "Question ID is incorrect: Try again ";
            return Answer_Question();
        }
        cout << "Enter your answer: ";
        string answer;
        cin >> std::ws;
        getline(cin, answer);
        int idanswer = 0;
        if (Answerslist.empty()) {
            idanswer = 1;
        }
        else {
            idanswer = (Answerslist.back().getidA()) + 1;
        }
        Answer New_ans(idanswer, answer, id, idfrom_user, queid);
        Answerslist.push_back(New_ans);
        Add_A_To_System(New_ans);
    } 
    void feed(){
        bool cq = 0;
        for (int i = 0; i < Questionslist.size(); i++) {
            bool cn = 0;
            cq = 1;
            cout << "Question id (" << Questionslist[i].getidQ() << ") from user id(" << Questionslist[i].getfromid() << ") To user id(" << Questionslist[i].gettoid() << ")" << endl;
            cout << "Question: " << Questionslist[i].getquestion() << endl;
            for (int j = 0; j < Answerslist.size(); j++) {
                if (Questionslist[i].getidQ() == Answerslist[j].getqid()) {
                    cout << "Answer: " << Answerslist[j].getanswer() << endl;
                    cn = 1;
                }
            }
            if (!cn) {
                cout << "There is no answer yet " << endl;
            }
        }
        if (!cq) {
            cout << "There is no Questions yet " << endl;
        }
    }
    void print_from_me() {// I send question 
        bool ok = 0;
        for (int i = 0; i < Questionslist.size(); i++) {
            if (Questionslist[i].getfromid() == id) {
                bool cn = 0;
                ok = 1;
                cout << "Question Id (" << Questionslist[i].getidQ() << ") to user id(" << Questionslist[i].gettoid() << ")" << endl;
                cout << "Question: " << Questionslist[i].getquestion() << endl;
                for (int j = 0; j < Answerslist.size(); j++) {
                    if (Questionslist[i].getidQ() == Answerslist[j].getqid()) {
                        cn = 1;
                        cout << "Answer: " << Answerslist[j].getanswer() << endl;
                    }
                    break;
                }
                if (!cn) {
                    cout << " NO answer yet" << endl;
                }
            }
        }
        if (!ok) {
            cout << "you didn't send any Questions." << endl;
        }
    }
    void print_Q_to_me() {// I send answer
        bool ok = 0;
        for (int i = 0; i < Questionslist.size(); i++) {
            if (Questionslist[i].gettoid() == id) {
                ok = 1;
                bool cn = 0; 
                string from_user = Userslist[Questionslist[i].getfromid() - 1].Username;
                cout << " Question ID (" << Questionslist[i].getidQ() << ")" << " from " << from_user << " :" << " Question is " << Questionslist[i].getquestion() << endl;
                for (int j = 0; j < Answerslist.size(); j++) {
                    if (Questionslist[i].getidQ() == Answerslist[j].getqid()) {
                        cout << " Your answer is -> " << Answerslist[j].getanswer() << endl;
                        cn = 1;
                    }
                }
                if (!cn) {
                    cout << "You still haven't answered the question " << endl;
                }
            }
        }
        if (!ok) {
            cout << "There are no Questions for you." << endl;
        }
    }
};
class System {
public:
    System() {
        Userslist.clear();
        ifstream User_file("users.txt", ios::in);
        if (User_file.is_open()) {
            User user;
            while (User_file >> user.id >> user.Username >> user.Password) {
                Userslist.push_back(user);
            }
            User_file.close();
        }
        Questionslist.clear();
        ifstream Qus_file("Question.txt", ios::in);
        if (Qus_file.is_open()) {
            Question qus;
            while (Qus_file >> qus.idQ >> qus.question >> qus.from_id >> qus.to_id) {
                Questionslist.push_back(qus);
            }
            Qus_file.close();
        }
        Answerslist.clear();
        ifstream ans_file("Answers.txt", ios::in);
        if (ans_file.is_open()) {
            Answer ans;
            while (ans_file >> ans.idA >> ans.answer >> ans.from_id >> ans.to_id >> ans.qid) {
                Answerslist.push_back(ans);
            }
            ans_file.close();
        }
    }
};
void Add_User_To_System(User New_User) {
    ofstream Ufile("users.txt", ios::out | ios::app);
    Ufile << New_User.id << " " << New_User.Username << " " << New_User.Password << endl;
    cout << "Registration is successfully! " << endl;
    Ufile.close();
}
void Add_Q_To_System(Question QNew) {
    ofstream Qfile("Question.txt", ios::out | ios::app);
    Qfile << QNew.getidQ() << " " << QNew.getquestion() << " " << QNew.getfromid() << " " << QNew.gettoid() << endl;
    cout << "Added question successfully! " << endl;
    Qfile.close();
}
void Add_A_To_System(Answer ANew) {
    ofstream Afile("Answers.txt", ios::out | ios::app);
    Afile << ANew.getidA() << " " << ANew.getanswer() << " " << ANew.getfromid() << " " << ANew.gettoid() <<" "<< ANew.getqid() << endl;
    cout << "Added answer successfully! " << endl;
    Afile.close();
}
int Mainn() {
    cout << "--------------------------" << endl;
    cout << "1: Log in" << endl;
    cout << "2: Sign up" << endl;
    cout << "3: forget password" << endl;
    cout << "4: Exit" << endl;
    cout << "Enter your choice: ";
    cin.exceptions(cin.failbit);
    try {
        int number;
        cin >> number;
        if (number != 1 and number != 2 and number != 3 and number !=4 ) {
            throw number;
        }
        if (number == 1) {
            return number;
        }
        if (number == 2) {
            return number;
        }
        if (number == 3) {
            return number;
        }
        if (number == 4) {
            return 0;
        }  
    }
    catch (int x) {
        cout << x << " is invalid number" << endl << "please enter number in range 1 - 4 : " << endl;
        Mainn();
    }
}
int Range() {
    cout << "--------------------------" << endl;
    cout << "1: Print Questions To Me" << endl;
    cout << "2: Print Questions From Me" << endl;
    cout << "3: Answer Question" << endl;
    cout << "4: Ask Question" << endl;
    cout << "5: List System Users" << endl;
    cout << "6: Feed" << endl;
    cout << "7: Logout" << endl;
    cout << "8: main" << endl;
    cout << "Enter number in range 1 - 8: ";
    cin.exceptions(cin.failbit);
    try {
        int option = 0; cin >> option;
        if (option <= 0 or option > 8) {
            throw option;
        }
        else {
            return option;
        }
    }
    catch (int x) {
        cout << x << " is invalid number" << endl << "please enter number in range 1 - 8 : " << endl;
        Range();
    }
}
int main(){
    System s;
    User use;
    int number;
    cout << "Welcome to the user management system." << endl;
start:
    number = Mainn();
    if (number == 1) {
        use = use.LogIn();
        cout << "Your ID is " << use.getid() << endl;
    }
    if (number == 2) {
        use = use.registration();
        cout << "Your ID is " << use.getid() << endl;
    }
    if (number == 3) {
         use.forgetuser();
         goto start;
    }
    int num = 0;
second:
    num = Range();
    if (num == 1) {
        use.print_Q_to_me();
        goto second;
    }
    if (num == 2) {
        use.print_from_me();
        goto second;
    }
    if (num == 3) {
        use.Answer_Question();
        goto second;
    }
    if (num == 4) {
        use.Ask_Question();
        goto second;
    }
    if (num == 5) {
         use.users_list();
         goto second;
    }
    if (num == 6) {
        use.feed();
        goto second;
    }
    if (num == 7) {
        return 0;
    }
    if (num == 8) {
        goto start;
    }
}
