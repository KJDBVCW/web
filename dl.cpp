#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Định nghĩa một cấu trúc dữ liệu để lưu trữ câu hỏi và câu trả lời
struct Question {
    string question;
    string correctAnswer;
    vector<string> options;
};

// Hàm để hiển thị câu hỏi và các phương án
void displayQuestion(const Question& q) {
    cout << q.question << endl;
    for (int i = 0; i < q.options.size(); ++i) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
}

// Hàm để lấy ngẫu nhiên một câu hỏi từ vector các câu hỏi
Question getRandomQuestion(const vector<Question>& questions) {
    int index = rand() % questions.size();
    return questions[index];
}

// Hàm kiểm tra xem người chơi có trả lời đúng không
bool checkAnswer(const Question& q, int choice) {
    return q.options[choice - 1] == q.correctAnswer;
}

int main() {
    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(time(0));

    // Tạo vector chứa các câu hỏi và câu trả lời
    vector<Question> questions = {
        {"Ai la ngươi dau tien dat chan len mat trang?", "Neil Armstrong", {"Neil Armstrong", "Buzz Aldrin", "Yuri Gagarin", "Alan Shepard"}},
        {"Thanh pho nao duoc goi la thanh pho khong ngu?", "New York", {"New York", "Las Vegas", "Tokyo", "Paris"}},
        {"Quoc gia nao co dan so dong nhat the gioi?", "Trung Quốc", {"Ấn Độ", "Trung Quốc", "Mỹ", "Indonesia"}},
        {"Ai la nha phat minh ra den dot o?", "Thomas Edison", {"Thomas Edison", "Nikola Tesla", "Albert Einstein", "Alexander Graham Bell"}}
    };

    // Biến để lưu trữ số điểm của người chơi
    int score = 0;

    // Lặp qua các câu hỏi
    for (int i = 0; i < questions.size(); ++i) {
        // Lấy một câu hỏi ngẫu nhiên
        Question q = getRandomQuestion(questions);

        // Hiển thị câu hỏi và các phương án
        displayQuestion(q);

        // Nhận câu trả lời từ người chơi
        int choice;
        cout << "Chon phuong an cua ban (1-4): ";
        cin >> choice;

        // Kiểm tra câu trả lời
        if (checkAnswer(q, choice)) {
            cout << "Chinh xac!" << endl;
            score++;
        } else {
            cout << "Sai roi. Cau tra loi dung la: " << q.correctAnswer << endl;
        }

        // Xóa câu hỏi đã sử dụng khỏi vector để không trùng lặp
        questions.erase(questions.begin() + i);

    }

    // Hiển thị số điểm cuối cùng
    cout << "So diem cua ban: " << score << endl;

    return 0;
}
