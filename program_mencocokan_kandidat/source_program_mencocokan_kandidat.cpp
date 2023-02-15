#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;
using std::vector;

namespace self {
    int tinggi, warnakulit, tampilan, postur, keramahan, kerajinan, pendidikan, profesi;
}

struct candidate {
    string nama = "";
    int tinggi = 0;
    int warnakulit = 0;
    int tampilan = 0;
    int postur = 0;
    int keramahan = 0;
    int kerajinan = 0;
    int pendidikan = 0;
    int profesi = 0;
};

vector<candidate> dataList;

int main() {
    cout << "Program mencari dan mencocokan jodoh \n";
    cout << "==================================== \n";

    string nama = "";
    cout << "Silahkan masukan nama mu: ";
    getline(cin, nama);
    cout << "Selamat datang " << nama << "\n";

    auto input = [&](const string& label, int& variable) {
        cout << "Berapa skor " << label << " kamu (1-10): ";
        while (!(cin >> variable)) {
            cout << "Input harus berupa integer, silahkan masukan lagi: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (variable > 10) variable = 10;
        if (variable < 1) variable = 1;
    };

    input("tinggi", self::tinggi);
    input("warna kulit", self::warnakulit);
    input("tampilan", self::tampilan);
    input("postur", self::postur);
    input("keramahan", self::keramahan);
    input("kerajinan", self::kerajinan);
    input("pendidikan", self::pendidikan);
    input("profesi", self::profesi);

    int selfScore = self::tinggi + self::warnakulit + self::tampilan + self::postur + self::keramahan + self::kerajinan + self::pendidikan + self::profesi;

    while (true) {
        candidate dataCandidate;

        cout << "Masukan nama kandidat pasangan kamu atau ketik \"s\" untuk berhenti : ";
        cin >> dataCandidate.nama;
        if (dataCandidate.nama == "s") {
            break;
        }

        auto input = [&](const string& label, int& variable) {
            cout << "Berapa skor " << label << " kandidat (1-10): ";
            while (!(cin >> variable)) {
                cout << "Input harus berupa integer, silahkan masukan lagi: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (variable > 10) variable = 10;
            if (variable < 1) variable = 1;
        };

        input("tinggi", dataCandidate.tinggi);
        input("warna kulit", dataCandidate.warnakulit);
        input("tampilan", dataCandidate.tampilan);
        input("postur", dataCandidate.postur);
        input("keramahan", dataCandidate.keramahan);
        input("kerajinan", dataCandidate.kerajinan);
        input("pendidikan", dataCandidate.pendidikan);
        input("profesi", dataCandidate.profesi);

        dataList.push_back(dataCandidate);
    }

    for (const auto& dataCandidate : dataList) {
        int candidateScore = { dataCandidate.tinggi + dataCandidate.warnakulit + dataCandidate.tampilan +
            dataCandidate.postur + dataCandidate.keramahan + dataCandidate.kerajinan + dataCandidate.pendidikan + dataCandidate.profesi };

        cout << "Nama: " << dataCandidate.nama << "\n";
        cout << "Skor tinggi kandidat: " << dataCandidate.tinggi << "\n";
        cout << "Skor warna kulit kandidat: " << dataCandidate.warnakulit << "\n";
        cout << "Skor tampilan kandidat: " << dataCandidate.tampilan << "\n";
        cout << "Skor postur kandidat: " << dataCandidate.postur << "\n";
        cout << "Skor keramahan kandidat: " << dataCandidate.keramahan << "\n";
        cout << "Skor kerajinan kandidat: " << dataCandidate.kerajinan << "\n";
        cout << "Skor pendidikan kandidat: " << dataCandidate.pendidikan << "\n";
        cout << "Skor profesi kandidat: " << dataCandidate.profesi << "\n";
        cout << "Total skor diri kamu: " << selfScore << "\n";
        cout << "Total skor kandidat: " << candidateScore << "\n";

        if (candidateScore >= selfScore - 3 && candidateScore <= selfScore + 3) {
            cout << "Kandidat ini sesuai dengan kriteria dirimu" << "\n";
        }
        else {
            cout << "Kandidat ini tidak sesuai dengan kriteria dirimu" << "\n";
        }

        int rangeScore = abs(selfScore - candidateScore);
        if (rangeScore >= 66) {
            cout << "Kamu tidak akan sejahtera dengan kandidat ini \n";
        }
        else if (rangeScore >= 33 && rangeScore <= 65) {
            cout << "Mungkin kamu bisa sejahtera dengan kandidat ini \n";
        }
        else if (rangeScore >= 0 && rangeScore <= 32) {
            cout << "Kamu akan sejahtera dengan kandidat ini \n";
        }
    }
    return 0;
}