#include <iostream>

using namespace std;

int hitungPanjangString(string str) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

string enkripsiSandi(string pesan) {
    int len = hitungPanjangString(pesan);
    string hasil_sandi = "";
    int prev_val = 0;

    for (int i = 0; i < len; i++) {
        char curr_char = pesan[i];
        
        if (curr_char >= 'A' && curr_char <= 'Z') {
            int curr_val = curr_char - 'A' + 1;
            int new_val = ((curr_val + prev_val - 1) % 26) + 1;
            char encrypted_char = (char)(new_val + 'A' - 1);

            hasil_sandi += encrypted_char;
            prev_val = curr_val;
        } else {
            hasil_sandi += curr_char;
        }
    }

    return hasil_sandi;
}

int main() {
    string pesan;

    cout << "Masukkan pesan rahasia: ";
    cin >> pesan;

    string hasil = enkripsiSandi(pesan);

    cout << "Pesan hasil sandi: " << hasil << endl;

    return 0;
}