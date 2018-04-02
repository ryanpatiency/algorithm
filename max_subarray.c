/*
 * Divide the problem into three part,
 * subarray including mid element,
 * subarray not .. and in left,
 * subarray not .. and in right
 *
 * for subarray including mid element,
 * example
 *
 * base on day 2
 *
 * symbol| i
 * Day   | 0    1   2   3   4   5
 * Price | 100  113 110 85  105 102
 * change|      13  -3  -25 20  -3
 * ch_sum| -10  3   0   -25 -5  -8
 *
 * it's propotional to n, because we only need to minus day(mid) by day(i)
 * find the max to the right,
 * find the min to the left,
 * record the index. and the value
 *
 * when there is only one element, return;
 *
 * there will be three return value:
 *      left index,
 *      right index,
 *      the difference
 * there will be parameter as follows::
 *      the array,
 *      the start index
 *      the end index
 *      the pointer to left index
 *      the pointer to right index
 *
 * Combine:
 *
 * compare three part's difference value, return the max one after set the
 * pointers
 */

static int max_mid_subarray(int *a, int start, int mid, int end, int *lidx,
        int *ridx)
{
    int midtoendsize = 1 + end - mid;

    int starttomidsize = 1 + mid - start;

    *lidx = *ridx = mid;
    // here, it is 0 to 2, and 2 to 5
    // change to end idx  | 0   1   2   3
    // array idx          | 2   3   4   5
    // change to start idx| 0   1   2
    // array idx          | 2   1   0
    // init change_to_end and change_to_start
    int right_max_change = 0;
    for(int i = 0; i < midtoendsize; i++) {
        int change = a[mid + i] - a[mid];
        if(change > right_max_change) {
            *ridx = mid + i;
            right_max_change = change;
        }
    }
    int left_min_change = 0;
    for(int i = 0; i < starttomidsize; i++) {
        int change = a[mid - i] - a[mid];
        if(change < left_min_change) {
            *lidx = mid - i;
            left_min_change = change;
        }
    }

    return right_max_change - left_min_change;
}

int max_subarray(int *a, int start, int end, int *lidx, int *ridx)
{
    if(start == end) {
        *lidx = *ridx = start;
        return 0;
    }
    int mid = (start + end) / 2;
    int mid_lidx, mid_ridx;
    int left_lidx, left_ridx;
    int right_lidx, right_ridx;
    int mid_max = max_mid_subarray(a, start, mid, end, &mid_lidx, &mid_ridx);
    int left_max = max_subarray(a, start, mid, &left_lidx, &left_ridx);
    int right_max = max_subarray(a, mid + 1, end, &right_lidx, &right_ridx);


    if(mid_max > left_max && mid_max > right_max) {
        *lidx = mid_lidx;
        *ridx = mid_ridx;
        return mid_max;
    } else if(left_max > right_max) {
        *lidx = left_lidx;
        *ridx = left_ridx;
        return left_max;
    } else {
        *lidx = right_lidx;
        *ridx = right_ridx;
        return right_max;
    }
}
