#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

struct Question {
    string question;
    string correctAnswer;
    vector<string> options;
};

void displayQuestion(const Question& q) {
    cout << q.question << endl;
    for (int i = 0; i < q.options.size(); ++i) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
}

Question getRandomQuestion(const vector<Question>& questions) {
    int index = rand() % questions.size();
    return questions[index];
}

bool checkAnswer(const Question& q, int choice) {
    return q.options[choice - 1] == q.correctAnswer;
}

int main() {
    srand(time(0));
    vector<Question> questions = {
        {"Ai la ngươi dau tien dat chan len mat trang?", "Neil Armstrong", {"Neil Armstrong", "Buzz Aldrin", "Yuri Gagarin", "Alan Shepard"}},
        {"Thanh pho nao duoc goi la thanh pho khong ngu?", "New York", {"New York", "Las Vegas", "Tokyo", "Paris"}},
        {"Quoc gia nao co dan so dong nhat the gioi?", "Trung Quoc", {"An Do", "Trung Quoc", "My", "Indonesia"}},
        {"Ai la nha phat minh ra den dot o?", "Thomas Edison", {"Thomas Edison", "Nikola Tesla", "Albert Einstein", "Alexander Graham Bell"}}
    };

    int score = 0;
    int questionIndex = 0;

    // Lặp qua các câu hỏi
    while (questionIndex < questions.size()) {
        Question q = getRandomQuestion(questions);
        displayQuestion(q);

        int choice;
        cout << "Chon phuon an cua ban (1-4): ";
        cin >> choice;

        if (checkAnswer(q, choice)) {
            cout << "Chinh xac!" << endl;
            score++;
            questionIndex++; // Chỉ tăng questionIndex nếu người chơi trả lời đúng
        } else {
            cout << "Sai roi! Cau tra loi dung la " << q.correctAnswer << endl;
            break; // Dừng ngay khi người chơi trả lời sai
        }
    }

    cout << "So diem cua ban: " << score << endl;

    return 0;
}
