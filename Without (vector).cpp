#include <iostream>
using namespace std;

// تابع برای چاپ ماتریس
void print_matrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// تابع برای تفریق دو ماتریس
void subtract_matrices(int mat1[][100], int mat2[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// تابع برای ضرب ماتریس در یک عدد (مقیاس)
void multiply_by_scalar(int mat[][100], int scalar, int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat[i][j] * scalar;
        }
    }
}

// تابع برای جستجوی یک عنصر در ماتریس
void search_element(int mat[][100], int element, int rows, int cols, int &found_i, int &found_j) {
    found_i = -1;
    found_j = -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == element) {
                found_i = i;
                found_j = j;
                return;
            }
        }
    }
}

// تابع برای ویرایش یک عنصر در ماتریس
void edit_element(int mat[][100], int i, int j, int new_value, int rows, int cols) {
    if (i >= 0 && i < rows && j >= 0 && j < cols) {
        mat[i][j] = new_value;
    } else {
        cout << "موقعیت نامعتبر است!" << endl;
    }
}

// تابع برای جمع عناصر هر سطر
void row_sum(int mat[][100], int rows, int cols, int sums[]) {
    for (int i = 0; i < rows; i++) {
        sums[i] = 0;
        for (int j = 0; j < cols; j++) {
            sums[i] += mat[i][j];
        }
    }
}

// تابع برای جمع عناصر هر ستون
void col_sum(int mat[][100], int rows, int cols, int sums[]) {
    for (int j = 0; j < cols; j++) {
        sums[j] = 0;
        for (int i = 0; i < rows; i++) {
            sums[j] += mat[i][j];
        }
    }
}

int main() {
    int rows1, cols1;
    cout << "تعداد سطرها و ستون‌های ماتریس اول را وارد کنید: ";
    cin >> rows1 >> cols1;

    int matrix1[100][100], matrix2[100][100], result[100][100];

    // ورود ماتریس اول
    cout << "عناصر ماتریس اول را وارد کنید:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cin >> matrix1[i][j];
        }
    }

    // ورود ماتریس دوم
    cout << "عناصر ماتریس دوم را وارد کنید:\n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cin >> matrix2[i][j];
        }
    }

    // تفریق ماتریس‌ها
    cout << "\nتفریق ماتریس‌ها:\n";
    subtract_matrices(matrix1, matrix2, result, rows1, cols1);
    print_matrix(result, rows1, cols1);

    // ضرب عدد در ماتریس
    int scalar;
    cout << "\nعدد مقیاس برای ضرب در ماتریس را وارد کنید: ";
    cin >> scalar;
    cout << "\nضرب ماتریس اول در عدد مقیاس:\n";
    multiply_by_scalar(matrix1, scalar, result, rows1, cols1);
    print_matrix(result, rows1, cols1);

    // جستجو
    int element;
    cout << "\nعنصری را برای جستجو وارد کنید: ";
    cin >> element;
    int found_i, found_j;
    search_element(matrix1, element, rows1, cols1, found_i, found_j);
    if (found_i != -1)
        cout << "عنصر در موقعیت (" << found_i << ", " << found_j << ") پیدا شد.\n";
    else
        cout << "عنصر پیدا نشد.\n";

    // ویرایش
    int i, j, new_value;
    cout << "\nموقعیت (i, j) را برای ویرایش وارد کنید: ";
    cin >> i >> j;
    cout << "مقدار جدید برای عنصر وارد کنید: ";
    cin >> new_value;
    edit_element(matrix1, i, j, new_value, rows1, cols1);
    cout << "\nماتریس پس از ویرایش:\n";
    print_matrix(matrix1, rows1, cols1);

    // جمع سطرها
    cout << "\nجمع عناصر سطرها:\n";
    int rowSums[100];
    row_sum(matrix1, rows1, cols1, rowSums);
    for (int i = 0; i < rows1; i++) cout << rowSums[i] << "\t";
    cout << endl;

    // جمع ستون‌ها
    cout << "\nجمع عناصر ستون‌ها:\n";
    int colSums[100];
    col_sum(matrix1, rows1, cols1, colSums);
    for (int j = 0; j < cols1; j++) cout << colSums[j] << "\t";
    cout << endl;

    return 0;
}