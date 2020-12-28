/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "common.h"

/* A108870 Tokuda's good set of increments for Shell sort.
 * Source: https://oeis.org/A108870 */
constexpr int tokuda_seq[] = { 1, 4, 9, 20, 46, 103, 233, 525, 1182, 2660, 5985, 13467, 30301, 68178, 153401, 345152,
                               776591, 1747331, 3931496, 8845866, 19903198, 44782196, 100759940, 226709866,
                               510097200, 1147718700 };

int get_max_gap(int n) {
    if (n <= 1) return 0;
    int st = 0, ed = sizeof(tokuda_seq) - 1;
    while (st < ed) {
        int mid = st + ((ed - st) / 2);
        if (n > tokuda_seq[mid]) st = mid + 1;
        else if (n < tokuda_seq[mid]) ed = mid;
        else if (n == tokuda_seq[mid]) {
            return mid - 1;
        }
    }
    return (tokuda_seq[st] < n) ? st : st - 1;
}

/* Shell sort
 * Average Complexity: -
 * Best Complexity: -
 * Worse Complexity: O(N^2) */
void shellsort(vector<double> &arr, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size();
    for (int index = get_max_gap(ed - st); index >= 0; --index) {
        int gap = tokuda_seq[index];
        for (int i = gap; i < ed; ++i) {
            double val = arr[i];
            int j = i;
            for (; j >= gap && arr[j - gap] > val; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = val;
        }
    }
}

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    print_arr(arr);
    shellsort(arr);
    print_arr(arr);
    return 0;
}
