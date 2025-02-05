#include <iostream>
#include <vector>

using namespace std;

// دریافت ماتریس از کاربر
vector<vector<int>> get_matrix(int& rows, int& cols) {
    cout << "تعداد ردیف‌ها را وارد کنید: ";
    cin >> rows;
    cout << "تعداد ستون‌ها را وارد کنید: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "ماتریس را وارد کنید:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// چاپ ماتریس
void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << "\t";
        }
        cout << endl;
    }
}

// ضرب ماتریس‌ها
vector<vector<int>> multiply_matrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        cout << "ضرب ماتریس‌ها ممکن نیست\n";
        return {};
    }

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// جمع ماتریس‌ها
vector<vector<int>> add_matrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2, int rows, int cols) {
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// تفریق ماتریس‌ها
vector<vector<int>> subtract_matrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2, int rows, int cols) {
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

// ضرب یک عدد در ماتریس
vector<vector<int>> multiply_by_scalar(const vector<vector<int>>& matrix, int scalar, int rows, int cols) {
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

// جستجوی یک عنصر در ماتریس
pair<int, int> search_element(const vector<vector<int>>& matrix, int element, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == element) {
                return {i, j};
            }
        }
    }
    return {-1, -1};  // اگر عنصر پیدا نشد
}

// ویرایش یک عنصر در ماتریس
void edit_element(vector<vector<int>>& matrix, int i, int j, int new_value) {
    matrix[i][j] = new_value;
}

// جمع عناصر سطرها
vector<int> row_sum(const vector<vector<int>>& matrix, int rows, int cols) {
    vector<int> result(rows);
    for (int i = 0; i < rows; i++) {
        result[i] = 0;
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i][j];
        }
    }
    return result;
}

// جمع عناصر ستون‌ها
vector<int> column_sum(const vector<vector<int>>& matrix, int rows, int cols) {
    vector<int> result(cols, 0);
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            result[j] += matrix[i][j];
        }
    }
    return result;
}

// جمع عناصر روی قطر اصلی
int diagonal_sum(const vector<vector<int>>& matrix, int rows, int cols) {
    int sum = 0;
    int n = min(rows, cols);
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

// شمارش درایه‌های صفر در ماتریس
int zero_count(const vector<vector<int>>& matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

// شناسایی نوع ماتریس (بالا مثلثی / پایین مثلثی)
string matrix_type(const vector<vector<int>>& matrix, int rows, int cols) {
    bool is_upper = true, is_lower = true;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j && matrix[i][j] != 0) {
                is_upper = false;
            }
            if (i < j && matrix[i][j] != 0) {
                is_lower = false;
            }
        }
    }

    if (is_upper) return "ماتریس بالا مثلثی است";
    if (is_lower) return "ماتریس پایین مثلثی است";
    return "ماتریس نه بالا مثلثی است و نه پایین مثلثی";
}

int main() {
    int rows1, cols1, rows2, cols2;

    // دریافت ماتریس اول
    vector<vector<int>> matrix1 = get_matrix(rows1, cols1);
    cout << "\nماتریس اول:\n";
    print_matrix(matrix1);

    // دریافت ماتریس دوم
    vector<vector<int>> matrix2 = get_matrix(rows2, cols2);
    cout << "\nماتریس دوم:\n";
    print_matrix(matrix2);

    // ضرب ماتریس‌ها
    cout << "\nضرب ماتریس‌ها:\n";
    vector<vector<int>> result = multiply_matrices(matrix1, matrix2, rows1, cols1, rows2, cols2);
    if (!result.empty()) print_matrix(result);

    // جمع ماتریس‌ها
    cout << "\nجمع ماتریس‌ها:\n";
    result = add_matrices(matrix1, matrix2, rows1, cols1);
    print_matrix(result);

    // تفریق ماتریس‌ها
    cout << "\nتفریق ماتریس‌ها:\n";
    result = subtract_matrices(matrix1, matrix2, rows1, cols1);
    print_matrix(result);

    // ضرب عدد در ماتریس
    int scalar;
    cout << "\nعدد مقیاس برای ضرب در ماتریس را وارد کنید: ";
    cin >> scalar;
    cout << "\nضرب ماتریس اول در عدد مقیاس:\n";
    result = multiply_by_scalar(matrix1, scalar, rows1, cols1);
    print_matrix(result);

    // جستجو
    int element;
    cout << "\nعنصری را برای جستجو وارد کنید: ";
    cin >> element;
    pair<int, int> position = search_element(matrix1, element, rows1, cols1);
    if (position.first != -1)
        cout << "عنصر در موقعیت (" << position.first << ", " << position.second << ") پیدا شد.\n";
    else
        cout << "عنصر پیدا نشد.\n";

    // ویرایش
    int i, j, new_value;
    cout << "\nموقعیت (i, j) را برای ویرایش وارد کنید: ";
    cin >> i >> j;
    cout << "مقدار جدید برای عنصر وارد کنید: ";
    cin >> new_value;
    edit_element(matrix1, i, j, new_value);
    cout << "\nماتریس پس از ویرایش:\n";
    print_matrix(matrix1);

    // جمع سطرها
    cout << "\nجمع عناصر سطرها:\n";
    vector<int> rowSums = row_sum(matrix1, rows1, cols1);
    for (int sum : rowSums) cout << sum << "\t";
    cout << endl;

    // جمع ستون‌ها
    cout << endl;
}
