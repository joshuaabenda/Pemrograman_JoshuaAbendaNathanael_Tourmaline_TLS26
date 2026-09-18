#include <iostream>

using namespace std;

void selesaikanProblem1(int N, int K) {
    int astronauts[1000];
    
    for (int i = 0; i < N; i++) {
        astronauts[i] = i + 1;
    }

    int idx = 0;

    cout << "Urutan astronot yang dieliminasi: ";

    while (N > 1) {
        idx = (idx + K - 1) % N;
        int eliminated_no = astronauts[idx];

        cout << eliminated_no << " ";

        for (int i = idx; i < N - 1; i++) {
            astronauts[i] = astronauts[i + 1];
        }

        N--;

        if (N > 1) {
            if (eliminated_no % 2 == 0) {
                K = K + 2;
            } else {
                K = K - 1;
            }

            if (K < 2) {
                K = 2;
            }
        }
    }

    cout << endl;
    cout << "Astronot terakhir yang bertahan: " << astronauts[0] << endl;
}

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;

    if (N < 1) {
        cout << "Jumlah astronot harus minimal 1." << endl;
        return 0;
    }

    cout << "Masukkan nilai K awal: ";
    cin >> K;

    if (K < 2) {
        K = 2;
    }

    selesaikanProblem1(N, K);

    return 0;
}